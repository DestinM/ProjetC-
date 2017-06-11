#include "patient.h"
#include "ui_Patient.h"
#include <QDebug>
#include <QSqlQuery>

Patient::Patient(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::Patient)
{
    ui->setupUi(this);
    connect(ui->savePatient,SIGNAL(clicked()),this,SLOT(Action()));


       //sexe
       ui->sexe->addItem("--none--");
       ui->sexe->addItem("masculin");
       ui->sexe->addItem("feminin");


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
        //requette d'insertion
        bool result;
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



   // qDebug() << code;
}

