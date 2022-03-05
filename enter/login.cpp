#include "login.h"
#include "ui_login.h"
#include"form.h"
#include<QMessageBox>
Login::Login(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::Login)
{
    ui->setupUi(this);
}

Login::~Login()
{
    delete ui;
}

static int n=3;
void Login::on_pushButton_clicked()
{
    n--;
    if(n>=0){
        if(ui->lineEdit->text()=="abc"&&ui->lineEdit_2->text()=="123")
        {
            this->close();
            f=new Form();
            f->show();
        }
        else{
            QMessageBox::information(NULL,"错误！","用户密码错误,还有"+tr("%1").arg(n)+"次机会");  //将数字转换为字符串·
        }
    }
    else{
        QMessageBox::information(NULL,"错误","用户密码错误3次");
        this->close();
    }
}
