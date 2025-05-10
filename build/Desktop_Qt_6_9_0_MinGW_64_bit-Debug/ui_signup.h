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
#include <QtWidgets/QDialog>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_signup
{
public:
    QGroupBox *groupBox;
    QPushButton *pushButton_2;
    QPushButton *cancelButton;
    QWidget *layoutWidget;
    QHBoxLayout *horizontalLayout;
    QLabel *label;
    QLineEdit *Username_box;
    QWidget *layoutWidget_2;
    QHBoxLayout *horizontalLayout_2;
    QLabel *label_2;
    QLineEdit *Password_box;

    void setupUi(QDialog *signup)
    {
        if (signup->objectName().isEmpty())
            signup->setObjectName("signup");
        signup->resize(686, 570);
        groupBox = new QGroupBox(signup);
        groupBox->setObjectName("groupBox");
        groupBox->setGeometry(QRect(180, 180, 291, 171));
        pushButton_2 = new QPushButton(groupBox);
        pushButton_2->setObjectName("pushButton_2");
        pushButton_2->setGeometry(QRect(10, 130, 135, 29));
        cancelButton = new QPushButton(groupBox);
        cancelButton->setObjectName("cancelButton");
        cancelButton->setGeometry(QRect(146, 130, 135, 29));
        layoutWidget = new QWidget(groupBox);
        layoutWidget->setObjectName("layoutWidget");
        layoutWidget->setGeometry(QRect(20, 50, 204, 30));
        horizontalLayout = new QHBoxLayout(layoutWidget);
        horizontalLayout->setObjectName("horizontalLayout");
        horizontalLayout->setContentsMargins(0, 0, 0, 0);
        label = new QLabel(layoutWidget);
        label->setObjectName("label");

        horizontalLayout->addWidget(label);

        Username_box = new QLineEdit(layoutWidget);
        Username_box->setObjectName("Username_box");

        horizontalLayout->addWidget(Username_box);

        layoutWidget_2 = new QWidget(groupBox);
        layoutWidget_2->setObjectName("layoutWidget_2");
        layoutWidget_2->setGeometry(QRect(20, 90, 201, 30));
        horizontalLayout_2 = new QHBoxLayout(layoutWidget_2);
        horizontalLayout_2->setObjectName("horizontalLayout_2");
        horizontalLayout_2->setContentsMargins(0, 0, 0, 0);
        label_2 = new QLabel(layoutWidget_2);
        label_2->setObjectName("label_2");

        horizontalLayout_2->addWidget(label_2);

        Password_box = new QLineEdit(layoutWidget_2);
        Password_box->setObjectName("Password_box");
        Password_box->setEchoMode(QLineEdit::EchoMode::Normal);

        horizontalLayout_2->addWidget(Password_box);


        retranslateUi(signup);

        QMetaObject::connectSlotsByName(signup);
    } // setupUi

    void retranslateUi(QDialog *signup)
    {
        signup->setWindowTitle(QCoreApplication::translate("signup", "Dialog", nullptr));
        groupBox->setTitle(QCoreApplication::translate("signup", "Sign Up", nullptr));
        pushButton_2->setText(QCoreApplication::translate("signup", "Save", nullptr));
        cancelButton->setText(QCoreApplication::translate("signup", "Cancel", nullptr));
        label->setText(QCoreApplication::translate("signup", "Username:", nullptr));
        label_2->setText(QCoreApplication::translate("signup", "Password:", nullptr));
    } // retranslateUi

};

namespace Ui {
    class signup: public Ui_signup {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_SIGNUP_H
