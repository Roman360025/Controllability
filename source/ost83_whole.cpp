#include "ost83_whole.h"
#include "ui_ost83_whole.h"

ost83_whole::ost83_whole(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::ost83_whole)
{
    ui->setupUi(this);
    connect(ui->spinBox, SIGNAL(valueChanged(int)), this, SLOT(row_change(int)));
}

void ost83_whole::row_change(int value)
{
    int k0=ui->tableWidget->rowCount();
    int k=value;
    if (k>k0)
        while (ui->tableWidget->rowCount()!=value)
        {
            ui->tableWidget->insertRow(1);
            ui->tableWidget_2->insertRow(1);
        }
    else
        while (ui->tableWidget->rowCount()!=value)
        {
            ui->tableWidget->removeRow(1);
            ui->tableWidget_2->removeRow(1);
        }
}

ost83_whole::~ost83_whole()
{
    delete ui;
}

void ost83_whole::on_pushButton_clicked()
{
    float tv, chis=0, znam=0;
    for(int i=1; i<=ui->spinBox->value();++i)
    {
        chis=chis+ui->tableWidget->item(i-1,0)->text().toFloat()*ui->tableWidget_2->item(i-1,0)->text().toFloat();
        znam+=ui->tableWidget->item(i-1,0)->text().toFloat();
    }
    tv=chis/znam;
    ui->lineEdit->setText(QString("%1").arg(tv));
}

void ost83_whole::on_pushButton_2_clicked()
{
    this->close();
}
