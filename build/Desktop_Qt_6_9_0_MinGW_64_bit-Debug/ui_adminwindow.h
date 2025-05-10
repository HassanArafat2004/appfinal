/********************************************************************************
** Form generated from reading UI file 'adminwindow.ui'
**
** Created by: Qt User Interface Compiler version 6.9.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_ADMINWINDOW_H
#define UI_ADMINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QTableWidget>

QT_BEGIN_NAMESPACE

class Ui_AdminWindow
{
public:
    QTableWidget *usersTable;
    QPushButton *loadUsersButton;
    QPushButton *saveChangesButton;
    QPushButton *deleteUserButton;
    QPushButton *reportsButton;
    QPushButton *backButton;

    void setupUi(QDialog *AdminWindow)
    {
        if (AdminWindow->objectName().isEmpty())
            AdminWindow->setObjectName("AdminWindow");
        AdminWindow->resize(600, 400);
        usersTable = new QTableWidget(AdminWindow);
        if (usersTable->columnCount() < 2)
            usersTable->setColumnCount(2);
        QTableWidgetItem *__qtablewidgetitem = new QTableWidgetItem();
        usersTable->setHorizontalHeaderItem(0, __qtablewidgetitem);
        QTableWidgetItem *__qtablewidgetitem1 = new QTableWidgetItem();
        usersTable->setHorizontalHeaderItem(1, __qtablewidgetitem1);
        usersTable->setObjectName("usersTable");
        usersTable->setGeometry(QRect(20, 20, 560, 300));
        loadUsersButton = new QPushButton(AdminWindow);
        loadUsersButton->setObjectName("loadUsersButton");
        loadUsersButton->setGeometry(QRect(20, 340, 100, 30));
        saveChangesButton = new QPushButton(AdminWindow);
        saveChangesButton->setObjectName("saveChangesButton");
        saveChangesButton->setGeometry(QRect(140, 340, 100, 30));
        deleteUserButton = new QPushButton(AdminWindow);
        deleteUserButton->setObjectName("deleteUserButton");
        deleteUserButton->setGeometry(QRect(260, 340, 100, 30));
        reportsButton = new QPushButton(AdminWindow);
        reportsButton->setObjectName("reportsButton");
        reportsButton->setGeometry(QRect(380, 340, 90, 30));
        backButton = new QPushButton(AdminWindow);
        backButton->setObjectName("backButton");
        backButton->setGeometry(QRect(480, 340, 100, 30));

        retranslateUi(AdminWindow);

        QMetaObject::connectSlotsByName(AdminWindow);
    } // setupUi

    void retranslateUi(QDialog *AdminWindow)
    {
        AdminWindow->setWindowTitle(QCoreApplication::translate("AdminWindow", "Admin Panel", nullptr));
        QTableWidgetItem *___qtablewidgetitem = usersTable->horizontalHeaderItem(0);
        ___qtablewidgetitem->setText(QCoreApplication::translate("AdminWindow", "Username", nullptr));
        QTableWidgetItem *___qtablewidgetitem1 = usersTable->horizontalHeaderItem(1);
        ___qtablewidgetitem1->setText(QCoreApplication::translate("AdminWindow", "Password", nullptr));
        loadUsersButton->setText(QCoreApplication::translate("AdminWindow", "Load Users", nullptr));
        saveChangesButton->setText(QCoreApplication::translate("AdminWindow", "Save Changes", nullptr));
        deleteUserButton->setText(QCoreApplication::translate("AdminWindow", "Delete User", nullptr));
        reportsButton->setText(QCoreApplication::translate("AdminWindow", "Reports", nullptr));
        backButton->setText(QCoreApplication::translate("AdminWindow", "Back", nullptr));
    } // retranslateUi

};

namespace Ui {
    class AdminWindow: public Ui_AdminWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_ADMINWINDOW_H
