#ifndef TABLE7_1_H
#define TABLE7_1_H

#include <QDialog>

namespace Ui {
class table7_1;
}

class table7_1 : public QDialog
{
    Q_OBJECT

public:
    explicit table7_1(QWidget *parent = 0);
    ~table7_1();

private slots:
    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

    void on_pushButton_3_clicked();

    void on_pushButton_4_clicked();


private:
    Ui::table7_1 *ui;
};

#endif // TABLE7_1_H
