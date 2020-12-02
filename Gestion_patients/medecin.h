#ifndef MEDECIN_H
#define MEDECIN_H
#include "QString"

class Medecin
{
public:
    Medecin();

   ~Medecin();

   QString getmemail();
   QString getmnom();
   QString getmsexe();
   QString getmdn();
   QString getmcab();
   void setmsexe(QString me);
   void setmnom(QString mn);
   void setmemail(QString mec);
   void setmdn(QString mdn);
   void setmcab(QString mcab);



private:
    QString mnom  ,memail,msexe,mdn,c;
};

#endif // MEDECIN_H
