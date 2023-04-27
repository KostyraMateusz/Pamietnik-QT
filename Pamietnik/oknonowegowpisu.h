#ifndef OKNONOWEGOWPISU_H
#define OKNONOWEGOWPISU_H

#include <QDialog>
#include <QMessageBox>

#include "Wpis.h"
#include "warstwauslug.h"

class WarstwaUslug;

namespace Ui {
class oknoNowegoWpisu;
}

class oknoNowegoWpisu : public QDialog
{
    Q_OBJECT

public:
    explicit oknoNowegoWpisu(QWidget *parent = nullptr, WarstwaUslug* uslugi = nullptr);
    ~oknoNowegoWpisu();

private slots:
    void on_Dodaj_clicked();
    void on_Anuluj_clicked();

    void on_WybierzZdjecie_clicked();

signals:
    void wyslijWpis(Wpis &wpis);

private:
    Ui::oknoNowegoWpisu *ui;
    WarstwaUslug* warstwaUslug = nullptr;
    Wpis wpis;
};

#endif // OKNONOWEGOWPISU_H
