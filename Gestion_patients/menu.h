#ifndef MENU_H
#define MENU_H
#include "QAbstractButton"
#include "mainwindow.h"
#include <QDialog>
#include"mededcin1.h"
#include"medecin.h"

namespace Ui {
class menu;
}

class menu : public QDialog
{
    Q_OBJECT

public:
    explicit menu(QWidget *parent = nullptr);
    ~menu();

private slots:
    void on_buttonBox_clicked(QAbstractButton *button);

    void on_pushButton_clicked();

private:
    Ui::menu *ui;
    MainWindow *m;
    mededcin1 *med;
};

#endif // MENU_H
