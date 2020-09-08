#include "ost83_choice.h"
#include "ui_ost83_choice.h"
#include "ost83_ready.h"
#include "ost4_83.h"
#include "ost83_whole.h"
#include "ost83_zip.h"
#include "ost4_83.h"

ost83_choice::ost83_choice(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::ost83_choice)
{
    ui->setupUi(this);
}

ost83_choice::~ost83_choice()
{
    delete ui;
}

void ost83_choice::on_buttonBox_accepted()
{
    if (ui->comboBox->currentIndex()==0)
    {
        ost83_ready *wnd=new ost83_ready(this);
        wnd->show();
    }
    if(ui->comboBox->currentIndex()==1)
    {
        ost4_83 *wnd=new ost4_83(this);
        wnd->show();
    }
    if(ui->comboBox->currentIndex()==2)
    {
        ost83_whole *wnd=new ost83_whole(this);
        wnd->show();
    }
    if(ui->comboBox->currentIndex()==3)
    {
        ost83_ZIP *wnd=new ost83_ZIP(this);
        wnd->show();
    }
}

void ost83_choice::on_buttonBox_rejected()
{
   this->close();
}
