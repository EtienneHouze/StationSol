#ifndef WRITESERIAL_H
#define WRITESERIAL_H


#include <QtWidgets>
#include <QObject>
#include <QSerialPort>
#include <QSerialPortInfo>
#include <QList>
#include <qapplication.h>

class SerialManager;

class WriteSerial : public QWidget
{
    Q_OBJECT

public:
    WriteSerial(SerialManager *manager);
private :
    SerialManager *parent;
    QGridLayout *layout;
    QLineEdit *textEntry;
    QPushButton *acceptButton;
    QPushButton *discardButton;


signals:

public slots:
    void writePort();
};

#endif // WRITESERIAL_H
