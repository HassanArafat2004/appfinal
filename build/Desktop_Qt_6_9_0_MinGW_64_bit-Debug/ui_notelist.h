/********************************************************************************
** Form generated from reading UI file 'notelist.ui'
**
** Created by: Qt User Interface Compiler version 6.9.0
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
    QPushButton *createNoteButton;

    void setupUi(QWidget *NoteList)
    {
        if (NoteList->objectName().isEmpty())
            NoteList->setObjectName("NoteList");
        NoteList->resize(400, 300);
        verticalLayout = new QVBoxLayout(NoteList);
        verticalLayout->setSpacing(8);
        verticalLayout->setObjectName("verticalLayout");
        verticalLayout->setContentsMargins(8, 8, 8, 8);
        notesPageTitleLabel = new QLabel(NoteList);
        notesPageTitleLabel->setObjectName("notesPageTitleLabel");
        QFont font;
        font.setPointSize(14);
        font.setBold(true);
        notesPageTitleLabel->setFont(font);

        verticalLayout->addWidget(notesPageTitleLabel);

        widget = new QWidget(NoteList);
        widget->setObjectName("widget");
        horizontalLayout = new QHBoxLayout(widget);
        horizontalLayout->setObjectName("horizontalLayout");
        searchLabel = new QLabel(widget);
        searchLabel->setObjectName("searchLabel");
        QFont font1;
        font1.setBold(true);
        searchLabel->setFont(font1);

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

        verticalLayout->addWidget(notesTableWidget);

        createNoteButton = new QPushButton(NoteList);
        createNoteButton->setObjectName("createNoteButton");

        verticalLayout->addWidget(createNoteButton);


        retranslateUi(NoteList);

        QMetaObject::connectSlotsByName(NoteList);
    } // setupUi

    void retranslateUi(QWidget *NoteList)
    {
        NoteList->setWindowTitle(QCoreApplication::translate("NoteList", "Form", nullptr));
        notesPageTitleLabel->setText(QCoreApplication::translate("NoteList", "                      Notes Page", nullptr));
        searchLabel->setText(QCoreApplication::translate("NoteList", "Search:", nullptr));
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
    } // retranslateUi

};

namespace Ui {
    class NoteList: public Ui_NoteList {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_NOTELIST_H
