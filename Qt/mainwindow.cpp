#include "mainwindow.h"
#include "qcustomplot.h"
#include "serialportwindow.h"
#include "writeserial.h"
#include "serialmanager.h"

#include <QDirIterator>
#include <QDate>

MainWindow::MainWindow()
{
    //Preparing the serial port=================================================
    manager = new SerialManager(this);



    //Setting up the menu bar=====================================================
        //File Menu
    menuFile = menuBar()->addMenu("&File");
    actionClose = new QAction("&Save and Quit", this);
    menuFile->addAction(actionClose);
        //Serial Port Menu
    menuSerialPort = menuBar()->addMenu("&SerialPort");
    actionOpenSerial = new QAction("&Open",this);
    actionCloseSerial = new QAction("&close",this);
    menuSerialPort -> addAction(actionOpenSerial);
    menuSerialPort->addAction(actionCloseSerial);




    //Setting up the central window================================================
    centralWindow = new QWidget();
    mainLayout = new QGridLayout();
    affichageLog = new QTextEdit(this);
    displayWriting = new QLineEdit(this);
    plot = new QCustomPlot();
    mainLayout ->addWidget(affichageLog,0,0);
    mainLayout ->addWidget(plot,0,1,1,2);
    mainLayout->addWidget(displayWriting,1,0);
    centralWindow->setLayout(mainLayout);
    setCentralWidget(centralWindow);

    //Setting up the log historic==============================================
    affichageLog->setReadOnly(true);


    //Setting up the workspace directory, where data will be stored============
    workspace = QDir::current();
    if(!workspace.cd("data")){
            workspace.mkdir("data");
            workspace.cd("data");
    }
    QDir::setCurrent(workspace.path());


    //Connectiong signals and slots ==========================================


    QObject::connect(displayWriting,SIGNAL(returnPressed()),manager,SLOT(writeSerialPort()));
    QObject::connect(actionOpenSerial,SIGNAL(triggered()),manager,SLOT(openSerialPort()));
    QObject::connect(actionCloseSerial,SIGNAL(triggered()),manager,SLOT(closeSerialPort()));
    QObject::connect(actionClose,SIGNAL(triggered()),this,SLOT(closeWindow()));



}



//This method (slot) can be used when any action is performed in order to update the log.
void MainWindow::updateLog(QString content){
    affichageLog->append(content);
}

//closes the window and save the log in a history file in the working directory
void MainWindow::closeWindow(){
    QFile file(QDate::currentDate().toString("yyyy.MM.dd")+".txt");
    file.open(QIODevice::WriteOnly | QIODevice::Text);
    QTextStream stream(&file);
    stream << affichageLog->toPlainText();
    file.close();
    this->close();
}

