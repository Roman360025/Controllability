#ifndef OST45_H
#define OST45_H

#include <QDialog>

namespace Ui {
class ost45;
}

class ost45 : public QDialog
{
    Q_OBJECT

public:
    explicit ost45(QWidget *parent = 0);
    ~ost45();

private slots:
    void on_pushButton_clicked();

    void make_enabled(bool value);

    void change_row(int value);

    void on_pushButton_2_clicked();

private:
    Ui::ost45 *ui;
};

#endif // OST45_H
