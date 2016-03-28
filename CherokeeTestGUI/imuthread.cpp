#include "imuthread.h"
#include <QtCore>
#include <QDebug>
#include <RTIMULib.h>
#include <assert.h>

#define MAX_SAMPLES 65536

IMUThread::IMUThread()
{
    // set up ringbuffer
    samples = new int[MAX_SAMPLES];
    // pointer for incoming data
    pIn = samples;
    // pointer for outgoing data
    pOut = samples;

}

int IMUThread::getSample()
{
  assert(pOut!=pIn);
  int value = *pOut;
  if (pOut == (&samples[MAX_SAMPLES-1]))
    pOut = samples;
  else
    pOut++;
  return value;
}


int IMUThread::hasSample()
{
  return (pOut!=pIn);
}

void IMUThread::run()
{
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

        usleep(imu->IMUGetPollInterval() * 1000);

        while (imu->IMURead()) {
            mutex.lock();
            RTIMU_DATA imuData = imu->getIMUData();
            now = RTMath::currentUSecsSinceEpoch();
            mutex.unlock();

            //  display 10 times per second

            if ((now - displayTimer) > 100000) {
                // for testing comment out unused lines and change \n for \r,
                printf("Observer Orientation Output. Roll: %.2f [deg] Pitch: %.2f [deg] Yaw: %.2f [deg]\n", (180/3.14)*imuData.fusionPose.x(),(180/3.14)*imuData.fusionPose.y(),(180/3.14)*imuData.fusionPose.z());
                printf("Gryo Output. Roll Rate: %.2f [deg/s] Pitch Rate: %.2f [deg/s] Yaw Rate: %.2f [deg/s]\n", (180/3.14)*imuData.gyro.x(),(180/3.14)*imuData.gyro.y(),(180/3.14)*imuData.gyro.z());
                printf("Accelerometer. X: %.2f [m/s^2] Y: %.2f [m/s^2] X: %.2f [m/s^2]\n", (9.81)*imuData.accel.x(),(9.81)*imuData.accel.y(),(9.81)*imuData.accel.z());
                printf("Compass. Xmag: %.2f [uT] Ymag: %.2f [uT] X: %.2f [uT]\n", imuData.compass.x(),imuData.compass.y(),imuData.compass.z());
                printf("Finished Printing\n");
                displayTimer = now;
                printf("set displayTime equal to now");


                mutex.lock();
                *pIn = imuData.fusionPose.z();
                if (pIn == (&samples[MAX_SAMPLES-1]))
                  pIn = samples;
                else
                  pIn++;
                mutex.unlock();

           }
        }
    }
}
