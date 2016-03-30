#include "producer.h"
#include "common.h"

Producer::Producer(QObject *parent) :
    QThread(parent)
{
}

void Producer::run()
{
    qsrand(QTime(0,0,0).secsTo(QTime::currentTime()));
    for (int i = 0; i < DataSize; ++i) {
        freeBytes.acquire();
        //buffer->Gyr->x[i % BufferSize] = i;
        buffer[i % BufferSize].Gyr.x = i;
        usedBytes.release();
        if(i % 20 == 0)
        emit bufferFillCountChanged(usedBytes.available());
        emit producerCountChanged(i);
    }
}

