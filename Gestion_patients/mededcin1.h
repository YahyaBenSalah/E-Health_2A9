#ifndef MEDEDCIN1_H
#define MEDEDCIN1_H

#include <QDialog>

namespace Ui {
class mededcin1;
}

class mededcin1 : public QDialog
{
    Q_OBJECT

public:
    explicit mededcin1(QWidget *parent = nullptr);
    ~mededcin1();

private slots:


    void on_pushButton_clicked();

private:
    Ui::mededcin1 *ui;
};

#endif // MEDEDCIN1_H
