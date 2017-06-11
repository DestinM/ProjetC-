#ifndef PATIENT_H
#define PATIENT_H


#include <QWidget>
#include <QMainWindow>
#include <QDateTime>

namespace Ui {
class Patient;
}

class Patient : public QMainWindow
{
    Q_OBJECT

public:
    explicit Patient(QWidget *parent = 0);
    ~Patient();
public slots:
    void Action();


private:
    Ui::Patient *ui;
    QString code;
    QString nom;
    QString prenom;
    QString sexe;
    QString telephone;
    QString adresse;
    QDateTime dateNaissance;
    QString maladie;
    QString commentaire;
};

#endif // PATIENT_H
