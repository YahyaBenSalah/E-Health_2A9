#ifndef FICHE_H
#define FICHE_H

#include<QString>
#include <QSqlQuery>
#include <memory>
#include <QSqlQueryModel>
class Fiche
{
public:
    Fiche();
    Fiche(int cin_client, QString nom_client, QString prenom_client, QString maladie_client, QString traitement_client);
    int getCin_client();
    QString getNom_client();
    QString getPrenom_client();
    QString getMaladie_client();
    QString getTraitement_client();
    void setCin_client(int cin_client);
    void setNom_client(QString nom_client);
    void setPrenom_client(QString prenom_client);
    void setMaladie_client(QString maladie_client);
    void setTraitement_client(QString traitement_client);
    bool ajouterFiche(Fiche fiche);
    bool trouverFiche(int cin);
    bool modifierFiche(int cin , QString nom , QString prenom , QString maladie , QString traitement);
    QSqlQueryModel *afficherAll();
    bool supprimerFiche(int cin);
    QString  trouverChamp(QString word , int cin);
    bool archiverFiche(int cin , QString nom , QString prenom , QString maladie , QString traitement);
    QSqlQueryModel *rechercheFiche(QString key);
    QSqlQueryModel *rechercheFicheCin();
    QSqlQueryModel *rechercheFicheNom();
    QSqlQueryModel *rechercheFichePrenom();
    QSqlQueryModel *rechercheFicheMaladie();
    QSqlQueryModel *rechercheFicheTraitement();

    //-------------------------------------------------------------------------------------------

private:
    int cin_client;
    QString nom_client;
    QString prenom_client;
    QString maladie_client;
    QString traitement_client;
};

#endif // FICHE_H
