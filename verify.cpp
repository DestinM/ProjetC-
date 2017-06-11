#include "verify.h"
#include "connexion.h"
#include "QSqlQuery"
#include "QString"
#include "QVariant"
#include "QDebug"
#include "QString"
#include <QSqlRecord>


verify::verify(QString &username,QString &password)
{
    this->username = username;
    this->password = password;
}
bool  verify::setting(){
    bool exist=false;
    QSqlQuery query;
        if(query.exec("SELECT username,password FROM administrators"))
        {
            while (query.next()) {
                        for(int x=0; x < query.record().count(); ++x)
                                {
                                    if(query.value(0).toString()==username and query.value(1).toString()==password){
                                        exist = true;
                                        break;
                                    }


//                                    qDebug() << query.record().fieldName(x) << " = " << query.value(x).toString();
                                }
                }
        }
        else{
            qDebug("querry don t execute");

        }

        return exist;



}
