/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 6.9.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralwidget;
    QVBoxLayout *verticalLayout;
    QSpacerItem *verticalSpacer;
    QHBoxLayout *horizontalLayout;
    QSpacerItem *horizontalSpacer;
    QWidget *loginContainer;
    QVBoxLayout *verticalLayout_2;
    QLabel *loginTitleLabel;
    QVBoxLayout *formLayout;
    QLabel *usernameLabel;
    QLineEdit *Username_box;
    QLabel *passwordLabel;
    QLineEdit *Password_box;
    QHBoxLayout *buttonLayout;
    QPushButton *handleLoginButton;
    QPushButton *goToSignupButton;
    QLabel *adminLoginLink;
    QSpacerItem *horizontalSpacer_2;
    QSpacerItem *verticalSpacer_2;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName("MainWindow");
        MainWindow->resize(1280, 720);
        MainWindow->setMinimumSize(QSize(1280, 720));
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName("centralwidget");
        verticalLayout = new QVBoxLayout(centralwidget);
        verticalLayout->setSpacing(0);
        verticalLayout->setObjectName("verticalLayout");
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        verticalSpacer = new QSpacerItem(20, 40, QSizePolicy::Policy::Minimum, QSizePolicy::Policy::Expanding);

        verticalLayout->addItem(verticalSpacer);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setSpacing(0);
        horizontalLayout->setObjectName("horizontalLayout");
        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Policy::Expanding, QSizePolicy::Policy::Minimum);

        horizontalLayout->addItem(horizontalSpacer);

        loginContainer = new QWidget(centralwidget);
        loginContainer->setObjectName("loginContainer");
        verticalLayout_2 = new QVBoxLayout(loginContainer);
        verticalLayout_2->setSpacing(32);
        verticalLayout_2->setObjectName("verticalLayout_2");
        loginTitleLabel = new QLabel(loginContainer);
        loginTitleLabel->setObjectName("loginTitleLabel");
        loginTitleLabel->setAlignment(Qt::AlignmentFlag::AlignCenter);

        verticalLayout_2->addWidget(loginTitleLabel);

        formLayout = new QVBoxLayout();
        formLayout->setSpacing(16);
        formLayout->setObjectName("formLayout");
        usernameLabel = new QLabel(loginContainer);
        usernameLabel->setObjectName("usernameLabel");

        formLayout->addWidget(usernameLabel);

        Username_box = new QLineEdit(loginContainer);
        Username_box->setObjectName("Username_box");

        formLayout->addWidget(Username_box);

        passwordLabel = new QLabel(loginContainer);
        passwordLabel->setObjectName("passwordLabel");

        formLayout->addWidget(passwordLabel);

        Password_box = new QLineEdit(loginContainer);
        Password_box->setObjectName("Password_box");
        Password_box->setEchoMode(QLineEdit::EchoMode::Password);

        formLayout->addWidget(Password_box);


        verticalLayout_2->addLayout(formLayout);

        buttonLayout = new QHBoxLayout();
        buttonLayout->setSpacing(16);
        buttonLayout->setObjectName("buttonLayout");
        handleLoginButton = new QPushButton(loginContainer);
        handleLoginButton->setObjectName("handleLoginButton");

        buttonLayout->addWidget(handleLoginButton);

        goToSignupButton = new QPushButton(loginContainer);
        goToSignupButton->setObjectName("goToSignupButton");

        buttonLayout->addWidget(goToSignupButton);


        verticalLayout_2->addLayout(buttonLayout);

        adminLoginLink = new QLabel(loginContainer);
        adminLoginLink->setObjectName("adminLoginLink");
        adminLoginLink->setAlignment(Qt::AlignCenter);
        adminLoginLink->setOpenExternalLinks(false);

        verticalLayout_2->addWidget(adminLoginLink);


        horizontalLayout->addWidget(loginContainer);

        horizontalSpacer_2 = new QSpacerItem(40, 20, QSizePolicy::Policy::Expanding, QSizePolicy::Policy::Minimum);

        horizontalLayout->addItem(horizontalSpacer_2);


        verticalLayout->addLayout(horizontalLayout);

        verticalSpacer_2 = new QSpacerItem(20, 40, QSizePolicy::Policy::Minimum, QSizePolicy::Policy::Expanding);

        verticalLayout->addItem(verticalSpacer_2);

        MainWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(MainWindow);
        menubar->setObjectName("menubar");
        menubar->setGeometry(QRect(0, 0, 1280, 24));
        MainWindow->setMenuBar(menubar);
        statusbar = new QStatusBar(MainWindow);
        statusbar->setObjectName("statusbar");
        MainWindow->setStatusBar(statusbar);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "Login", nullptr));
        MainWindow->setStyleSheet(QCoreApplication::translate("MainWindow", "QWidget {\n"
"    background-color: #f5f7fa;\n"
"    font-family: \"Segoe UI\", \"Helvetica Neue\", Arial, sans-serif;\n"
"    font-size: 14px;\n"
"    color: #000000;\n"
"}\n"
"QLabel {\n"
"    color: #000000;\n"
"}\n"
"QLabel#loginTitleLabel {\n"
"    font-size: 36px;\n"
"    font-weight: 700;\n"
"    color: #1a1a1a;\n"
"    margin-bottom: 32px;\n"
"    letter-spacing: -0.5px;\n"
"}\n"
"QLabel#usernameLabel, QLabel#passwordLabel {\n"
"    font-size: 13px;\n"
"    font-weight: 600;\n"
"    color: #4b5563;\n"
"    text-transform: uppercase;\n"
"    letter-spacing: 0.5px;\n"
"    margin-bottom: 4px;\n"
"}\n"
"QLineEdit {\n"
"    background-color: #ffffff;\n"
"    border: 1px solid #e2e8f0;\n"
"    border-radius: 6px;\n"
"    padding: 12px 16px;\n"
"    min-height: 48px;\n"
"    font-size: 15px;\n"
"    min-width: 300px;\n"
"}\n"
"QLineEdit:focus {\n"
"    border: 2px solid #2563eb;\n"
"    outline: none;\n"
"}\n"
"QPushButton {\n"
"    background-color: #2563eb;\n"
"    color: white;\n"
"    border-radius: 6px;"
                        "\n"
"    padding: 12px 24px;\n"
"    min-height: 48px;\n"
"    font-weight: 500;\n"
"    font-size: 15px;\n"
"    min-width: 120px;\n"
"}\n"
"QPushButton:hover {\n"
"    background-color: #1d4ed8;\n"
"}\n"
"QPushButton:pressed {\n"
"    background-color: #1e40af;\n"
"}\n"
"QWidget#loginContainer {\n"
"    background-color: #ffffff;\n"
"    border-radius: 12px;\n"
"    border: 1px solid #e2e8f0;\n"
"    padding: 48px;\n"
"}", nullptr));
        loginTitleLabel->setText(QCoreApplication::translate("MainWindow", "Welcome to NoteNexus", nullptr));
        usernameLabel->setText(QCoreApplication::translate("MainWindow", "USERNAME", nullptr));
        Username_box->setPlaceholderText(QCoreApplication::translate("MainWindow", "Enter your username", nullptr));
        passwordLabel->setText(QCoreApplication::translate("MainWindow", "PASSWORD", nullptr));
        Password_box->setPlaceholderText(QCoreApplication::translate("MainWindow", "Enter your password", nullptr));
        handleLoginButton->setText(QCoreApplication::translate("MainWindow", "Login", nullptr));
        goToSignupButton->setText(QCoreApplication::translate("MainWindow", "Register", nullptr));
        adminLoginLink->setText(QCoreApplication::translate("MainWindow", "<html><head/><body><p align=\"center\"><a href=\"#\"><span style=\" text-decoration: underline; color:#2563eb;\">Admin Access</span></a></p></body></html>", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
