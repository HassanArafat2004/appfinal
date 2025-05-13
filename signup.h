#ifndef SIGNUP_H
#define SIGNUP_H

#include <QMainWindow>
#include <QString>

// Forward declarations
class MainWindow;
namespace Ui {
    class signup;
}

class signup : public QMainWindow
{
    Q_OBJECT

public:
    explicit signup(QWidget *parent = nullptr);
    ~signup();

private slots:
    void on_createAccountButton_clicked();
    void on_cancelButton_clicked();

private:
    Ui::signup *ui;
    MainWindow *mainWindow;
    bool validatePassword(const QString &password);
    bool validateEmail(const QString &email);
};

QString getLoginFilePath();

#endif
