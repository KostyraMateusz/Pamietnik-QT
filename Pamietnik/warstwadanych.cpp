#include "warstwadanych.h"

WarstwaDanych::WarstwaDanych(QObject *parent, WarstwaUslug *uslugi)
    :QObject(parent), warstwaUslug(uslugi){
    warstwaUslug->setWarstwaDanych(this);
    wspomnienia.setFileName("Wspomnienia.txt");
}


void WarstwaDanych::sortujWpisy(){
    std::sort(listaWpisow.begin(), listaWpisow.end());
    auto v_powtorzone = std::unique(listaWpisow.begin(), listaWpisow.end());
    listaWpisow.erase(v_powtorzone, listaWpisow.end());
}


int WarstwaDanych::getAktualnyWpisID(){
    return aktualnyWpisID;
}

void WarstwaDanych::setAktualnyWpis(QList<Wpis> lista){
    for(int i=0; i<lista.size(); i++)
        if(aktualnyWpis==lista[i]) setAktualnyWpisID(i);
}

void WarstwaDanych::setAktualnyWpisID(int pozycja){
    this->aktualnyWpisID=pozycja;
}


void WarstwaDanych::dodajWpis(Wpis &wpis){
    listaWpisow.push_back(wpis);
    aktualnyWpis = wpis;

    for(Wpis &wpis2 : listaWpisow)
        if(wpis2==aktualnyWpis) wpis2=aktualnyWpis;

    sortujWpisy();
    setAktualnyWpis(listaWpisow);
}

void WarstwaDanych::usunWpis(){
    if(listaWpisow.size()>0 && aktualnyWpisID>0){
        listaWpisow.removeAt(aktualnyWpisID);
        aktualnyWpisID--;
    }
    else if(listaWpisow.size()>0 && aktualnyWpisID==0)
        listaWpisow.removeAt(aktualnyWpisID);
}

void WarstwaDanych::wyczyscListe(){
    listaWpisow.clear();
}


void WarstwaDanych::zapiszDoPliku(QString sciezka){
    wspomnienia.setFileName(sciezka);
    if(wspomnienia.open(QIODevice::WriteOnly)){
        QTextStream dane(&wspomnienia);
            for (Wpis& wpis : listaWpisow)
                dane << wpis.getTekst() + ";" + wpis.getDataCzas().toString()+ ";" +
                wpis.getKolor().name(QColor::HexArgb)+ ";" +wpis.getObrazek()+";"+wpis.getRodzajWpsomnienia()+'\n';
    }
    wspomnienia.close();
}

void WarstwaDanych::wczytajZPliku(QString sciezka){
    wspomnienia.setFileName(sciezka);
    if(wspomnienia.size()!=0){
         if(wspomnienia.open(QIODevice::ReadOnly)){
            QTextStream dane(&wspomnienia);
            while(!dane.atEnd()){
                QString linia = dane.readLine();
                QStringList temp = linia.split(";");
                Wpis pamietnik;
                pamietnik.setTekst(temp[0]);
                pamietnik.setDataCzas(QDateTime::fromString(temp[1]));
                pamietnik.setKolor(temp[2]);
                pamietnik.setObrazek(temp[3]);
                pamietnik.setRodzajWpsomnienia(temp[4]);
                listaWpisow.push_back(pamietnik);
            }
        }
        aktualnyWpisID=0;
        aktualnyWpis=listaWpisow[aktualnyWpisID];
    }
    wspomnienia.close();
}

void WarstwaDanych::filtrujLista(bool smutne, bool neutralne, bool radosne){
    listaRodzajiWspomnien.clear();

    for(int i=0; i<listaWpisow.size(); i++){
        if(smutne==true && listaWpisow[i].getRodzajWpsomnienia()=="Smutne")
            listaRodzajiWspomnien.push_back(listaWpisow[i]);

        else if(neutralne==true && listaWpisow[i].getRodzajWpsomnienia()=="Neutralne")
            listaRodzajiWspomnien.push_back(listaWpisow[i]);

        else if(radosne==true && listaWpisow[i].getRodzajWpsomnienia()=="Radosne")
            listaRodzajiWspomnien.push_back(listaWpisow[i]);
    }

    if(listaRodzajiWspomnien.size()>0){
        aktualnyWpis=listaRodzajiWspomnien[0];
        setAktualnyWpis(listaRodzajiWspomnien);
    }
}

QList<Wpis> WarstwaDanych::getListaWpisow(){
    return listaWpisow;
}

QList<Wpis> WarstwaDanych::getlistaRodzajiWspomnien(){
    return listaRodzajiWspomnien;
}
