#ifndef OST83_WHOLE_H
#define OST83_WHOLE_H

#include <QDialog>

namespace Ui {
class ost83_whole;
}

class ost83_whole : public QDialog
{
    Q_OBJECT

public:
    explicit ost83_whole(QWidget *parent = 0);
    ~ost83_whole();

private slots:
    void on_pushButton_clicked();
    void row_change(int value);

    void on_pushButton_2_clicked();

private:
    Ui::ost83_whole *ui;
};

#endif // OST83_WHOLE_H
