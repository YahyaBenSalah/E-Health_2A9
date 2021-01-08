#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QMessageBox>
#include <QDebug>
#include <QHeaderView>
#include <QtSerialPort/QSerialPort>
#include <QtSerialPort/QSerialPortInfo>
#include <QLineEdit>
#include <QtCore>
#include <QPrinter>
#include <QPdfWriter>
#include <QPainter>
#include <QDesktopServices>
#include <QUrl>
#include <QSound>
#include <QTableWidget>
#include <QMediaPlayer>
#include <QFileDialog>
#include <QFileInfo>
#include <QPrintDialog>
#include <QtSql>
#include "connection.h"
#include "comptes.h"
#include "fiche.h"
#include "bilan.h"
#include "dossiermedicale.h"
#include "exportexcelobject.h"
#include "maladie.h"
#include "maladie1.h"
#include "medicament.h"
#include "patient.h"
#include "medecin.h"


QT_CHARTS_USE_NAMESPACE


MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
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


void MainWindow::on_BtnAddFiche_clicked()
{

    int cin = ui->ECin->text().toInt();
    QString nom = ui->ENom->text();
    QString prenom = ui->EPrenom->text();
    QString maladie = ui->EMaladie->text();
    QString traitement = ui->ETraitement->toPlainText();
    if(cin==NULL||prenom==""||nom==""||maladie==""||traitement=="")
    {
        QMessageBox::critical(nullptr, QObject::tr("Contrainte "),
                           QObject::tr("Touts les champs sonts obligatoire !.\n"
                                       "cliqué ok pour continuer..."), QMessageBox::Ok);
    }else {
        Fiche* f = new Fiche(cin,nom,prenom,maladie,traitement);
        bool testExiste = f->trouverFiche(cin);
        if(testExiste){
            QMessageBox::critical(nullptr, QObject::tr("Existe "),
                               QObject::tr("la fiche est deja existante.\n"
                                           "cliqué ok pour quitter."), QMessageBox::Ok);
        }else {
            bool testAjout = f->ajouterFiche(*f);
            if(testAjout){
                QMessageBox::information(nullptr, QObject::tr("fiche Ajoutée "),
                                   QObject::tr("la fiche a été bien ajoutée a votre base de donné.\n"
                                               "cliqué ok pour quitter."), QMessageBox::Ok);
            }
    }
}


}

void MainWindow::on_BtnRefrech_clicked()
{
    Fiche *f =new Fiche();
ui->tableView->setModel(f->afficherAll());
}



void MainWindow::on_BtnDeleteFche_clicked()
{
    int ligne = ui->tableView->currentIndex().row();
    int cin = ui->tableView->model()->data(ui->tableView->model()->index(ligne, 0)).toInt();
    Fiche *f =new Fiche();
    if(f->supprimerFiche(cin)){
        f->afficherAll();
        QMessageBox::information(nullptr, QObject::tr("Existe "),
                           QObject::tr("la fiche est bien supprimer.\n"
                                       "cliqué ok pour quitter."), QMessageBox::Ok);
    }


}

void MainWindow::on_BtnUpdateFiche_clicked()
{
    int ligne = ui->tableView->currentIndex().row();
    int cin = ui->tableView->model()->data(ui->tableView->model()->index(ligne, 0)).toInt();
    QString nom = ui->tableView->model()->data(ui->tableView->model()->index(ligne, 1)).toString();
    QString prenom = ui->tableView->model()->data(ui->tableView->model()->index(ligne, 2)).toString();
    QString maladie = ui->tableView->model()->data(ui->tableView->model()->index(ligne, 3)).toString();
    QString traitement = ui->tableView->model()->data(ui->tableView->model()->index(ligne, 4)).toString();
    qDebug()<< nom;
//    Fiche * f =new Fiche();
//    f->setCin_client(cin);
//    f->setPrenom_client(f->trouverChamp("PRENOM",cin));
//    f->setNom_client(f->trouverChamp("NOM",cin));
//    f->setMaladie_client(f->trouverChamp("MALADIE",cin));
//    f->setTraitement_client(f->trouverChamp("TRAITEMENT",cin));
//    qDebug()<<f->getNom_client();
//    ui->F_C_FModules->setCurrentIndex(2);

    ui->UNom->setText(nom);
    ui->UPrenom->setText(prenom);
    ui->UMaladie->setText(maladie);
    ui->UTraitement->setText(traitement);

}

void MainWindow::on_BtnUpdateFiche_2_clicked()
{
    int ligne = ui->tableView->currentIndex().row();
    int cin = ui->tableView->model()->data(ui->tableView->model()->index(ligne, 0)).toInt();

    QString maladie1 = ui->tableView->model()->data(ui->tableView->model()->index(ligne, 4)).toString();
    QString traitement1 = ui->tableView->model()->data(ui->tableView->model()->index(ligne, 5)).toString();
    QString nom = ui->UNom->text();
    QString prenom = ui->UNom->text();
    QString maladie = ui->UMaladie->text();
    QString traitement = ui->UTraitement->toPlainText();
    Fiche *f =new Fiche();
    f->modifierFiche(cin,nom,prenom,maladie1+","+maladie,traitement1+","+traitement);


}

