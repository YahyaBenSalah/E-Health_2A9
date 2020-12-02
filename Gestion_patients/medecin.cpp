#include "medecin.h"
#include "ui_mededcin1.h"
#include "medecin2.h"

Medecin::Medecin()
{

}


Medecin::~Medecin(){}
QString Medecin :: getmemail(){return memail;}
QString Medecin :: getmnom(){return mnom;}

QString Medecin :: getmsexe(){return msexe;}
QString Medecin :: getmdn(){return mdn;}
QString Medecin :: getmcab(){return c;}

void Medecin :: setmemail(QString me){memail = me;}
void Medecin :: setmnom(QString n){mnom=n;}
void Medecin :: setmsexe(QString p){msexe=p;}
void Medecin :: setmdn(QString d){mdn=d;}
void Medecin :: setmcab(QString mcab){c =mcab;}
