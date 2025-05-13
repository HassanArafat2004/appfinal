/********************************************************************************
** Form generated from reading UI file 'reports.ui'
**
** Created by: Qt User Interface Compiler version 6.8.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_REPORTS_H
#define UI_REPORTS_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTableView>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_reports
{
public:
    QWidget *centralwidget;
    QVBoxLayout *verticalLayout;
    QLabel *reportsPageTitleLabel;
    QWidget *widget;
    QHBoxLayout *horizontalLayout;
    QLabel *totalNotesLabel;
    QSpacerItem *horizontalSpacer;
    QLabel *reportTypeLabel;
    QComboBox *reportTypeComboBox;
    QPushButton *generateReportButton;
    QTableView *reportTableView;
    QHBoxLayout *buttonLayout;
    QPushButton *exportReportButton;
    QPushButton *backToDashboardButton;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *reports)
    {
        if (reports->objectName().isEmpty())
            reports->setObjectName("reports");
        reports->resize(1280, 720);
        reports->setMinimumSize(QSize(1280, 720));
        centralwidget = new QWidget(reports);
        centralwidget->setObjectName("centralwidget");
        verticalLayout = new QVBoxLayout(centralwidget);
        verticalLayout->setSpacing(24);
        verticalLayout->setObjectName("verticalLayout");
        verticalLayout->setContentsMargins(32, 32, 32, 32);
        reportsPageTitleLabel = new QLabel(centralwidget);
        reportsPageTitleLabel->setObjectName("reportsPageTitleLabel");
        QFont font;
        font.setFamilies({QString::fromUtf8("Segoe UI")});
        reportsPageTitleLabel->setFont(font);

        verticalLayout->addWidget(reportsPageTitleLabel);

        widget = new QWidget(centralwidget);
        widget->setObjectName("widget");
        horizontalLayout = new QHBoxLayout(widget);
        horizontalLayout->setSpacing(16);
        horizontalLayout->setObjectName("horizontalLayout");
        totalNotesLabel = new QLabel(widget);
        totalNotesLabel->setObjectName("totalNotesLabel");

        horizontalLayout->addWidget(totalNotesLabel);

        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Policy::Expanding, QSizePolicy::Policy::Minimum);

        horizontalLayout->addItem(horizontalSpacer);

        reportTypeLabel = new QLabel(widget);
        reportTypeLabel->setObjectName("reportTypeLabel");

        horizontalLayout->addWidget(reportTypeLabel);

        reportTypeComboBox = new QComboBox(widget);
        reportTypeComboBox->addItem(QString());
        reportTypeComboBox->addItem(QString());
        reportTypeComboBox->setObjectName("reportTypeComboBox");

        horizontalLayout->addWidget(reportTypeComboBox);

        generateReportButton = new QPushButton(widget);
        generateReportButton->setObjectName("generateReportButton");

        horizontalLayout->addWidget(generateReportButton);


        verticalLayout->addWidget(widget);

        reportTableView = new QTableView(centralwidget);
        reportTableView->setObjectName("reportTableView");
        reportTableView->setAlternatingRowColors(true);
        reportTableView->setSelectionMode(QAbstractItemView::SingleSelection);
        reportTableView->setSelectionBehavior(QAbstractItemView::SelectRows);

        verticalLayout->addWidget(reportTableView);

        buttonLayout = new QHBoxLayout();
        buttonLayout->setSpacing(16);
        buttonLayout->setObjectName("buttonLayout");
        exportReportButton = new QPushButton(centralwidget);
        exportReportButton->setObjectName("exportReportButton");

        buttonLayout->addWidget(exportReportButton);

        backToDashboardButton = new QPushButton(centralwidget);
        backToDashboardButton->setObjectName("backToDashboardButton");

        buttonLayout->addWidget(backToDashboardButton);


        verticalLayout->addLayout(buttonLayout);

        reports->setCentralWidget(centralwidget);
        menubar = new QMenuBar(reports);
        menubar->setObjectName("menubar");
        menubar->setGeometry(QRect(0, 0, 1280, 24));
        reports->setMenuBar(menubar);
        statusbar = new QStatusBar(reports);
        statusbar->setObjectName("statusbar");
        reports->setStatusBar(statusbar);

        retranslateUi(reports);

        QMetaObject::connectSlotsByName(reports);
    } // setupUi

    void retranslateUi(QMainWindow *reports)
    {
        reports->setWindowTitle(QCoreApplication::translate("reports", "Reports", nullptr));
        reports->setStyleSheet(QCoreApplication::translate("reports", "QWidget {\n"
"    background-color: #f5f7fa;\n"
"    font-family: \"Segoe UI\", \"Helvetica Neue\", Arial, sans-serif;\n"
"    font-size: 14px;\n"
"    color: #000000;\n"
"}\n"
"QLabel {\n"
"    color: #000000;\n"
"}\n"
"QLabel#reportsPageTitleLabel {\n"
"    font-size: 24px;\n"
"    font-weight: 600;\n"
"    color: #1a1a1a;\n"
"}\n"
"QTableView {\n"
"    background-color: #ffffff;\n"
"    border: 1px solid #e2e8f0;\n"
"    border-radius: 6px;\n"
"    gridline-color: #e5e7eb;\n"
"}\n"
"QTableView::item {\n"
"    padding: 8px;\n"
"}\n"
"QTableView::item:selected {\n"
"    background-color: #e5e7eb;\n"
"    color: #1f2937;\n"
"}\n"
"QPushButton {\n"
"    background-color: #2563eb;\n"
"    color: white;\n"
"    border-radius: 6px;\n"
"    padding: 12px 24px;\n"
"    min-height: 48px;\n"
"    font-weight: 500;\n"
"    font-size: 15px;\n"
"}\n"
"QPushButton:hover {\n"
"    background-color: #1d4ed8;\n"
"}\n"
"QPushButton:pressed {\n"
"    background-color: #1e40af;\n"
"}\n"
"QPushButton#backToDashboardButton {\n"
""
                        "    background-color: #e5e7eb;\n"
"    color: #1a1a1a;\n"
"}\n"
"QPushButton#backToDashboardButton:hover {\n"
"    background-color: #d1d5db;\n"
"}\n"
"QLabel#totalNotesLabel {\n"
"    color: #2563eb;\n"
"    font-weight: 600;\n"
"    font-size: 16px;\n"
"}\n"
"QComboBox {\n"
"    background-color: #ffffff;\n"
"    border: 1px solid #e2e8f0;\n"
"    border-radius: 6px;\n"
"    padding: 8px 12px;\n"
"    min-width: 200px;\n"
"    color: #000000;\n"
"}\n"
"QComboBox:focus {\n"
"    border: 2px solid #2563eb;\n"
"    outline: none;\n"
"}\n"
"QComboBox::drop-down {\n"
"    border: none;\n"
"    width: 20px;\n"
"}\n"
"QComboBox::down-arrow {\n"
"    image: none;\n"
"    border: none;\n"
"}", nullptr));
        reportsPageTitleLabel->setText(QCoreApplication::translate("reports", "Reports", nullptr));
        totalNotesLabel->setText(QCoreApplication::translate("reports", "Total Notes: 0", nullptr));
        reportTypeLabel->setText(QCoreApplication::translate("reports", "Report Type:", nullptr));
        reportTypeComboBox->setItemText(0, QCoreApplication::translate("reports", "Total Notes Per User", nullptr));
        reportTypeComboBox->setItemText(1, QCoreApplication::translate("reports", "Most Accessed Notes", nullptr));

        generateReportButton->setText(QCoreApplication::translate("reports", "Generate", nullptr));
        exportReportButton->setText(QCoreApplication::translate("reports", "Export Report", nullptr));
        backToDashboardButton->setText(QCoreApplication::translate("reports", "Back to Dashboard", nullptr));
    } // retranslateUi

};

namespace Ui {
    class reports: public Ui_reports {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_REPORTS_H
