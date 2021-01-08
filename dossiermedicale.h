#ifndef DOSSIERMEDICALE_H
#define DOSSIERMEDICALE_H
#include <QString>
#include "QSqlQuery"
#include <QDebug>
#include "qsqltablemodel.h"


class dossiermedicale
{
public:
    dossiermedicale();
    dossiermedicale(QString,QString,QString);
    bool ajouter();
    QSqlQueryModel * afficher();
    bool update( QString , QString , QString );
    bool supprimer(QString ID);
private:
    QString ID,REF,DATECRE;
};

#endif // DOSSIERMEDICALE_H
