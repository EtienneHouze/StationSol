/*This Class describes a pop-up window that will open when "actionOpenSerial" is triggered
 * It will allow the user to change the settings of the serial port throught a user-friendly interface */

#include "serialportwindow.h"

#include <QObject>

SerialPortWindow::SerialPortWindow(MainWindow *mainWindow)
{
    parent = mainWindow;
    setWindowTitle("Select a port");
    QGridLayout *mainLayout = new QGridLayout();
    availablePortsDisplay = new QComboBox(this);
    if (QSerialPortInfo::availablePorts().isEmpty()){
    }
    else{
        Q_FOREACH(QSerialPortInfo port, QSerialPortInfo::availablePorts()){
        availablePortsDisplay->addItem(port.portName());
        }
    }
    acceptButton = new QPushButton("Accept");
    discardButton = new QPushButton("Discard");
    mainLayout->addWidget(availablePortsDisplay,0,0,1,2);
    mainLayout->addWidget(acceptButton,1,0,1,1);
    mainLayout->addWidget(discardButton,1,1,1,1);
    this->setLayout(mainLayout);

    QObject::connect(discardButton, SIGNAL(clicked()), this, SLOT(close()));
    QObject::connect(acceptButton, SIGNAL(clicked()),this, SLOT(acceptSerialPort()));







}

void SerialPortWindow::acceptSerialPort(){
    parent->serial = new QSerialPort(availablePortsDisplay->currentText());
    bool result = parent->serial->open(QIODevice::ReadWrite);
    if (result)
            parent->updateLog("Serial port " + availablePortsDisplay->currentText() + " is open.");
        else
            parent->updateLog("Serial port " + availablePortsDisplay->currentText() + " could not be opened");

    this->close();
}


