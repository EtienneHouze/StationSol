#ifndef SERIALPORTWINDOW_H
#define SERIALPORTWINDOW_H

#include <QtWidgets>
#include <QObject>
#include "mainwindow.h"
#include <QSerialPort>
#include <QSerialPortInfo>
#include <QList>
#include <qapplication.h>

class SerialPortWindow:public QWidget
{

Q_OBJECT

private :
    QComboBox *availablePortsDisplay;
    QGroupBox *speedRate;
    QString portName;
    QLabel *displayTest;
    QPushButton *acceptButton;
    QPushButton *discardButton;
    MainWindow *parent;


public:
    SerialPortWindow(MainWindow *mainWindow);

public slots :

    void acceptSerialPort();


};

#endif // SERIALPORTWINDOW_H
