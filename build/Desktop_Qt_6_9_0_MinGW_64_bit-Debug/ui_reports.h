/********************************************************************************
** Form generated from reading UI file 'reports.ui'
**
** Created by: Qt User Interface Compiler version 6.9.0
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
#include <QtWidgets/QPushButton>
#include <QtWidgets/QTableView>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_reports
{
public:
    QVBoxLayout *verticalLayout;
    QLabel *reportsPageTitleLabel;
    QWidget *widget;
    QHBoxLayout *horizontalLayout;
    QLabel *reportTypeLabel;
    QComboBox *reportTypeComboBox;
    QPushButton *generateReportButton;
    QTableView *reportTableView;
    QPushButton *exportReportButton;
    QPushButton *backToDashboardButton;

    void setupUi(QWidget *reports)
    {
        if (reports->objectName().isEmpty())
            reports->setObjectName("reports");
        reports->resize(400, 300);
        verticalLayout = new QVBoxLayout(reports);
        verticalLayout->setObjectName("verticalLayout");
        reportsPageTitleLabel = new QLabel(reports);
        reportsPageTitleLabel->setObjectName("reportsPageTitleLabel");
        QFont font;
        font.setPointSize(14);
        font.setBold(true);
        reportsPageTitleLabel->setFont(font);

        verticalLayout->addWidget(reportsPageTitleLabel);

        widget = new QWidget(reports);
        widget->setObjectName("widget");
        horizontalLayout = new QHBoxLayout(widget);
        horizontalLayout->setObjectName("horizontalLayout");
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

        reportTableView = new QTableView(reports);
        reportTableView->setObjectName("reportTableView");

        verticalLayout->addWidget(reportTableView);

        exportReportButton = new QPushButton(reports);
        exportReportButton->setObjectName("exportReportButton");

        verticalLayout->addWidget(exportReportButton);

        backToDashboardButton = new QPushButton(reports);
        backToDashboardButton->setObjectName("backToDashboardButton");

        verticalLayout->addWidget(backToDashboardButton);


        retranslateUi(reports);

        QMetaObject::connectSlotsByName(reports);
    } // setupUi

    void retranslateUi(QWidget *reports)
    {
        reports->setWindowTitle(QCoreApplication::translate("reports", "Form", nullptr));
        reportsPageTitleLabel->setText(QCoreApplication::translate("reports", "Reports Page", nullptr));
        reportTypeLabel->setText(QCoreApplication::translate("reports", "Report Type:", nullptr));
        reportTypeComboBox->setItemText(0, QCoreApplication::translate("reports", "Total Notes Per User", nullptr));
        reportTypeComboBox->setItemText(1, QCoreApplication::translate("reports", "Most Accessed Notes", nullptr));

        generateReportButton->setText(QCoreApplication::translate("reports", "Generate", nullptr));
        exportReportButton->setText(QCoreApplication::translate("reports", "Export", nullptr));
        backToDashboardButton->setText(QCoreApplication::translate("reports", "Back to Dashboard", nullptr));
    } // retranslateUi

};

namespace Ui {
    class reports: public Ui_reports {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_REPORTS_H
