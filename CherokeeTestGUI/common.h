#ifndef COMMON_H
#define COMMON_H

#include <QSemaphore>
#include "myconstants.h"
#include <QtCore>


struct XYZ
{
    int x;
    int y;
    int z;
};

struct SetBuffer
{
    struct XYZ Ang;    //Angle [rad]
    struct XYZ Gyr;    //Gyro Angle Rate [rad]
    struct XYZ Acc;    //Acceleation [m/s/s]
    struct XYZ Mag;    //Magnetometer reading [uT]
    u_int64_t time;
};

extern SetBuffer buffer[BufferSize];

extern QSemaphore freeBytes;
extern QSemaphore usedBytes;

#endif // COMMON_H
