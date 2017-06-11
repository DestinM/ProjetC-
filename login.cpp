#include "login.h"
#include "ui_login.h"
#include "connexion.h"
#include "verify.h"
#include "administrator.h"


login::login(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    connexion con;
    con.connect();
    ui->setupUi(this);
    connect(ui->loginButton,SIGNAL(clicked()),this,SLOT(Action()));
}

login::~login()
{
    delete ui;
}

void login::Action(){
    this->show();
    username=ui->username->text();
    password=ui->password->text();
    verify verification(username,password);
    if(verification.setting()){

        this->hide();
        Administrator *adminpage= new Administrator;
        adminpage->show();
    }
    else{
        ui->msg->setText("wrong password");
    }

}
