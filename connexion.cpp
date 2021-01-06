#include "connexion.h"
#include<QDebug>

connexion::connexion()
{

}

bool connexion::createconnect()
{
    bool test=false;
    QSqlDatabase db = QSqlDatabase::addDatabase("QODBC");
    db.setDatabaseName("Source_Projet2A");
    db.setUserName("Aziz1");
    db.setPassword("Aziz01");

    if(db.open())
        test=true;

    qDebug()<<db.lastError().text();

    return test;
}
