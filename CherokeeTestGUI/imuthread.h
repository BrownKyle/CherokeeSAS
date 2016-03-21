#ifndef IMUTHREAD_H
#define IMUTHREAD_H
#include <QtCore>

class IMUThread : public QThread
{
public:
    IMUThread();
    void run();

    // ring buffer functions
    int hasSample();
    int getSample();

private:

    float now;
    float displayTimer;

    // data collected
    int *samples;

    // pointer to ringbuffer
    int *pIn;
    int *pOut;
};

#endif // IMUTHREAD_H
