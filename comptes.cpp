#include "comptes.h"

Comptes::Comptes()
{

}
Comptes::Comptes(int cin,QString nom, QString prenom, QString mdp , QString email){
    this->Cin=cin;
    this->Nom=nom;
    this->Prenom=prenom;
    this->mdp=mdp;
    this->Email=email;
}
int Comptes::getCin(){
    return this->Cin;
}

QString Comptes::getNom(){
    return this->Nom;
}

QString Comptes::getPrenom(){
    return this->Prenom;
}

QString Comptes::getMdp(){
    return this->mdp;
}

QString Comptes::getEmail(){
    return this->Email;
}

void Comptes::setCin(int cin){
    this->Cin=cin;
}

void Comptes::setNom(QString nom){
    this->Nom=nom;
}

void Comptes::setPrenom(QString prenom){
    this->Prenom=prenom;
}

void Comptes::setMdp(QString mdp){
    this->mdp=mdp;
}

void Comptes::setEmail(QString email){
    this->Email=email;
}

bool Comptes::ajouterCompte(Comptes compte){
    QSqlQuery query;
        query.prepare("INSERT INTO compte (cin, nom ,prenom ,mdp,email ) "
                      "VALUES (:cin, :nom, :prenom, :mdp, :email)");

        query.bindValue(":cin", compte.getCin());
        query.bindValue(":nom", compte.getNom());
        query.bindValue(":prenom", compte.getPrenom());
        query.bindValue(":mdp", compte.getMdp());
        query.bindValue(":email", compte.getEmail());

        query.exec();
}

QSqlQueryModel * Comptes::afficherAll(){
    QSqlQueryModel * model= new QSqlQueryModel();

    model->setQuery("select * from compte");
    model->setHeaderData(0, Qt::Horizontal, QObject::tr("Cin"));
    model->setHeaderData(1, Qt::Horizontal, QObject::tr("Nom"));
    model->setHeaderData(2, Qt::Horizontal, QObject::tr("Prenom"));
    model->setHeaderData(3, Qt::Horizontal, QObject::tr("mdp"));
    model->setHeaderData(4, Qt::Horizontal, QObject::tr("Email"));
        return model;
}

bool Comptes::supprimerCompte(int cin){
    QSqlQuery  query;
   query.prepare("DELETE FROM compte WHERE cin = '" + QString::number(cin) + "'");

    query.exec();
}

bool Comptes::trouverCompte(int cin){
    QSqlQuery query;
    query.prepare("SELECT * FROM compte WHERE CIN = :CIN ");
    query.bindValue(":CIN",cin);
    query.exec();
    if(query.exec())
        while(query.next()){
                       return true;
               }
               return false;
}

bool Comptes::archiverCompte(int cin , QString nom , QString prenom , QString mdp , QString email){
    QSqlQuery query;
        query.prepare("update COMPTE set nom =:nom,prenom=:prenom,mdp=:mdp,email=:email"
                      " where CIN_CLIENT=:CIN_CLIENT");
        query.prepare("INSERT INTO ARCHIVE_COMPTE (CIN, NOM, PRENOM ,MDP ,EMAIL) "
                      "VALUES (:CIN, :NOM, :PRENOM, :MDP, :EMAIL)");

        query.bindValue(":CIN", cin);
        query.bindValue(":NOM", nom);
        query.bindValue(":PRENOM", prenom);
        query.bindValue(":MDP", mdp);
        query.bindValue(":EMAIL", email);

        query.exec();
}
bool Comptes::testEmail(QString email){
    QSqlQuery query;
    query.prepare("SELECT * FROM compte WHERE EMAIL = :EMAIL");
    query.bindValue(":EMAIL",email);
    query.exec();
    if(query.exec())
        while(query.next()){
                       return true;
               }
               return false;
}
bool Comptes::testMdp(QString mdp){
    QSqlQuery query;
    query.prepare("SELECT * FROM compte WHERE MDP = :MDP");
    query.bindValue(":MDP",mdp);
    query.exec();
    if(query.exec())
        while(query.next()){
                       return true;
               }
               return false;
}
