#include "login.h"
#include "ui_login.h"
#include "connexion.h"
#include "verify.h"
#include "patient.h"
#include "administrateur.h"


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
    if(verification.setting() == 'A'){

        this->hide();
        Administrateur *adminpage= new Administrateur;
        adminpage->show();
    }
    if(verification.setting() == 'U'){

        this->hide();
        Patient *patient= new Patient;
        patient->show();
    }
    if(verification.setting() == 'F'){

        ui->message->setText("mauvais identifiant");
    }

}
