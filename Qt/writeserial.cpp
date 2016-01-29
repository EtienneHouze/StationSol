#include "writeserial.h"
#include "mainwindow.h"
#include "serialmanager.h"
#include<QObject>
WriteSerial::WriteSerial(SerialManager *manager)
{
    parent = manager;
    textEntry = new QLineEdit();
    acceptButton = new QPushButton("Write");
    discardButton = new QPushButton("Discard");
    layout = new QGridLayout();
    layout->addWidget(textEntry,0,0,1,2);
    layout->addWidget(acceptButton,1,0);
    layout->addWidget(discardButton,1,1);
    this->setLayout(layout);

    QObject::connect(acceptButton,SIGNAL(clicked()),this,SLOT(writePort()));
    QObject::connect(discardButton,SIGNAL(clicked()),this,SLOT(close()));

}

void WriteSerial::writePort(){
    int test = parent->serial->write(textEntry->text().toLatin1());
    if (test==-1){
        parent->parent->updateLog("Error, data could not be written");
    }
    else{
        parent->parent->updateLog(textEntry->text() + "has been written");
    }
    close();
}
