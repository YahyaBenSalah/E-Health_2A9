#include "medecin2.h"
#include "ui_medecin2.h"
#include"medecin.h"
#include"mededcin1.h"

medecin2::medecin2(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::medecin2)
{
    ui->setupUi(this);
}

medecin2::~medecin2()
{
    delete ui;
}


void medecin2::afficher(Medecin med)
{
    ui->lineEdit_mnp2->setText(med.getmnom());
    ui->lineEdit_mdn2->setText(med.getmdn());
    ui->lineEdit_msexe2->setText(med.getmsexe());
    ui->lineEdit_memail2->setText(med.getmemail());
     ui->lineEdit_mad2->setText(med.getmcab());


   }
