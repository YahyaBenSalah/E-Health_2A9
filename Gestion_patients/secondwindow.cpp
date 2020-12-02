#include "secondwindow.h"
#include "ui_secondwindow.h"
#include "patient.h"
secondwindow::secondwindow(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::secondwindow)
{
    ui->setupUi(this);
}

secondwindow::~secondwindow()
{
    delete ui;
}


void secondwindow::afficher(patient pat)
{
    ui->line_edit_cin2->setText(pat.getcin());
    ui->line_edit_nom2->setText(pat.getnom());
    ui->line_edit_prenom2->setText(pat.getprenom());
    ui->line_edit_civ2->setText(pat.getciv());
    ui->line_edit_dn2->setText(pat.getdn());

   }

void secondwindow::on_pushButton_clicked()
{

}
