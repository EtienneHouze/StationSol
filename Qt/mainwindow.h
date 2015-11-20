#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QtWidgets>
#include <QObject>
#include <QSerialPort>
#include <QSerialPortInfo>

#include "qcustomplot.h"

class MainWindow : public QMainWindow
{

    Q_OBJECT


    //General settings=====================================================================================================
public:
    MainWindow();

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
    QHBoxLayout *mainLayout;
    QTextEdit *affichageLog;
        //--------------------------------------------------------------------------------------------------------------


        //Serial Port==================================================

public :
    QSerialPort *serial;

public slots:

    void openSerialPort();

        //--------------------------------------------------------------






    //Menu bar==========================================================


private :

        //File Menu
    QMenu *menuFile;
    QAction *actionOpenFile;
        //Serial Port Menu : can open, read (write) serial ports to communicate with
    QMenu *menuSerialPort;
    QAction *actionOpenSerial;
    QAction *actionReadSerial;

    //-----------------------------------------------------


//Log==============================================================
public :
    void updateLog(QString content);

};

#endif // MAINWINDOW_H
