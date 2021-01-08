#ifndef MALADIE_H
#define MALADIE_H
#include <QString>
#include "QSqlQueryModel"



class Maladie
{
public:
    Maladie();
    Maladie(QString,QString,QString,QString);
    bool ajouter();
    QSqlQueryModel * afficher();
    bool update( QString , QString , QString , QString );
    bool supprimer(QString);
    QSqlQueryModel * afficher1(QString );
    QSqlQueryModel * afficher2(QString );
    QSqlQueryModel * afficher3(QString );
    QSqlQueryModel * affichercr();
    QSqlQueryModel * afficherdc();
    QSqlQueryModel * afficherdu();





private:
   QString ID,NOM,SYMPTOMES,CAUSES;
};

#endif // MALADIE_H
