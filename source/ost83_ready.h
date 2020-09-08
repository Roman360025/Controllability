#ifndef OST83_READY_H
#define OST83_READY_H

#include <QDialog>

namespace Ui {
class ost83_ready;
}

class ost83_ready : public QDialog
{
    Q_OBJECT

public:
    explicit ost83_ready(QWidget *parent = 0);
    ~ost83_ready();

 private slots:
        void row_change_A(int value);

        void row_change_B(int value);

        void on_pushButton_clicked();

        void on_pushButton_2_clicked();

private:
    Ui::ost83_ready *ui;
};

#endif // OST83_READY_H
