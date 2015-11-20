#include "mainwindow.h"
#include "qcustomplot.h"
#include "serialportwindow.h"


MainWindow::MainWindow()
{
    //Preparing the serial port=================================================
    serial = new QSerialPort();


    //Setting up the menu bar=====================================================
        //File Menu
    menuFile = menuBar()->addMenu("&File");
    actionOpenFile = new QAction("&Open",this);
    menuFile->addAction(actionOpenFile);
        //Serial Port Menu
    menuSerialPort = menuBar()->addMenu("&SerialPort");
    actionOpenSerial = new QAction("&Open",this);
    actionReadSerial = new QAction("&Read",this);
    menuSerialPort -> addAction(actionOpenSerial);
    menuSerialPort->addAction(actionReadSerial);

    QObject::connect(actionOpenFile,SIGNAL(triggered()),this, SLOT(openTxtFile()));
    QObject::connect(actionOpenSerial,SIGNAL(triggered()),this,SLOT(openSerialPort()));


    //Setting up the central window================================================
    centralWindow = new QWidget();
    mainLayout = new QHBoxLayout();
    affichageLog = new QTextEdit();
    plot = new QCustomPlot();
    mainLayout ->addWidget(affichageLog);
    mainLayout ->addWidget(plot);
    centralWindow->setLayout(mainLayout);
    setCentralWidget(centralWindow);


    //Setting up the log historic==============================================
    affichageLog->setReadOnly(true);
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

//This method opens a window from the SerialPortWindodow Class, in order to select which port to open.
void MainWindow::openSerialPort(){
    SerialPortWindow *serialDialogue = new SerialPortWindow(this);
    serialDialogue->show();
}

//This method (slot) can be used when any action is performed in order to update the log.
void MainWindow::updateLog(QString content){
    affichageLog->append(QTime::currentTime().toString("h:m:s") + " - " + content);
}

