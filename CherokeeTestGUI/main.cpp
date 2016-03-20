#include "mainwindow.h"
#include <QApplication>
#include <RTIMULib.h>
#include <QString>


int main(int argc, char *argv[])
{
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

    MainWindow window;


    //  poll at the rate recommended by the IMU

    //usleep(imu->IMUGetPollInterval() * 1000);
    RTIMU_DATA imuData = imu->getIMUData();
    float GyroOut = imuData.gyro.x();
    QString Gyro= QString::number(GyroOut);

    QApplication a(argc, argv);

    //create the window
    MainWindow w;
    w.setName(Gyro);
    w.show();

    //execture the application
    window.startTimer(200);
    return a.exec();

}
