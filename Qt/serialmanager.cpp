#include "serialmanager.h"
#include "mainwindow.h"
#include "writeserial.h"
#include "serialportwindow.h"

SerialManager::SerialManager(MainWindow *mainWindow) : QObject(mainWindow)
{
    parent = mainWindow;
    serial = new QSerialPort();
    stillReading = false;
    readTimer = new QTimer(this);
    QObject::connect(readTimer,SIGNAL(timeout()),this,SLOT(automaticReading()));
}

void  SerialManager::readSerialPort(){
    QByteArray data = serial->readAll();
    parent->updateLog(QString(data));
}

void SerialManager::writeSerialPort(){
    QString buff = parent->displayWriting->text()+"\r";
    parent->displayWriting->setText("");
    parent->updateLog(buff);
    serial->write(buff.toLatin1());
}

void SerialManager::openSerialPort(){
    SerialPortWindow *serialDialogue = new SerialPortWindow(this);
    serialDialogue->show();
}

void SerialManager::beginReading(int msec){
    readTimer->start(msec);
}

void SerialManager::automaticReading(){
    if(stillReading)
        buffer.append(serial->readLine(2048));
    else
        buffer = serial->readLine(2048);
    if(buffer.size() != 0){
        if(buffer.contains('\r')){
            parent->updateLog(QString(buffer));
            stillReading = false;
        }
        else
            stillReading = true;

    }
}

void SerialManager::closeSerialPort(){
    if(serial->isOpen()){
       serial->close();
       parent->updateLog("Serial has been closed");
    }
    else
        parent->updateLog("Serial was not open");
}
