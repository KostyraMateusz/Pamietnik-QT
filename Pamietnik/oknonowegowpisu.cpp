#include "oknonowegowpisu.h"
#include "ui_oknonowegowpisu.h"

oknoNowegoWpisu::oknoNowegoWpisu(QWidget *parent, WarstwaUslug *uslugi)
    :QDialog(parent), ui(new Ui::oknoNowegoWpisu), warstwaUslug(uslugi)
{
    uslugi->setOknoNowegoWpisu(this);
    ui->setupUi(this);

    ui->DateTimeEdit->setDateTime(QDateTime::currentDateTime());
    wpis.setObrazek("Zdjecia/Brak.jpg");
}

oknoNowegoWpisu::~oknoNowegoWpisu(){
    delete ui;
}


void oknoNowegoWpisu::on_Dodaj_clicked(){
    if(ui->TrescWpisu->toPlainText()==""){
        QMessageBox mesBox;
        mesBox.setText("Źle dodany wpis !");
        mesBox.setInformativeText("Brak treści dla wpisu");
        mesBox.setStandardButtons(QMessageBox::Ok);
        mesBox.setIcon(QMessageBox::Warning);

        switch(mesBox.exec()){
            case QMessageBox::Ok: this->show();
            break;
        }
    }
    else{
        wpis.setTekst(ui->TrescWpisu->toPlainText());
        wpis.setDataCzas(ui->DateTimeEdit->dateTime());

        if(ui->Kolor->currentText()=="Biały") wpis.setKolor("white");
        else if(ui->Kolor->currentText()=="Żółty") wpis.setKolor("yellow");
        else if(ui->Kolor->currentText()=="Zielony") wpis.setKolor("green");

        if(ui->RodzajWspomnienia->currentText()=="Smutne") wpis.setRodzajWpsomnienia("Smutne");
        else if(ui->RodzajWspomnienia->currentText()=="Neutralne") wpis.setRodzajWpsomnienia("Neutralne");
        else if(ui->RodzajWspomnienia->currentText()=="Radosne") wpis.setRodzajWpsomnienia("Radosne");

        warstwaUslug->przesylijInstancje(wpis);

        this->close();
    }
}

void oknoNowegoWpisu::on_Anuluj_clicked(){
    this->close();
}

void oknoNowegoWpisu::on_WybierzZdjecie_clicked(){
    wpis.setObrazek(QFileDialog::getOpenFileName(this, "Wybierz obrazek", "", "(*.png *.bmp *.jpg)"));
}
