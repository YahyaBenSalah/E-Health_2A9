#ifndef MEDECIN2_H
#define MEDECIN2_H
#include "medecin.h"
#include"mededcin1.h"
#include <QDialog>

namespace Ui {
class medecin2;
}

class medecin2 : public QDialog
{
    Q_OBJECT

public:
    explicit medecin2(QWidget *parent = nullptr);
    ~medecin2();
    void afficher(Medecin med);

private:
    Ui::medecin2 *ui;
};

#endif // MEDECIN2_H
