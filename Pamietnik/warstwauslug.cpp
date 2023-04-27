#include "warstwauslug.h"

WarstwaUslug::WarstwaUslug(QObject *parent) : QObject(parent) {}

void WarstwaUslug::setOknoGlowne(MainWindow *ui) { oknoGlowne = ui; }
void WarstwaUslug::setOknoNowegoWpisu(oknoNowegoWpisu *ui) { oknoWpisu = ui; }
void WarstwaUslug::setWarstwaDanych(WarstwaDanych *ui) { warstwaDanych = ui; }


void WarstwaUslug::zapiszWszystkieWpisy(QString sciezka){
    warstwaDanych->zapiszDoPliku(sciezka);
}

void WarstwaUslug::wczytajZapisaneWpisy(QString sciezka){
    warstwaDanych->wczytajZPliku(sciezka);
    filtruj(smutne, neutralne, radosne);
}


void WarstwaUslug::otworzOknoNowegoWpisu(){
    oknoWpisu = new oknoNowegoWpisu(oknoGlowne, this);
    oknoWpisu->exec();
    delete oknoWpisu;
}

void WarstwaUslug::przesylijInstancje(Wpis &wpis){
    warstwaDanych->dodajWpis(wpis);
    if(boolFiltruj==true) filtruj(smutne, neutralne, radosne);
    else wyswietl(warstwaDanych->getListaWpisow());
}


void WarstwaUslug::wyswietl(QList<Wpis> lista){
    if(lista.size()>0){
        oknoGlowne->aktualnyWypisz(lista[warstwaDanych->getAktualnyWpisID()]);
        if((warstwaDanych->getAktualnyWpisID()+1) < lista.size()){
            oknoGlowne->porzedniWypisz(lista[warstwaDanych->getAktualnyWpisID()+1]);
        }
        else oknoGlowne->poprzedniBrak();

        if((warstwaDanych->getAktualnyWpisID()-1)>=0){
            oknoGlowne->nastepnyWypisz(lista[warstwaDanych->getAktualnyWpisID()-1]);
        }
        else oknoGlowne->nastepnyBrak();
    }
    else{
        oknoGlowne->poprzedniBrak();
        oknoGlowne->aktualnyBrak();
        oknoGlowne->nastepnyBrak();
    }
}

void WarstwaUslug::poprzedniWpis(){
    QList<Wpis> lista;
    if(boolFiltruj==true) lista=warstwaDanych->getlistaRodzajiWspomnien();
    else lista=warstwaDanych->getListaWpisow();

    if(warstwaDanych->getAktualnyWpisID()<lista.size()-1){
        warstwaDanych->setAktualnyWpisID(warstwaDanych->getAktualnyWpisID()+1);
        wyswietl(lista);
    }
}

void WarstwaUslug::nastepnyWpis(){
    QList<Wpis> lista;
    if(boolFiltruj==true) lista=warstwaDanych->getlistaRodzajiWspomnien();
    else lista=warstwaDanych->getListaWpisow();

    if(warstwaDanych->getAktualnyWpisID()>0){
        warstwaDanych->setAktualnyWpisID(warstwaDanych->getAktualnyWpisID()-1);
        wyswietl(lista);
    }
}

void WarstwaUslug::usunWpis(){
    warstwaDanych->usunWpis();
    if(boolFiltruj == true) filtruj(smutne, neutralne, radosne);
    else wyswietl(warstwaDanych->getListaWpisow());
}

void WarstwaUslug::filtruj(bool smu, bool neutr, bool rado){
    this->smutne=smu;
    this->neutralne=neutr;
    this->radosne=rado;

    if(smutne==false && neutralne==false && radosne==false){
        boolFiltruj=false;
        warstwaDanych->setAktualnyWpisID(0);
        wyswietl(warstwaDanych->getListaWpisow());
    }
    else{
        boolFiltruj = true;
        warstwaDanych->filtrujLista(smutne, neutralne, radosne);
        wyswietl(warstwaDanych->getlistaRodzajiWspomnien());
    }
}

void WarstwaUslug::funkctaTestowa(){
    Wpis wpis1("Smutny 1", QDateTime::fromString("Fri Dec 20 20:47:42 2022"), QColor::fromRgb(255,255,255), "Zdjecia/Brak.jpg", "Smutny");
    Wpis wpis2("Smutny 2", QDateTime::fromString("Fri Dec 23 20:47:42 2022"), QColor::fromRgb(255,255,255),"Zdjecia/Brak.jpg", "Smutny");
    Wpis wpis3("Smutny 3", QDateTime::fromString("Fri Dec 26 20:47:42 2022"), QColor::fromRgb(255,255,255),"Zdjecia/Brak.jpg", "Smutny");
    Wpis wpis4("Neutralny 1", QDateTime::fromString("Fri Dec 21 20:47:42 2022"), QColor::fromRgb(255,255,255),"Zdjecia/Brak.jpg", "Neutralny");
    Wpis wpis5("Neutralny 2", QDateTime::fromString("Fri Dec 24 20:47:42 2022"), QColor::fromRgb(255,255,255),"Zdjecia/Brak.jpg", "Neutralny");
    Wpis wpis6("Neutralny 3", QDateTime::fromString("Fri Dec 27 20:47:42 2022"), QColor::fromRgb(255,255,255),"Zdjecia/Brak.jpg", "Neutralny");
    Wpis wpis7("Radosny 1", QDateTime::fromString("Fri Dec 22 20:47:42 2022"), QColor::fromRgb(255,255,255),"Zdjecia/Brak.jpg", "Radosny");
    Wpis wpis8("Radosny 2", QDateTime::fromString("Fri Dec 25 20:47:42 2022"), QColor::fromRgb(255,255,255),"Zdjecia/Brak.jpg", "Radosny");
    Wpis wpis9("Radosny 3", QDateTime::fromString("Fri Dec 28 20:47:42 2022"), QColor::fromRgb(255,255,255),"Zdjecia/Brak.jpg", "Radosny");

    QList<Wpis>listaTestowa = {wpis9, wpis3, wpis8, wpis2, wpis7, wpis1};

    przesylijInstancje(wpis1); przesylijInstancje(wpis2); przesylijInstancje(wpis3);
    przesylijInstancje(wpis4); przesylijInstancje(wpis5); przesylijInstancje(wpis6);
    przesylijInstancje(wpis7); przesylijInstancje(wpis8);przesylijInstancje(wpis9);

    filtruj(true, false, true);

    try {
        int licznik = 0;
        for(int i=0; i<warstwaDanych->getlistaRodzajiWspomnien().size(); i++)
            if(listaTestowa[i]==warstwaDanych->getlistaRodzajiWspomnien()[i]) licznik++;

        if (licznik==warstwaDanych->getlistaRodzajiWspomnien().size()) qDebug() << "Test jednostkowy: OK!";
        else qDebug() << "Blad!";
    }

    catch (const std::exception&) {
        qDebug() << "Test jednostkowy: BLAD!";
    }

    warstwaDanych->wyczyscListe();
}
