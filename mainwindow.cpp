#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "medicament.h"
#include<QMessageBox>
#include<QPrinter>
#include <QPrintDialog>
#include<QPainter>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->table_maladie->setModel(tmpmld.afficher());
    ui->table_medic->setModel(tmpmedic.afficher());
    son=new QSound(":/Sound/Sound.wav");
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_Ajout_medic_clicked()
{
    QString nom = ui->le_nom->text();
    QString prix = ui->le_prix->text();
    QString CasUtilisation = ui->le_cas->text();

    medicament mdc(nom, prix, CasUtilisation);

    bool test = mdc.ajouter();
    if (test)
    {
        QMessageBox::information(nullptr, QObject::tr("Ajout avec succès!"),
        QObject::tr("Addition successful.\n""Click Cancel to exit."), QMessageBox::Cancel);
    }
    else
    {
        QMessageBox::critical(nullptr, QObject::tr("Echec de l'ajout!"),
        QObject::tr("Addition failed.\n""Click Cancel to exit."), QMessageBox::Cancel);
    }

    son->play();

}

void MainWindow::on_Supprimer_medic_clicked()
{
    QString nom = ui->le_medic_supp->text();
    bool test = tmpmedic.supprimer(nom);
    if (test)
    {
        ui->table_medic->setModel(tmpmedic.afficher());
        QMessageBox::information(nullptr, QObject::tr("Supprimer un médicament."),
                QObject::tr("Médicament supprimé.\n"
                            "Click cancel to exit."), QMessageBox::Cancel);
    }
    else
    {
        QMessageBox::critical(nullptr, QObject::tr("Supprimer un médicament."),
                              QObject::tr("Erreur!\n"
                                          "Click Cancel to exit."), QMessageBox::Cancel);
    }
}

void MainWindow::on_Modifier_medic_clicked()
{
    QString nom = ui->le_nom->text();
    QString prix = ui->le_prix->text();
    QString CasUtilisation = ui->le_cas->text();

    medicament mdc(nom, prix, CasUtilisation);

    bool test = mdc.modifier();
    if (test)
    {
        ui->table_medic->setModel(tmpmedic.afficher_medicament_trier());

        QMessageBox::information(nullptr, QObject::tr("Modification avec succès!"),
        QObject::tr("Modification successful.\n""Click Cancel to exit."), QMessageBox::Cancel);
    }
    else
    {
        QMessageBox::critical(nullptr, QObject::tr("Echec de la modification!"),
        QObject::tr("Modification failed.\n""Click Cancel to exit."), QMessageBox::Cancel);
    }
}

void MainWindow::on_Afficher_medic_clicked()
{
    medicament mdc;

    ui->table_medic->setModel(mdc.afficher());
}

void MainWindow::on_Trier_medic_clicked()
{
         ui->table_medic->setModel(tmpmedic.afficher_medicament_trier());
}

void MainWindow::on_pushButton_2_clicked()
{
         ui->table_medic->setModel(tmpmedic.medicament_trier_prix());
}

void MainWindow::on_pushButton_3_clicked()
{
        ui->table_medic->setModel(tmpmedic.medicament_trier_cas());
}

void MainWindow::on_pb_recherche_clicked()
{
    QString nom = ui->le_nom_rech->text();
    ui->table_rech_mdc->setModel(tmpmedic.rechercher_medicament(nom));
    ui->table_medic->setModel(tmpmedic.afficher());
}


//Maladie
void MainWindow::on_Ajout_maladie_clicked()
{
    QString nom = ui->le_nom_2->text();
    QString cause = ui->le_cause->text();
    QString symptome = ui->le_symptome->text();

    Maladie mld(nom, cause, symptome);

    bool test = mld.ajouter();
    if (test)
    {
        QMessageBox::information(nullptr, QObject::tr("Ajout avec succès!"),
        QObject::tr("Addition successful.\n""Click Cancel to exit."), QMessageBox::Cancel);
    }
    else
    {
        QMessageBox::critical(nullptr, QObject::tr("Echec de l'ajout!"),
        QObject::tr("Addition failed.\n""Click Cancel to exit."), QMessageBox::Cancel);
    }
}

