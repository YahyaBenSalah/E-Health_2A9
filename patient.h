#ifndef PATIENT_H
#define PATIENT_H
#include<QString>
#include <QSqlQuery>
#include <memory>
#include <QSqlQueryModel>

class patient
{
public:
    patient();
    ~patient();
  patient(int,QString,QString,QString,QString);
   int getcin();
   QString getnom();
   QString getprenom();
   QString getciv();
   QString getdn();
   void setcin(int c);
   void setnom(QString n);
   void setprenom(QString p);
   void setciv(QString ec);
   void setdn(QString dn);
bool ajouter(patient patient);
bool trouver(int cin);
bool modifier(int cin , QString nom , QString prenom , QString dn , QString civ);
bool supprimer(int cin);
QSqlQueryModel * afficher();
QString  trouverChamp(QString word , int cin);
QSqlQueryModel *recherchePatient(QString key);



private:
    QString nom ,prenom,dn,civ;
    int cin;
};

#endif // PATIENT_H
