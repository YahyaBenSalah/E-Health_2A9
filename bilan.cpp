#include "bilan.h"
#include <QSqlDatabase>
#include <QSql>
#include <QVector>
#include<QVariant>
#include<QDebug>
#include <memory>
#include <QtCore>
#include <QTextDocument>
#include <QPdfWriter>
#include <QPainter>
#include <QTextCharFormat>
#include <QTextCursor>
#include <QPrinter>
#include <QDate>

Bilan::Bilan()
{

}
Bilan::Bilan(int Num_Bilan,QString Nom_Charge,QString Nom_Recette,int Charge,int Recette, QString date){
    this->Num_Bilan=Num_Bilan;
    this->Nom_Charge=Nom_Charge;
    this->Nom_Recette=Nom_Recette;
    this->Charge=Charge;
    this->Recette=Recette;
    this->date=QDate::currentDate().toString();
}
int Bilan::getNum_Bilan(){
    return this->Num_Bilan;
}
QString Bilan::getNom_Charge(){
    return this->Nom_Charge;
}
QString Bilan::getNom_Recette(){
    return this->Nom_Recette;
}
int Bilan::getCharge(){
    return this->Charge;
}
int Bilan::getRecette(){
    return this->Recette;
}
QString Bilan::getDate(){
    return this->date;
}
void Bilan::setDate(QString date){
    this->date=date;
}
void Bilan::setNom_Charge(QString nom_charge){
    this->Nom_Charge=nom_charge;
}
void Bilan::setNom_Recette(QString nom_recette){
    this->Nom_Recette=nom_recette;
}
void Bilan::setNum_Bilan(int num_bilan){
    this->Num_Bilan=num_bilan;
}
void Bilan::setRecette(int recette){
    this->Recette=recette;
}
void Bilan::setCharge(int charge){
    this->Charge=charge;
}

int Bilan::creat_ID(){
    QSqlQuery query;
    query.prepare("select max(NUM_BILAN) from BILAN");
    query.exec();
    qDebug()<< query.value(0).toInt();
    int i;
    while(query.next())
        {
            qDebug() << query.value(0).toInt();
            i=query.value(0).toInt()+1;
        }

    return i;
}

bool Bilan::ajouter_Bilan(Bilan bilan){
    QSqlQuery query;
        query.prepare("INSERT INTO BILAN (NUM_BILAN, NOM_RECETTE ,RECETTE ,NOM_CHARGE,CHARGE ,EXACT_DATE) "
                      "VALUES (:NUM_BILAN, :NOM_RECETTE, :RECETTE, :NOM_CHARGE, :CHARGE, :EXACT_DATE)");

        query.bindValue(":NUM_BILAN", bilan.getNum_Bilan());
        query.bindValue(":NOM_RECETTE", bilan.getNom_Recette());
        query.bindValue(":RECETTE", bilan.getRecette());
        query.bindValue(":NOM_CHARGE", bilan.getNom_Charge());
        query.bindValue(":CHARGE", bilan.getCharge());
        query.bindValue(":EXACT_DATE", bilan.getDate());

        query.exec();
}

QSqlQueryModel * Bilan::afficherAll(){
    QSqlQueryModel * model= new QSqlQueryModel();

    model->setQuery("select * from BILAN");
    model->setHeaderData(0, Qt::Horizontal, QObject::tr("NUM_BILAN"));
    model->setHeaderData(1, Qt::Horizontal, QObject::tr("NOM_RECETTE"));
    model->setHeaderData(2, Qt::Horizontal, QObject::tr("RECETTE"));
    model->setHeaderData(3, Qt::Horizontal, QObject::tr("NOM_CHARGE"));
    model->setHeaderData(4, Qt::Horizontal, QObject::tr("CHARGE"));
    model->setHeaderData(5, Qt::Horizontal, QObject::tr("EXACT_DATE"));
        return model;
}

bool Bilan::supprimerBilan(int num){
    QSqlQuery  query;
   query.prepare("DELETE FROM BILAN WHERE NUM_BILAN = '" + QString::number(num) + "'");

    query.exec();
}

bool Bilan::modifierBilan(int num , QString nom_r , QString nom_c , int recette , int charge){
    QSqlQuery query;
    query.prepare("update BILAN set NOM_RECETTE =:nom_r , RECETTE =:recette , NOM_CHARGE =:nom_c , CHARGE =:charge "
                  " where NUM_BILAN=:num");

        query.bindValue(":nom_r",nom_r);
        query.bindValue(":recette",QString::number(recette).toInt());
        query.bindValue(":nom_c",nom_c);
        query.bindValue(":charge",QString::number(charge).toInt());
        query.bindValue(":num",num);
       return query.exec();
}

QSqlQueryModel *Bilan::rechercheBilan(QString key){
    QSqlQueryModel * model= new QSqlQueryModel();
    model->setQuery("SELECT * FROM BILAN WHERE NUM_BILAN LIKE '%"+key+"%' OR NOM_RECETTE LIKE '%"+key+"%'OR RECETTE LIKE '%"+key+"%' OR NOM_CHARGE LIKE '%"+key+"%' OR CHARGE LIKE '%"+key+"%' OR EXACT_DATE LIKE '%"+key+"%'");

    model->setHeaderData(0, Qt::Horizontal, QObject::tr("NUM_BILAN"));
    model->setHeaderData(1, Qt::Horizontal, QObject::tr("NOM_RECETTE"));
    model->setHeaderData(2, Qt::Horizontal, QObject::tr("RECETTE"));
    model->setHeaderData(3, Qt::Horizontal, QObject::tr("NOM_CHARGE"));
    model->setHeaderData(4, Qt::Horizontal, QObject::tr("CHARGE"));
    model->setHeaderData(5, Qt::Horizontal, QObject::tr("EXACT_DATE"));
        return model;
}

float Bilan::chargeSum(){
    QSqlQueryModel * model= new QSqlQueryModel();
    model->setQuery("SELECT CHARGE FROM BILAN");
    int result = 0;
        const int column = 0;
        for (int row = 0; row < model->rowCount(); ++row) {
            result += model->data(model->index(row, column)).toInt();
        }
        return result;
}
float Bilan::gainSum(){
    QSqlQueryModel * model= new QSqlQueryModel();
    model->setQuery("SELECT RECETTE FROM BILAN");
    int result = 0;
        const int column = 0;
        for (int row = 0; row < model->rowCount(); ++row) {
            result += model->data(model->index(row, column)).toInt();
        }
        return result;
}

float Bilan::diff(float GS, float CS){
    if ((GS - CS)>0){
        qDebug()<<"un gain de"<<GS - CS;
    }else if ((GS - CS)<0){
        qDebug()<<"une perte de"<<CS - GS;
    }else {
        qDebug()<<"ni perte ni gain";
    }
    return (GS-CS);
}


