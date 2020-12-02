#ifndef PATIENT_H
#define PATIENT_H
#include <QString>
class patient
{
public:
    patient();
    ~patient();
  patient(QString,QString,QString,QString,QString);
   QString getcin();
   QString getnom();
   QString getprenom();
   QString getciv();
   QString getdn();
   void setcin(QString c);
   void setnom(QString n);
   void setprenom(QString p);
   void setciv(QString ec);
   void setdn(QString dn);
bool ajouter();


private:
    QString nom ,prenom ,cin,civ,dn;
};

#endif // PATIENT_H
