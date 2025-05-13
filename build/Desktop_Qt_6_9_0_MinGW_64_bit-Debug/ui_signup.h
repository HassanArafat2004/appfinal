/********************************************************************************
** Form generated from reading UI file 'signup.ui'
**
** Created by: Qt User Interface Compiler version 6.9.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_SIGNUP_H
#define UI_SIGNUP_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_signup
{
public:
    QVBoxLayout *verticalLayout;
    QSpacerItem *verticalSpacer;
    QHBoxLayout *horizontalLayout;
    QSpacerItem *horizontalSpacer;
    QWidget *signupContainer;
    QVBoxLayout *verticalLayout_2;
    QLabel *signupTitleLabel;
    QLabel *adminLabel;
    QVBoxLayout *formLayout;
    QLabel *usernameLabel;
    QLineEdit *Username_box;
    QLabel *passwordLabel;
    QLineEdit *Password_box;
    QLabel *emailLabel;
    QLineEdit *Email_box;
    QHBoxLayout *buttonLayout;
    QPushButton *createAccountButton;
    QPushButton *cancelButton;
    QSpacerItem *horizontalSpacer_2;
    QSpacerItem *verticalSpacer_2;

    void setupUi(QMainWindow *signup)
    {
        if (signup->objectName().isEmpty())
            signup->setObjectName("signup");
        signup->resize(1280, 720);
        signup->setMinimumSize(QSize(1280, 720));
        verticalLayout = new QVBoxLayout(signup);
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

        signupContainer = new QWidget(signup);
        signupContainer->setObjectName("signupContainer");
        verticalLayout_2 = new QVBoxLayout(signupContainer);
        verticalLayout_2->setSpacing(32);
        verticalLayout_2->setObjectName("verticalLayout_2");
        signupTitleLabel = new QLabel(signupContainer);
        signupTitleLabel->setObjectName("signupTitleLabel");
        signupTitleLabel->setAlignment(Qt::AlignCenter);

        verticalLayout_2->addWidget(signupTitleLabel);

        adminLabel = new QLabel(signupContainer);
        adminLabel->setObjectName("adminLabel");
        adminLabel->setAlignment(Qt::AlignCenter);
        adminLabel->setStyleSheet(QString::fromUtf8("color: #2563eb; font-weight: bold;"));

        verticalLayout_2->addWidget(adminLabel);

        formLayout = new QVBoxLayout();
        formLayout->setSpacing(16);
        formLayout->setObjectName("formLayout");
        usernameLabel = new QLabel(signupContainer);
        usernameLabel->setObjectName("usernameLabel");

        formLayout->addWidget(usernameLabel);

        Username_box = new QLineEdit(signupContainer);
        Username_box->setObjectName("Username_box");

        formLayout->addWidget(Username_box);

        passwordLabel = new QLabel(signupContainer);
        passwordLabel->setObjectName("passwordLabel");

        formLayout->addWidget(passwordLabel);

        Password_box = new QLineEdit(signupContainer);
        Password_box->setObjectName("Password_box");
        Password_box->setEchoMode(QLineEdit::Password);

        formLayout->addWidget(Password_box);

        emailLabel = new QLabel(signupContainer);
        emailLabel->setObjectName("emailLabel");

        formLayout->addWidget(emailLabel);

        Email_box = new QLineEdit(signupContainer);
        Email_box->setObjectName("Email_box");

        formLayout->addWidget(Email_box);


        verticalLayout_2->addLayout(formLayout);

        buttonLayout = new QHBoxLayout();
        buttonLayout->setSpacing(16);
        buttonLayout->setObjectName("buttonLayout");
        createAccountButton = new QPushButton(signupContainer);
        createAccountButton->setObjectName("createAccountButton");

        buttonLayout->addWidget(createAccountButton);

        cancelButton = new QPushButton(signupContainer);
        cancelButton->setObjectName("cancelButton");

        buttonLayout->addWidget(cancelButton);


        verticalLayout_2->addLayout(buttonLayout);

        signup->setCentralWidget(signupContainer);

        horizontalLayout->addWidget(signupContainer);

        horizontalSpacer_2 = new QSpacerItem(40, 20, QSizePolicy::Policy::Expanding, QSizePolicy::Policy::Minimum);

        horizontalLayout->addItem(horizontalSpacer_2);


        verticalLayout->addLayout(horizontalLayout);

        verticalSpacer_2 = new QSpacerItem(20, 40, QSizePolicy::Policy::Minimum, QSizePolicy::Policy::Expanding);

        verticalLayout->addItem(verticalSpacer_2);


        retranslateUi(signup);

        QMetaObject::connectSlotsByName(signup);
    } // setupUi

    void retranslateUi(QMainWindow *signup)
    {
        signup->setWindowTitle(QCoreApplication::translate("signup", "Sign Up", nullptr));
        signup->setStyleSheet(QCoreApplication::translate("signup", "QWidget {\n"
"    background-color: #f5f7fa;\n"
"    font-family: \"Segoe UI\", \"Helvetica Neue\", Arial, sans-serif;\n"
"    font-size: 14px;\n"
"    color: #000000;\n"
"}\n"
"QLabel {\n"
"    color: #000000;\n"
"}\n"
"QLabel#signupTitleLabel {\n"
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
"    border-radius: 6px"
                        ";\n"
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
"QPushButton#cancelButton {\n"
"    background-color: #e5e7eb;\n"
"    color: #1a1a1a;\n"
"}\n"
"QPushButton#cancelButton:hover {\n"
"    background-color: #d1d5db;\n"
"}\n"
"QPushButton#cancelButton:pressed {\n"
"    background-color: #9ca3af;\n"
"}\n"
"QWidget#signupContainer {\n"
"    background-color: #ffffff;\n"
"    border-radius: 12px;\n"
"    border: 1px solid #e2e8f0;\n"
"    padding: 48px;\n"
"}", nullptr));
        signupTitleLabel->setText(QCoreApplication::translate("signup", "Create Account", nullptr));
        adminLabel->setText(QCoreApplication::translate("signup", "Please fill in all fields to create your account", nullptr));
        usernameLabel->setText(QCoreApplication::translate("signup", "USERNAME", nullptr));
        Username_box->setPlaceholderText(QCoreApplication::translate("signup", "Choose a username", nullptr));
        passwordLabel->setText(QCoreApplication::translate("signup", "PASSWORD", nullptr));
        Password_box->setPlaceholderText(QCoreApplication::translate("signup", "Choose a password", nullptr));
        emailLabel->setText(QCoreApplication::translate("signup", "EMAIL", nullptr));
        Email_box->setPlaceholderText(QCoreApplication::translate("signup", "Enter your email address", nullptr));
        createAccountButton->setText(QCoreApplication::translate("signup", "Create Account", nullptr));
        cancelButton->setText(QCoreApplication::translate("signup", "Cancel", nullptr));
    } // retranslateUi

};

namespace Ui {
    class signup: public Ui_signup {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_SIGNUP_H
