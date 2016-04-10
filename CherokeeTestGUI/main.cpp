#include "mainwindow.h"
#include <QApplication>
#include <RTIMULib.h>
#include <QString>
//#include <imuthread.h>



int main(int argc, char *argv[])
{

    //IMUThread imuthread;
    //imuthread.start();
    QApplication a(argc, argv);

    //create the window
    MainWindow w;


    w.show();
    w.startTimer(100);

    return a.exec();

}
