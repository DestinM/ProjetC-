#ifndef ADMINISTRATEUR_H
#define ADMINISTRATEUR_H

#include <QWidget>
#include <QMainWindow>
#include <QDateTime>

namespace Ui {
class Administrateur;
}

class Administrateur : public QMainWindow
{
    Q_OBJECT

public:
    explicit Administrateur(QWidget *parent = 0);
    ~Administrateur();
public slots:
    void Action();
    void changePassword();

private:
    Ui::Administrateur *ui;
    QString code;
    QString nom;
    QString prenom;
    QDateTime dateNaissance;
    QString sexe;
    QString fonction;
    QString telephone;
    QString adresse;
    QString email;
    QString username;
    QString password;


};


#endif // ADMINISTRATEUR_H
