#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "consumer.h"
#include "producer.h"
#include <QSemaphore>



namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

    void setName(const QString &name);
    QString name() const;

    void timerEvent( QTimerEvent * );
    void onBufferValueChanged(int);
    void onProducerValueChanged(int);
    void onConsumerValueChanged(int);

private:
    Ui::MainWindow *ui;
    int value;

    Producer *mProducer;
    //Consumer *mConsumer;

public slots:
    //void plotnewvector(int newvector);

};

#endif // MAINWINDOW_H
