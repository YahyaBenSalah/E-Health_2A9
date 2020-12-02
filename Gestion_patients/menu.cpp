#include "menu.h"
#include "ui_menu.h"
#include <QCheckBox>
#include <QMessageBox>
#include "mainwindow.h"
#include "medecin.h"
#include "mededcin1.h"


menu::menu(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::menu)
{
    ui->setupUi(this);
    ui->Patient->setChecked(false);
    ui->medecin->setChecked(false);

}

menu::~menu()
{
    delete ui;
}



void menu::on_pushButton_clicked()
{
    if (ui->Patient->isChecked())
   { m=new MainWindow(this);
    m->show();}
    else
    {
        med=new mededcin1(this);
        med->show();
    }
}
