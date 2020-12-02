#ifndef SECONDWINDOW_H
#define SECONDWINDOW_H
#include "patient.h"
#include <QDialog>
#include <QDateEdit>
namespace Ui {
class secondwindow;
}

class secondwindow : public QDialog
{
    Q_OBJECT

public:
    explicit secondwindow(QWidget *parent = nullptr);
    ~secondwindow();
    void afficher(patient pat);

private slots:
    void on_pushButton_clicked();

private:
    Ui::secondwindow *ui;
};

#endif // SECONDWINDOW_H
