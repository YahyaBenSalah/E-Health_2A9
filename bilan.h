#ifndef BILAN_H
#define BILAN_H
#include<QString>
#include <QSqlQuery>
#include <memory>
#include <QSqlQueryModel>
#include <QDate>

class Bilan
{
private:
    int Num_Bilan;
    QString Nom_Charge;
    QString Nom_Recette;
    int Charge;
    int Recette;
    QString date;
public:
    Bilan();
    Bilan(int,QString,QString,int,int,QString);

    int getNum_Bilan();
    QString getNom_Charge();
    QString getNom_Recette();
    int getCharge();
    int getRecette();
    QString getDate();

    void setNum_Bilan(int);
    void setNom_Charge(QString);
    void setNom_Recette(QString);
    void setCharge(int);
    void setRecette(int);
    void setDate(QString);

    bool ajouter_Bilan(Bilan);
    int creat_ID();
    QSqlQueryModel *afficherAll();
    bool supprimerBilan(int num);
    bool modifierBilan(int num , QString nom_r , QString nom_c , int recette , int charge);
    QSqlQueryModel *rechercheBilan(QString key);
    float chargeSum();
    float gainSum();
    float diff(float GS , float CS);

};

#endif // BILAN_H
