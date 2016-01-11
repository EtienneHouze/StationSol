#ifndef SERIALPORTWINDOW_H
#define SERIALPORTWINDOW_H

#include <QtWidgets>
#include <QObject>
#include <QSerialPort>
#include <QSerialPortInfo>
#include <QList>
#include <qapplication.h>

class SerialManager;

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
    SerialManager *parent;


public:
    SerialPortWindow(SerialManager *manager);

public slots :

    void acceptSerialPort();


};

#endif // SERIALPORTWINDOW_H
