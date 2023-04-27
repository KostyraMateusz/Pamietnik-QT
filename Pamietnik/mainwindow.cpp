#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent, WarstwaUslug* uslugi)
    : QMainWindow(parent), ui(new Ui::MainWindow), warstwaUslug(uslugi) {
    warstwaUslug->setOknoGlowne(this);
    ui->setupUi(this);
    warstwaUslug->funkctaTestowa();
    setFocusPolicy(Qt::ClickFocus);
    wymiary = ui->Zdjecie->size();
    warstwaUslug->wczytajZapisaneWpisy("Wspomnienia.txt");
    warstwaUslug->filtruj(true, true, true);
}

MainWindow::~MainWindow(){
    delete ui;
}


void MainWindow::poprzedniBrak(){
    ui->PoprzedniWpis->clear();
    ui->PoprzedniWpis->setFontWeight(QFont::Bold);
    ui->PoprzedniWpis->setTextColor("red");
    ui->PoprzedniWpis->append("Brak poprzedniego wpisu !!!");
}

void MainWindow::porzedniWypisz(Wpis poprzedni){
    ui->PoprzedniWpis->clear();
    ui->PoprzedniWpis->setTextColor(poprzedni.getKolor());
    ui->PoprzedniWpis->setFontWeight(QFont::Bold);
    ui->PoprzedniWpis->append(poprzedni.getDataCzas().toString("dd-MM-yyyy hh:mm"));
    ui->PoprzedniWpis->setFontWeight(QFont::Normal);
    ui->PoprzedniWpis->append(poprzedni.getTekst());
}

void MainWindow::aktualnyBrak(){
    ui->AktualnyWpis->clear();
    ui->AktualnyWpis->setFontWeight(QFont::Bold);
    ui->AktualnyWpis->setTextColor("red");
    ui->AktualnyWpis->append("Brak aktualnego wpisu !!!");
    ui->Zdjecie->clear();
}

void MainWindow::aktualnyWypisz(Wpis aktualny){
    ui->AktualnyWpis->clear();
    ui->AktualnyWpis->setTextColor(aktualny.getKolor());
    ui->AktualnyWpis->setFontWeight(QFont::Bold);
    ui->AktualnyWpis->append(aktualny.getDataCzas().toString("dd-MM-yyyy hh:mm"));
    ui->AktualnyWpis->setFontWeight(QFont::Normal);
    ui->AktualnyWpis->append(aktualny.getTekst());

    obrazek = new QImage(aktualny.getObrazek());
    ui->Zdjecie->setPixmap(QPixmap::fromImage(obrazek->scaled(wymiary)));
}

void MainWindow::nastepnyBrak(){
    ui->NastepnyWpis->clear();
    ui->NastepnyWpis->setFontWeight(QFont::Bold);
    ui->NastepnyWpis->setTextColor("red");
    ui->NastepnyWpis->append("Brak następnego wpisu !!!");
}

void MainWindow::nastepnyWypisz(Wpis nastepny){
    ui->NastepnyWpis->clear();
    ui->NastepnyWpis->setTextColor(nastepny.getKolor());
    ui->NastepnyWpis->setFontWeight(QFont::Bold);
    ui->NastepnyWpis->append(nastepny.getDataCzas().toString("dd-MM-yyyy hh:mm"));
    ui->NastepnyWpis->setFontWeight(QFont::Normal);
    ui->NastepnyWpis->append(nastepny.getTekst());
}


void MainWindow::closeEvent(QCloseEvent *event){
    warstwaUslug->zapiszWszystkieWpisy("Wspomnienia.txt");
}


void MainWindow::keyPressEvent(QKeyEvent * event){
    if(event->key() == Qt::Key_Up) on_Poprzednie_Button_clicked();
    if(event->key() == Qt::Key_Down) on_Nastepny_Button_clicked();
}


void MainWindow::on_Doda_Button_clicked(){
    warstwaUslug->otworzOknoNowegoWpisu();
}

void MainWindow::on_Poprzednie_Button_clicked(){
    warstwaUslug->poprzedniWpis();
}

void MainWindow::on_Nastepny_Button_clicked(){
    warstwaUslug->nastepnyWpis();
}

void MainWindow::on_Usun_Button_clicked(){
    warstwaUslug->usunWpis();
}

void MainWindow::on_actionImportujWpisy_triggered(){
    QString sciezka = QFileDialog::getOpenFileName(this,"Wybierz miejsce odczytania wspomnień","","*.txt");
    warstwaUslug->wczytajZapisaneWpisy(sciezka);
}

void MainWindow::on_actionEksportujWpisy_triggered(){
    QString sciezka = QFileDialog::getOpenFileName(this,"Wybierz miejsce zapisu wspomnień","","*.txt");
    warstwaUslug->zapiszWszystkieWpisy(sciezka);
}


void MainWindow::on_WspomnieniaSmutne_clicked(bool checked){
    smutne=checked;
    warstwaUslug->filtruj(smutne, neutralne, radosne);
}

void MainWindow::on_WspomnieniaNeutralne_clicked(bool checked){
    neutralne=checked;
    warstwaUslug->filtruj(smutne, neutralne, radosne);
}

void MainWindow::on_WspomnieniaRadosne_clicked(bool checked){
    radosne=checked;
    warstwaUslug->filtruj(smutne, neutralne, radosne);
}