void MainWindow::on_BtnAjouterAuBilan_clicked()
{
    QString d= QDate::currentDate().toString();
    Bilan *b =new Bilan(0,"visite","TVA",60,8,d);

    int num_bilan=b->creat_ID();
    qDebug()<<num_bilan;
    b->setNum_Bilan(num_bilan);

    b->setCharge(ui->charge->text().toInt());
    b->setRecette(ui->recette->text().toInt());
    b->setNom_Charge(ui->titreCharge->text());
    b->setNom_Recette(ui->titreRecette->text());
    b->setDate(d);
    qDebug()<<"bilan";

    if(ui->recette->text().toInt()== NULL && ui->charge->text().toInt()==NULL){
        QMessageBox::critical(nullptr, QObject::tr("Erreur "),
                           QObject::tr("Verifier vos donnés.\n"
                                       "cliqué ok pour continuer."), QMessageBox::Ok);
    }else{
        QMessageBox::information(nullptr, QObject::tr("Bien ajouté "),
                           QObject::tr("les donnés sont bien ajoutées.\n"
                                       "cliqué ok pour continuer."), QMessageBox::Ok);
        b->ajouter_Bilan(*b);
    }




}

void MainWindow::on_pushButton_9_clicked()
{
    Bilan *b =new Bilan();
    float GS = b->gainSum();
    float CS = b->chargeSum();
ui->tableView_2->setModel(b->afficherAll());
qDebug()<<( QString::number(b->chargeSum()) );
qDebug()<<( QString::number(b->gainSum()) );
qDebug()<< b->diff(GS,CS);
//b->pdf();

}

void MainWindow::on_pushButton_7_clicked()
{
    int ligne = ui->tableView_2->currentIndex().row();
    int num = ui->tableView_2->model()->data(ui->tableView_2->model()->index(ligne, 0)).toInt();
    Bilan * b=new Bilan();
    if(b->supprimerBilan(num)){
        b->afficherAll();
        QMessageBox::information(nullptr, QObject::tr("Supprimer "),
                           QObject::tr("le bilan est bien supprimé.\n"
                                       "cliqué ok pour quitter."), QMessageBox::Ok);
    }
}

void MainWindow::on_pushButton_6_clicked()
{
    int ligne = ui->tableView_2->currentIndex().row();
    QString nom_recette = ui->tableView_2->model()->data(ui->tableView_2->model()->index(ligne, 1)).toString();
    int recette = ui->tableView_2->model()->data(ui->tableView_2->model()->index(ligne, 2)).toInt();
    QString nom_charge = ui->tableView_2->model()->data(ui->tableView_2->model()->index(ligne, 3)).toString();
    int charge = ui->tableView_2->model()->data(ui->tableView_2->model()->index(ligne, 4)).toInt();

    ui->U_Nom_R->setText(nom_recette);
    ui->U_R->setText(QString::number(recette));
    ui->U_Nom_C->setText(nom_charge);
    ui->U_C->setText(QString::number(charge));
}

void MainWindow::on_pushButton_8_clicked()
{
    int ligne = ui->tableView_2->currentIndex().row();
    int num = ui->tableView_2->model()->data(ui->tableView_2->model()->index(ligne, 0)).toInt();
    QString nom_r =ui->U_Nom_R->text() ;
    QString nom_c =ui->U_Nom_C->text() ;
    int r = ui->U_R->text().toInt();
    int c = ui->U_C->text().toInt();
    Bilan *b =new Bilan();
    b->modifierBilan(num,nom_r,nom_c,r,c);
}

// transition buttons

void MainWindow::on_pushButton_2_clicked()
{
    ui->F_C_FModules->setCurrentIndex(1);
}
void MainWindow::on_pushButton_13_clicked()
{
    ui->F_C_FModules->setCurrentIndex(1);
}

void MainWindow::on_pushButton_3_clicked()
{
    ui->F_C_FModules->setCurrentIndex(3);
}
void MainWindow::on_pushButton_16_clicked()
{
    ui->F_C_FModules->setCurrentIndex(3);
}
void MainWindow::on_signUp_clicked()
{
    ui->F_C_FModules->setCurrentIndex(4);
}
void MainWindow::on_pushButton_18_clicked()
{
    ui->F_C_FModules->setCurrentIndex(6);
}
void MainWindow::on_pushButton_20_clicked()
{
    ui->F_C_FModules->setCurrentIndex(7);
}
void MainWindow::on_pushButton_19_clicked()
{
    ui->F_C_FModules->setCurrentIndex(7);
}
void MainWindow::on_pushButton_23_clicked()
{
    ui->F_C_FModules->setCurrentIndex(7);
}
void MainWindow::on_pushButton_33_clicked()
{
    ui->F_C_FModules->setCurrentIndex(7);
}

void MainWindow::on_pushButton_34_clicked()
{
    ui->F_C_FModules->setCurrentIndex(10);
}
void MainWindow::on_pushButton_4_clicked()
{
    ui->F_C_FModules->setCurrentIndex(0);
    Fiche *f =new Fiche();
    ui->tableView->setModel(f->afficherAll());
}
void MainWindow::on_pushButton_14_clicked()
{
    ui->F_C_FModules->setCurrentIndex(0);
    Fiche *f =new Fiche();
    ui->tableView->setModel(f->afficherAll());
}
void MainWindow::on_pushButton_17_clicked()
{
    ui->F_C_FModules->setCurrentIndex(6);
}

