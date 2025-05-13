/********************************************************************************
** Form generated from reading UI file 'notelist.ui'
**
** Created by: Qt User Interface Compiler version 6.8.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_NOTELIST_H
#define UI_NOTELIST_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QTableWidget>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_NoteList
{
public:
    QVBoxLayout *verticalLayout;
    QLabel *notesPageTitleLabel;
    QWidget *widget;
    QHBoxLayout *horizontalLayout;
    QLabel *searchLabel;
    QLineEdit *searchLineEdit;
    QComboBox *typeFilterComboBox;
    QTableWidget *notesTableWidget;
    QHBoxLayout *buttonLayout;
    QPushButton *createNoteButton;
    QPushButton *deleteNoteButton;
    QSpacerItem *horizontalSpacer;
    QPushButton *backToDashboardButton;

    void setupUi(QWidget *NoteList)
    {
        if (NoteList->objectName().isEmpty())
            NoteList->setObjectName("NoteList");
        NoteList->resize(1280, 720);
        NoteList->setMinimumSize(QSize(1280, 720));
        verticalLayout = new QVBoxLayout(NoteList);
        verticalLayout->setSpacing(24);
        verticalLayout->setObjectName("verticalLayout");
        verticalLayout->setContentsMargins(32, 32, 32, 32);
        notesPageTitleLabel = new QLabel(NoteList);
        notesPageTitleLabel->setObjectName("notesPageTitleLabel");
        QFont font;
        font.setFamilies({QString::fromUtf8("Segoe UI")});
        notesPageTitleLabel->setFont(font);

        verticalLayout->addWidget(notesPageTitleLabel);

        widget = new QWidget(NoteList);
        widget->setObjectName("widget");
        horizontalLayout = new QHBoxLayout(widget);
        horizontalLayout->setSpacing(16);
        horizontalLayout->setObjectName("horizontalLayout");
        searchLabel = new QLabel(widget);
        searchLabel->setObjectName("searchLabel");

        horizontalLayout->addWidget(searchLabel);

        searchLineEdit = new QLineEdit(widget);
        searchLineEdit->setObjectName("searchLineEdit");

        horizontalLayout->addWidget(searchLineEdit);

        typeFilterComboBox = new QComboBox(widget);
        typeFilterComboBox->addItem(QString());
        typeFilterComboBox->addItem(QString());
        typeFilterComboBox->addItem(QString());
        typeFilterComboBox->setObjectName("typeFilterComboBox");

        horizontalLayout->addWidget(typeFilterComboBox);


        verticalLayout->addWidget(widget);

        notesTableWidget = new QTableWidget(NoteList);
        if (notesTableWidget->columnCount() < 3)
            notesTableWidget->setColumnCount(3);
        QTableWidgetItem *__qtablewidgetitem = new QTableWidgetItem();
        notesTableWidget->setHorizontalHeaderItem(0, __qtablewidgetitem);
        QTableWidgetItem *__qtablewidgetitem1 = new QTableWidgetItem();
        notesTableWidget->setHorizontalHeaderItem(1, __qtablewidgetitem1);
        QTableWidgetItem *__qtablewidgetitem2 = new QTableWidgetItem();
        notesTableWidget->setHorizontalHeaderItem(2, __qtablewidgetitem2);
        notesTableWidget->setObjectName("notesTableWidget");
        notesTableWidget->setAlternatingRowColors(true);
        notesTableWidget->setSelectionMode(QAbstractItemView::SingleSelection);
        notesTableWidget->setSelectionBehavior(QAbstractItemView::SelectRows);
        notesTableWidget->setEditTriggers(QAbstractItemView::NoEditTriggers);

        verticalLayout->addWidget(notesTableWidget);

        buttonLayout = new QHBoxLayout();
        buttonLayout->setSpacing(16);
        buttonLayout->setObjectName("buttonLayout");
        createNoteButton = new QPushButton(NoteList);
        createNoteButton->setObjectName("createNoteButton");

        buttonLayout->addWidget(createNoteButton);

        deleteNoteButton = new QPushButton(NoteList);
        deleteNoteButton->setObjectName("deleteNoteButton");

        buttonLayout->addWidget(deleteNoteButton);

        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Policy::Expanding, QSizePolicy::Policy::Minimum);

        buttonLayout->addItem(horizontalSpacer);

        backToDashboardButton = new QPushButton(NoteList);
        backToDashboardButton->setObjectName("backToDashboardButton");

        buttonLayout->addWidget(backToDashboardButton);


        verticalLayout->addLayout(buttonLayout);


        retranslateUi(NoteList);

        QMetaObject::connectSlotsByName(NoteList);
    } // setupUi

    void retranslateUi(QWidget *NoteList)
    {
        NoteList->setWindowTitle(QCoreApplication::translate("NoteList", "Notes List", nullptr));
        NoteList->setStyleSheet(QCoreApplication::translate("NoteList", "QWidget {\n"
"    background-color: #f5f7fa;\n"
"    font-family: \"Segoe UI\", \"Helvetica Neue\", Arial, sans-serif;\n"
"    font-size: 14px;\n"
"    color: #000000;\n"
"}\n"
"QLabel {\n"
"    color: #000000;\n"
"}\n"
"QLabel#notesPageTitleLabel {\n"
"    font-size: 24px;\n"
"    font-weight: 600;\n"
"    color: #1a1a1a;\n"
"}\n"
"QTableWidget {\n"
"    background-color: #ffffff;\n"
"    border: 1px solid #e2e8f0;\n"
"    border-radius: 6px;\n"
"    gridline-color: #e5e7eb;\n"
"}\n"
"QTableWidget::item {\n"
"    padding: 8px;\n"
"}\n"
"QTableWidget::item:selected {\n"
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
"QLineEdit {\n"
"    background-color"
                        ": #ffffff;\n"
"    border: 1px solid #e2e8f0;\n"
"    border-radius: 6px;\n"
"    padding: 8px 12px;\n"
"    min-height: 24px;\n"
"}\n"
"QLineEdit:focus {\n"
"    border: 2px solid #2563eb;\n"
"    outline: none;\n"
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
        notesPageTitleLabel->setText(QCoreApplication::translate("NoteList", "Notes", nullptr));
        searchLabel->setText(QCoreApplication::translate("NoteList", "Search:", nullptr));
        searchLineEdit->setPlaceholderText(QCoreApplication::translate("NoteList", "Search notes...", nullptr));
        typeFilterComboBox->setItemText(0, QCoreApplication::translate("NoteList", "All", nullptr));
        typeFilterComboBox->setItemText(1, QCoreApplication::translate("NoteList", "Text", nullptr));
        typeFilterComboBox->setItemText(2, QCoreApplication::translate("NoteList", "Doodle", nullptr));

        QTableWidgetItem *___qtablewidgetitem = notesTableWidget->horizontalHeaderItem(0);
        ___qtablewidgetitem->setText(QCoreApplication::translate("NoteList", "Name", nullptr));
        QTableWidgetItem *___qtablewidgetitem1 = notesTableWidget->horizontalHeaderItem(1);
        ___qtablewidgetitem1->setText(QCoreApplication::translate("NoteList", "Type", nullptr));
        QTableWidgetItem *___qtablewidgetitem2 = notesTableWidget->horizontalHeaderItem(2);
        ___qtablewidgetitem2->setText(QCoreApplication::translate("NoteList", "Date Created", nullptr));
        createNoteButton->setText(QCoreApplication::translate("NoteList", "Create Note", nullptr));
        deleteNoteButton->setText(QCoreApplication::translate("NoteList", "Delete Note", nullptr));
        deleteNoteButton->setStyleSheet(QCoreApplication::translate("NoteList", "background-color: #e11d48;\n"
"color: white;\n"
"border-radius: 6px;\n"
"padding: 12px 24px;\n"
"min-height: 48px;\n"
"font-weight: 500;\n"
"font-size: 15px;\n"
"}\n"
"QPushButton:hover {\n"
"    background-color: #be123c;\n"
"}\n"
"QPushButton:pressed {\n"
"    background-color: #9f1239;\n"
"}", nullptr));
        backToDashboardButton->setText(QCoreApplication::translate("NoteList", "Back to Dashboard", nullptr));
        backToDashboardButton->setStyleSheet(QCoreApplication::translate("NoteList", "background-color: #e5e7eb;\n"
"color: #1a1a1a;\n"
"border-radius: 6px;\n"
"padding: 12px 24px;\n"
"min-height: 48px;\n"
"font-weight: 500;\n"
"font-size: 15px;\n"
"}\n"
"QPushButton:hover {\n"
"    background-color: #d1d5db;\n"
"}\n"
"QPushButton:pressed {\n"
"    background-color: #9ca3af;\n"
"}", nullptr));
    } // retranslateUi

};

namespace Ui {
    class NoteList: public Ui_NoteList {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_NOTELIST_H
