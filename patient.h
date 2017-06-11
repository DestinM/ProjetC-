#ifndef PATIENT_H
#define PATIENT_H


#include <QWidget>
#include <QMainWindow>

namespace Ui {
class Patient;
}

class Patient : public QMainWindow
{
    Q_OBJECT

public:
    explicit Patient(QWidget *parent = 0);
    ~Patient();

private:
    Ui::Patient *ui;
};

#endif // PATIENT_H
