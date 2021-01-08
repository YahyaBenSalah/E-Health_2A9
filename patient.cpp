#include "patient.h"
#include <QSqlQueryModel>
#include <QSqlQueryModel>
#include "QSqlQuery"


patient::patient()
{
//    nom="";
//    prenom="";
//    cin=0;
//    dn="";
//    civ="";
}
patient::patient(int cin , QString nom,QString prenom, QString civ, QString dn)
{
    this->cin=cin;
    this->nom=nom;
this->prenom=prenom;
this->dn=dn;
this->civ=civ;
}

patient::~patient(){}
int patient :: getcin(){return this->cin;}
QString patient :: getnom(){return this->nom;}
QString patient :: getprenom(){return this->prenom;}
QString patient :: getciv(){return this->civ;}
QString patient :: getdn(){return this->dn;}
void patient :: setcin(int c){this->cin = c;}
void patient :: setnom(QString n){this->nom=n;}
void patient :: setprenom(QString p){this->prenom=p;}
void patient :: setciv(QString ec){this->civ=ec;}
void patient :: setdn(QString d){this->dn=d;}

bool patient::ajouter(patient patient)
{
    QSqlQuery query;
    query.prepare("INSERT INTO PATIENT(CIN,NOM,PRENOM,DN,CIV)" "VALUES (:CIN,:NOM,:PRENOM,:DN,:CIV)");
    query.bindValue(":CIN",patient.getcin());
    query.bindValue(":NOM",patient.getnom());
    query.bindValue(":PRENOM",patient.getprenom());
    query.bindValue(":DN",patient.getdn());
    query.bindValue(":CIV",patient.getciv());
    return query.exec();
}
bool patient::trouver(int cin){
    QSqlQuery query;
    query.prepare("SELECT * FROM PATIENT WHERE CIN = :CIN ");
    query.bindValue(":CIN",cin);
    query.exec();
    if(query.exec())
        while(query.next()){
                       return true;
               }
               return false;
}
bool patient::supprimer(int cin){
    QSqlQuery  query;
   query.prepare("DELETE FROM PATIENT WHERE CIN = '" + QString::number(cin) + "'");

    query.exec();
}

QSqlQueryModel * patient::afficher(){
    QSqlQueryModel * model= new QSqlQueryModel();

    model->setQuery("select * from PATIENT");
    model->setHeaderData(0, Qt::Horizontal, QObject::tr("CIN"));
    model->setHeaderData(1, Qt::Horizontal, QObject::tr("NOM"));
    model->setHeaderData(2, Qt::Horizontal, QObject::tr("PRENOM"));
    model->setHeaderData(3, Qt::Horizontal, QObject::tr("DN"));
    model->setHeaderData(4, Qt::Horizontal, QObject::tr("CIV"));
        return model;
}
QString  patient::trouverChamp(QString word , int cin){
    QSqlQuery query;
    query.prepare("SELECT" +word+" FROM PATIENT WHERE CIN = :CIN ");
    query.bindValue(":CIN",cin);

    query.exec();
    QString ret= query.value(0).toString();
    return ret;

}
bool patient::modifier(int cin , QString nom , QString prenom , QString dn , QString civ){
    QSqlQuery query;
    query.prepare("update PATIENT set nom =:nom,prenom=:prenom,dn=:dn,civ=:civ"
                      " where CIN=:CIN");

        query.bindValue(":CIN",cin);
        query.bindValue(":nom",nom);
        query.bindValue(":prenom",prenom);
        query.bindValue(":dn",dn);
        query.bindValue(":civ",civ);

       return query.exec();
}
QSqlQueryModel *patient::recherchePatient(QString key){
    QSqlQueryModel * model= new QSqlQueryModel();
    model->setQuery("SELECT * FROM PATIENT WHERE CIN LIKE '%"+key+"%' OR NOM LIKE '%"+key+"%'OR PRENOM LIKE '%"+key+"%' OR DN LIKE '%"+key+"%' OR CIV LIKE '%"+key+"%'");

    model->setHeaderData(0, Qt::Horizontal, QObject::tr("CIN"));
    model->setHeaderData(1, Qt::Horizontal, QObject::tr("NOM"));
    model->setHeaderData(2, Qt::Horizontal, QObject::tr("PRENOM"));
    model->setHeaderData(3, Qt::Horizontal, QObject::tr("DN"));
    model->setHeaderData(4, Qt::Horizontal, QObject::tr("CIV"));
        return model;
    }
