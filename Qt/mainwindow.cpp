#include "mainwindow.h"
#include "qcustomplot.h"
#include "serialportwindow.h"
#include "writeserial.h"
#include "serialmanager.h"

#include <QDirIterator>

MainWindow::MainWindow()
{
    //Preparing the serial port=================================================
    manager = new SerialManager(this);



    //Setting up the menu bar=====================================================
        //File Menu
    menuFile = menuBar()->addMenu("&File");
    actionOpenDir = new QAction("&Open Directory",this);
    menuFile->addAction(actionOpenDir);
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

    workspace = QDir::current();
    if(!workspace.cd("data")){
            workspace.mkdir("data");
            workspace.cd("data");
}


    //Connectiong signals and slots ==========================================


    QObject::connect(displayWriting,SIGNAL(returnPressed()),manager,SLOT(writeSerialPort()));
    QObject::connect(actionOpenDir,SIGNAL(triggered()),this, SLOT(openDir()));
    QObject::connect(actionOpenSerial,SIGNAL(triggered()),manager,SLOT(openSerialPort()));
    QObject::connect(actionCloseSerial,SIGNAL(triggered()),manager,SLOT(closeSerialPort()));



}

void MainWindow::openDir(){
    QFileDialog *fileDialog = new QFileDialog(this);
    filesStack = new QStack<QString>();
    if (fileDialog->exec() == QFileDialog::Accepted) {
        QDir selectedDir(fileDialog->selectedFiles().first());
        selectedDir.setFilter(QDir::Files |
                              QDir::Dirs | QDir::NoDot | QDir::NoDotDot);
        //QStringList qsl; qsl.append("*.tex"); // I only want XML files
        //selectedDir.setNameFilters(qsl);

        QDirIterator it(selectedDir, QDirIterator::Subdirectories);
            while(it.hasNext()) {
                filesStack->push(it.next());
            }
        updateLog(QString::number(filesStack->length()));
    }

}

//This method (slot) can be used when any action is performed in order to update the log.
void MainWindow::updateLog(QString content){
    affichageLog->append(content);
}


