#include "fiche.h"
#include <QSqlDatabase>
#include <QSql>
#include <QVector>
#include<QVariant>
#include <memory>
#include <QCheckBox>

Fiche::Fiche(){}
Fiche::Fiche(int cin_client,QString nom, QString prenom_client, QString maladie_client , QString traitement_client){
    this->cin_client=cin_client;
    this->nom_client=nom;
    this->prenom_client=prenom_client;
    this->maladie_client=maladie_client;
    this->traitement_client=traitement_client;
}
int Fiche::getCin_client(){
    return this->cin_client;
}

QString Fiche::getNom_client(){
    return this->nom_client;
}

QString Fiche::getPrenom_client(){
    return this->prenom_client;
}

QString Fiche::getMaladie_client(){
    return this->maladie_client;
}

QString Fiche::getTraitement_client(){
    return this->traitement_client;
}

void Fiche::setCin_client(int cin_client){
    this->cin_client=cin_client;
}

void Fiche::setNom_client(QString nom_client){
    this->nom_client=nom_client;
}

void Fiche::setPrenom_client(QString prenom_client){
    this->prenom_client=prenom_client;
}

void Fiche::setMaladie_client(QString maladie_client){
    this->maladie_client=maladie_client;
}

void Fiche::setTraitement_client(QString traitement_client){
    this->traitement_client=traitement_client;
}

bool Fiche::ajouterFiche(Fiche fiche){
    QSqlQuery query;
        query.prepare("INSERT INTO FICHE (CIN_CLIENT, NOM, PRENOM ,MALADIE ,TRAITEMENT) "
                      "VALUES (:CIN_CLIENT, :NOM, :PRENOM, :MALADIE, :TRAITEMENT)");

        query.bindValue(":CIN_CLIENT", fiche.getCin_client());
        query.bindValue(":NOM", fiche.getNom_client());
        query.bindValue(":PRENOM", fiche.getPrenom_client());
        query.bindValue(":MALADIE", fiche.getMaladie_client());
        query.bindValue(":TRAITEMENT", fiche.getTraitement_client());

        query.exec();
}

bool Fiche::trouverFiche(int cin){
    QSqlQuery query;
    query.prepare("SELECT * FROM FICHE WHERE CIN_CLIENT = :CIN_CLIENT ");
    query.bindValue(":CIN_CLIENT",cin);
    query.exec();
    if(query.exec())
        while(query.next()){
                       return true;
               }
               return false;
}

bool Fiche::supprimerFiche(int cin){
    QSqlQuery  query;
   query.prepare("DELETE FROM FICHE WHERE CIN_CLIENT = '" + QString::number(cin) + "'");

    query.exec();
}

QSqlQueryModel * Fiche::afficherAll(){
    QSqlQueryModel * model= new QSqlQueryModel();

    model->setQuery("select * from FICHE");
    model->setHeaderData(0, Qt::Horizontal, QObject::tr("CIN_PATIENT"));
    model->setHeaderData(1, Qt::Horizontal, QObject::tr("NOM_PATIENT"));
    model->setHeaderData(2, Qt::Horizontal, QObject::tr("PRENOM_PATIENT"));
    model->setHeaderData(3, Qt::Horizontal, QObject::tr("MALADIE"));
    model->setHeaderData(4, Qt::Horizontal, QObject::tr("TRAITEMENT"));
        return model;
}

QString  Fiche::trouverChamp(QString word , int cin){
    QSqlQuery query;
    query.prepare("SELECT" +word+" FROM FICHE WHERE CIN_CLIENT = :CIN_CLIENT ");
    query.bindValue(":CIN_CLIENT",cin);

    query.exec();
    QString ret= query.value(0).toString();
    return ret;

}

