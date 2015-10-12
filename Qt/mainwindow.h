#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QtWidgets>
#include "qcustomplot.h"

class MainWindow : public QMainWindow
{
public:
    MainWindow();


private:
    QWidget *centralWindow;
    QHBoxLayout *mainLayout;
    QPushButton *button1;
    QCustomPlot *plot;
signals:

public slots:
};

#endif // MAINWINDOW_H
