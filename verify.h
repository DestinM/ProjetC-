#ifndef VERIFY_H
#define VERIFY_H

#include <QString>
class verify
{
public:
    verify(QString &,QString &);
    bool setting();
private:
    QString username;
    QString password;
};

#endif // VERIFY_H
