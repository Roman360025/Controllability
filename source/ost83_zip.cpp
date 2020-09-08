#include "ost83_zip.h"
#include "ui_ost83_zip.h"
#include <QMessageBox>

ost83_ZIP::ost83_ZIP(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::ost83_ZIP)
{
    ui->setupUi(this);
    connect(ui->spinBox, SIGNAL(valueChanged(int)), this, SLOT(row_change(int)));
}

void ost83_ZIP::row_change(int value)
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

ost83_ZIP::~ost83_ZIP()
{
    delete ui;
}

void ost83_ZIP::on_pushButton_clicked()
{
    float chis=0, znam=0, t_ob, t_z, t_v;
    if(ui->lineEdit->text().isEmpty())
        QMessageBox::warning(this, "Ошибка", "Введены не все параметры");
    else{
    for(int i=1; i<=ui->spinBox->value();++i)
    {
        if (ui->tableWidget->item(i-1,0)->text().isEmpty())
        {
            QMessageBox::warning(this, "Ошибка", "Введены не все параметры");
            break;
        }
        chis+=ui->tableWidget->item(i-1,0)->text().toFloat()*ui->tableWidget_2->item(i-1,0)->text().toFloat();
        znam+=ui->tableWidget_2->item(i-1,0)->text().toFloat();
    }
    t_ob=chis/znam;
    ui->lineEdit_2->setText(QString("%1").arg(t_ob));
    t_z=ui->lineEdit->text().toFloat();
    t_v=t_ob+t_z;
    ui->lineEdit_3->setText(QString("%1").arg(t_v));
    }
}

void ost83_ZIP::on_pushButton_2_clicked()
{
    this->close();
}
