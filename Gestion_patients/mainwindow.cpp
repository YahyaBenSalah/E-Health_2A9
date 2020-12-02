#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "patient.h"
#include"secondwindow.h"
#include "QMessageBox"
#include <QSqlQuery>
MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_pushButton_clicked()
{
    patient pat;
    QString nom= ui->Edit_line_nom->text();
     QString cin= ui->edit_line_cin->text();
      QString civ= ui->edit_line_civ->text();
       QString dn= ui->edit_line_dn->text();
        QString prenom= ui->edit_line_prenom->text();
        patient e(nom,prenom,cin,civ,dn);
        bool test=e.ajouter();
if (test)
{QMessageBox::information(nullptr, QObject::tr("Patient ajouté"),
                          QObject::tr(" Ajouté!\n"
                                      "Click Cancel to exit."), QMessageBox::Cancel);}
    else {
        {QMessageBox::information(nullptr, QObject::tr("Patient NON AJOUTé"),
                                  QObject::tr("NON Ajouté!\n"
                                              "Click Cancel to exit."), QMessageBox::Cancel);
    }
}
    pat.setcin(ui->edit_line_cin->text());
    pat.setnom(ui->Edit_line_nom->text());
    pat.setprenom(ui->edit_line_prenom->text());
    pat.setciv(ui->edit_line_civ->text());
     pat.setdn(ui->edit_line_dn->text());

    secondwindow aff;
aff.afficher(pat);
aff.exec();
}