bool Fiche::modifierFiche(int cin , QString nom , QString prenom , QString maladie , QString traitement){
    QSqlQuery query;
    query.prepare("update FICHE set nom =:nom,prenom=:prenom,maladie=:maladie,traitement=:traitement"
                      " where CIN_CLIENT=:CIN_CLIENT");

        query.bindValue(":nom",nom);
        query.bindValue(":prenom",prenom);
        query.bindValue(":maladie",maladie);
        query.bindValue(":traitement",traitement);
        query.bindValue(":CIN_CLIENT",cin);

       return query.exec();
}

bool Fiche::archiverFiche(int cin , QString nom , QString prenom , QString maladie , QString traitement){
    QSqlQuery query;
        query.prepare("update FICHE set nom =:nom,prenom=:prenom,maladie=:maladie,traitement=:traitement"
                      " where CIN_CLIENT=:CIN_CLIENT");
        query.prepare("INSERT INTO ARCHIVE_FICHE (CIN_CLIENT, NOM, PRENOM ,MALADIE ,TRAITEMENT) "
                      "VALUES (:CIN_CLIENT, :NOM, :PRENOM, :MALADIE, :TRAITEMENT)");

        query.bindValue(":CIN_CLIENT", cin);
        query.bindValue(":NOM", nom);
        query.bindValue(":PRENOM", prenom);
        query.bindValue(":MALADIE", maladie);
        query.bindValue(":TRAITEMENT", traitement);

        query.exec();
}

QSqlQueryModel *Fiche::rechercheFiche(QString key){
    QSqlQueryModel * model= new QSqlQueryModel();
    model->setQuery("SELECT * FROM FICHE WHERE CIN_CLIENT LIKE '%"+key+"%' OR NOM LIKE '%"+key+"%'OR PRENOM LIKE '%"+key+"%' OR MALADIE LIKE '%"+key+"%' OR TRAITEMENT LIKE '%"+key+"%'");

    model->setHeaderData(0, Qt::Horizontal, QObject::tr("CIN_PATIENT"));
    model->setHeaderData(1, Qt::Horizontal, QObject::tr("NOM_PATIENT"));
    model->setHeaderData(2, Qt::Horizontal, QObject::tr("PRENOM_PATIENT"));
    model->setHeaderData(3, Qt::Horizontal, QObject::tr("MALADIE"));
    model->setHeaderData(4, Qt::Horizontal, QObject::tr("TRAITEMENT"));
        return model;
    }

QSqlQueryModel *Fiche::rechercheFicheCin(){
    QSqlQueryModel * model= new QSqlQueryModel();
    model->setQuery("SELECT CIN_CLIENT FROM FICHE");
    model->setHeaderData(0, Qt::Horizontal, QObject::tr("CIN_PATIENT"));
    return model;
    }

QSqlQueryModel * Fiche::rechercheFicheNom(){
    QSqlQueryModel * model= new QSqlQueryModel();
    model->setQuery("SELECT NOM FROM FICHE");
    model->setHeaderData(1,Qt::Horizontal, QObject::tr("NOM_PATIENT"));
        return model;
}

QSqlQueryModel *Fiche::rechercheFichePrenom(){
    QSqlQueryModel * model= new QSqlQueryModel();
    model->setQuery("SELECT PRENOM FROM FICHE");
    model->setHeaderData(2, Qt::Horizontal, QObject::tr("PRENOM_PATIENT"));
        return model;
    }

QSqlQueryModel *Fiche::rechercheFicheMaladie(){
    QSqlQueryModel * model= new QSqlQueryModel();
    model->setQuery("SELECT Maladie FROM FICHE");
    model->setHeaderData(3, Qt::Horizontal, QObject::tr("MALADIE"));
        return model;
    }

QSqlQueryModel *Fiche::rechercheFicheTraitement(){
    QSqlQueryModel * model= new QSqlQueryModel();
    model->setQuery("SELECT traitement FROM FICHE");
    model->setHeaderData(4, Qt::Horizontal, QObject::tr("TRAITEMENT"));
        return model;
    }
