#ifndef WARSTWAUSLUG_H
#define WARSTWAUSLUG_H

#include <QObject>
#include <QFile>

#include "mainwindow.h"
#include "warstwadanych.h"
#include "oknonowegowpisu.h"
#include "Wpis.h"

class MainWindow;
class WarstwaDanych;
class oknoNowegoWpisu;

class WarstwaUslug : public QObject
{
    Q_OBJECT
public:
    explicit WarstwaUslug(QObject *parent = nullptr);

    void setOknoGlowne(MainWindow *ui = nullptr);
    void setOknoNowegoWpisu(oknoNowegoWpisu *ui = nullptr);
    void setWarstwaDanych(WarstwaDanych *ui = nullptr);

    void zapiszWszystkieWpisy(QString sciezka);
    void wczytajZapisaneWpisy(QString sciezka);

    void otworzOknoNowegoWpisu();
    void przesylijInstancje(Wpis& wpis);

    void wyswietl(QList<Wpis> lista);
    void poprzedniWpis();
    void nastepnyWpis();
    void usunWpis();

    void filtruj(bool smutne, bool neutralne, bool radosne);

    void funkctaTestowa();

private:
    MainWindow* oknoGlowne = nullptr;
    oknoNowegoWpisu* oknoWpisu = nullptr;
    WarstwaDanych* warstwaDanych = nullptr;
    bool boolFiltruj = false;
    bool smutne=false, neutralne=false, radosne=false;
};

#endif // WARSTWAUSLUG_H
