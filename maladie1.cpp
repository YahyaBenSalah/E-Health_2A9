#include "maladie1.h"
#include <QSqlQuery>
#include <QDebug>
#include <QSqlQueryModel>

maladie1::maladie1()
{
    nom = "";
    cause = "";
    sympt = "";
}

maladie1::maladie1(QString nom,QString cause, QString sympt)
{
    this->nom = nom;
    this->cause = cause;
    this->sympt = sympt;
}

QString maladie1::get_nom()
{
    return nom;
}

QString maladie1::get_maladie1_cause()
{
    return  cause;
}

QString maladie1::get_maladie1_sympt()
{
    return  sympt;
}

bool maladie1::ajouter()
{
    QSqlQuery query;

        query.prepare("INSERT INTO maladie1 (nom, cause, symptome) " "VALUES (:id, :forename, :surname)");
          query.bindValue(":id", nom);
          query.bindValue(":forename", cause);
          query.bindValue(":surname", sympt);

          return query.exec();
}

QSqlQueryModel *maladie1::afficher()
{
    QSqlQueryModel * model = new QSqlQueryModel();

    model->setQuery("select * from maladie1");
    model->setHeaderData(0, Qt::Horizontal, QObject::tr("nom"));
    model->setHeaderData(1, Qt::Horizontal, QObject::tr("cause"));
    model->setHeaderData(2, Qt::Horizontal, QObject::tr("symptome"));

    return model;
}

bool maladie1::supprimer(QString nom)
{
    QSqlQuery query;

    query.prepare("Delete from maladie1 where Nom = :nom");
    query.bindValue(":nom", nom);

    return query.exec();
}

bool maladie1::modifier()
{
    QSqlQuery query;

    query.prepare("Update maladie1 set nom=:nom ,cause=:cause ,symptome=:symptome where nom=:nom");
          query.bindValue(":nom", nom);
          query.bindValue(":cause", cause);
          query.bindValue(":symptome", sympt);

          return query.exec();
}

QSqlQueryModel *maladie1::rechercher_maladie1(const QString &nom)
{
   QSqlQueryModel *model=new QSqlQueryModel();

   model->setQuery("select * from maladie1 where(nom LIKE '"+nom+"')");
   model->setHeaderData(0, Qt::Horizontal, QObject::tr("nom"));
   model->setHeaderData(1, Qt::Horizontal, QObject::tr("cause"));
   model->setHeaderData(2, Qt::Horizontal, QObject::tr("symptome"));

   return model;
}
