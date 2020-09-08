#include "table7_1.h"
#include "ui_table7_1.h"

table7_1::table7_1(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::table7_1)
{
    ui->setupUi(this);
}

table7_1::~table7_1()
{
    delete ui;
}

void table7_1::on_pushButton_clicked()
{
    //Расчитываем Tncp
    float tus=0, tm=0, tncp;
    for (int i=1; i<=ui->spinBoxk->value();i++)
    {
        tus+=ui->tableWidget->item(i-1, 0)->text().toFloat();
    }
    for(int i=1;i<=ui->spinBoxl->value();i++)
    {
        tm+=ui->tableWidget->item(i-1,1)->text().toFloat();
    }
    tncp=tus+tm;
    ui->lineEditncp->setText(QString("%1").arg(tncp));
    //Рассчитываем Тв
    float tcp=0, tmdr=0, tv=0;
    for (int i=1; i<=ui->spinBoxn->value();i++)
    {
        tcp+=ui->tableWidget_2->item(i-1,0)->text().toFloat();
    }
    for (int i=1; i<=ui->spinBoxm->value();i++)
    {
        tmdr+=ui->tableWidget_2->item(i-1,1)->text().toFloat();
    }
    tv=tcp+tmdr;
    ui->lineEditv->setText(QString("%1").arg(tv));
    //Рассчитываем Ктд
    float td=ui->lineEdit_td->text().toFloat();
    if (tv==0)
         tv=ui->lineEdit_tv->text().toFloat();
    float ktd=(td-tv)/td;
    ui->lineEdit_ktd->setText(QString("%1").arg(ktd));
    //Рассчитываем Кпп
    float lambdak=ui->lineEdit_lambdak->text().toFloat();
    float lambda0=ui->lineEdit_lambda0->text().toFloat();
    float kpp=lambdak/lambda0;
    ui->lineEdit_kpp->setText(QString("%1").arg(kpp));
     //Рассчитываем Кгп
    float f=ui->lineEdit_F->text().toFloat();
    float r=ui->lineEdit_R->text().toFloat();
    float kgp=f/r;
    ui->lineEdit_kgp->setText(QString("%1").arg(kgp));
    //Рассчитываем L
    float n=ui->lineEdit_N->text().toFloat();
    float l=n;
    ui->lineEdit_L->setText(QString("%1").arg(l));
    //Рассчитываем Knn
    float gn=ui->lineEdit_gn->text().toFloat();
    float gid=ui->lineEdit_gid->text().toFloat();
    float knn=(gn+gid)/gn; //Отличаются в разных методиках
    ui->lineEdit_knn->setText(QString("%1").arg(knn));
    //Рассчитываем Кус
    float nu=ui->lineEdit_Nu->text().toFloat();
    float n0=ui->lineEdit_N0->text().toFloat();
    float kus=nu/n0;
    ui->lineEdit_Kus->setText(QString("%1").arg(kus));
    //Рассчитываем Куп
    float deltau=ui->lineEdit_delta_u->text().toFloat();
    float delta0=ui->lineEdit_delta_0->text().toFloat();
    float kup=deltau/delta0;
    ui->lineEdit_kup->setText(QString("%1").arg(kup));
    //Рассчитываем Кнс
    float gcd=ui->lineEdit_Gcd->text().toFloat();
    float gccd=ui->lineEdit_Gccd->text().toFloat();
    float kns=(gcd-gccd)/gcd;
    ui->lineEdit_Kns->setText(QString("%1").arg(kns));
    //Рассчитываем q
    float k0i=0, kbi=0, qi=0, gi, q=1;
    for (int i=0; i<=ui->spinBoxn_2->value()-1;i++)
    {
        k0i=ui->tableWidget_3->item(i,0)->text().toFloat();
        kbi=ui->tableWidget_3->item(i,1)->text().toFloat();
        gi=ui->tableWidget_3->item(i,2)->text().toFloat();
        qi=k0i/kbi;
        q=q*gi*qi;
    }
    ui->lineEdit_q->setText(QString("%1").arg(q));
}

void table7_1::on_pushButton_2_clicked()
{
    ui->tableWidget->insertRow(1);
}

void table7_1::on_pushButton_3_clicked()
{
     ui->tableWidget_2->insertRow(1);
}

void table7_1::on_pushButton_4_clicked()
{
     ui->tableWidget_3->insertRow(1);
}
