#ifndef MAINWINDOW_H
#define MAINWINDOW_H
#include "maladie.h"
#include "maladie1.h"
#include "dossiermedicale.h"
#include <QMediaPlayer>
#include <QSound>
#include "medicament.h"
#include <iostream>
#include "QString"
#include <vector>
#include "QSqlQueryModel"
#include <QMainWindow>
#include <QSystemTrayIcon>
#include <QtCharts/QChartView>
#include <QtCharts/QBarSeries>
#include <QtCharts/QBarSet>
#include <QtCharts/QLegend>
#include <QtCharts/QBarCategoryAxis>
#include <QtCharts/QValueAxis>



QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_BtnAddFiche_clicked();

    void on_BtnRefrech_clicked();

    void on_BtnDeleteFche_clicked();

    void on_BtnUpdateFiche_clicked();

    void on_BtnUpdateFiche_2_clicked();

    void on_BtnAjouterAuBilan_clicked();

    void on_pushButton_9_clicked();

    void on_pushButton_7_clicked();

    void on_pushButton_6_clicked();

    void on_pushButton_8_clicked();

    void on_pushButton_2_clicked();

    void on_pushButton_3_clicked();

    void on_pushButton_4_clicked();

    void on_pushButton_clicked();

    void on_pushButton_5_clicked();

    void on_pushButton_10_clicked();

    void on_pushButton_11_clicked();

    void on_BtnArchiveFiche_clicked();

    void on_BtnSearchFiche_clicked();

    void on_BtnSearchBilan_clicked();

    void on_BtnArchiveCompte_clicked();

    void on_BtnSearchFiche_2_clicked();

    void on_seConnecterBtn_clicked();

    void on_pushButton_15_clicked();

    void on_pushButton_13_clicked();

    void on_pushButton_16_clicked();

    void on_pushButton_14_clicked();

    void on_pushButton_17_clicked();

    void on_formPdf_clicked();

    void on_signUp_clicked();

    void on_pushButton_18_clicked();

    void on_pushButton_19_clicked();

    void on_pushButton_20_clicked();

    void on_pushButton_23_clicked();

    void on_pushButton_22_clicked();

    void on_pushButton_21_clicked();

    void on_jouterfm_clicked();

    void on_ajout_maisondeproduction_clicked();

    void on_jouterfm_2_clicked();

    void on_Mod_maisondeproduction_clicked();

    void on_suppm_clicked();

    void on_deletemdp_clicked();

    void on_afficher1_clicked();

    void on_Trier_clicked();

    void on_pushButton_12_clicked();

    void on_pushButton_24_clicked();

    void on_pushButton_25_clicked();

    void on_pushButton_33_clicked();

    void on_pushButton_34_clicked();

    void on_pushButton_35_clicked();

    void on_pushButton_36_clicked();

    void on_pushButton_76_clicked();

    void on_pushButton_78_clicked();

    void on_pushButton_74_clicked();
    
    void on_Afficher_medic_2_clicked();

    void on_Ajout_medic_2_clicked();

    void on_Supprimer_medic_2_clicked();

    void on_Modifier_medic_2_clicked();

    void on_pb_recherche_2_clicked();

    void on_Ajout_maladie_2_clicked();

    void on_Modifier_maladie_2_clicked();

    void on_Afficher_maladie_2_clicked();

    void on_Supp_maladie_2_clicked();

    void on_rechercher_maladie_2_clicked();

    void on_pushButton_73_clicked();

    void on_Printer_2_clicked();

    void on_Print_malad_2_clicked();

    void on_Trier_medic_2_clicked();

    void on_pushButton_71_clicked();

    void on_pushButton_72_clicked();

    void on_BtnRefrech_2_clicked();

    void on_BtnAddPatient_4_clicked();

    void on_pushButton_26_clicked();

    void on_pushButton_79_clicked();

    void on_BtnDeletePatient_clicked();

    void on_BtnUpdatePatient_clicked();

    void on_BtnUpdatePatient_2_clicked();


    void on_BtnSearchPatient_clicked();

    void on_pushButton_75_clicked();

    void on_pushButton_77_clicked();

    void on_pushButton_80_clicked();

    void on_pushButton_84_clicked();

    void on_pushButton_85_clicked();

    void on_pushButton_86_clicked();

    void on_pushButton_83_clicked();

    void on_pushButton_82_clicked();

    void on_pushButton_81_clicked();

    void on_BtnAddMedecin_5_clicked();

    void on_BtnRefrech_3_clicked();

    void on_BtnDeleteMedecin_clicked();

    void on_BtnUpdateMed_clicked();

    void on_BtnUpdateMed_2_clicked();

    void on_BtnSearchMedecin_clicked();

private:
    Ui::MainWindow *ui;
    Maladie tmpmaladie;
    dossiermedicale tmpdossier;
    medicament tmpmedic;
    maladie1 tmpmld;
    QSound *son;
//    QSystemTrayIcon *mysystem;
//    Secretaire tmps,tmpentret ;
//    Rendez_vous tmpbus,tempbus;
//     Rendez_vous * b,*trier ;
 //    statistique_etat *stat ;
//     int getIDFromTableView(QTableView * tv);


};
#endif // MAINWINDOW_H
