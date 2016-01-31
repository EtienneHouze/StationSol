#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QtWidgets>
#include <QObject>
#include <QSerialPort>
#include <QSerialPortInfo>
#include <QThread>
#include <QStack>
#include <QDir>

#include "qcustomplot.h"

class SerialManager;

class MainWindow : public QMainWindow
{

    Q_OBJECT

    friend class SerialManager;

    //Constructor=====================================================================================================
public:
    MainWindow();

    //--------------------------------------------------------------------------------------------------------------------


    //Setting up a work directory=====================================================================

public :

    QDir workspace;


    //--------------------------------------------------------------------------------------------------------------------


        //Central Window Settup==========================================================================================
private:

    QCustomPlot *plot;
    QWidget *centralWindow;
    QGridLayout *mainLayout;
    QTextEdit *affichageLog;
    QLineEdit *displayWriting;
        //--------------------------------------------------------------------------------------------------------------


        //Serial Port==================================================

private :
    SerialManager *manager;

        //--------------------------------------------------------------






    //Menu bar==========================================================


private :

        //File Menu
    QMenu *menuFile;
    QAction *actionClose;
        //Serial Port Menu : can open, read (write) serial ports to communicate with
    QMenu *menuSerialPort;
    QAction *actionOpenSerial;
    QAction *actionCloseSerial;

    //-----------------------------------------------------


    //Log==============================================================
public :
    void updateLog(QString content);


    //Closing the window and saving===============================
public slots:
    void closeWindow();

};

#endif // MAINWINDOW_H
