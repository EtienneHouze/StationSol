#ifndef DATA_H
#define DATA_H

#include <QObject>
#include <QLinkedList>
#include<QByteArray>



class Data : public QObject
{
  //  Q_OBJECT
public:

    Data();
    
private :
    int temp;
    QByteArray lastData;

    

//signals:

//public slots:
};

#endif // DATA_H
