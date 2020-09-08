#include "ost4_83.h"
#include "ui_ost4_83.h"

ost4_83::ost4_83(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::ost4_83)
{
    ui->setupUi(this);
    connect(ui->spinBox_k, SIGNAL(valueChanged(int)), this, SLOT(row_change_tprodg(int)));
    connect(ui->spinBox_N_2,SIGNAL(valueChanged(int)),this, SLOT(row_change_2(int)));
    connect(ui->spinBox_N_2, SIGNAL(valueChanged(int)), this, SLOT(change_max(int)));
    ui->spinBox_i->setMaximum(ui->spinBox_N_2->value());
    ui->tabWidget->setTabText(0, "Подробный расчёт");
    ui->tabWidget->setTabText(1, "Готовые параметры");
    ui->tabWidget->setTabText(2, "Результат");
}

void ost4_83::change_max(int value)
{
    ui->spinBox_i->setMaximum(value);
}


void ost4_83::row_change_2(int value)
{
    int k0=ui->tableWidget_Tob_2->rowCount();
    int k=value;
    if (k>k0)
        while (ui->tableWidget_Tob_2->rowCount()!=value)
        {
            ui->tableWidget_Tob_2->insertRow(1);
            ui->tableWidget_n_2->insertRow(1);

        }
    else
        while (ui->tableWidget_Tob_2->rowCount()!=value)
        {
            ui->tableWidget_Tob_2->removeRow(1);
            ui->tableWidget_n_2->removeRow(1);
        }
}

void ost4_83::row_change_tprodg(int value)
{    
    //Изменяем таблицу tpodg
    int k=value;
    int k0=ui->tableWidget_tpodg->rowCount();
    if (k>k0)
        while (ui->tableWidget_tpodg->rowCount()!=value)
            ui->tableWidget_tpodg->insertRow(1);
    else
        while (ui->tableWidget_tpodg->rowCount()!=value)
            ui->tableWidget_tpodg->removeRow(1);
    //change table
        //change table Tustr
    k0=ui->tableWidget_Tustr->rowCount();
    if(k>k0)
        while (ui->tableWidget_Tustr->rowCount()!=value) {
            ui->tableWidget_Tustr->insertRow(1);
        }
    else
        while (ui->tableWidget_Tustr->rowCount()!=value) {
            ui->tableWidget_Tustr->removeRow(1);
        }
    //Изменяем таблицу lambda
    k0=ui->tableWidget_lambda->rowCount();
    if (k>k0)
        while (ui->tableWidget_lambda->rowCount()!=value)
            ui->tableWidget_lambda->insertRow(1);
    else
        while (ui->tableWidget_lambda->rowCount()!=value)
            ui->tableWidget_lambda->removeRow(1);
    //change tables s and p
    k0=ui->tableWidget_p->rowCount();
    if (k>k0)
        while (ui->tableWidget_p->rowCount()!=value)
        {
            ui->tableWidget_p->insertRow(1);
            ui->tableWidget_s->insertRow(1);
        }
    else
        while (ui->tableWidget_p->rowCount()!=value)
        {
            ui->tableWidget_p->removeRow(1);
            ui->tableWidget_s->removeRow(1);
        }
    //change table Tprovi
    k0=ui->tableWidget_tprovi->rowCount();
    if (k>k0)
        while (ui->tableWidget_tprovi->rowCount()!=value)
        {
            ui->tableWidget_tprovi->insertRow(1);
        }
    else
        while (ui->tableWidget_p->rowCount()!=value)
        {
            ui->tableWidget_tprovi->removeRow(1);
        }
    }

ost4_83::~ost4_83()
{
    delete ui;
}

