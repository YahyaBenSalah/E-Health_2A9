#ifndef MEDECIN_H
#define MEDECIN_H

#include<QString>
#include <QSqlQuery>
#include <memory>
#include <QSqlQueryModel>

class medecin
{
public:
    medecin();
    medecin(int cin, QString nom, QString prenom, QString email, QString adresse);
    int getCin();
    QString getNom();
    QString getPrenom();
    QString getEmail();
    QString getAdresse();
    void setCin(int cin);
    void setNom(QString nom);
    void setPrenom(QString prenom);
    void setEmail(QString email);
    void setAdresse(QString adresse);
    bool ajouterMedecin(medecin medecin);
    bool trouverMedecin(int cin);
    bool modifierMedecin(int cin , QString nom , QString prenom , QString email , QString adresse);
    QSqlQueryModel *afficherAll();
    bool supprimerMedecin(int cin);
    QString  trouverChamp(QString word , int cin);
    QSqlQueryModel *rechercheMedecin(QString key);


    //-------------------------------------------------------------------------------------------

private:
    int cin;
    QString nom;
    QString prenom;
    QString email;
    QString adresse;
};

#endif // MEDECIN_H
