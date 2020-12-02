#include "mededcin1.h"
#include "ui_mededcin1.h"
#include "medecin.h"
#include "medecin2.h"

mededcin1::mededcin1(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::mededcin1)
{
    ui->setupUi(this);
}

mededcin1::~mededcin1()
{
    delete ui;
}



void mededcin1::on_pushButton_clicked()
{
    Medecin med;

   med.setmnom(ui->lineEdit_mnp->text());
   med.setmdn(ui->lineEdit_mdn->text());
   med.setmsexe(ui->lineEdit_msexe->text());
   med.setmemail(ui->lineEdit_mad->text());
   med.setmcab(ui->lineEdit->text());



medecin2 aff;
aff.afficher(med);
aff.exec();
}
