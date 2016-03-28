#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <RTIMULib.h>
#include <imuthread.h>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{

    ui->setupUi(this);

    connect(ui->PitchCommand,SIGNAL(valueChanged(int)),ui->ElevatorOut,SLOT(setNum(int)));
    connect(ui->RollCommand,SIGNAL(valueChanged(int)),ui->AileronOut,SLOT(setNum(int)));
    connect(ui->YawRateCommand,SIGNAL(valueChanged(int)),ui->RudderOut,SLOT(setNum(int)));
}


MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::timerEvent( QTimerEvent * )
{
    MainWindow window;
    IMUThread imuthread;
    value = imuthread.getSample();
    this->ui->lcdNumber->display(value);
    printf("/n The value from the ring buffer: %d/n",value);
    window.show();
}
