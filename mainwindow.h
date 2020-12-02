#ifndef MAINWINDOW_H
#define MAINWINDOW_H
#include"medicament.h"
#include"maladie.h"
#include <QMainWindow>
#include <QSound>

QT_BEGIN_NAMESPACE
namespace Ui
{
    class MainWindow;
}
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_Ajout_medic_clicked();

    void on_Supprimer_medic_clicked();

    void on_Modifier_medic_clicked();

    void on_Afficher_medic_clicked();

    void on_Ajout_maladie_clicked();

    void on_Modifier_maladie_clicked();

    void on_Afficher_maladie_clicked();

    void on_Supp_maladie_clicked();

    void on_Trier_medic_clicked();

    void on_pb_recherche_clicked();

    void on_rechercher_maladie_clicked();

    void on_pushButton_clicked();

private:
    Ui::MainWindow *ui;
    medicament tmpmedic;
    Maladie tmpmld;
    QSound *son;


};
#endif // MAINWINDOW_H
