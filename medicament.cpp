#include "medicament.h"
#include <QSqlQuery>
#include <QDebug>
#include <QSqlQueryModel>
#include <QMediaPlayer>



medicament::medicament()
{
    nom = "";
    prix = "";
    cas = "";
}

medicament::medicament(QString nom,QString prix,QString cas)
{
  this->nom = nom;
  this->prix = prix;
  this->cas = cas;
}

QString medicament::get_nom()
{
    return nom;
}

QString medicament::get_prix()
{
    return prix;
}

QString medicament::get_cas()
{
    return cas;
}

bool medicament::ajouter()
{

    QSqlQuery query;

    query.prepare("INSERT INTO medicament (nom, prix, casutilisation) " "VALUES (:id, :forename, :surname)");

    query.bindValue(":id", nom);
    query.bindValue(":forename", prix);
    query.bindValue(":surname", cas);

    return query.exec();
}

QSqlQueryModel * medicament::afficher()
{
    QSqlQueryModel * model = new QSqlQueryModel();
    QMediaPlayer * music =new QMediaPlayer;
        music->setMedia(QUrl("qrc:/son/Sound.wav"));
        music->play();

    model->setQuery("select * from medicament");
    model->setHeaderData(0, Qt::Horizontal, QObject::tr("nom"));
    model->setHeaderData(1, Qt::Horizontal, QObject::tr("prix"));
    model->setHeaderData(2, Qt::Horizontal, QObject::tr("cas utilisation"));

    return model;
}

bool medicament::supprimer(QString nom)
{
    QSqlQuery query;

    query.prepare("Delete from medicament where Nom = :nom");
    query.bindValue(":nom", nom);

    return query.exec();
}

bool medicament::modifier()
{
    QSqlQuery query;

    query.prepare("Update medicament set nom=:nom ,prix=:prix ,casutilisation=:cas where nom=:nom");
          query.bindValue(":nom", nom);
          query.bindValue(":prix", prix);
          query.bindValue(":cas", cas);

          return query.exec();
}

QSqlQueryModel *medicament::afficher_medicament_trier()
{
        QSqlQueryModel * model=new QSqlQueryModel();

        model->setQuery("select * from medicament order by nom desc ");
        model->setHeaderData(0, Qt::Horizontal, QObject::tr("nom"));
        model->setHeaderData(1, Qt::Horizontal, QObject::tr("prix"));
        model->setHeaderData(2, Qt::Horizontal, QObject::tr("cas"));

        return model;
}

QSqlQueryModel *medicament::medicament_trier_prix()
{
        QSqlQueryModel * model=new QSqlQueryModel();

        model->setQuery("select * from medicament order by prix asc ");
        model->setHeaderData(0, Qt::Horizontal, QObject::tr("nom"));
        model->setHeaderData(1, Qt::Horizontal, QObject::tr("prix"));
        model->setHeaderData(2, Qt::Horizontal, QObject::tr("cas"));

        return model;
}

QSqlQueryModel *medicament::medicament_trier_cas()
{
        QSqlQueryModel * model=new QSqlQueryModel();

        model->setQuery("select * from medicament order by CASUTILISATION desc ");
        model->setHeaderData(0, Qt::Horizontal, QObject::tr("nom"));
        model->setHeaderData(1, Qt::Horizontal, QObject::tr("prix"));
        model->setHeaderData(2, Qt::Horizontal, QObject::tr("CASUTILISATION"));

        return model;
}

QSqlQueryModel *medicament::rechercher_medicament(const QString &nom)
{
    QSqlQueryModel *model=new QSqlQueryModel();

    model->setQuery("select * from medicament where(nom LIKE '"+nom+"')");
    model->setHeaderData(0, Qt::Horizontal, QObject::tr("nom"));
    model->setHeaderData(1, Qt::Horizontal, QObject::tr("prix"));
    model->setHeaderData(2, Qt::Horizontal, QObject::tr("casutilisation"));

    return model;
}
