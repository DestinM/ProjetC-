#include "patient.h"
#include "administrateur.h"
#include "login.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    login w;
    w.setFixedSize(800,600);
    w.show();


    return a.exec();
}
