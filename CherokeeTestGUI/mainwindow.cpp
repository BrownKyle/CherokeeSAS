#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <RTIMULib.h>
#include <imuthread.h>

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


void MainWindow::timerEvent( QTimerEvent * )
{
    MainWindow window;
    window.show();
}
