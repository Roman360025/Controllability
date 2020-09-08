#include "ost45_choice.h"
#include "ui_ost45_choice.h"
#include "ost45.h"

ost45_choice::ost45_choice(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::ost45_choice)
{
    ui->setupUi(this);
}

ost45_choice::~ost45_choice()
{
    delete ui;
}

void ost45_choice::on_pushButton_clicked()
{
    if(ui->comboBox->currentIndex()==0)
    {
        ost45 *wnd=new ost45(this);
        wnd->show();
    }
}
