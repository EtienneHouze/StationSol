#include "mainwindow.h"
#include "qcustomplot.h"
#include "serialportwindow.h"
#include "writeserial.h"
#include "serialmanager.h"


MainWindow::MainWindow()
{
    //Preparing the serial port=================================================
    manager = new SerialManager(this);



    //Setting up the menu bar=====================================================
        //File Menu
    menuFile = menuBar()->addMenu("&File");
    actionOpenFile = new QAction("&Open",this);
    menuFile->addAction(actionOpenFile);
        //Serial Port Menu
    menuSerialPort = menuBar()->addMenu("&SerialPort");
    actionOpenSerial = new QAction("&Open",this);
    menuSerialPort -> addAction(actionOpenSerial);




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


    //Connectiong signals and slots ==========================================


    QObject::connect(displayWriting,SIGNAL(returnPressed()),manager,SLOT(writeSerialPort()));  QObject::connect(actionOpenFile,SIGNAL(triggered()),this, SLOT(openTxtFile()));
    QObject::connect(actionOpenSerial,SIGNAL(triggered()),manager,SLOT(openSerialPort()));



}

void MainWindow::openTxtFile(){
    QString fileName = QFileDialog::getOpenFileName(this,tr("Open File"),"/home",tr("Bin file(*.bin)"));
    QFile file(fileName);
    if(!file.open(QIODevice::ReadOnly)) {
        QMessageBox::information(0, "error", file.errorString());
    }
    QTextStream in(&file);
    *fileContent = in.readAll();
    affichageLog->setText(*fileContent);

}

//This method (slot) can be used when any action is performed in order to update the log.
void MainWindow::updateLog(QString content){
    affichageLog->append(QTime::currentTime().toString("h:m:s") + " - " + content);
}


