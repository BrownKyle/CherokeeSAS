#include "mainwindow.h"
#include <QApplication>
#include <RTIMULib.h>
#include <QString>
#include <imuthread.h>


int main(int argc, char *argv[])
{

    IMUThread imuthread;
    imuthread.start();

    QApplication a(argc, argv);

    //create the window
    MainWindow w;


    w.show();

    //sleep(20);

    // Need to test getSample by uncommmenting this timer.


    //while(1)
    //{
     //  imuthread.getSample();
     //  QThread::msleep(20);
    //}

    return a.exec();
    sleep(2);
    w.startTimer(200);

}
