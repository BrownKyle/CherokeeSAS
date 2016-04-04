#include "consumer.h"
#include "common.h"
#include <QtCore>

Consumer::Consumer(QObject *parent) :
    QThread(parent)
{
}

void Consumer::run()
{
    int BufferReadCount = 0;
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
    while(1){

        int valueGz[usedBytes.available()];

        if (usedBytes.available()>0) {
            for (int i=0; (i < usedBytes.available()); i++) {

                usedBytes.acquire();
                valueGz[i]=buffer[i % BufferSize].Gyr.z;
                printf("Gryro Z in consumer thread: %d", valueGz[i]);
                BufferReadCount++;
                freeBytes.release();
                emit bufferFillCountChanged(usedBytes.available());
                emit consumerCountChanged(i);
            };
            emit newvector(*valueGz);
        }
    }
}

