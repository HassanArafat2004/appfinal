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
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTableWidget>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_AdminWindow
{
public:
    QWidget *centralwidget;
    QVBoxLayout *verticalLayout;
    QLabel *adminTitleLabel;
    QGroupBox *addUserGroup;
    QHBoxLayout *addUserLayout;
    QLineEdit *usernameInput;
    QLineEdit *passwordInput;
    QLineEdit *emailInput;
    QPushButton *addUserButton;
    QTableWidget *usersTable;
    QHBoxLayout *buttonLayout;
    QPushButton *loadUsersButton;
    QPushButton *saveChangesButton;
    QPushButton *deleteUserButton;
    QPushButton *reportsButton;
    QSpacerItem *horizontalSpacer;
    QPushButton *backButton;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *AdminWindow)
    {
        if (AdminWindow->objectName().isEmpty())
            AdminWindow->setObjectName("AdminWindow");
        AdminWindow->resize(1280, 720);
        AdminWindow->setMinimumSize(QSize(1280, 720));
        AdminWindow->setStyleSheet(QString::fromUtf8("QWidget {\n"
"    background-color: #f5f7fa;\n"
"    font-family: \"Segoe UI\", \"Helvetica Neue\", Arial, sans-serif;\n"
"    font-size: 14px;\n"
"    color: #000000;\n"
"}\n"
"QLabel {\n"
"    color: #000000;\n"
"}\n"
"QLabel#adminTitleLabel {\n"
"    font-size: 36px;\n"
"    font-weight: 700;\n"
"    color: #1a1a1a;\n"
"    margin-bottom: 32px;\n"
"    letter-spacing: -0.5px;\n"
"}\n"
"QTableWidget {\n"
"    background-color: #ffffff;\n"
"    border: 1px solid #e2e8f0;\n"
"    border-radius: 8px;\n"
"    gridline-color: #e2e8f0;\n"
"}\n"
"QTableWidget::item {\n"
"    padding: 8px;\n"
"    border-bottom: 1px solid #e2e8f0;\n"
"}\n"
"QTableWidget::item:selected {\n"
"    background-color: #ebf5ff;\n"
"    color: #2563eb;\n"
"}\n"
"QHeaderView::section {\n"
"    background-color: #f8fafc;\n"
"    color: #4b5563;\n"
"    padding: 12px;\n"
"    border: none;\n"
"    border-bottom: 2px solid #e2e8f0;\n"
"    font-weight: 600;\n"
"}\n"
"QPushButton {\n"
"    background-color: #2563eb;\n"
"    color: white;\n"
"   "
                        " border-radius: 6px;\n"
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
"QPushButton#backButton {\n"
"    background-color: #e5e7eb;\n"
"    color: #1a1a1a;\n"
"}\n"
"QPushButton#backButton:hover {\n"
"    background-color: #d1d5db;\n"
"}\n"
"QPushButton#backButton:pressed {\n"
"    background-color: #9ca3af;\n"
"}\n"
"QLineEdit {\n"
"    padding: 12px;\n"
"    border: 1px solid #e2e8f0;\n"
"    border-radius: 6px;\n"
"    background-color: #ffffff;\n"
"}\n"
"QLineEdit:focus {\n"
"    border-color: #2563eb;\n"
"}\n"
"QWidget#adminContainer {\n"
"    background-color: #ffffff;\n"
"    border-radius: 12px;\n"
"    border: 1px solid #e2e8f0;\n"
"    padding: 48px;\n"
"}"));
        centralwidget = new QWidget(AdminWindow);
        centralwidget->setObjectName("centralwidget");
        verticalLayout = new QVBoxLayout(centralwidget);
        verticalLayout->setSpacing(24);
        verticalLayout->setObjectName("verticalLayout");
        verticalLayout->setContentsMargins(32, 32, 32, 32);
        adminTitleLabel = new QLabel(centralwidget);
        adminTitleLabel->setObjectName("adminTitleLabel");
        adminTitleLabel->setAlignment(Qt::AlignCenter);

        verticalLayout->addWidget(adminTitleLabel);

        addUserGroup = new QGroupBox(centralwidget);
        addUserGroup->setObjectName("addUserGroup");
        addUserLayout = new QHBoxLayout(addUserGroup);
        addUserLayout->setSpacing(16);
        addUserLayout->setObjectName("addUserLayout");
        usernameInput = new QLineEdit(addUserGroup);
        usernameInput->setObjectName("usernameInput");

        addUserLayout->addWidget(usernameInput);

        passwordInput = new QLineEdit(addUserGroup);
        passwordInput->setObjectName("passwordInput");
        passwordInput->setEchoMode(QLineEdit::Password);

        addUserLayout->addWidget(passwordInput);

        emailInput = new QLineEdit(addUserGroup);
        emailInput->setObjectName("emailInput");

        addUserLayout->addWidget(emailInput);

        addUserButton = new QPushButton(addUserGroup);
        addUserButton->setObjectName("addUserButton");

        addUserLayout->addWidget(addUserButton);


        verticalLayout->addWidget(addUserGroup);

        usersTable = new QTableWidget(centralwidget);
        if (usersTable->columnCount() < 3)
            usersTable->setColumnCount(3);
        QTableWidgetItem *__qtablewidgetitem = new QTableWidgetItem();
        usersTable->setHorizontalHeaderItem(0, __qtablewidgetitem);
        QTableWidgetItem *__qtablewidgetitem1 = new QTableWidgetItem();
        usersTable->setHorizontalHeaderItem(1, __qtablewidgetitem1);
        QTableWidgetItem *__qtablewidgetitem2 = new QTableWidgetItem();
        usersTable->setHorizontalHeaderItem(2, __qtablewidgetitem2);
        usersTable->setObjectName("usersTable");
        usersTable->setColumnCount(3);
        usersTable->setRowCount(0);

        verticalLayout->addWidget(usersTable);

        buttonLayout = new QHBoxLayout();
        buttonLayout->setSpacing(16);
        buttonLayout->setObjectName("buttonLayout");
        loadUsersButton = new QPushButton(centralwidget);
        loadUsersButton->setObjectName("loadUsersButton");

        buttonLayout->addWidget(loadUsersButton);

        saveChangesButton = new QPushButton(centralwidget);
        saveChangesButton->setObjectName("saveChangesButton");

        buttonLayout->addWidget(saveChangesButton);

        deleteUserButton = new QPushButton(centralwidget);
        deleteUserButton->setObjectName("deleteUserButton");

        buttonLayout->addWidget(deleteUserButton);

        reportsButton = new QPushButton(centralwidget);
        reportsButton->setObjectName("reportsButton");

        buttonLayout->addWidget(reportsButton);

        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Policy::Expanding, QSizePolicy::Policy::Minimum);

        buttonLayout->addItem(horizontalSpacer);

        backButton = new QPushButton(centralwidget);
        backButton->setObjectName("backButton");

        buttonLayout->addWidget(backButton);


        verticalLayout->addLayout(buttonLayout);

        AdminWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(AdminWindow);
        menubar->setObjectName("menubar");
        menubar->setGeometry(QRect(0, 0, 1280, 22));
        AdminWindow->setMenuBar(menubar);
        statusbar = new QStatusBar(AdminWindow);
        statusbar->setObjectName("statusbar");
        AdminWindow->setStatusBar(statusbar);

        retranslateUi(AdminWindow);

        QMetaObject::connectSlotsByName(AdminWindow);
    } // setupUi

    void retranslateUi(QMainWindow *AdminWindow)
    {
        AdminWindow->setWindowTitle(QCoreApplication::translate("AdminWindow", "Admin Panel", nullptr));
        adminTitleLabel->setText(QCoreApplication::translate("AdminWindow", "Admin Panel", nullptr));
        addUserGroup->setTitle(QCoreApplication::translate("AdminWindow", "Add New User", nullptr));
        usernameInput->setPlaceholderText(QCoreApplication::translate("AdminWindow", "Username", nullptr));
        passwordInput->setPlaceholderText(QCoreApplication::translate("AdminWindow", "Password (8+ chars with numbers)", nullptr));
        emailInput->setPlaceholderText(QCoreApplication::translate("AdminWindow", "Email Address", nullptr));
        addUserButton->setText(QCoreApplication::translate("AdminWindow", "Add User", nullptr));
        QTableWidgetItem *___qtablewidgetitem = usersTable->horizontalHeaderItem(0);
        ___qtablewidgetitem->setText(QCoreApplication::translate("AdminWindow", "Username", nullptr));
        QTableWidgetItem *___qtablewidgetitem1 = usersTable->horizontalHeaderItem(1);
        ___qtablewidgetitem1->setText(QCoreApplication::translate("AdminWindow", "Password", nullptr));
        QTableWidgetItem *___qtablewidgetitem2 = usersTable->horizontalHeaderItem(2);
        ___qtablewidgetitem2->setText(QCoreApplication::translate("AdminWindow", "Email", nullptr));
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
