#ifndef MALADIE1_H
#define MALADIE1_H


#include<QString>
#include<QSqlQueryModel>

//test git
class maladie1
{
public:
    maladie1();
    maladie1(QString,QString,QString);
    QString get_nom();
    QString get_maladie1_cause();
    QString get_maladie1_sympt();
    QSqlQueryModel * afficher();
    QSqlQueryModel * afficher_maladie1_trier();
    QSqlQueryModel * rechercher_maladie1(const QString &nom);
    bool supprimer(QString);
    bool ajouter();
    bool modifier();

private:
    QString nom, cause, sympt;
};



#endif // maladie1_H
