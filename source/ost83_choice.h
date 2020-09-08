#ifndef OST83_CHOICE_H
#define OST83_CHOICE_H

#include <QDialog>

namespace Ui {
class ost83_choice;
}

class ost83_choice : public QDialog
{
    Q_OBJECT

public:
    explicit ost83_choice(QWidget *parent = 0);
    ~ost83_choice();

private slots:
    void on_buttonBox_accepted();



    void on_buttonBox_rejected();

private:
    Ui::ost83_choice *ui;
};

#endif // OST83_CHOICE_H
