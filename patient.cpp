#include "patient.h"
#include "ui_Patient.h"
#include <QDebug>
#include <QSqlQuery>
#include<QMessageBox>
#include <QObject>
#include <QSqlQueryModel>
#include <QSqlRecord>
#include <QTableView>
#include <QStandardItemModel>

Patient::Patient(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::Patient)
{
    ui->setupUi(this);
    connect(ui->savePatient,SIGNAL(clicked()),this,SLOT(Action()));
    connect(ui->changePasswordButton,SIGNAL(clicked()),this,SLOT(changePassword()));


       //sexe
       ui->sexe->addItem("--none--");
       ui->sexe->addItem("masculin");
       ui->sexe->addItem("feminin");

       //table
       QSqlQueryModel *model = new QSqlQueryModel;

               model->setQuery("SELECT * FROM patient");

       //        for (int i = 0; i < model.rowCount(); ++i) {
       //            int id = model.record(i).value("id").toInt();
       //            QString name = model.record(i).value("name").toString();
       //            qDebug() << id << name;
       //        }

       //        model.setData(model.index(row, column), 75000);
       //        model.submitAll();



                //model->setHorizontalHeaderLabels(columnNames);





               qDebug() << model->rowCount();

               ui->tableList->setModel(model);


}

Patient::~Patient()
{
    delete ui;
}

void Patient::Action(){
    QSqlQuery query;


    //les contenues des champs
    code = ui->code->text();
    nom = ui->nom->text();
    prenom = ui->prenom->text();
    dateNaissance = ui->dateNaissance->dateTime();
    qDebug() << dateNaissance;
    sexe = ui->sexe->currentText();
    telephone = ui->telephone->text();
    adresse = ui->adresse->text();
    maladie = ui->maladie->text();
    commentaire = ui->commentaire->text();




    //verification

    //insertion apres verification
    if(true){

        query.prepare("insert into patient (code, Nom, Prenom, Sexe,Adresse, Telephone,Maladie,Commentaires ,Date_naissance) values(?, ?, ?, ?, ?, ?, ?, ?, ?) ");

        query.addBindValue(code);
        query.addBindValue(nom);
        query.addBindValue(prenom);
        query.addBindValue(dateNaissance);
        query.addBindValue(sexe);
        query.addBindValue(telephone);
        query.addBindValue(adresse);
        query.addBindValue(maladie);
        query.addBindValue(commentaire);

        //qDebug() << query.exec();

            qDebug() << code << nom << prenom << maladie << dateNaissance << telephone << adresse << commentaire;

        if(query.exec() ) {
            qDebug() << "insertion reussie";
        } else {
            qDebug() << "insertion echoued";
        }

    }
    else{

    }


}

void Patient::changePassword(){
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







