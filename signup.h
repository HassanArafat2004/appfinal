<<<<<<< HEAD
#ifndef SIGNUP_H
#define SIGNUP_H

#include <QDialog>

namespace Ui {
class signup;
}

class signup : public QDialog
{
    Q_OBJECT

public:
    explicit signup(QWidget *parent = nullptr);
    ~signup();

private slots:
    void on_pushButton_2_clicked();
    void on_goToSignInButton_clicked();

private:
    Ui::signup *ui;
};

#endif
=======
#ifndef SIGNUP_H
#define SIGNUP_H

#include <QDialog>

namespace Ui {
class signup;
}

class signup : public QDialog
{
    Q_OBJECT

public:
    explicit signup(QWidget *parent = nullptr);
    ~signup();

private slots:
    void on_pushButton_2_clicked();
    void on_goToSignInButton_clicked();

private:
    Ui::signup *ui;
};

#endif
>>>>>>> f29377b6a49b3dc9fa486f0f187a3e82ccd13fde
