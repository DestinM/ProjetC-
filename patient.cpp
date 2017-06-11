#include "patient.h"
#include "ui_Patient.h"

Patient::Patient(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::Patient)
{
    ui->setupUi(this);
    qDebug("entree reussie");
}

Patient::~Patient()
{
    delete ui;
}
