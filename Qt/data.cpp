#include "data.h"
#include "mainwindow.h"


Data::Data(MainWindow *mainWindow):QObject()
{
    temp = 0;
    parent = mainWindow;
}

void Data::save(){

}

