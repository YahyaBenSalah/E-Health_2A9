#ifndef MEDICAMENT_H
#define MEDICAMENT_H
#include<QString>
#include <QSqlQueryModel>

class medicament
{
public:
    medicament();
    medicament(QString, QString, QString);
    QString get_nom();
    QString get_prix();
    QString get_cas();
    bool ajouter();
    QSqlQueryModel * afficher();
    QSqlQueryModel * afficher_medicament_trier();
    QSqlQueryModel * medicament_trier_prix();
    QSqlQueryModel * medicament_trier_cas();
    QSqlQueryModel * rechercher_medicament(const QString &nom);
    bool supprimer(QString);
    bool modifier();

private:
    QString nom,prix,cas;
};

#endif // MEDICAMENT_H
