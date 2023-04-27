#ifndef WPIS_H
#define WPIS_H

#include <QString>
#include <QDateTime>
#include <QColor>
#include <QFileDialog>

class Wpis
{
public:
    Wpis();
    Wpis(QString tresc, QDateTime data, QColor kolor, QString zdjecie, QString rodzajWspomnienia);

    void setTekst(QString text);
    void setDataCzas(QDateTime data);
    void setKolor(QColor kolor);
    void setObrazek(QString zdjecie);
    void setRodzajWpsomnienia(QString rodzajWspomnienia);

    QString getTekst();
    QDateTime getDataCzas();
    QColor getKolor();
    QString getObrazek();
    QString getRodzajWpsomnienia();

    bool operator==(const Wpis& wpis);
    bool operator!=(const Wpis& wpis);
    bool operator<(const Wpis& wpis);

private:
    QString tekst;
    QDateTime dataCzas;
    QColor kolor;
    QString zdjecie;
    QString rodzajWspomnienia;
};

#endif // WPIS_H
