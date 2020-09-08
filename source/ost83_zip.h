#ifndef OST83_ZIP_H
#define OST83_ZIP_H

#include <QDialog>

namespace Ui {
class ost83_ZIP;
}

class ost83_ZIP : public QDialog
{
    Q_OBJECT

public:
    explicit ost83_ZIP(QWidget *parent = 0);
    ~ost83_ZIP();

private slots:
    void on_pushButton_clicked();

    void row_change(int value);

    void on_pushButton_2_clicked();

private:
    Ui::ost83_ZIP *ui;
};

#endif // OST83_ZIP_H
