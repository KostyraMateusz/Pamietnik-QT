#include "wpis.h"

Wpis::Wpis(){}

Wpis::Wpis(QString tresc, QDateTime data, QColor kolor, QString zdjecie, QString rodzajWspomnienia)
    :tekst(tresc), dataCzas(data), kolor(kolor), zdjecie(zdjecie), rodzajWspomnienia(rodzajWspomnienia) {}


void Wpis::setTekst(QString text){
    this->tekst=text;
}

void Wpis::setDataCzas(QDateTime data){
    this->dataCzas=data;
}

void Wpis::setKolor(QColor kolor){
    this->kolor=kolor;
}

void Wpis::setObrazek(QString zdjecie){
    this->zdjecie=zdjecie;
}

void Wpis::setRodzajWpsomnienia(QString rodzajWspomnienia){
    this->rodzajWspomnienia=rodzajWspomnienia;
}

QString Wpis::getTekst(){
    return this->tekst;
}

QDateTime Wpis::getDataCzas(){
    return this->dataCzas;
}

QColor Wpis::getKolor(){
    return this->kolor;
}

QString Wpis::getObrazek(){
    return this->zdjecie;
}

QString Wpis::getRodzajWpsomnienia(){
    return this->rodzajWspomnienia;
}

bool Wpis::operator==(const Wpis &wpis){
    if(this != &wpis)
        if(this->dataCzas.date().year() == wpis.dataCzas.date().year())
            if(this->dataCzas.date().month() == wpis.dataCzas.date().month())
                if(this->dataCzas.date().day() == wpis.dataCzas.date().day())
                    if(this->dataCzas.time().hour() == wpis.dataCzas.time().hour())
                        if(this->dataCzas.time().minute() == wpis.dataCzas.time().minute())
                            return true;
    return false;
}

bool Wpis::operator!=(const Wpis &wpis){
    return !(*this == wpis);
}

bool Wpis::operator<(const Wpis &wpis){
    if(this != &wpis) return this->dataCzas > wpis.dataCzas;
}
