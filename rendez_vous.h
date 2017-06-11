#ifndef RENDEZ_VOUS_H
#define RENDEZ_VOUS_H

#include <QString>
#include <QDateTime>
class rendez_vous
{
public:
    rendez_vous(QString &,QDateTime &);
    bool setting();

private:
    QString val;
    QDateTime date;
};

#endif // RENDEZ_VOUS_H