void MainWindow::on_pushButton_clicked()
{
    ui->F_C_FModules->setCurrentIndex(2);
    Bilan *b =new Bilan();
    ui->tableView_2->setModel(b->afficherAll());
}
void MainWindow::on_pushButton_15_clicked()
{
    ui->F_C_FModules->setCurrentIndex(2);
    Bilan *b =new Bilan();
    ui->tableView_2->setModel(b->afficherAll());
}

void MainWindow::on_pushButton_22_clicked()
{
    ui->F_C_FModules->setCurrentIndex(7);
}

void MainWindow::on_pushButton_21_clicked()
{
    ui->F_C_FModules->setCurrentIndex(7);
}
void MainWindow::on_pushButton_10_clicked()
{
    Comptes *c =new Comptes();
    ui->tableView_3->setModel(c->afficherAll());
}
void MainWindow::on_pushButton_24_clicked()
{
    ui->F_C_FModules->setCurrentIndex(7);
}

void MainWindow::on_pushButton_25_clicked()
{
    ui->F_C_FModules->setCurrentIndex(7);
}
void MainWindow::on_pushButton_76_clicked()
{
    ui->F_C_FModules->setCurrentIndex(8);
}

void MainWindow::on_pushButton_78_clicked()
{
    ui->F_C_FModules->setCurrentIndex(10);
}

void MainWindow::on_pushButton_74_clicked()
{
    ui->F_C_FModules->setCurrentIndex(7);
}
void MainWindow::on_pushButton_75_clicked()
{
    ui->F_C_FModules->setCurrentIndex(11);
}

void MainWindow::on_pushButton_77_clicked()
{
    ui->F_C_FModules->setCurrentIndex(9);
}

void MainWindow::on_pushButton_80_clicked()
{
    ui->F_C_FModules->setCurrentIndex(7);
}

void MainWindow::on_pushButton_84_clicked()
{
    ui->F_C_FModules->setCurrentIndex(7);
}

void MainWindow::on_pushButton_85_clicked()
{
    ui->F_C_FModules->setCurrentIndex(7);
}

void MainWindow::on_pushButton_86_clicked()
{
    ui->F_C_FModules->setCurrentIndex(12);
}

void MainWindow::on_pushButton_83_clicked()
{
    ui->F_C_FModules->setCurrentIndex(13);
}

void MainWindow::on_pushButton_82_clicked()
{
    ui->F_C_FModules->setCurrentIndex(12);
}

void MainWindow::on_pushButton_81_clicked()
{
    ui->F_C_FModules->setCurrentIndex(13);
}
void MainWindow::on_pushButton_5_clicked()
{
    int cin = ui->C_Cin->text().toInt();
    QString nom = ui->C_Nom->text();
    QString prenom = ui->C_Prenom->text();
    QString mdp = ui->C_Mdp->text();
    QString email = ui->C_Email->text();
    if(cin==NULL||prenom==""||nom==""||mdp==""||email=="")
    {
        QMessageBox::critical(nullptr, QObject::tr("Contrainte "),
                           QObject::tr("Touts les champs sonts obligatoire !.\n"
                                       "cliqué ok pour continuer..."), QMessageBox::Ok);
    }else {
        Comptes * c = new Comptes(cin,nom,prenom,mdp,email);
        bool testExiste = c->trouverCompte(cin);
        if(testExiste){
            QMessageBox::critical(nullptr, QObject::tr("Existe "),
                               QObject::tr("le compte  est deja existante.\n"
                                           "cliqué ok pour quitter."), QMessageBox::Ok);
        }else {
            bool testAjout = c->ajouterCompte(*c);
            if(testAjout){
                QMessageBox::information(nullptr, QObject::tr("Compte Ajouté "),
                                   QObject::tr("Votre Compte est bien ajouté a votre base de donné.\n"
                                               "cliqué ok pour quitter."), QMessageBox::Ok);

            }
            ui->F_C_FModules->setCurrentIndex(7);
    }

}

}



void MainWindow::on_pushButton_11_clicked()
{
    int ligne = ui->tableView_3->currentIndex().row();
    int cin = ui->tableView_3->model()->data(ui->tableView_3->model()->index(ligne, 0)).toInt();
    Comptes *c =new Comptes();
    if(c->supprimerCompte(cin)){
        c->afficherAll();
        QMessageBox::information(nullptr, QObject::tr("supprimer "),
                           QObject::tr("le compte est est bien supprimer.\n"
                                       "cliqué ok pour quitter."), QMessageBox::Ok);
    }
}

void MainWindow::on_BtnArchiveFiche_clicked()
{
    int ligne = ui->tableView->currentIndex().row();
    int cin = ui->tableView->model()->data(ui->tableView->model()->index(ligne, 0)).toInt();
    QString nom = ui->tableView->model()->data(ui->tableView->model()->index(ligne, 1)).toString();
    QString prenom = ui->tableView->model()->data(ui->tableView->model()->index(ligne, 2)).toString();
    QString maladie = ui->tableView->model()->data(ui->tableView->model()->index(ligne, 3)).toString();
    QString traitement = ui->tableView->model()->data(ui->tableView->model()->index(ligne, 4)).toString();
    qDebug()<< nom;
    Fiche *a=new Fiche(cin,nom,prenom,maladie,traitement);
    Fiche* f = new Fiche();
    bool testArchive = a->archiverFiche(cin , nom , prenom , maladie , traitement);
        if(testArchive){
            QMessageBox::information(nullptr, QObject::tr("fiche Archiver "),
                               QObject::tr("la fiche est bien archiver.\n"
                                           "cliqué ok pour quitter."), QMessageBox::Ok);
        }
    a->archiverFiche(cin , nom , prenom , maladie , traitement);
    if(f->supprimerFiche(cin)){
        f->afficherAll();
        }
}


