#include "patient.h"
#include <QSqlQueryModel>
#include <QSqlQueryModel>
#include "connexion.h"

patient::patient()
{
    nom="";
    prenom="";
    cin="";
    dn="";
    civ="";
}
patient::patient(QString nom,QString prenom,QString cin, QString civ, QString dn)
{
    this->cin=cin;
    this->nom=nom;
this->prenom=prenom;
this->dn=dn;
this->civ=civ;
}

patient::~patient(){}
QString patient :: getcin(){return cin;}
QString patient :: getnom(){return nom;}
QString patient :: getprenom(){return prenom;}
QString patient :: getciv(){return civ;}
QString patient :: getdn(){return dn;}
void patient :: setcin(QString c){cin = c;}
void patient :: setnom(QString n){nom=n;}
void patient :: setprenom(QString p){prenom=p;}
void patient :: setciv(QString ec){civ=ec;}
void patient :: setdn(QString d){dn=d;}

bool patient::ajouter()
{
    QSqlQuery query;
    QString res=QString(nom);
    query.prepare("INSTER INTO PATIENT(NOM,PRENOM,DN,CIN,CIV)" "VALUES (:nom,:prenom,:dn,:cin,civ:)");
    query.bindValue(":NOM",nom);
    query.bindValue(":PRENOM",prenom);
    query.bindValue(":CIN",cin);
    query.bindValue(":CIV",civ);
    query.bindValue(":DN",dn);
    return query.exec();
}
