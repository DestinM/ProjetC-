#include "administrateur.h"
#include "ui_administrateur.h"
#include <QSqlQuery>
#include <QDebug>
#include <QSqlQueryModel>
#include <QSqlRecord>
#include <QTableView>
#include <QStandardItemModel>

Administrateur::Administrateur(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::Administrateur)
{
    ui->setupUi(this);
    connect(ui->saveAgentButton,SIGNAL(clicked()),this,SLOT(Action()));
    connect(ui->changePasswordButton,SIGNAL(clicked()),this,SLOT(changePassword()));


       //sexe
       ui->sexe->addItem("--none--");
       ui->sexe->addItem("masculin");
       ui->sexe->addItem("feminin");

       //role
       ui->fonction->addItem("docteur");
       ui->fonction->addItem("secretaire");

       //table
       QSqlQueryModel *model = new QSqlQueryModel;

               model->setQuery("SELECT * FROM agent_medicales");

     model->removeColumn(4);




               qDebug() << model->rowCount();

               ui->tableList->setModel(model);
}

Administrateur::~Administrateur()
{
    delete ui;
}
void Administrateur::Action(){
    QSqlQuery query;


    //les contenues des champs
    code = ui->code->text();
    username = ui->username->text();
    nom = ui->nom->text();
    prenom = ui->prenom->text();
    password = ui->password->text();
    fonction = ui->fonction->currentText();
    dateNaissance = ui->dateNaissance->dateTime();
    qDebug() << dateNaissance;
    sexe = ui->sexe->currentText();
    telephone = ui->telephone->text();
    adresse = ui->adresse->text();
    email = ui->email->text();



    //verification
    if(username == "admin"){
//        ui->error_msg->setText("echec,admin existant");
    }
    else{
            //insertion apres verification
            if(true){
                //requette d'insertion
                bool result;
                query.prepare("insert into agent_medicales (username, nom, prenom, password, role, Date_naissance, sexe, telephone, adresse, email) values(?, ?, ?, ?, ?, ?, ?, ?, ?, ?) ");

                query.addBindValue(username);
                query.addBindValue(nom);
                query.addBindValue(prenom);
                query.addBindValue(password);
                query.addBindValue(fonction);
                query.addBindValue(dateNaissance);
                query.addBindValue(sexe);
                query.addBindValue(telephone);
                query.addBindValue(adresse);
                query.addBindValue(email);

                //qDebug() << query.exec();

                    qDebug() << username << nom << prenom << password << dateNaissance << telephone << adresse << email;

                if(query.exec() ) {
                    qDebug() << "insertion reussie";
                } else {
                    qDebug() << "insertion echoued";
                }

            }
            else{
//                ui->error_msg->setText("echec");
            }

    }

   // qDebug() << code;
}
void Administrateur::changePassword(){
    QSqlQuery query;


    //les contenues des champs
    password = ui->newpassword->text();

    //verification

    //insertion apres verification
    if(true){
        query.prepare("update agent_medicales set password=?");

        query.addBindValue(password);

        if(query.exec() ) {
            ui->mymsg->setText("reussie");
            qDebug() << "modification reussie";
        } else {
            qDebug() << "modification echoued";
        }


    }
    else{

    }




   // qDebug() << code;
}

