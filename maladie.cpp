#include "maladie.h"
#include <QSqlQuery>
#include <QDebug>
#include <QSqlQueryModel>

Maladie::Maladie()
{
    nom = "";
    cause = "";
    sympt = "";
}

Maladie::Maladie(QString nom,QString cause, QString sympt)
{
    this->nom = nom;
    this->cause = cause;
    this->sympt = sympt;
}

QString Maladie::get_nom()
{
    return nom;
}

QString Maladie::get_maladie_cause()
{
    return  cause;
}

QString Maladie::get_maladie_sympt()
{
    return  sympt;
}

bool Maladie::ajouter()
{
    QSqlQuery query;

        query.prepare("INSERT INTO maladie (nom, cause, symptome) " "VALUES (:id, :forename, :surname)");
          query.bindValue(":id", nom);
          query.bindValue(":forename", cause);
          query.bindValue(":surname", sympt);

          return query.exec();
}

QSqlQueryModel *Maladie::afficher()
{
    QSqlQueryModel * model = new QSqlQueryModel();

    model->setQuery("select * from maladie");
    model->setHeaderData(0, Qt::Horizontal, QObject::tr("nom"));
    model->setHeaderData(1, Qt::Horizontal, QObject::tr("cause"));
    model->setHeaderData(2, Qt::Horizontal, QObject::tr("symptome"));

    return model;
}

bool Maladie::supprimer(QString nom)
{
    QSqlQuery query;

    query.prepare("Delete from maladie where Nom = :nom");
    query.bindValue(":nom", nom);

    return query.exec();
}

bool Maladie::modifier()
{
    QSqlQuery query;

    query.prepare("Update maladie set nom=:nom ,cause=:cause ,symptome=:symptome where nom=:nom");
          query.bindValue(":nom", nom);
          query.bindValue(":cause", cause);
          query.bindValue(":symptome", sympt);

          return query.exec();
}

QSqlQueryModel *Maladie::rechercher_maladie(const QString &nom)
{
   QSqlQueryModel *model=new QSqlQueryModel();

   model->setQuery("select * from maladie where(nom LIKE '"+nom+"')");
   model->setHeaderData(0, Qt::Horizontal, QObject::tr("nom"));
   model->setHeaderData(1, Qt::Horizontal, QObject::tr("cause"));
   model->setHeaderData(2, Qt::Horizontal, QObject::tr("symptome"));

   return model;
}