void MainWindow::on_Modifier_maladie_clicked()
{
    QString nom = ui->le_nom_2->text();
    QString cause = ui->le_cause->text();
    QString symptome = ui->le_symptome->text();

    Maladie mld(nom, cause, symptome);

    bool test = mld.modifier();
    if (test)
    {
        QMessageBox::information(nullptr, QObject::tr("Modification avec succès!"),
        QObject::tr("Modification successful.\n""Click Cancel to exit."), QMessageBox::Cancel);
    }
    else
    {
        QMessageBox::critical(nullptr, QObject::tr("Echec de la modification!"),
        QObject::tr("Modification failed.\n""Click Cancel to exit."), QMessageBox::Cancel);
    }
}

void MainWindow::on_Afficher_maladie_clicked()
{
    Maladie mld;

    ui->table_maladie->setModel(mld.afficher());
}

void MainWindow::on_Supp_maladie_clicked()
{
    QString nom = ui->le_supp->text();

    bool test = tmpmld.supprimer(nom);
    if (test)
    {
        QMessageBox::information(nullptr, QObject::tr("Supprimer un médicament."),
                QObject::tr("Médicament supprimé.\n"
                            "Click cancel to exit."), QMessageBox::Cancel);
    }
    else
    {
        QMessageBox::critical(nullptr, QObject::tr("Supprimer un médicament."),
                              QObject::tr("Erreur!\n"
                                          "Click Cancel to exit."), QMessageBox::Cancel);
    }
}

void MainWindow::on_rechercher_maladie_clicked()
{
    QString nom = ui->le_nom_rech_maladie->text();
    ui->table_rech_mld->setModel(tmpmld.rechercher_maladie(nom));
    ui->table_maladie->setModel(tmpmld.afficher());
}

//son
void MainWindow::on_pushButton_clicked()
{
    son->play();
}

void MainWindow::on_Printer_clicked()
{
    QPrinter *printer = new QPrinter(QPrinter::HighResolution);
              printer->setOutputFormat(QPrinter::NativeFormat);
              printer->setPageSize(QPrinter::A4);
              printer->setOrientation(QPrinter::Portrait);
              printer->setFullPage(true);


          QPrintDialog *printDialog = new QPrintDialog(printer,this);
          printDialog->setWindowTitle("Impression PDF");
          if(printDialog->exec())
          {
             QPainter painter;
             if(painter.begin(printer))
             {
                 double xscale = double(ui->table_medic->width() / 65);
                 double yscale = double(ui->table_medic->height() / 65);
                 painter.scale(xscale, yscale);
                 ui->table_medic->render(&painter);
                 painter.end();
             }
             else
             {
                 qWarning("failed to open file");
                QMessageBox::warning(nullptr,QObject::tr("PDF echoue"),QObject::tr("click cancel to exit!"),QMessageBox::Cancel);
             }
          }
}

void MainWindow::on_Print_malad_clicked()
{
    QPrinter *printer = new QPrinter(QPrinter::HighResolution);
              printer->setOutputFormat(QPrinter::NativeFormat);
              printer->setPageSize(QPrinter::A4);
              printer->setOrientation(QPrinter::Portrait);
              printer->setFullPage(true);


          QPrintDialog *printDialog = new QPrintDialog(printer,this);
          printDialog->setWindowTitle("Impression PDF");
          if(printDialog->exec())
          {
             QPainter painter;
             if(painter.begin(printer))
             {
                 double xscale = double(ui->table_medic->width() / 65);
                 double yscale = double(ui->table_medic->height() / 65);
                 painter.scale(xscale, yscale);
                 ui->table_maladie->render(&painter);
                 painter.end();
             }
             else
             {
                 qWarning("failed to open file");
                QMessageBox::warning(nullptr,QObject::tr("PDF echoue"),QObject::tr("click cancel to exit!"),QMessageBox::Cancel);
             }
          }
}
