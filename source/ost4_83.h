    #ifndef OST4_83_H
#define OST4_83_H

#include <QDialog>
#include <QTableWidget>

namespace Ui {
class ost4_83;
}

class ost4_83 : public QDialog
{
    Q_OBJECT

public:
    explicit ost4_83(QWidget *parent = 0);
    ~ost4_83();

private slots:
    void on_pushButton_clicked();

    void change_max(int value);

    void row_change_tprodg(int value);

    void row_change_2(int value);

    void on_pushButton_3_clicked();

    void on_pushButton_7_clicked();

    void on_pushButton_4_clicked();

private:
    Ui::ost4_83 *ui;
};

#endif // OST4_83_H
