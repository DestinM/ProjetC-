#ifndef INSCRIRE_AGENT_H
#define INSCRIRE_AGENT_H
#include <QString>
#include <QDate>
#include <QDateTime>


class Inscrire_agent
{
public:
    Inscrire_agent(QString *,QString *,QString *,QDate *,QChar *,QString *,QString *,QString *,QString *,QString *,QString *);
    bool setting();

private:
    QString code;
    QString nom;
    QString prenom;
    QDate date_naissance;
    QChar sexe;
    QString role;
    QString telephone;
    QString adresse;
    QString email;
    QString username;
    QString password;

};

#endif // INSCRIRE_AGENT_H
