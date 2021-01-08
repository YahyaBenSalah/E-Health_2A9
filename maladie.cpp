#include "maladie.h"
#include "dossiermedicale.h"
#include "QSqlQuery"
#include <QDebug>
#include "qsqltablemodel.h"
#include "QSqlQueryModel"
#include <iostream>



Maladie::Maladie()
{
}

Maladie::Maladie(QString ID,QString NOM,QString SYMPTOMES,QString CAUSES)
{
    this->ID=ID;
    this->NOM=NOM;
    this->SYMPTOMES=SYMPTOMES;
    this->CAUSES=CAUSES;

}

bool Maladie::ajouter()
{

QSqlQuery query;

query.prepare("INSERT INTO MALADIE (ID,SYMPTOMES, CAUSES,NOM) "
                    "VALUES (:ID, :SYMPTOMES, :CAUSES,:NOM)");
query.bindValue(":ID", ID);
query.bindValue(":SYMPTOMES", SYMPTOMES);
query.bindValue(":CAUSES", CAUSES);
query.bindValue(":NOM", NOM);

return    query.exec();
}

QSqlQueryModel * Maladie::afficher()
{
    QSqlQuery query;
    query.prepare("select * from MALADIE ");
    query.bindValue(":ID", ID);
    query.exec();
    QSqlQueryModel * model= new QSqlQueryModel();
    model->setQuery(query);

    model->setHeaderData(0, Qt::Horizontal, QObject::tr("ID"));
    model->setHeaderData(1, Qt::Horizontal, QObject::tr("SYMPTOMES"));
    model->setHeaderData(2, Qt::Horizontal, QObject::tr("CAUSES"));
    model->setHeaderData(3, Qt::Horizontal, QObject::tr("Nom "));

     return model;
}


bool Maladie::update( QString ID, QString Nom, QString SYMPTOMES, QString CAUSES)
{
    QSqlQuery query;

    query.prepare("UPDATE Maladie SET Nom =:Nom,SYMPTOMES =:SYMPTOMES,CAUSES=:CAUSES WHERE ID=:ID");
    query.bindValue(":ID",ID);
    query.bindValue(":Nom",Nom);
    query.bindValue(":SYMPTOMES",SYMPTOMES);
    query.bindValue(":CAUSES",CAUSES);
    return query.exec();
}


bool Maladie::supprimer(QString ID)
{
QSqlQuery query;

query.prepare("delete from Maladie where ID=:ID");
query.bindValue(":ID",ID );
return query.exec();

}


QSqlQueryModel *  Maladie::afficher2(QString Nom)
{
    QSqlQuery query;
    query.prepare("select * from Maladie WHERE Nom=:Nom");
    query.bindValue(":Nom", Nom);
    query.exec();
    QSqlQueryModel * model= new QSqlQueryModel();
    model->setQuery(query);

    model->setHeaderData(0, Qt::Horizontal, QObject::tr("ID"));
    model->setHeaderData(1, Qt::Horizontal, QObject::tr("SYMPTOMES"));
    model->setHeaderData(2, Qt::Horizontal, QObject::tr("CAUSES"));
    model->setHeaderData(3, Qt::Horizontal, QObject::tr("Nom "));


     return model;

}

QSqlQueryModel *  Maladie::afficher1(QString ID)
{
    QSqlQuery query;
    query.prepare("select * from Maladie WHERE ID=:ID");
    query.bindValue(":ID", ID);
    query.exec();
    QSqlQueryModel * model= new QSqlQueryModel();
    model->setQuery(query);

    model->setHeaderData(0, Qt::Horizontal, QObject::tr("ID"));
    model->setHeaderData(1, Qt::Horizontal, QObject::tr("SYMPTOMES"));
    model->setHeaderData(2, Qt::Horizontal, QObject::tr("CAUSES"));
    model->setHeaderData(3, Qt::Horizontal, QObject::tr("Nom "));



     return model;

}

QSqlQueryModel *  Maladie::afficher3(QString SYMPTOMES)
{
    QSqlQuery query;
    query.prepare("select * from Maladie WHERE SYMPTOMES=:SYMPTOMES");
    query.bindValue(":SYMPTOMES", SYMPTOMES);
    query.exec();
    QSqlQueryModel * model= new QSqlQueryModel();
    model->setQuery(query);

    model->setHeaderData(0, Qt::Horizontal, QObject::tr("ID"));
    model->setHeaderData(1, Qt::Horizontal, QObject::tr("SYMPTOMES"));
    model->setHeaderData(2, Qt::Horizontal, QObject::tr("CAUSES"));
    model->setHeaderData(3, Qt::Horizontal, QObject::tr("Nom "));



     return model;

}


QSqlQueryModel * Maladie::affichercr()

{
    QSqlQuery query;
    query.prepare("SELECT * FROM Maladie ORDER BY Nom ASC;");

    query.exec();
    QSqlQueryModel * model= new QSqlQueryModel();
    model->setQuery(query);

    model->setHeaderData(0, Qt::Horizontal, QObject::tr("ID"));
    model->setHeaderData(1, Qt::Horizontal, QObject::tr("SYMPTOMES"));
    model->setHeaderData(2, Qt::Horizontal, QObject::tr("CAUSES"));
    model->setHeaderData(3, Qt::Horizontal, QObject::tr("Nom "));



return model;
}
QSqlQueryModel * Maladie::afficherdc()
{
    QSqlQuery query;
    query.prepare("SELECT * FROM Maladie ORDER BY Nom DESC;");

    query.exec();
    QSqlQueryModel * model= new QSqlQueryModel();
    model->setQuery(query);

    model->setHeaderData(0, Qt::Horizontal, QObject::tr("ID"));
    model->setHeaderData(1, Qt::Horizontal, QObject::tr("SYMPTOMES"));
    model->setHeaderData(2, Qt::Horizontal, QObject::tr("CAUSES"));
    model->setHeaderData(3, Qt::Horizontal, QObject::tr("Nom "));



return model;



}

QSqlQueryModel * Maladie::afficherdu()
{
    QSqlQuery query;
    query.prepare("SELECT * FROM Maladie ORDER BY SYMPTOMES ASC;");

    query.exec();
    QSqlQueryModel * model= new QSqlQueryModel();
    model->setQuery(query);

    model->setHeaderData(0, Qt::Horizontal, QObject::tr("ID"));
    model->setHeaderData(1, Qt::Horizontal, QObject::tr("SYMPTOMES"));
    model->setHeaderData(2, Qt::Horizontal, QObject::tr("CAUSES"));
    model->setHeaderData(3, Qt::Horizontal, QObject::tr("Nom "));

return model;
}


