#include "medecin.h"
#include <QSqlDatabase>
#include <QSql>
#include <QVector>
#include<QVariant>
#include <memory>
#include <QCheckBox>

medecin::medecin(){}
medecin::medecin(int cin, QString nom, QString prenom, QString email, QString adresse){
    this->cin=cin;
    this->nom=nom;
    this->prenom=prenom;
    this->email=email;
    this->adresse=adresse;
}
int medecin::getCin(){
    return this->cin;
}
QString medecin::getNom(){
    return this->nom;
}
QString medecin::getPrenom(){
    return this->prenom;
}
QString medecin::getEmail(){
    return this->email;
}
QString medecin::getAdresse(){
    return this->adresse;
}
void medecin::setCin(int cin){
    this->cin=cin;
}
void medecin::setNom(QString nom){
    this->nom=nom;
}
void medecin::setPrenom(QString prenom){
    this->prenom=prenom;
}
void medecin::setEmail(QString email){
    this->email=email;
}
void medecin::setAdresse(QString adresse){
    this->adresse=adresse;
}

bool medecin::ajouterMedecin(medecin medecin){
    QSqlQuery query;
        query.prepare("INSERT INTO MEDECIN (CIN, NOM, PRENOM ,EMAIL ,ADRESSE) "
                      "VALUES (:CIN, :NOM, :PRENOM, :EMAIL, :ADRESSE)");

        query.bindValue(":CIN", medecin.getCin());
        query.bindValue(":NOM", medecin.getNom());
        query.bindValue(":PRENOM", medecin.getPrenom());
        query.bindValue(":EMAIL", medecin.getEmail());
        query.bindValue(":ADRESSE", medecin.getAdresse());

        query.exec();
}

bool medecin::trouverMedecin(int cin){
    QSqlQuery query;
    query.prepare("SELECT * FROM MEDECIN WHERE CIN = :CIN ");
    query.bindValue(":CIN",cin);
    query.exec();
    if(query.exec())
        while(query.next()){
                       return true;
               }
               return false;
}

bool medecin::supprimerMedecin(int cin){
    QSqlQuery  query;
   query.prepare("DELETE FROM MEDECIN WHERE CIN = '" + QString::number(cin) + "'");

    query.exec();
}

QSqlQueryModel * medecin::afficherAll(){
    QSqlQueryModel * model= new QSqlQueryModel();

    model->setQuery("select * from MEDECIN");
    model->setHeaderData(0, Qt::Horizontal, QObject::tr("CIN"));
    model->setHeaderData(1, Qt::Horizontal, QObject::tr("NOM"));
    model->setHeaderData(2, Qt::Horizontal, QObject::tr("PRENOM"));
    model->setHeaderData(3, Qt::Horizontal, QObject::tr("EMAIL"));
    model->setHeaderData(4, Qt::Horizontal, QObject::tr("ADRESSE"));
        return model;
}

QString  medecin::trouverChamp(QString word , int cin){
    QSqlQuery query;
    query.prepare("SELECT" +word+" FROM MEDECIN WHERE CIN = :CIN ");
    query.bindValue(":CIN",cin);

    query.exec();
    QString ret= query.value(0).toString();
    return ret;

}

bool medecin::modifierMedecin(int cin, QString nom, QString prenom, QString email, QString adresse){
    QSqlQuery query;
    query.prepare("update MEDECIN set nom =:nom,prenom=:prenom,email=:email,adresse=:adresse"
                      " where CIN =:CIN");

        query.bindValue(":nom",nom);
        query.bindValue(":prenom",prenom);
        query.bindValue(":email",email);
        query.bindValue(":adresse",adresse);
        query.bindValue(":CIN",cin);

       return query.exec();
}

QSqlQueryModel *medecin::rechercheMedecin(QString key){
    QSqlQueryModel * model= new QSqlQueryModel();
    model->setQuery("SELECT * FROM MEDECIN WHERE CIN LIKE '%"+key+"%' OR NOM LIKE '%"+key+"%'OR PRENOM LIKE '%"+key+"%' OR EMAIL LIKE '%"+key+"%' OR ADRESSE LIKE '%"+key+"%'");

    model->setHeaderData(0, Qt::Horizontal, QObject::tr("CIN"));
    model->setHeaderData(1, Qt::Horizontal, QObject::tr("NOM"));
    model->setHeaderData(2, Qt::Horizontal, QObject::tr("PRENOM"));
    model->setHeaderData(3, Qt::Horizontal, QObject::tr("EMAIL"));
    model->setHeaderData(4, Qt::Horizontal, QObject::tr("ADRESSE"));
        return model;
    }
