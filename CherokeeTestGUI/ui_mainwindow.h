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
#include <QtGui/QLCDNumber>
#include <QtGui/QLabel>
#include <QtGui/QMainWindow>
#include <QtGui/QSlider>
#include <QtGui/QVBoxLayout>
#include <QtGui/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralWidget;
    QWidget *widget;
    QVBoxLayout *verticalLayout_4;
    QHBoxLayout *horizontalLayout;
    QLabel *label;
    QLCDNumber *lcdNumber;
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
    QLabel *label_5;
    QLabel *label_2;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        MainWindow->resize(693, 206);
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName(QString::fromUtf8("centralWidget"));
        widget = new QWidget(centralWidget);
        widget->setObjectName(QString::fromUtf8("widget"));
        widget->setGeometry(QRect(12, 22, 681, 171));
        verticalLayout_4 = new QVBoxLayout(widget);
        verticalLayout_4->setSpacing(6);
        verticalLayout_4->setContentsMargins(11, 11, 11, 11);
        verticalLayout_4->setObjectName(QString::fromUtf8("verticalLayout_4"));
        verticalLayout_4->setContentsMargins(0, 0, 0, 0);
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setSpacing(6);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        label = new QLabel(widget);
        label->setObjectName(QString::fromUtf8("label"));

        horizontalLayout->addWidget(label);

        lcdNumber = new QLCDNumber(widget);
        lcdNumber->setObjectName(QString::fromUtf8("lcdNumber"));

        horizontalLayout->addWidget(lcdNumber);


        verticalLayout_4->addLayout(horizontalLayout);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setSpacing(6);
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        verticalLayout_3 = new QVBoxLayout();
        verticalLayout_3->setSpacing(6);
        verticalLayout_3->setObjectName(QString::fromUtf8("verticalLayout_3"));
        PitchCommand = new QSlider(widget);
        PitchCommand->setObjectName(QString::fromUtf8("PitchCommand"));
        PitchCommand->setMinimumSize(QSize(400, 0));
        PitchCommand->setMaximumSize(QSize(400, 16777215));
        PitchCommand->setMinimum(-20);
        PitchCommand->setMaximum(20);
        PitchCommand->setOrientation(Qt::Horizontal);

        verticalLayout_3->addWidget(PitchCommand);

        RollCommand = new QSlider(widget);
        RollCommand->setObjectName(QString::fromUtf8("RollCommand"));
        RollCommand->setMinimumSize(QSize(400, 0));
        RollCommand->setMaximumSize(QSize(400, 16777215));
        RollCommand->setMinimum(-20);
        RollCommand->setMaximum(20);
        RollCommand->setOrientation(Qt::Horizontal);

        verticalLayout_3->addWidget(RollCommand);

        YawRateCommand = new QSlider(widget);
        YawRateCommand->setObjectName(QString::fromUtf8("YawRateCommand"));
        YawRateCommand->setMinimumSize(QSize(400, 0));
        YawRateCommand->setMaximumSize(QSize(400, 16777215));
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

        verticalLayout_2->addWidget(label_6);

        label_3 = new QLabel(widget);
        label_3->setObjectName(QString::fromUtf8("label_3"));

        verticalLayout_2->addWidget(label_3);

        label_4 = new QLabel(widget);
        label_4->setObjectName(QString::fromUtf8("label_4"));

        verticalLayout_2->addWidget(label_4);


        horizontalLayout_2->addLayout(verticalLayout_2);

        verticalLayout = new QVBoxLayout();
        verticalLayout->setSpacing(6);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        ElevatorOut = new QLabel(widget);
        ElevatorOut->setObjectName(QString::fromUtf8("ElevatorOut"));
        ElevatorOut->setEnabled(true);
        ElevatorOut->setMinimumSize(QSize(30, 0));
        //ElevatorOut->setToolTipDuration(0);

        verticalLayout->addWidget(ElevatorOut);

        AileronOut = new QLabel(widget);
        AileronOut->setObjectName(QString::fromUtf8("AileronOut"));
        AileronOut->setMinimumSize(QSize(30, 0));

        verticalLayout->addWidget(AileronOut);

        RudderOut = new QLabel(widget);
        RudderOut->setObjectName(QString::fromUtf8("RudderOut"));
        RudderOut->setMinimumSize(QSize(30, 0));

        verticalLayout->addWidget(RudderOut);


        horizontalLayout_2->addLayout(verticalLayout);

        label_5 = new QLabel(widget);
        label_5->setObjectName(QString::fromUtf8("label_5"));

        horizontalLayout_2->addWidget(label_5);

        label_2 = new QLabel(widget);
        label_2->setObjectName(QString::fromUtf8("label_2"));

        horizontalLayout_2->addWidget(label_2);


        verticalLayout_4->addLayout(horizontalLayout_2);

        MainWindow->setCentralWidget(centralWidget);
        QWidget::setTabOrder(PitchCommand, RollCommand);
        QWidget::setTabOrder(RollCommand, YawRateCommand);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "MainWindow", 0, QApplication::UnicodeUTF8));
        label->setText(QApplication::translate("MainWindow", "Gyro Rate Z", 0, QApplication::UnicodeUTF8));
        label_6->setText(QApplication::translate("MainWindow", "Elevator Deflection:", 0, QApplication::UnicodeUTF8));
        label_3->setText(QApplication::translate("MainWindow", "Aileron Deflection:", 0, QApplication::UnicodeUTF8));
        label_4->setText(QApplication::translate("MainWindow", "Rudder Defecection:", 0, QApplication::UnicodeUTF8));
        ElevatorOut->setText(QApplication::translate("MainWindow", "0", 0, QApplication::UnicodeUTF8));
        AileronOut->setText(QApplication::translate("MainWindow", "0", 0, QApplication::UnicodeUTF8));
        RudderOut->setText(QApplication::translate("MainWindow", "0", 0, QApplication::UnicodeUTF8));
        label_5->setText(QString());
        label_2->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
