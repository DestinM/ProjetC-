#include "administrator.h"
#include "ui_administrator.h"

Administrator::Administrator(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::Administrator)
{
    ui->setupUi(this);
    qDebug("entree reussie");
}

Administrator::~Administrator()
{
    delete ui;
}
