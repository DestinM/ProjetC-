#include "connexion.h"
#include <QtSql>
#include "QSqlDatabase"

connexion::connexion()
{

}
void connexion::connect(){
    QSqlDatabase db = QSqlDatabase::addDatabase("QMYSQL");
    db.setHostName("localhost");
    db.setUserName("root");
    db.setPassword("DAANA");
    db.setDatabaseName("HOSPITAL");
    if(db.open())
    {
       qDebug("connexion reussie");
    }
    else
    {
         qDebug("connexion ratee");
         qDebug(db.lastError().text().toLatin1());
    }

}
