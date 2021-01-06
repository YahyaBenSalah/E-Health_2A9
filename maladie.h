#ifndef MALADIE_H
#define MALADIE_H
#include<QString>
#include<QSqlQueryModel>

//test git
class Maladie
{
public:
    Maladie();
    Maladie(QString,QString,QString);
    QString get_nom();
    QString get_maladie_cause();
    QString get_maladie_sympt();
    QSqlQueryModel * afficher();
    QSqlQueryModel * afficher_maladie_trier();
    QSqlQueryModel * rechercher_maladie(const QString &nom);
    bool supprimer(QString);
    bool ajouter();
    bool modifier();

private:
    QString nom, cause, sympt;
};



#endif // MALADIE_H
