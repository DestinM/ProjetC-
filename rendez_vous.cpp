#include "rendez_vous.h"
#include <QSqlQuery>
#include "QVariant"
#include "QDebug"
#include "QString"
#include <QSqlRecord>

rendez_vous::rendez_vous(QString &val)
{

}
bool rendez_vous::setting(){
    bool exist=false;
    QSqlQuery query;
        if(query.exec("SELECT code FROM patient"))
        {
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
