/*
 * Cabrera: main.cpp
 * Author: Vicente Cunha
 * Date: July 2016
 */

#include "mainwindow.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    w.show();

    return a.exec();
}
