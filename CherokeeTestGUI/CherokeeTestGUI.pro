#-------------------------------------------------
#
# Project created by QtCreator 2016-03-14T09:05:22
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets printsupport

TARGET = CherokeeTestGUI
TEMPLATE = app
CONFIG  += qxt
QXT     += core gui
INCLUDEPATH += /usr/include/qwt-qt4
LIBS += -lqwt -lm



SOURCES += main.cpp\
        mainwindow.cpp \
    IMUDrivers/RTHumidity.cpp \
    IMUDrivers/RTHumidityHTS221.cpp \
    IMUDrivers/RTHumidityHTU21D.cpp \
    IMUDrivers/RTIMU.cpp \
    IMUDrivers/RTIMUBMX055.cpp \
    IMUDrivers/RTIMUBNO055.cpp \
    IMUDrivers/RTIMUGD20HM303D.cpp \
    IMUDrivers/RTIMUGD20HM303DLHC.cpp \
    IMUDrivers/RTIMUGD20M303DLHC.cpp \
    IMUDrivers/RTIMULSM9DS0.cpp \
    IMUDrivers/RTIMULSM9DS1.cpp \
    IMUDrivers/RTIMUMPU9150.cpp \
    IMUDrivers/RTIMUMPU9250.cpp \
    IMUDrivers/RTIMUNull.cpp \
    IMUDrivers/RTPressure.cpp \
    IMUDrivers/RTPressureBMP180.cpp \
    IMUDrivers/RTPressureLPS25H.cpp \
    IMUDrivers/RTPressureMS5611.cpp \
    IMUDrivers/RTPressureMS5637.cpp \
    RTFusion.cpp \
    RTFusionKalman4.cpp \
    RTFusionRTQF.cpp \
    RTIMUAccelCal.cpp \
    RTIMUHal.cpp \
    RTIMUMagCal.cpp \
    RTIMUSettings.cpp \
    RTMath.cpp \
    imuthread.cpp \
    producer.cpp \
    consumer.cpp \
    qcustomplot.cpp \
    rpiPWM1.cpp \
    rpiServo.cpp

HEADERS  += mainwindow.h \
    RTMath.h \
    IMUDrivers/RTHumidity.h \
    IMUDrivers/RTHumidityDefs.h \
    IMUDrivers/RTHumidityHTS221.h \
    IMUDrivers/RTHumidityHTU21D.h \
    IMUDrivers/RTIMU.h \
    IMUDrivers/RTIMUBMX055.h \
    IMUDrivers/RTIMUBNO055.h \
    IMUDrivers/RTIMUDefs.h \
    IMUDrivers/RTIMUGD20HM303D.h \
    IMUDrivers/RTIMUGD20HM303DLHC.h \
    IMUDrivers/RTIMUGD20M303DLHC.h \
    IMUDrivers/RTIMULSM9DS0.h \
    IMUDrivers/RTIMULSM9DS1.h \
    IMUDrivers/RTIMUMPU9150.h \
    IMUDrivers/RTIMUMPU9250.h \
    IMUDrivers/RTIMUNull.h \
    IMUDrivers/RTPressure.h \
    IMUDrivers/RTPressureBMP180.h \
    IMUDrivers/RTPressureDefs.h \
    IMUDrivers/RTPressureLPS25H.h \
    IMUDrivers/RTPressureMS5611.h \
    IMUDrivers/RTPressureMS5637.h \
    RTFusion.h \
    RTFusionKalman4.h \
    RTFusionRTQF.h \
    RTIMUAccelCal.h \
    RTIMUCalDefs.h \
    RTIMUHal.h \
    RTIMULib.h \
    RTIMULibDefs.h \
    RTIMUMagCal.h \
    RTIMUSettings.h \
    imuthread.h \
    producer.h \
    consumer.h \
    common.h \
    myconstants.h \
    qcustomplot.h \
    rpiPWM1.h \
    rpiServo.h \
    ui_mainwindow.h

FORMS    += mainwindow.ui
