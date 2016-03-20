#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <RTIMULib.h>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{

    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::setName(const QString &name)
{
    ui->lineEdit->setText(name);
}

QString MainWindow::name() const
{
    return ui->lineEdit->text();
}

void MainWindow::timerEvent( QTimerEvent * )
{
    RTIMUSettings *settings = new RTIMUSettings("RTIMULib");
    RTIMU *imu = RTIMU::createIMU(settings);

    RTIMU_DATA imuData = imu->getIMUData();
    float GyroOut = imuData.gyro.x();
    QString Gyro= QString::number(GyroOut);

    MainWindow window;

    window.setName(Gyro);
    window.show();
}
