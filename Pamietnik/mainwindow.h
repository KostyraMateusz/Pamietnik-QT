#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QKeyEvent>
#include <QImage>
#include <QMenuBar>

#include "warstwauslug.h"
#include "Wpis.h"

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class WarstwaUslug;

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr, WarstwaUslug* uslugi = nullptr);
    ~MainWindow();

    void poprzedniBrak();
    void porzedniWypisz(Wpis poprzedni);

    void aktualnyBrak();
    void aktualnyWypisz(Wpis aktualny);

    void nastepnyBrak();
    void nastepnyWypisz(Wpis nastepny);

private slots:
    void closeEvent(QCloseEvent *event) override;
    void keyPressEvent(QKeyEvent * event) override;

    void on_Doda_Button_clicked();
    void on_Poprzednie_Button_clicked();
    void on_Nastepny_Button_clicked();
    void on_Usun_Button_clicked();

    void on_actionImportujWpisy_triggered();
    void on_actionEksportujWpisy_triggered();

    void on_WspomnieniaSmutne_clicked(bool checked);
    void on_WspomnieniaNeutralne_clicked(bool checked);
    void on_WspomnieniaRadosne_clicked(bool checked);

private:
    Ui::MainWindow *ui = nullptr;
    WarstwaUslug* warstwaUslug = nullptr;
    QImage *obrazek = nullptr;
    QSize wymiary;
    QMenuBar *menubar;
    bool smutne, neutralne, radosne;
};
#endif // MAINWINDOW_H