void ost4_83::on_pushButton_clicked()
{
    //Расчёт Tu
    int k=ui->spinBox_k->value();
    float t_provi=0;
    float Tu=0, chislitel=0, lambda_gr=0;
    for(int i=1; i<=k; i++)
    {
        chislitel+=ui->tableWidget_lambda->item(i-1,0)->text().toFloat()*ui->tableWidget_Tustr->item(i-1,0)->text().toFloat();
        lambda_gr+=ui->tableWidget_lambda->item(i-1,0)->text().toFloat();
    }
    Tu=chislitel/lambda_gr;
    ui->lineEdit_tu->setText(QString("%1").arg(Tu));

    //Расчёт Tprov
 for(int i=1;i<=k;++i)
   {
       t_provi=0;
       int si=ui->tableWidget_s->item(i-1,0)->text().toInt();
       int pi=ui->tableWidget_p->item(i-1,0)->text().toInt();
       for(int s=1;s<=si;++s)
       {
           for(int p=1;p<=pi;++p)
           {
               t_provi+=ui->tableWidget_msp_4->item(s-1,p-1)->text().toFloat()*ui->tableWidget_tprov_sp_4->item(s-1,p-1)->text().toFloat();
           }
       }
       QTableWidgetItem *itm=new QTableWidgetItem(tr("%1").arg(t_provi));
       ui->tableWidget_tprovi->setItem(i-1,0,itm);
       ui->tabWidget->setCurrentIndex(2);
   }
 //Расчёт Tot
 float Tp=ui->lineEdit_tp_2->text().toFloat();
 float Tot;
 chislitel=0;
 for(int i=1;i<=k;++i)
 {
     chislitel+=ui->tableWidget_lambda->item(i-1,0)->text().toFloat()*(ui->tableWidget_tpodg->item(i-1,0)->text().toFloat()+ui->tableWidget_tprovi->item(i-1,0)->text().toFloat());
 }
 Tot=Tp+chislitel/lambda_gr;
 ui->lineEdit_ot->setText(QString("%1").arg(Tot));
 //Расчёт Tob
 float ni=0;
 float Tob;
 int N=ui->spinBox_N_2->value();
 chislitel=0; for(int i=1; i<=N; ++i)
 {
     chislitel+=ui->tableWidget_Tob_2->item(i-1,0)->text().toFloat()*ui->tableWidget_n_2->item(i-1,0)->text().toFloat();
     ni+=ui->tableWidget_n_2->item(i-1,0)->text().toFloat();
 }
 Tob=chislitel/ni;
 ui->lineEdit_ob->setText(QString("%1").arg(Tob));

 //Расчёт Тв
 float tv;
 tv=Tot+Tob+Tu;
 ui->lineEdit_Tv->setText(QString::number(tv));
}

void ost4_83::on_pushButton_3_clicked()
{
    float tv;
    tv=ui->lineEdit->text().toFloat()+ui->lineEdit_2->text().toFloat()+ui->lineEdit_3->text().toFloat();
    ui->lineEdit_Tv_2->setText(QString::number(tv));
    ui->tabWidget->setCurrentIndex(2);
}

void ost4_83::on_pushButton_7_clicked()
{
    //Change row of T_prov_sp
    int max_s=0;
    int k_s=ui->tableWidget_s->rowCount();
    int k_mss=ui->tableWidget_msp_4->rowCount();
    for(int i=1; i<=k_s; ++i)
    {
        if (ui->tableWidget_s->item(i-1,0)->text().toInt()>max_s)
            max_s=ui->tableWidget_s->item(i-1,0)->text().toInt();
    }
    if (max_s>k_mss)
        while (ui->tableWidget_msp_4->rowCount()!=max_s)
        {
            ui->tableWidget_msp_4->insertRow(1);
            ui->tableWidget_tprov_sp_4->insertRow(1);
        }
    else
        while (ui->tableWidget_msp_4->rowCount()!=max_s)
        {
            ui->tableWidget_msp_4->removeRow(1);
            ui->tableWidget_msp_4->removeRow(1);
        }
    //Change columg of T_prov_sp
    int max_p=0;
    int k_mpp=ui->tableWidget_msp_4->columnCount();
    int k_p=ui->tableWidget_p->rowCount();
    for(int i=1; i<=k_p; ++i)
    {
        if (ui->tableWidget_p->item(i-1,0)->text().toInt()>max_p)
            max_p=ui->tableWidget_p->item(i-1,0)->text().toInt();
    }
    if (max_p>k_mpp)
        while (ui->tableWidget_msp_4->columnCount()!=max_p)
        {
            ui->tableWidget_msp_4->insertColumn(1);
            ui->tableWidget_tprov_sp_4->insertColumn(1);
        }
    else
        while (ui->tableWidget_msp_4->columnCount()!=max_p)
        {
            ui->tableWidget_msp_4->removeColumn(1);
            ui->tableWidget_tprov_sp_4->removeColumn(1);
        }
}

void ost4_83::on_pushButton_4_clicked()
{
    this->close();
}
