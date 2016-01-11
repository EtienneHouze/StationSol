#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QtWidgets>
#include <QObject>
#include <QSerialPort>
#include <QSerialPortInfo>
#include <QThread>

#include "qcustomplot.h"

class SerialManager;

class MainWindow : public QMainWindow
{

    Q_OBJECT

    friend class SerialManager;

    //General settings=====================================================================================================
public:
    MainWindow();

private :

    QThread serialThread;

    //--------------------------------------------------------------------------------------------------------------------


    //Opening a text file=================================================================================================
    QString *openFileName;
    QString *fileContent;


public slots:

    void openTxtFile();


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

public slots:

        //--------------------------------------------------------------






    //Menu bar==========================================================


private :

        //File Menu
    QMenu *menuFile;
    QAction *actionOpenFile;
        //Serial Port Menu : can open, read (write) serial ports to communicate with
    QMenu *menuSerialPort;
    QAction *actionOpenSerial;

    //-----------------------------------------------------


//Log==============================================================
public :
    void updateLog(QString content);

};

#endif // MAINWINDOW_H
