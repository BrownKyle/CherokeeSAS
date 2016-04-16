/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 4.8.6
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QHBoxLayout>
#include <QtGui/QHeaderView>
#include <QtGui/QLabel>
#include <QtGui/QMainWindow>
#include <QtGui/QSlider>
#include <QtGui/QVBoxLayout>
#include <QtGui/QWidget>
#include "qcustomplot.h"

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralWidget;
    QWidget *widget;
    QVBoxLayout *verticalLayout_5;
    QVBoxLayout *verticalLayout_4;
    QHBoxLayout *horizontalLayout_2;
    QVBoxLayout *verticalLayout_3;
    QSlider *PitchCommand;
    QSlider *RollCommand;
    QSlider *YawRateCommand;
    QVBoxLayout *verticalLayout_2;
    QLabel *label_6;
    QLabel *label_3;
    QLabel *label_4;
    QVBoxLayout *verticalLayout;
    QLabel *ElevatorOut;
    QLabel *AileronOut;
    QLabel *RudderOut;
    QCustomPlot *RudderCommandPlot;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        MainWindow->resize(1280, 1024);
        MainWindow->setMinimumSize(QSize(1280, 800));
        MainWindow->setMaximumSize(QSize(1280, 1024));
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName(QString::fromUtf8("centralWidget"));
        centralWidget->setMinimumSize(QSize(1280, 1024));
        centralWidget->setMaximumSize(QSize(16777215, 1024));
        widget = new QWidget(centralWidget);
        widget->setObjectName(QString::fromUtf8("widget"));
        widget->setGeometry(QRect(10, 22, 1282, 1000));
        widget->setMinimumSize(QSize(0, 1000));
        widget->setMaximumSize(QSize(16777215, 1000));
        verticalLayout_5 = new QVBoxLayout(widget);
        verticalLayout_5->setSpacing(6);
        verticalLayout_5->setContentsMargins(11, 11, 11, 11);
        verticalLayout_5->setObjectName(QString::fromUtf8("verticalLayout_5"));
        verticalLayout_4 = new QVBoxLayout();
        verticalLayout_4->setSpacing(6);
        verticalLayout_4->setObjectName(QString::fromUtf8("verticalLayout_4"));
        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setSpacing(6);
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        verticalLayout_3 = new QVBoxLayout();
        verticalLayout_3->setSpacing(6);
        verticalLayout_3->setObjectName(QString::fromUtf8("verticalLayout_3"));
        PitchCommand = new QSlider(widget);
        PitchCommand->setObjectName(QString::fromUtf8("PitchCommand"));
        PitchCommand->setMinimumSize(QSize(500, 0));
        PitchCommand->setMaximumSize(QSize(800, 16777215));
        PitchCommand->setMinimum(-20);
        PitchCommand->setMaximum(20);
        PitchCommand->setOrientation(Qt::Horizontal);

        verticalLayout_3->addWidget(PitchCommand);

        RollCommand = new QSlider(widget);
        RollCommand->setObjectName(QString::fromUtf8("RollCommand"));
        RollCommand->setMinimumSize(QSize(500, 0));
        RollCommand->setMaximumSize(QSize(800, 16777215));
        RollCommand->setMinimum(-20);
        RollCommand->setMaximum(20);
        RollCommand->setOrientation(Qt::Horizontal);

        verticalLayout_3->addWidget(RollCommand);

        YawRateCommand = new QSlider(widget);
        YawRateCommand->setObjectName(QString::fromUtf8("YawRateCommand"));
        YawRateCommand->setMinimumSize(QSize(500, 0));
        YawRateCommand->setMaximumSize(QSize(800, 16777215));
        YawRateCommand->setMinimum(-20);
        YawRateCommand->setMaximum(20);
        YawRateCommand->setOrientation(Qt::Horizontal);

        verticalLayout_3->addWidget(YawRateCommand);


        horizontalLayout_2->addLayout(verticalLayout_3);

        verticalLayout_2 = new QVBoxLayout();
        verticalLayout_2->setSpacing(6);
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
        label_6 = new QLabel(widget);
        label_6->setObjectName(QString::fromUtf8("label_6"));
        label_6->setMaximumSize(QSize(16777215, 30));

        verticalLayout_2->addWidget(label_6);

        label_3 = new QLabel(widget);
        label_3->setObjectName(QString::fromUtf8("label_3"));
        label_3->setMaximumSize(QSize(16777215, 30));

        verticalLayout_2->addWidget(label_3);

        label_4 = new QLabel(widget);
        label_4->setObjectName(QString::fromUtf8("label_4"));
        label_4->setMaximumSize(QSize(16777215, 30));

        verticalLayout_2->addWidget(label_4);


        horizontalLayout_2->addLayout(verticalLayout_2);

        verticalLayout = new QVBoxLayout();
        verticalLayout->setSpacing(6);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        ElevatorOut = new QLabel(widget);
        ElevatorOut->setObjectName(QString::fromUtf8("ElevatorOut"));
        ElevatorOut->setMaximumSize(QSize(16777215, 30));

        verticalLayout->addWidget(ElevatorOut);

        AileronOut = new QLabel(widget);
        AileronOut->setObjectName(QString::fromUtf8("AileronOut"));
        AileronOut->setMinimumSize(QSize(30, 0));
        AileronOut->setMaximumSize(QSize(16777215, 30));

        verticalLayout->addWidget(AileronOut);

        RudderOut = new QLabel(widget);
        RudderOut->setObjectName(QString::fromUtf8("RudderOut"));
        RudderOut->setMinimumSize(QSize(30, 0));
        RudderOut->setMaximumSize(QSize(16777215, 30));

        verticalLayout->addWidget(RudderOut);


        horizontalLayout_2->addLayout(verticalLayout);


        verticalLayout_4->addLayout(horizontalLayout_2);


        verticalLayout_5->addLayout(verticalLayout_4);

        RudderCommandPlot = new QCustomPlot(widget);
        RudderCommandPlot->setObjectName(QString::fromUtf8("RudderCommandPlot"));
        RudderCommandPlot->setMinimumSize(QSize(1100, 784));
        RudderCommandPlot->setMaximumSize(QSize(1240, 1024));
        RudderCommandPlot->setLayoutDirection(Qt::LeftToRight);

        verticalLayout_5->addWidget(RudderCommandPlot);

        MainWindow->setCentralWidget(centralWidget);
        QWidget::setTabOrder(PitchCommand, RollCommand);
        QWidget::setTabOrder(RollCommand, YawRateCommand);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "MainWindow", 0, QApplication::UnicodeUTF8));
        label_6->setText(QApplication::translate("MainWindow", "Elevator Deflection:", 0, QApplication::UnicodeUTF8));
        label_3->setText(QApplication::translate("MainWindow", "Aileron Deflection:", 0, QApplication::UnicodeUTF8));
        label_4->setText(QApplication::translate("MainWindow", "Rudder Defecection:", 0, QApplication::UnicodeUTF8));
        ElevatorOut->setText(QApplication::translate("MainWindow", "0", 0, QApplication::UnicodeUTF8));
        AileronOut->setText(QApplication::translate("MainWindow", "0", 0, QApplication::UnicodeUTF8));
        RudderOut->setText(QApplication::translate("MainWindow", "0", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
