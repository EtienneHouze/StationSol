#include "mainwindow.h"
#include "qcustomplot.h"

MainWindow::MainWindow()
{
    centralWindow = new QWidget();
    mainLayout = new QHBoxLayout();
    button1 = new QPushButton("Test");
    plot = new QCustomPlot();
    mainLayout ->addWidget(button1);
    mainLayout ->addWidget(plot);
    centralWindow->setLayout(mainLayout);
    setCentralWidget(centralWindow);
}