void MainWindow::on_BtnSearchFiche_clicked()
{
    QString key = ui->SearchLineEdit->text();
    Fiche* f = new Fiche();
    ui->tableView->setModel(f->rechercheFiche(key));
}

void MainWindow::on_BtnSearchBilan_clicked()
{
    QString key = ui->SearchLineEdit_2->text();
    Bilan* b = new Bilan();
    ui->tableView_2->setModel(b->rechercheBilan(key));
}

void MainWindow::on_BtnArchiveCompte_clicked()
{
    int ligne = ui->tableView_3->currentIndex().row();
    int cin = ui->tableView_3->model()->data(ui->tableView_3->model()->index(ligne, 0)).toInt();
    QString nom = ui->tableView_3->model()->data(ui->tableView_3->model()->index(ligne, 1)).toString();
    QString prenom = ui->tableView_3->model()->data(ui->tableView_3->model()->index(ligne, 2)).toString();
    QString mdp = ui->tableView_3->model()->data(ui->tableView_3->model()->index(ligne, 3)).toString();
    QString email = ui->tableView_3->model()->data(ui->tableView_3->model()->index(ligne, 4)).toString();
    qDebug()<< nom;
    Comptes *a=new Comptes(cin,nom,prenom,mdp,email);
    Comptes* c = new Comptes();
    bool testArchive = a->archiverCompte(cin , nom , prenom , mdp , email);
        if(testArchive){
            QMessageBox::information(nullptr, QObject::tr("Compte Archiver "),
                               QObject::tr("le compte est bien archiver.\n"
                                           "cliqué ok pour quitter."), QMessageBox::Ok);
        }
    a->archiverCompte(cin , nom , prenom , mdp , email);
    if(c->supprimerCompte(cin)){
        c->afficherAll();
        }
    ui->tableView_3->setModel(c->afficherAll());
}

void MainWindow::on_BtnSearchFiche_2_clicked()
{
    Fiche *f =new Fiche();
    if ((!(ui->cinCheckBox->isChecked())&&!(ui->nomCheckBox->isChecked())&&!(ui->prenomCheckBox->isChecked())&&!(ui->maladieCheckBox->isChecked())&&!(ui->traitementCheckBox->isChecked()))){
    ui->tableView->setModel(f->afficherAll());
    }
    if (ui->cinCheckBox->isChecked()){
       ui->tableView->setModel(f->rechercheFicheCin());
    }
    if (ui->nomCheckBox->isChecked()){
       ui->tableView->setModel(f->rechercheFicheNom());
    }
    if (ui->prenomCheckBox->isChecked()){
       ui->tableView->setModel(f->rechercheFichePrenom());
    }
    if (ui->maladieCheckBox->isChecked()){
       ui->tableView->setModel(f->rechercheFicheMaladie());
    }
    if (ui->traitementCheckBox->isChecked()){
       ui->tableView->setModel(f->rechercheFicheTraitement());
    }

}




void MainWindow::on_seConnecterBtn_clicked()
{
    Comptes* c = new Comptes();
    QString email = ui->Email->text();
    bool testEmailExiste = c->testEmail(email);
    QString mdp = ui->Password->text();

    bool testMdpExiste = c->testMdp(mdp);
    if(email==NULL||mdp==NULL)
    {
        QMessageBox::critical(nullptr, QObject::tr("Contrainte "),
                           QObject::tr("Touts les champs sonts obligatoire !.\n"
                                       "cliqué ok pour continuer..."), QMessageBox::Ok);
    }else {

        if(!testEmailExiste){
            QMessageBox::warning(nullptr, QObject::tr("Echec "),
                               QObject::tr("le compte n'exist pas.\n"
                                           "cliqué ok pour quitter."), QMessageBox::Ok);
        }else if (!testMdpExiste){
            QMessageBox::warning(nullptr, QObject::tr("Echec "),
                               QObject::tr("le mot de passe est incorrect.\n"
                                           "cliqué ok pour quitter."), QMessageBox::Ok);
        }else
            ui->F_C_FModules->setCurrentIndex(7);
            }
    }



void MainWindow::on_formPdf_clicked()
{
    Bilan *b =new Bilan();
    float g = b->gainSum();
    float c = b->chargeSum();
    float d = b->diff(g,c);
    QString r;
    QString GS = QString::number(g);
    QString CS = QString::number(c);
    QString D = QString::number(d);
qDebug()<<( QString::number(b->chargeSum()) );
qDebug()<<( QString::number(b->gainSum()) );
qDebug()<< b->diff(g,c);

    if(g>c){
        r="un gain de";
    }else if (g<c){
        r="une perte de";
    }else{
        r="ni gain ni perte";
    }

    QPdfWriter pdf ("D:/esprit/projects/QT/Work/E-Health/bilan.pdf");
    QPainter painter (&pdf);

    painter.setFont(QFont("Times",10));
    painter.setPen(Qt::blue);
    painter.drawText(4000,100,"Bilan Financiere");
    painter.setPen(Qt::red);
    painter.drawText(100,400,"Charge");
    painter.setPen(Qt::black);
    painter.drawText(1000,400,CS);
    painter.setPen(Qt::red);
    painter.drawText(100,600,"Recette");
    painter.setPen(Qt::black);
    painter.drawText(1000,600,GS);
    painter.setPen(Qt::red);
    painter.drawText(100,800,"Gain");
    painter.setPen(Qt::black);
    painter.drawText(1000,800,r);
    painter.setPen(Qt::black);
    painter.drawText(1900,800,D);
    painter.end();

}


