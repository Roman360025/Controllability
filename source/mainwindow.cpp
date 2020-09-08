#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "table7_1.h"
#include "ost4_83.h"
#include "ost83_choice.h"
#include "ost45_choice.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_pushButton_clicked()
{
    if (ui->comboBox->currentIndex()==0)
    {
        table7_1 *wnd=new table7_1(this);
        wnd->show();
    }
    if (ui->comboBox->currentIndex()==1)
    {
        ost83_choice *wnd=new ost83_choice(this);
        wnd->show();
    }
    if(ui->comboBox->currentIndex()==2)
    {
        ost45_choice *wnd=new ost45_choice(this);
        wnd->show();
    }
}
