#ifndef LOGIN_H
#define LOGIN_H

#include <QMainWindow>
#include <QWidget>


namespace Ui {
class MainWindow;
}

class login : public QMainWindow
{
    Q_OBJECT

public:
    void setting();
    login(QWidget *parent = 0);
    ~login();
public slots:
    void Action();

private:
    Ui::MainWindow *ui;
    QString username;
    QString password;
};
#endif // LOGIN_H