// yassin
void MainWindow::on_jouterfm_clicked()
{
    QString ID= ui->L1->text();
    QString NOM= ui->L2->text();
    QString SYMPTOMES= ui->L3->text();
    QString CAUSES= ui->L4->text();


 Maladie f(ID,NOM,SYMPTOMES,CAUSES);

  bool test=f.ajouter();

  if(test)
{

     // ui->filmtable->setModel(tmpfilm.afficher());
          //player = new QMediaPlayer(this);
         // player->setMedia(QUrl::fromLocalFile("C:/Users/seifi/OneDrive/Desktop/mp3.mp3"));
          //qDebug() << player->errorString();
         // player->setVolume(100);
          //player->play();
QMessageBox::information(nullptr, QObject::tr("Maladie Ajoutee"),
                  QObject::tr("Maladie Ajoutee"), QMessageBox::Ok);
ui->maladietable->setModel(tmpmaladie.afficher());


}
  else
      QMessageBox::critical(nullptr, QObject::tr("Maladie Ajoutee"),
                  QObject::tr("Operation Echoue"), QMessageBox::Ok);

}

void MainWindow::on_ajout_maisondeproduction_clicked()
{
    QString ID= ui->id->text();
    QString REF= ui->ref->text();
    QString DATECRE= ui->date->text();



 dossiermedicale f(ID,REF,DATECRE);

  bool test=f.ajouter();

  if(test)
{

     // ui->filmtable->setModel(tmpfilm.afficher());
          //player = new QMediaPlayer(this);
         // player->setMedia(QUrl::fromLocalFile("C:/Users/seifi/OneDrive/Desktop/mp3.mp3"));
          //qDebug() << player->errorString();
         // player->setVolume(100);
          //player->play();
QMessageBox::information(nullptr, QObject::tr("Dossier Ajoutee"),
                  QObject::tr("Dossier Ajoutee"), QMessageBox::Ok);
ui->dossiertable->setModel(tmpdossier.afficher());


}
  else
      QMessageBox::critical(nullptr, QObject::tr("Maladie Ajoutee"),
                  QObject::tr("Operation Echoue"), QMessageBox::Ok);
}

void MainWindow::on_jouterfm_2_clicked()
{
    QString ID= ui->idm->text();
    QString Nom= ui->nomm->text();
    QString SYMPTOMES= ui->symm->text();
    QString CAUSES= ui->causem->text();

  bool test=tmpmaladie.update(ID, Nom, SYMPTOMES, CAUSES);
  if(test)
{

      ui->maladietable->setModel(tmpmaladie.afficher());
      //player = new QMediaPlayer(this);
         // player->setMedia(QUrl::fromLocalFile("C:/Users/seifi/OneDrive/Desktop/mp3.mp3"));
          //qDebug() << player->errorString();
         // player->setVolume(100);
         // player->play();
QMessageBox::information(nullptr, QObject::tr("Ajouter unu Maladie"),
                  QObject::tr("Maladie modifier.\n"
                              "Click Cancel to exit."), QMessageBox::Cancel);
ui->dossiertable->setModel(tmpdossier.afficher());


}
  else
      QMessageBox::critical(nullptr, QObject::tr("Ajouter un FIlm"),
                  QObject::tr("Operation Echoue\n"
                              "Click Cancel to exit."), QMessageBox::Cancel);
}

void MainWindow::on_Mod_maisondeproduction_clicked()
{
    QString ID= ui->IDM_2->text();
    QString REF= ui->DIRM_2->text();
    QString DATECRE= ui->NOMM_2->text();


  bool test=tmpdossier.update(ID, REF, DATECRE);
  if(test)
{

      ui->maladietable->setModel(tmpmaladie.afficher());
      //player = new QMediaPlayer(this);
         // player->setMedia(QUrl::fromLocalFile("C:/Users/seifi/OneDrive/Desktop/mp3.mp3"));
          //qDebug() << player->errorString();
         // player->setVolume(100);
         // player->play();
QMessageBox::information(nullptr, QObject::tr("Modifier un Dossier"),
                  QObject::tr("Modifier un Dossier.\n"
                              "Click Cancel to exit."), QMessageBox::Cancel);
ui->dossiertable->setModel(tmpdossier.afficher());


}
  else
      QMessageBox::critical(nullptr, QObject::tr("Modifier un Dossier"),
                  QObject::tr("Operation Echoue\n"
                              "Click Cancel to exit."), QMessageBox::Cancel);
}


