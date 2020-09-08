#ifndef OST45_CHOICE_H
#define OST45_CHOICE_H

#include <QDialog>

namespace Ui {
class ost45_choice;
}

class ost45_choice : public QDialog
{
    Q_OBJECT

public:
    explicit ost45_choice(QWidget *parent = 0);
    ~ost45_choice();

private slots:
    void on_pushButton_clicked();

private:
    Ui::ost45_choice *ui;
};

#endif // OST45_CHOICE_H
