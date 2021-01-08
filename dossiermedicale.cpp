#include "dossiermedicale.h"

dossiermedicale::dossiermedicale()
{

}
dossiermedicale::dossiermedicale(QString ID,QString REF,QString DATECRE)
{
    this->ID=ID;
    this->REF=REF;
    this->DATECRE=DATECRE;
}
bool dossiermedicale::ajouter()
{

QSqlQuery query;

query.prepare("INSERT INTO dossiermedicale (ID,REF, DATECRE) "
                    "VALUES (:ID, :REF, :DATECRE)");
query.bindValue(":ID", ID);
query.bindValue(":REF", REF);
query.bindValue(":CAUSES", DATECRE);

return    query.exec();
}


QSqlQueryModel * dossiermedicale::afficher()
{
    QSqlQuery query;
    query.prepare("select * from dossiermedicale ");
    query.bindValue(":ID", ID);
    query.exec();
    QSqlQueryModel * model= new QSqlQueryModel();
    model->setQuery(query);

 model->setHeaderData(0, Qt::Horizontal, QObject::tr("ID"));
 model->setHeaderData(1, Qt::Horizontal, QObject::tr("REF "));
 model->setHeaderData(2, Qt::Horizontal, QObject::tr("DATECREATION"));

     return model;

}



bool dossiermedicale::update( QString ID, QString REF, QString DATECRE)
{
    QSqlQuery query;

    query.prepare("UPDATE dossiermedicale SET REF =:REF,DATECRE =:DATECRE WHERE ID=:ID");
    query.bindValue(":ID",ID);
    query.bindValue(":REF",REF);
    query.bindValue(":DATECRE",DATECRE);

    return query.exec();

}


bool dossiermedicale::supprimer(QString ID)
{
QSqlQuery query;

query.prepare("delete from dossiermedicale where ID=:ID");
query.bindValue(":ID",ID );
return query.exec();

}