void MainWindow::on_suppm_clicked()
{
    QString ID = ui->filmsup->text();
    bool test=tmpmaladie.supprimer(ID);
    if(test)
       {// player = new QMediaPlayer(this);
            //player->setMedia(QUrl::fromLocalFile("C:/Users/seifi/OneDrive/Desktop/mp3.mp3"));
            //qDebug() << player->errorString();
           // player->setVolume(100);
           // player->play();
        ui->maladietable->setModel(tmpmaladie.afficher());//refresh
        QMessageBox::information(nullptr, QObject::tr("Supprimer effectuer"),
                    QObject::tr("maladie supprime.\n"), QMessageBox::Ok);


    }
    else
        QMessageBox::critical(nullptr, QObject::tr("Supprimer erronée"),
                    QObject::tr("Erreur Film introuveable  !.\n"), QMessageBox::Cancel);

}
void MainWindow::on_pushButton_35_clicked()
{
    Maladie *m =new Maladie();
ui->maladietable->setModel(m->afficher());

}

void MainWindow::on_pushButton_36_clicked()
{
    dossiermedicale *d =new dossiermedicale();
ui->dossiertable->setModel(d->afficher());
}
void MainWindow::on_deletemdp_clicked()
{
    QString ID = ui->delmaison->text();
    bool test=tmpdossier.supprimer(ID);
    if(test)
       {// player = new QMediaPlayer(this);
            //player->setMedia(QUrl::fromLocalFile("C:/Users/seifi/OneDrive/Desktop/mp3.mp3"));
            //qDebug() << player->errorString();
           // player->setVolume(100);
           // player->play();

        QMessageBox::information(nullptr, QObject::tr("Supprimer effectuer"),
                    QObject::tr("maladie supprime.\n"), QMessageBox::Ok);
        ui->dossiertable->setModel(tmpdossier.afficher());

    }
    else
        QMessageBox::critical(nullptr, QObject::tr("Supprimer erronée"),
                    QObject::tr("Erreur Film introuveable  !.\n"), QMessageBox::Cancel);
}

void MainWindow::on_afficher1_clicked()
{
    ui->filmtable_4->setModel(tmpmaladie.afficher());
   // player = new QMediaPlayer(this);
     //   player->setMedia(QUrl::fromLocalFile("C:/Users/seifi/OneDrive/Desktop/mp3.mp3"));
      //  qDebug() << player->errorString();
      //  player->setVolume(100);
     //   player->play();


   if(ui->rechercherparid->isChecked())
      {
       QString ID= ui->ID1->text();
       ui->filmtable_4->setModel(tmpmaladie.afficher1(ID));

      }
   else if (ui->recherceparnom->isChecked())
   {
       QString Nom= ui->ID1->text();
       ui->filmtable_4->setModel(tmpmaladie.afficher2(Nom));

   }
   else if (ui->rechercheparns->isChecked())
   {
       QString SYMPTOMES= ui->ID1->text();
       ui->filmtable_4->setModel(tmpmaladie.afficher3(SYMPTOMES));
   }
}

void MainWindow::on_Trier_clicked()
{
    ui->maladietable->setModel(tmpmaladie.afficher());
   // player = new QMediaPlayer(this);
     //   player->setMedia(QUrl::fromLocalFile("C:/Users/seifi/OneDrive/Desktop/mp3.mp3"));
      //  qDebug() << player->errorString();
      //  player->setVolume(100);
       // player->play();
    if(ui->radioButton->isChecked())
       {
        ui->filmtable_2->setModel(tmpmaladie.affichercr());

       }
    else if (ui->radioButton_2->isChecked())
    {
        ui->filmtable_2->setModel(tmpmaladie.afficherdc());

    }
    else if (ui->radioButton_3->isChecked())
    {
        ui->filmtable_2->setModel(tmpmaladie.afficherdu());
    };



}


void MainWindow::on_pushButton_12_clicked()
{
    QString fileName = QFileDialog::getSaveFileName(this, tr("Excel file"), qApp->applicationDirPath (),

                                                          tr("Excel Files (*.xls)"));

          if (fileName.isEmpty())

              return;



          ExportExcelObject obj(fileName, "mydata", ui->maladietable);


          //colums to export

          obj.addField(0, "ID", "char(20)");

          obj.addField(1, "Nom", "char(20)");

          obj.addField(2, "SYMPTOMES", "char(20)");
          obj.addField(3, "CAUSES", "char(20)");






          int retVal = obj.export2Excel();

          if( retVal > 0)

          {

              QMessageBox::information(this, tr("Done"),

                                       QString(tr("%1 records exported!")).arg(retVal)

                                       );

          }
}

