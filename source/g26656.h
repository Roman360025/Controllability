#ifndef G26656_H
#define G26656_H

#include <QDialog>

namespace Ui {
class g26656;
}

class g26656 : public QDialog
{
    Q_OBJECT

public:
    explicit g26656(QWidget *parent = 0);
    ~g26656();

private:
    Ui::g26656 *ui;
};

#endif // G26656_H
