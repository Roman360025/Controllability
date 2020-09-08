#include "ost45.h"
#include "ui_ost45.h"

ost45::ost45(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::ost45)
{
    ui->setupUi(this);
    connect(ui->radioButton_100, SIGNAL(toggled(bool)), this, SLOT(make_enabled(bool)));
    connect(ui->radioButton_not_100, SIGNAL(toggled(bool)), this, SLOT(make_enabled(bool)));
    connect(ui->spinBox_m, SIGNAL(valueChanged(int)), this, SLOT(change_row(int)));
    ui->tabWidget->setTabText(0, "Готовые параметры");
    ui->tabWidget->setTabText(1, "Подробный расчёт");
    ui->tabWidget->setTabText(2, "Результат");
}

ost45::~ost45()
{
    delete ui;
}

void ost45::change_row(int value)
{
    QSpinBox *spinBox=(QSpinBox *)sender();
    if(spinBox->objectName()=="spinBox_m")
    {
        int k0=ui->tableWidget_Tou->rowCount();
        int k=value;
        if (k>k0)
            while (ui->tableWidget_Tou->rowCount()!=value)
            {
                ui->tableWidget_Tou->insertRow(1);
            }
        else
            while (ui->tableWidget_Tou->rowCount()!=value)
            {
                ui->tableWidget_Tou->removeRow(1);
            }
    }
}

void ost45::make_enabled(bool value)
{
    QRadioButton *rad_but=(QRadioButton *)sender();
 if(rad_but->text()=="Неполный контроль")
    {
        ui->label_m->setEnabled(value);
        ui->spinBox_m->setEnabled(value);
        ui->tableWidget_Tou->setEnabled(value);
    }
}

void ost45::on_pushButton_clicked()
{
    //Рачёт Po
    float Tou, Po;
    if((ui->spinBox_m->isEnabled()))
    {
        float ni=0, lambda_i_0=0, lambda_i;
        float chislitel=0, znamenatel;
        for(int i=1; i<=ui->spinBox_m->value();++i)
        {
            ni=ui->tableWidget_Tou->item(i-1,0)->text().toFloat();
            lambda_i_0=ui->tableWidget_Tou->item(i-1,1)->text().toFloat();
            lambda_i=ui->tableWidget_Tou->item(i-1, 2)->text().toFloat();
            chislitel+=ni*lambda_i_0;
            znamenatel+=ni*lambda_i;
        }
        Po=chislitel/znamenatel;
        ui->lineEdit_Po->setText(QString::number(Po));
        //Расчёт Тоу
        Tou=Po*ui->lineEdit_sum_tj->text().toFloat()+(1-Po)*ui->lineEdit_Tot->text().toFloat();
    }
    else  Tou=ui->lineEdit_sum_tj->text().toFloat();

    ui->lineEdit_Tou->setText(QString::number(Tou));

    //Расчёт Тоб
    float Tob, n;
    n=Po*ui->lineEdit_n1->text().toFloat()+(1-Po)*ui->lineEdit_n2->text().toFloat();
    ui->lineEdit_n->setText(QString::number(n));
    if((ui->radioButton_point->isChecked()))
    {
        Tob=ui->lineEdit_Top->text().toFloat()+(n+1)*(ui->lineEdit_T_zam->text().toFloat()+ui->lineEdit_T->text().toFloat())/2;
    }
    ui->lineEdit_Tob->setText(QString::number(Tob));
    //Расчёт Тв
    float tv;
    tv=Tob+Tou+ui->lineEdit_Tzm->text().toFloat();
    ui->lineEdit_Tv->setText(QString::number(tv));
}

void ost45::on_pushButton_2_clicked()
{
    this->close();
}
