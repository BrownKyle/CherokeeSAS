#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <RTIMULib.h>
#include "myconstants.h"
#include "common.h"
//#include <QTime>
#include <QTimerEvent>

// BufferSize: maximum bytes that can be stored
SetBuffer buffer[BufferSize];
float key=0;
int j=0;
double PlotTime;
uint64_t StartTime = RTMath::currentUSecsSinceEpoch();
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
    ui->RudderCommandPlot->xAxis->setDateTimeFormat("mm:ss");
    //ui->RudderCommandPlot->xAxis->setAutoTickStep(false);
    //ui->RudderCommandPlot->xAxis->setTickStep(2);

    //ui->RudderCommandPlot->xAxis->setRange(-1, 1);
    ui->RudderCommandPlot->yAxis->setRange(-1, 1);

    connect(ui->RudderCommandPlot->xAxis, SIGNAL(rangeChanged(QCPRange)), ui->RudderCommandPlot->xAxis2, SLOT(setRange(QCPRange)));


    connect(ui->PitchCommand,SIGNAL(valueChanged(int)),ui->ElevatorOut,SLOT(setNum(int)));
    connect(ui->RollCommand,SIGNAL(valueChanged(int)),ui->AileronOut,SLOT(setNum(int)));
    connect(ui->YawRateCommand,SIGNAL(valueChanged(int)),ui->RudderOut,SLOT(setNum(int)));

    // make two threads
    mProducer = new Producer(this);
    //mConsumer = new Consumer(this);

    mProducer->start();
    //mConsumer->start();

    //QTimer *timer = new QTimer(this);
    //connect(timer,SIGNAL(timeout()),this,SLOT(PlotData()));
    //timer->start(500);


    //connect(mConsumer,SIGNAL(newvector(int)),this,SLOT(plotnewvector(int)));
}


MainWindow::~MainWindow()
{
    delete ui;
}


//void MainWindow::timerEvent( QTimerEvent * )
//{
    //MainWindow window;
    //IMUThread imuthread;
    //value = imuthread.getSample();
    //this->ui->lcdNumber->display(value);
    //printf("/n The value from the TestStruct: %d/n",TestStruct.number);
  //  window.show();
//}

void MainWindow::timerEvent( QTimerEvent * )
{
    //printf("Timer event occured");

    //int BufferReadCount = 0;
    /*
    for (int i = 0; i < DataSize; ++i) {
        usedBytes.acquire();
        //printf("%c", buffer[i % BufferSize]);
        freeBytes.release();
        emit bufferFillCountChanged(usedBytes.available());
        emit consumerCountChanged(i);
        printf("Info in the buffer: %d \n",buffer[i % BufferSize].Gyr.x);
    };
    //printf("\n");
    */


        //int valueGz[usedBytes.available()];

        if (usedBytes.available()>0) {
            for (int i=0; (i < usedBytes.available()); i++) {

                usedBytes.acquire();
                //valueGz[i]=buffer[i % BufferSize].Gyr.z;
                PlotTime = (buffer[i % BufferSize].time-StartTime)/1000000.00;
                ui->RudderCommandPlot->graph(0)->addData(PlotTime, buffer[i % BufferSize].Gyr.z);
                //printf("Gryro Z in consumer thread: %d3", valueGz[i]);
                //BufferReadCount++;
                freeBytes.release();
                //emit bufferFillCountChanged(usedBytes.available());
                //emit consumerCountChanged(i);
                //emit newvector(valueGz[i]);
            };
            printf("%f \n",PlotTime);
            ui->RudderCommandPlot->graph(0)->removeDataBefore(PlotTime-20);
            ui->RudderCommandPlot->graph(0)->rescaleValueAxis();
            ui->RudderCommandPlot->xAxis->setRange(PlotTime+0.25, PlotTime-20);
            ui->RudderCommandPlot->replot();
        }

    //int numberofdatapoints;
    //numberofdatapoints = (sizeof(newvector)/sizeof(newvector[1]))
    //key = key + 0.1;
    //ui->RudderCommandPlot->graph(0)->addData(key, newvector);
    //printf("\n Size of key : %f", key);
    //j++;

    //if (j>20){
        // remove data of lines that's outside visible range:
        //ui->RudderCommandPlot->graph(0)->removeDataBefore(key-8);
        // rescale value (vertical) axis to fit the current data:
        //ui->RudderCommandPlot->graph(0)->rescaleValueAxis();
        // make key axis range scroll with the data (at a constant range size of 8):
        //ui->RudderCommandPlot->xAxis->setRange(key+0.25, 10);
        //ui->RudderCommandPlot->replot();
        //printf("Plotting Data \n");
        //j = 0;
}
