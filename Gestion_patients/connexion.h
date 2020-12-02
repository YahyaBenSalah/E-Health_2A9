#ifndef CONNECTION_H
#define CONNECTION_H
#include <QtSql/QSqlDatabase>
#include "QSqlQuery"

class connexion
{
private:
    QSqlDatabase db;

public:
    connexion();
    bool createconnect();
    void fermerconnexion();
};

#endif // CONNECTION_H
