#include "ost83_ready.h"
#include "ui_ost83_ready.h"

ost83_ready::ost83_ready(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::ost83_ready)
{
    ui->setupUi(this);
    connect(ui->spinBox_A, SIGNAL(valueChanged(int)), this, SLOT(row_change_A(int)));
    connect(ui->spinBox_B, SIGNAL(valueChanged(int)), this, SLOT(row_change_B(int)));
}

void ost83_ready::row_change_B(int value)
{
    int k0=ui->tableWidget_lambda_j->rowCount();
    int k=value;
    if (k>k0)
        while (ui->tableWidget_lambda_tv_j->rowCount()!=value)
        {
            ui->tableWidget_lambda_j->insertRow(1);
            ui->tableWidget_lambda_tv_j->insertRow(1);
        }
    else
        while (ui->tableWidget_lambda_tv_j->rowCount()!=value)
        {
            ui->tableWidget_lambda_j->removeRow(1);
            ui->tableWidget_lambda_tv_j->removeRow(1);
        }
}

void ost83_ready::row_change_A(int value)
{
    int k0=ui->tableWidget_lambda_i->rowCount();
    int k=value;
    if (k>k0)
        while (ui->tableWidget_lambda_tv_i->rowCount()!=value)
        {
            ui->tableWidget_lambda_i->insertRow(1);
            ui->tableWidget_lambda_tv_i->insertRow(1);
        }
    else
        while (ui->tableWidget_lambda_tv_i->rowCount()!=value)
        {
            ui->tableWidget_lambda_i->removeRow(1);
            ui->tableWidget_lambda_tv_i->removeRow(1);
        }
}

ost83_ready::~ost83_ready()
{
    delete ui;
}

void ost83_ready::on_pushButton_clicked()
{
    float tv, lam_i=0, lam_j=0,  sum_i=0, sum_j=0;
    for(int i=1; i<=ui->spinBox_A->value(); ++i)
    {
        sum_i=sum_i+ui->tableWidget_lambda_i->item(i-1,0)->text().toFloat()*ui->tableWidget_lambda_tv_i->item(i-1,0)->text().toFloat();
        lam_i+=ui->tableWidget_lambda_i->item(i-1,0)->text().toFloat();
    }
    for(int j=1; j<=ui->spinBox_B->value(); ++j)
    {
        sum_j=sum_i+ui->tableWidget_lambda_j->item(j-1,0)->text().toFloat()*ui->tableWidget_lambda_tv_j->item(j-1,0)->text().toFloat();
        lam_j+=ui->tableWidget_lambda_j->item(j-1,0)->text().toFloat();
    }
    tv=(sum_i+sum_j)/(lam_i+lam_j);
    ui->lineEdit->setText(QString("%1").arg(tv));

}

void ost83_ready::on_pushButton_2_clicked()
{
    this->close();
}
