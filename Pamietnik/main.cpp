#include "mainwindow.h"
#include "warstwauslug.h"
#include "warstwadanych.h"
#include "oknonowegowpisu.h"

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    WarstwaUslug warstwaUslug;
    WarstwaDanych warstwaDanych(nullptr, &warstwaUslug);
    MainWindow mainWindow(nullptr, &warstwaUslug);
    oknoNowegoWpisu oknoWpis(nullptr, &warstwaUslug);
    mainWindow.show();
    return a.exec();
}
