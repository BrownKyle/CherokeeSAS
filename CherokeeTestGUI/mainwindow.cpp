#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <RTIMULib.h>
#include <imuthread.h>
#include "myconstants.h"

// BufferSize: maximum bytes that can be stored
int buffer[BufferSize];
int key=0;
int j=0;

QSemaphore freeBytes(BufferSize);
QSemaphore usedBytes;


MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{

    ui->setupUi(this);

    //QCustomPlot *RudderCommandPlot;

    ui->RudderCommandPlot->xAxis->setLabel("Time [s]");
    ui->RudderCommandPlot->yAxis->setLabel("Rudder Deflection [deg]");
    ui->RudderCommandPlot->addGraph();
    ui->RudderCommandPlot->graph(0)->setPen(QPen(Qt::red));

    ui->RudderCommandPlot->xAxis->setTickLabelType(QCPAxis::ltDateTime);
    ui->RudderCommandPlot->xAxis->setDateTimeFormat("hh:mm:ss");
    ui->RudderCommandPlot->xAxis->setAutoTickStep(false);
    ui->RudderCommandPlot->xAxis->setTickStep(2);

    //ui->RudderCommandPlot->xAxis->setRange(-1, 1);
    ui->RudderCommandPlot->yAxis->setRange(-20, 20);

    connect(ui->RudderCommandPlot->xAxis, SIGNAL(rangeChanged(QCPRange)), ui->RudderCommandPlot->xAxis2, SLOT(setRange(QCPRange)));


    connect(ui->PitchCommand,SIGNAL(valueChanged(int)),ui->ElevatorOut,SLOT(setNum(int)));
    connect(ui->RollCommand,SIGNAL(valueChanged(int)),ui->AileronOut,SLOT(setNum(int)));
    connect(ui->YawRateCommand,SIGNAL(valueChanged(int)),ui->RudderOut,SLOT(setNum(int)));

    // make two threads
    mProducer = new Producer(this);
    mConsumer = new Consumer(this);

    mProducer->start();
    mConsumer->start();


    connect(mConsumer,SIGNAL(newvector(int)),this,SLOT(plotnewvector(int)));
}


MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::timerEvent( QTimerEvent * )
{
    MainWindow window;
    //IMUThread imuthread;
    //value = imuthread.getSample();
    //this->ui->lcdNumber->display(value);
    //printf("/n The value from the TestStruct: %d/n",TestStruct.number);
    window.show();
}

void MainWindow::plotnewvector(int newvector)
{
    //int numberofdatapoints;
    //numberofdatapoints = (sizeof(newvector)/sizeof(newvector[1]))
    key = key + 0.01;
    ui->RudderCommandPlot->graph(0)->addData(key, newvector);
    j++;

    if (j>20){
        // remove data of lines that's outside visible range:
        ui->RudderCommandPlot->graph(0)->removeDataBefore(key*100-8);
        // rescale value (vertical) axis to fit the current data:
        ui->RudderCommandPlot->graph(0)->rescaleValueAxis();
        // make key axis range scroll with the data (at a constant range size of 8):
        ui->RudderCommandPlot->xAxis->setRange(key+0.25, 8, Qt::AlignRight);
        ui->RudderCommandPlot->replot();
        MainWindow w;
        w.show();
        printf("Plotting Data \n");
        j = 0;
    }
}
