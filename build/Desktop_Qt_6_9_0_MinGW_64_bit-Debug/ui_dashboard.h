/********************************************************************************
** Form generated from reading UI file 'dashboard.ui'
**
** Created by: Qt User Interface Compiler version 6.9.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_DASHBOARD_H
#define UI_DASHBOARD_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenu>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_dashboard
{
public:
    QWidget *dashboardCentralWidget;
    QLabel *welcomeLabel;
    QLabel *clockLabel;
    QGroupBox *totalNotesGroupBox;
    QGroupBox *recentNotesGroupBox;
    QGroupBox *reportsGroupBox;
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
        dashboard->resize(1196, 600);
        dashboardCentralWidget = new QWidget(dashboard);
        dashboardCentralWidget->setObjectName("dashboardCentralWidget");
        welcomeLabel = new QLabel(dashboardCentralWidget);
        welcomeLabel->setObjectName("welcomeLabel");
        welcomeLabel->setGeometry(QRect(460, 10, 241, 20));
        QFont font;
        font.setPointSize(14);
        font.setBold(true);
        welcomeLabel->setFont(font);
        clockLabel = new QLabel(dashboardCentralWidget);
        clockLabel->setObjectName("clockLabel");
        clockLabel->setGeometry(QRect(1060, 0, 101, 20));
        QFont font1;
        font1.setPointSize(14);
        font1.setUnderline(true);
        clockLabel->setFont(font1);
        totalNotesGroupBox = new QGroupBox(dashboardCentralWidget);
        totalNotesGroupBox->setObjectName("totalNotesGroupBox");
        totalNotesGroupBox->setGeometry(QRect(130, 100, 120, 80));
        QFont font2;
        font2.setPointSize(12);
        totalNotesGroupBox->setFont(font2);
        recentNotesGroupBox = new QGroupBox(dashboardCentralWidget);
        recentNotesGroupBox->setObjectName("recentNotesGroupBox");
        recentNotesGroupBox->setGeometry(QRect(500, 100, 151, 81));
        recentNotesGroupBox->setFont(font2);
        reportsGroupBox = new QGroupBox(dashboardCentralWidget);
        reportsGroupBox->setObjectName("reportsGroupBox");
        reportsGroupBox->setGeometry(QRect(860, 100, 120, 80));
        reportsGroupBox->setFont(font2);
        notesButton = new QPushButton(dashboardCentralWidget);
        notesButton->setObjectName("notesButton");
        notesButton->setGeometry(QRect(30, 490, 361, 29));
        newNoteButton = new QPushButton(dashboardCentralWidget);
        newNoteButton->setObjectName("newNoteButton");
        newNoteButton->setGeometry(QRect(420, 490, 361, 29));
        reportsButton = new QPushButton(dashboardCentralWidget);
        reportsButton->setObjectName("reportsButton");
        reportsButton->setGeometry(QRect(810, 490, 361, 29));
        dashboard->setCentralWidget(dashboardCentralWidget);
        dashboardMenuBar = new QMenuBar(dashboard);
        dashboardMenuBar->setObjectName("dashboardMenuBar");
        dashboardMenuBar->setGeometry(QRect(0, 0, 1196, 21));
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
        dashboard->setWindowTitle(QCoreApplication::translate("dashboard", "MainWindow", nullptr));
        welcomeLabel->setText(QCoreApplication::translate("dashboard", "Weclome, <username>", nullptr));
        clockLabel->setText(QCoreApplication::translate("dashboard", "Time", nullptr));
        totalNotesGroupBox->setTitle(QCoreApplication::translate("dashboard", "Total Notes", nullptr));
        recentNotesGroupBox->setTitle(QCoreApplication::translate("dashboard", "Recent Notes", nullptr));
        reportsGroupBox->setTitle(QCoreApplication::translate("dashboard", "Reports", nullptr));
        notesButton->setText(QCoreApplication::translate("dashboard", "Notes", nullptr));
        newNoteButton->setText(QCoreApplication::translate("dashboard", "New Note", nullptr));
        reportsButton->setText(QCoreApplication::translate("dashboard", "Reports", nullptr));
        menu->setTitle(QCoreApplication::translate("dashboard", "\342\200\216 ", nullptr));
    } // retranslateUi

};

namespace Ui {
    class dashboard: public Ui_dashboard {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_DASHBOARD_H