// aziz
void MainWindow::on_Ajout_medic_2_clicked()
{
    QString nom = ui->le_nom_3->text();
    QString prix = ui->le_prix_2->text();
    QString CasUtilisation = ui->le_cas_2->text();

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

void MainWindow::on_Supprimer_medic_2_clicked()
{
    QString nom = ui->le_medic_supp_2->text();
    bool test = tmpmedic.supprimer(nom);
    if (test)
    {
        ui->table_medic_2->setModel(tmpmedic.afficher());
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

void MainWindow::on_Modifier_medic_2_clicked()
{
    QString nom = ui->le_nom_3->text();
    QString prix = ui->le_prix_2->text();
    QString CasUtilisation = ui->le_cas_2->text();

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

void MainWindow::on_Afficher_medic_2_clicked()
{
    medicament mdc;

    ui->table_medic_2->setModel(mdc.afficher());
}

void MainWindow::on_Trier_medic_2_clicked()
{
         ui->table_medic_2->setModel(tmpmedic.afficher_medicament_trier());
}

void MainWindow::on_pushButton_71_clicked()
{
         ui->table_medic_2->setModel(tmpmedic.medicament_trier_prix());
}

void MainWindow::on_pushButton_72_clicked()
{
        ui->table_medic_2->setModel(tmpmedic.medicament_trier_cas());
}

void MainWindow::on_pb_recherche_2_clicked()
{
    QString nom = ui->le_nom_rech_2->text();
    ui->table_rech_mdc_2->setModel(tmpmedic.rechercher_medicament(nom));
    ui->table_medic_2->setModel(tmpmedic.afficher());
}


//maladie1
void MainWindow::on_Ajout_maladie_2_clicked()
{
    QString nom = ui->le_nom_4->text();
    QString cause = ui->le_cause_2->text();
    QString symptome = ui->le_symptome_2->text();

    maladie1 mld(nom, cause, symptome);

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

void MainWindow::on_Modifier_maladie_2_clicked()
{
    QString nom = ui->le_nom_4->text();
    QString cause = ui->le_cause_2->text();
    QString symptome = ui->le_symptome_2->text();

    maladie1 mld(nom, cause, symptome);

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

void MainWindow::on_Afficher_maladie_2_clicked()
{
    maladie1 mld;

    ui->table_maladie_2->setModel(mld.afficher());
}

void MainWindow::on_Supp_maladie_2_clicked()
{
    QString nom = ui->le_supp_2->text();

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

void MainWindow::on_rechercher_maladie_2_clicked()
{
    QString nom = ui->le_nom_rech_maladie_2->text();
    ui->table_rech_mld_2->setModel(tmpmld.rechercher_maladie1(nom));
    ui->table_maladie_2->setModel(tmpmld.afficher());
}

//son
void MainWindow::on_pushButton_73_clicked()
{
    son->play();
}

void MainWindow::on_Printer_2_clicked()
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
                 double xscale = double(ui->table_medic_2->width() / 65);
                 double yscale = double(ui->table_medic_2->height() / 65);
                 painter.scale(xscale, yscale);
                 ui->table_medic_2->render(&painter);
                 painter.end();
             }
             else
             {
                 qWarning("failed to open file");
                QMessageBox::warning(nullptr,QObject::tr("PDF echoue"),QObject::tr("click cancel to exit!"),QMessageBox::Cancel);
             }
          }
}

void MainWindow::on_Print_malad_2_clicked()
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
                 double xscale = double(ui->table_medic_2->width() / 65);
                 double yscale = double(ui->table_medic_2->height() / 65);
                 painter.scale(xscale, yscale);
                 ui->table_maladie_2->render(&painter);
                 painter.end();
             }
             else
             {
                 qWarning("failed to open file");
                QMessageBox::warning(nullptr,QObject::tr("PDF echoue"),QObject::tr("click cancel to exit!"),QMessageBox::Cancel);
             }
          }
}

//ahmed

void MainWindow::on_BtnRefrech_2_clicked()
{
    patient *p =new patient();
ui->tableView_4->setModel(p->afficher());
}

void MainWindow::on_BtnAddPatient_4_clicked()
{
    int cin = ui->ECin_4->text().toInt();
    QString nom = ui->ENom_4->text();
    QString prenom = ui->EPrenom_4->text();
    QString dn = ui->EDn_4->text();
    QString civ = ui->ECiv_4->text();
    if(cin==NULL||prenom==""||nom==""||dn==""||civ=="")
    {
        QMessageBox::critical(nullptr, QObject::tr("Contrainte "),
                           QObject::tr("Touts les champs sonts obligatoire !.\n"
                                       "cliqué ok pour continuer..."), QMessageBox::Ok);
    }else {
        patient* p = new patient(cin,nom,prenom,dn,civ);
        bool testExiste = p->trouver(cin);
        if(testExiste){
            QMessageBox::critical(nullptr, QObject::tr("Existe "),
                               QObject::tr("le patient est deja existant.\n"
                                           "cliqué ok pour quitter."), QMessageBox::Ok);
        }else {
            bool testAjout = p->ajouter(*p);
            if(testAjout){
                QMessageBox::information(nullptr, QObject::tr("Patient Ajouté "),
                                   QObject::tr("le patient a été bien ajouté a votre base de donné.\n"
                                               "cliqué ok pour quitter."), QMessageBox::Ok);
            }
    }
}
}

void MainWindow::on_pushButton_26_clicked()
{
    ui->F_C_FModules->setCurrentIndex(10);
}

void MainWindow::on_pushButton_79_clicked()
{
    ui->F_C_FModules->setCurrentIndex(9);
    patient *p =new patient();
    ui->tableView_4->setModel(p->afficher());
}

void MainWindow::on_BtnDeletePatient_clicked()
{
    int ligne = ui->tableView_4->currentIndex().row();
    int cin = ui->tableView_4->model()->data(ui->tableView_4->model()->index(ligne, 0)).toInt();
    patient *p =new patient();
    if(p->supprimer(cin)){
        p->afficher();
        QMessageBox::information(nullptr, QObject::tr("Existe "),
                           QObject::tr("le patient est bien supprimer.\n"
                                       "cliqué ok pour quitter."), QMessageBox::Ok);
    }

}


void MainWindow::on_BtnUpdatePatient_clicked()
{
    int ligne = ui->tableView_4->currentIndex().row();
    int cin = ui->tableView_4->model()->data(ui->tableView_4->model()->index(ligne, 0)).toInt();
    QString nom = ui->tableView_4->model()->data(ui->tableView_4->model()->index(ligne, 1)).toString();
    QString prenom = ui->tableView_4->model()->data(ui->tableView_4->model()->index(ligne, 2)).toString();
    QString dn = ui->tableView_4->model()->data(ui->tableView_4->model()->index(ligne, 3)).toString();
    QString civ = ui->tableView_4->model()->data(ui->tableView_4->model()->index(ligne, 4)).toString();
    qDebug()<< nom;

    ui->UNom_P->setText(nom);
    ui->UPrenom_P->setText(prenom);
    ui->UDn_P->setText(dn);
    ui->UCiv_P->setText(civ);
}

void MainWindow::on_BtnUpdatePatient_2_clicked()
{
    int ligne = ui->tableView_4->currentIndex().row();
    int cin = ui->tableView_4->model()->data(ui->tableView_4->model()->index(ligne, 0)).toInt();

    QString nom = ui->UNom_P->text();
    QString prenom = ui->UPrenom_P->text();
    QString dn = ui->UDn_P->text();
    QString civ = ui->UCiv_P->text();
    patient *p =new patient();
    p->modifier(cin,nom,prenom,dn,civ);

}


void MainWindow::on_BtnSearchPatient_clicked()
{
    QString key = ui->SearchLineEdit_3->text();
    patient* p = new patient();
    ui->tableView_4->setModel(p->recherchePatient(key));
}



void MainWindow::on_BtnAddMedecin_5_clicked()
{
    int cin = ui->ECin_5->text().toInt();
    QString nom = ui->ENom_5->text();
    QString prenom = ui->EPrenom_5->text();
    QString maladie = ui->EMail_5->text();
    QString traitement = ui->EAdresse_5->text();
    if(cin==NULL||prenom==""||nom==""||maladie==""||traitement=="")
    {
        QMessageBox::critical(nullptr, QObject::tr("Contrainte "),
                           QObject::tr("Touts les champs sonts obligatoire !.\n"
                                       "cliqué ok pour continuer..."), QMessageBox::Ok);
    }else {
        medecin* m = new medecin(cin,nom,prenom,maladie,traitement);
        bool testExiste = m->trouverMedecin(cin);
        if(testExiste){
            QMessageBox::critical(nullptr, QObject::tr("Existe "),
                               QObject::tr("le medecin est deja existante.\n"
                                           "cliqué ok pour quitter."), QMessageBox::Ok);
        }else {
            bool testAjout = m->ajouterMedecin(*m);
            if(testAjout){
                QMessageBox::information(nullptr, QObject::tr("Medecin Ajoutée "),
                                   QObject::tr("le medecin a été bien ajoutée a votre base de donné.\n"
                                               "cliqué ok pour quitter."), QMessageBox::Ok);
            }
    }
    }
}

void MainWindow::on_BtnRefrech_3_clicked()
{
    medecin *m =new medecin();
ui->tableView_8->setModel(m->afficherAll());
}

void MainWindow::on_BtnDeleteMedecin_clicked()
{
    int ligne = ui->tableView_8->currentIndex().row();
    int cin = ui->tableView_8->model()->data(ui->tableView_8->model()->index(ligne, 0)).toInt();
    medecin *m =new medecin();
    if(m->supprimerMedecin(cin)){
        m->afficherAll();
        QMessageBox::information(nullptr, QObject::tr("Existe "),
                           QObject::tr("le medecin est bien supprimer.\n"
                                       "cliqué ok pour quitter."), QMessageBox::Ok);
    }
}


void MainWindow::on_BtnUpdateMed_clicked()
{
    int ligne = ui->tableView_8->currentIndex().row();
    int cin = ui->tableView_8->model()->data(ui->tableView_8->model()->index(ligne, 0)).toInt();
    QString nom = ui->tableView_8->model()->data(ui->tableView_8->model()->index(ligne, 1)).toString();
    QString prenom = ui->tableView_8->model()->data(ui->tableView_8->model()->index(ligne, 2)).toString();
    QString email = ui->tableView_8->model()->data(ui->tableView_8->model()->index(ligne, 3)).toString();
    QString adresse = ui->tableView_8->model()->data(ui->tableView_8->model()->index(ligne, 4)).toString();
    qDebug()<< nom;

    ui->UNom_M->setText(nom);
    ui->UPrenom_M->setText(prenom);
    ui->UEmail_M->setText(email);
    ui->UAdresse_M->setText(adresse);

}


void MainWindow::on_BtnUpdateMed_2_clicked()
{
    int ligne = ui->tableView_8->currentIndex().row();
    int cin = ui->tableView_8->model()->data(ui->tableView_8->model()->index(ligne, 0)).toInt();

    QString nom = ui->UNom_M->text();
    QString prenom = ui->UPrenom_M->text();
    QString email = ui->UEmail_M->text();
    QString adresse = ui->UAdresse_M->text();
    medecin *m =new medecin();
    m->modifierMedecin(cin,nom,prenom,email,adresse);

}


void MainWindow::on_BtnSearchMedecin_clicked()
{
    QString key = ui->SearchLineEdit_5->text();
    medecin* m = new medecin();
    ui->tableView_8->setModel(m->rechercheMedecin(key));
}
