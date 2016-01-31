#ifndef DATA_H
#define DATA_H

#include <QObject>
#include <QLinkedList>
#include <QByteArray>
#include <QTimer>

class MainWindow;

class Data : public QObject
{
  //  Q_OBJECT
public:

    Data(MainWindow *mainWindow);
    void save();
    
private :
    MainWindow *parent;
    int temp;
    QByteArray lastData;
    QTimer refreshTimer;

    

//signals:

//public slots:
};

#endif // DATA_H
