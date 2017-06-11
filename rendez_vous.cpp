#include "rendez_vous.h"
#include <QSqlQuery>
#include "QVariant"
#include "QDebug"
#include "QString"
#include <QSqlRecord>
#include <QDateTime>

rendez_vous::rendez_vous(QString &val,QDateTime &date)
{
    this->val = val;
    this->date =date;
}
bool rendez_vous::setting(){
    qDebug() << date;

    bool exist=false;
    QSqlQuery query;
        if(query.exec("SELECT code FROM patient") == true)
        {
//            UPDATE patient SET rendez_vous = :current
             query.exec("UPDATE patient SET rendez_vous = :current ");
            query.bindValue(":current_dp",date);

            while (query.next()) {
                        for(int x=0; x < query.record().count(); ++x)
                                {
                                    if(query.value(0).toString()==val){
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
