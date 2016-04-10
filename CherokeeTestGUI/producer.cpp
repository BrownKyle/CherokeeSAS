#include "producer.h"
#include "common.h"
#include <QtCore>
#include <QDebug>
#include <RTIMULib.h>
#include <assert.h>

Producer::Producer(QObject *parent) :
    QThread(parent)
{
}

void Producer::run()
{
    //qsrand(QTime(0,0,0).secsTo(QTime::currentTime()));
    //for (int i = 0; i < DataSize; ++i) {
    //    freeBytes.acquire();
    //    //buffer->Gyr->x[i % BufferSize] = i;
    //    buffer[i % BufferSize].Gyr.x = i;
    //    usedBytes.release();
    //    if(i % 20 == 0)
    //    emit bufferFillCountChanged(usedBytes.available());
    //    emit producerCountChanged(i);
    //}

    uint64_t now;
    uint64_t displayTimer;

    QMutex mutex;

    // mutex prevents the CPU from stopping to work on another thread

    mutex.lock(); // lock mutex for setup
    RTIMUSettings *settings = new RTIMUSettings("RTIMULib");
    RTIMU *imu = RTIMU::createIMU(settings);

    if ((imu == NULL) || (imu->IMUType() == RTIMU_TYPE_NULL)) {
        printf("Canny find the IMU ya dafty.\n");
        exit(1);
    }

    imu->IMUInit();

    imu->setSlerpPower(0.02);
    imu->setGyroEnable(true);
    imu->setAccelEnable(true);
    imu->setCompassEnable(true);

    //unlock mutex
    mutex.unlock();

    displayTimer = RTMath::currentUSecsSinceEpoch();

    //  now just process data

    while (1) {
        //  poll at the rate recommended by the IMU
        int i = 0;

        usleep(imu->IMUGetPollInterval() * 1000); // Reducing this number could reduce the poll time.

        while (imu->IMURead()) {
            mutex.lock();
            RTIMU_DATA imuData = imu->getIMUData();
            now = RTMath::currentUSecsSinceEpoch();
            mutex.unlock();

            //  display 10 times per second

            if ((now - displayTimer) > 100000) {
                // for testing comment out unused lines and change \n for \r,
                // printf("Observer Orientation Output. Roll: %.2f [deg] Pitch: %.2f [deg] Yaw: %.2f [deg]\n", (180/3.14)*imuData.fusionPose.x(),(180/3.14)*imuData.fusionPose.y(),(180/3.14)*imuData.fusionPose.z());
                // printf("Gryo Output. Roll Rate: %.2f [deg/s] Pitch Rate: %.2f [deg/s] Yaw Rate: %.2f [deg/s]\n", (180/3.14)*imuData.gyro.x(),(180/3.14)*imuData.gyro.y(),(180/3.14)*imuData.gyro.z());
                // printf("Accelerometer. X: %.2f [m/s^2] Y: %.2f [m/s^2] X: %.2f [m/s^2]\n", (9.81)*imuData.accel.x(),(9.81)*imuData.accel.y(),(9.81)*imuData.accel.z());
                // printf("Compass. Xmag: %.2f [uT] Ymag: %.2f [uT] X: %.2f [uT]\n", imuData.compass.x(),imuData.compass.y(),imuData.compass.z());
                displayTimer = now;
                //printf("The number from the struct: %f", TestStruct.number);
                mutex.lock();
                freeBytes.acquire();
                buffer[i % BufferSize].Gyr.x = imuData.gyro.x();
                buffer[i % BufferSize].Gyr.y = imuData.gyro.y();
                buffer[i % BufferSize].Gyr.z = imuData.gyro.z();

                buffer[i % BufferSize].Ang.x = imuData.fusionPose.x();
                buffer[i % BufferSize].Ang.y = imuData.fusionPose.y();
                buffer[i % BufferSize].Ang.z = imuData.fusionPose.z();

                buffer[i % BufferSize].Acc.x = imuData.accel.x();
                buffer[i % BufferSize].Acc.y = imuData.accel.y();
                buffer[i % BufferSize].Acc.z = imuData.accel.z();

                buffer[i % BufferSize].Mag.x = imuData.compass.x();
                buffer[i % BufferSize].Mag.y = imuData.compass.y();
                buffer[i % BufferSize].Mag.z = imuData.compass.z();

                buffer[i % BufferSize].time = now;

                usedBytes.release();
                mutex.unlock();
                if(i % 20 == 0)
                emit bufferFillCountChanged(usedBytes.available());
                emit producerCountChanged(i);

                i++;
                /*
                *pIn = imuData.fusionPose.z();
                if (pIn == (&samples[MAX_SAMPLES-1]))
                  pIn = samples;
                else
                  pIn++;
                mutex.unlock();
                */

           }
        }
    }
}

