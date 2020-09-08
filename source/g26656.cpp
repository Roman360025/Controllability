#include "g26656.h"
#include "ui_g26656.h"

g26656::g26656(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::g26656)
{
    ui->setupUi(this);
}

g26656::~g26656()
{
    delete ui;
}
