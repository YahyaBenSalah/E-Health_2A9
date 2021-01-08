#ifndef COMPTES_H
#define COMPTES_H

#include<QString>
#include <QSqlQuery>
#include <memory>
#include <QSqlQueryModel>

class Comptes
{
private:
    QString Email;
    QString Nom;
    QString Prenom;
    int Cin;
    QString mdp;


public:
    Comptes();
    Comptes(int,QString,QString,QString,QString);

    int getCin();
    QString getNom();
    QString getPrenom();
    QString getMdp();
    QString getEmail();

    void setCin(int cin);
    void setNom(QString nom);
    void setPrenom(QString prenom);
    void setMdp(QString mdp);
    void setEmail(QString email);

    bool ajouterCompte(Comptes);
    bool supprimerCompte(int);
    QSqlQueryModel *afficherAll();
    bool trouverCompte(int cin);
    bool archiverCompte(int cin , QString nom , QString prenom , QString mdp , QString email);
    bool testEmail(QString email);
    bool testMdp(QString mdp);

};

#endif // COMPTES_H
