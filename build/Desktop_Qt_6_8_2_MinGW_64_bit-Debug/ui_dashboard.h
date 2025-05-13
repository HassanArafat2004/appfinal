/********************************************************************************
** Form generated from reading UI file 'dashboard.ui'
**
** Created by: Qt User Interface Compiler version 6.8.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_DASHBOARD_H
#define UI_DASHBOARD_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenu>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_dashboard
{
public:
    QWidget *dashboardCentralWidget;
    QVBoxLayout *verticalLayout;
    QHBoxLayout *headerLayout;
    QLabel *welcomeLabel;
    QSpacerItem *horizontalSpacer;
    QLabel *clockLabel;
    QPushButton *logoutButton;
    QHBoxLayout *statsLayout;
    QGroupBox *totalNotesGroupBox;
    QGroupBox *recentNotesGroupBox;
    QGroupBox *reportsGroupBox;
    QSpacerItem *verticalSpacer;
    QHBoxLayout *buttonLayout;
    QPushButton *notesButton;
    QPushButton *newNoteButton;
    QPushButton *reportsButton;
    QMenuBar *dashboardMenuBar;
    QMenu *menu;
    QStatusBar *dashboardStatusBar;

    void setupUi(QMainWindow *dashboard)
    {
        if (dashboard->objectName().isEmpty())
            dashboard->setObjectName("dashboard");
        dashboard->resize(1280, 720);
        dashboard->setMinimumSize(QSize(1280, 720));
        dashboardCentralWidget = new QWidget(dashboard);
        dashboardCentralWidget->setObjectName("dashboardCentralWidget");
        verticalLayout = new QVBoxLayout(dashboardCentralWidget);
        verticalLayout->setSpacing(24);
        verticalLayout->setObjectName("verticalLayout");
        verticalLayout->setContentsMargins(32, 32, 32, 32);
        headerLayout = new QHBoxLayout();
        headerLayout->setObjectName("headerLayout");
        welcomeLabel = new QLabel(dashboardCentralWidget);
        welcomeLabel->setObjectName("welcomeLabel");
        QFont font;
        font.setFamilies({QString::fromUtf8("Segoe UI")});
        font.setPointSize(16);
        font.setBold(true);
        welcomeLabel->setFont(font);

        headerLayout->addWidget(welcomeLabel);

        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Policy::Expanding, QSizePolicy::Policy::Minimum);

        headerLayout->addItem(horizontalSpacer);

        clockLabel = new QLabel(dashboardCentralWidget);
        clockLabel->setObjectName("clockLabel");
        QFont font1;
        font1.setFamilies({QString::fromUtf8("Segoe UI")});
        font1.setPointSize(14);
        clockLabel->setFont(font1);

        headerLayout->addWidget(clockLabel);

        logoutButton = new QPushButton(dashboardCentralWidget);
        logoutButton->setObjectName("logoutButton");
        logoutButton->setMinimumSize(QSize(100, 40));

        headerLayout->addWidget(logoutButton);


        verticalLayout->addLayout(headerLayout);

        statsLayout = new QHBoxLayout();
        statsLayout->setSpacing(24);
        statsLayout->setObjectName("statsLayout");
        totalNotesGroupBox = new QGroupBox(dashboardCentralWidget);
        totalNotesGroupBox->setObjectName("totalNotesGroupBox");
        QFont font2;
        font2.setFamilies({QString::fromUtf8("Segoe UI")});
        font2.setPointSize(12);
        totalNotesGroupBox->setFont(font2);

        statsLayout->addWidget(totalNotesGroupBox);

        recentNotesGroupBox = new QGroupBox(dashboardCentralWidget);
        recentNotesGroupBox->setObjectName("recentNotesGroupBox");
        recentNotesGroupBox->setFont(font2);

        statsLayout->addWidget(recentNotesGroupBox);

        reportsGroupBox = new QGroupBox(dashboardCentralWidget);
        reportsGroupBox->setObjectName("reportsGroupBox");
        reportsGroupBox->setFont(font2);

        statsLayout->addWidget(reportsGroupBox);


        verticalLayout->addLayout(statsLayout);

        verticalSpacer = new QSpacerItem(20, 40, QSizePolicy::Policy::Minimum, QSizePolicy::Policy::Expanding);

        verticalLayout->addItem(verticalSpacer);

        buttonLayout = new QHBoxLayout();
        buttonLayout->setSpacing(24);
        buttonLayout->setObjectName("buttonLayout");
        notesButton = new QPushButton(dashboardCentralWidget);
        notesButton->setObjectName("notesButton");

        buttonLayout->addWidget(notesButton);

        newNoteButton = new QPushButton(dashboardCentralWidget);
        newNoteButton->setObjectName("newNoteButton");

        buttonLayout->addWidget(newNoteButton);

        reportsButton = new QPushButton(dashboardCentralWidget);
        reportsButton->setObjectName("reportsButton");

        buttonLayout->addWidget(reportsButton);


        verticalLayout->addLayout(buttonLayout);

        dashboard->setCentralWidget(dashboardCentralWidget);
        dashboardMenuBar = new QMenuBar(dashboard);
        dashboardMenuBar->setObjectName("dashboardMenuBar");
        dashboardMenuBar->setGeometry(QRect(0, 0, 1280, 24));
        menu = new QMenu(dashboardMenuBar);
        menu->setObjectName("menu");
        dashboard->setMenuBar(dashboardMenuBar);
        dashboardStatusBar = new QStatusBar(dashboard);
        dashboardStatusBar->setObjectName("dashboardStatusBar");
        dashboard->setStatusBar(dashboardStatusBar);

        dashboardMenuBar->addAction(menu->menuAction());

        retranslateUi(dashboard);

        QMetaObject::connectSlotsByName(dashboard);
    } // setupUi

    void retranslateUi(QMainWindow *dashboard)
    {
        dashboard->setWindowTitle(QCoreApplication::translate("dashboard", "Dashboard", nullptr));
        dashboard->setStyleSheet(QCoreApplication::translate("dashboard", "QWidget {\n"
"    background-color: #f5f7fa;\n"
"    font-family: \"Segoe UI\", \"Helvetica Neue\", Arial, sans-serif;\n"
"    font-size: 14px;\n"
"    color: #000000;\n"
"}\n"
"QLabel {\n"
"    color: #000000;\n"
"}\n"
"QLabel#welcomeLabel {\n"
"    font-size: 24px;\n"
"    font-weight: 600;\n"
"    color: #1a1a1a;\n"
"}\n"
"QLabel#clockLabel {\n"
"    font-size: 18px;\n"
"    color: #4a5568;\n"
"    font-weight: 500;\n"
"}\n"
"QGroupBox {\n"
"    background-color: #ffffff;\n"
"    border: 1px solid #e2e8f0;\n"
"    border-radius: 8px;\n"
"    margin-top: 16px;\n"
"    padding: 16px;\n"
"    min-width: 300px;\n"
"    min-height: 200px;\n"
"}\n"
"QGroupBox::title {\n"
"    color: #2d3748;\n"
"    font-size: 16px;\n"
"    font-weight: 600;\n"
"    subcontrol-origin: margin;\n"
"    subcontrol-position: top left;\n"
"    padding: 0 8px;\n"
"}\n"
"QPushButton {\n"
"    background-color: #2563eb;\n"
"    color: white;\n"
"    border-radius: 6px;\n"
"    padding: 12px 24px;\n"
"    min-height: 48px;\n"
"    font-we"
                        "ight: 500;\n"
"    font-size: 15px;\n"
"}\n"
"QPushButton:hover {\n"
"    background-color: #1d4ed8;\n"
"}\n"
"QPushButton:pressed {\n"
"    background-color: #1e40af;\n"
"}\n"
"QMenuBar {\n"
"    background-color: #ffffff;\n"
"    color: #000000;\n"
"}\n"
"QMenuBar::item {\n"
"    color: #000000;\n"
"}\n"
"QStatusBar {\n"
"    color: #000000;\n"
"}\n"
"", nullptr));
        welcomeLabel->setText(QCoreApplication::translate("dashboard", "Welcome, <username>", nullptr));
        clockLabel->setText(QCoreApplication::translate("dashboard", "Time", nullptr));
        logoutButton->setText(QCoreApplication::translate("dashboard", "Logout", nullptr));
        logoutButton->setStyleSheet(QCoreApplication::translate("dashboard", "QPushButton#logoutButton {\n"
"    background-color: #e5e7eb;\n"
"    color: #1a1a1a;\n"
"    border-radius: 6px;\n"
"    padding: 8px 16px;\n"
"    font-weight: 500;\n"
"}\n"
"QPushButton#logoutButton:hover {\n"
"    background-color: #d1d5db;\n"
"}\n"
"QPushButton#logoutButton:pressed {\n"
"    background-color: #9ca3af;\n"
"}", nullptr));
        totalNotesGroupBox->setTitle(QCoreApplication::translate("dashboard", "Total Notes", nullptr));
        recentNotesGroupBox->setTitle(QCoreApplication::translate("dashboard", "Recent Notes", nullptr));
        reportsGroupBox->setTitle(QCoreApplication::translate("dashboard", "System Stats", nullptr));
        notesButton->setText(QCoreApplication::translate("dashboard", "View Notes", nullptr));
        newNoteButton->setText(QCoreApplication::translate("dashboard", "Create New Note", nullptr));
        reportsButton->setText(QCoreApplication::translate("dashboard", "View Reports", nullptr));
        menu->setTitle(QCoreApplication::translate("dashboard", "\342\200\216 ", nullptr));
    } // retranslateUi

};

namespace Ui {
    class dashboard: public Ui_dashboard {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_DASHBOARD_H
