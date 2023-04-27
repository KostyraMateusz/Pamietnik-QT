#ifndef WARSTWADANYCH_H
#define WARSTWADANYCH_H

#include <QObject>
#include <QList>
#include <QFile>

#include "Wpis.h"
#include "warstwauslug.h"

class WarstwaUslug;

class WarstwaDanych : public QObject
{
    Q_OBJECT
public:
    explicit WarstwaDanych(QObject *parent = nullptr, WarstwaUslug* uslugi = nullptr);

    void sortujWpisy();

    int getAktualnyWpisID();
    void setAktualnyWpis(QList<Wpis> lista);
    void setAktualnyWpisID(int pozycja);

    void dodajWpis(Wpis& wpis);
    void usunWpis();
    void wyczyscListe();

    void zapiszDoPliku(QString sciezka);
    void wczytajZPliku(QString sciezka);

    void filtrujLista(bool smutne, bool neutralne, bool radosne);

    QList<Wpis> getListaWpisow();
    QList<Wpis> getlistaRodzajiWspomnien();

private:
    WarstwaUslug* warstwaUslug;
    QList<Wpis> listaWpisow;
    QList<Wpis> listaRodzajiWspomnien;
    QFile wspomnienia;
    Wpis aktualnyWpis;
    int aktualnyWpisID;
};

#endif // WARSTWADANYCH_H
