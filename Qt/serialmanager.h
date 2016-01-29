#ifndef SERIALMANAGER_H
#define SERIALMANAGER_H

#include <QObject>
#include <QSerialPort>
#include "qapplication.h"
#include <QThread>
#include <QTimer>


class MainWindow;

class SerialManager : public QObject
{

    friend class MainWindow;

    Q_OBJECT

public :
    QSerialPort *serial;
    MainWindow *parent;

public:
    SerialManager(MainWindow *mainWindow);
    void beginReading(int msec);

private :
    QTimer *readTimer;



signals:



public slots:

    void openSerialPort();
    void  readSerialPort();
    void writeSerialPort();
    void closeSerialPort();

private slots :

    void automaticReading();
};

#endif // SERIALMANAGER_H
