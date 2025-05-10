/********************************************************************************
** Form generated from reading UI file 'createnote.ui'
**
** Created by: Qt User Interface Compiler version 6.9.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_CREATENOTE_H
#define UI_CREATENOTE_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QGraphicsView>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSlider>
#include <QtWidgets/QTabWidget>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QToolButton>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_CreateNote
{
public:
    QVBoxLayout *verticalLayout;
    QLabel *titleLabel;
    QLineEdit *titleLineEdit;
    QTabWidget *modeTabWidget;
    QWidget *textTab;
    QHBoxLayout *horizontalLayout;
    QLabel *textColorLabel;
    QToolButton *textColorButton;
    QWidget *textToolBar;
    QHBoxLayout *horizontalLayout_2;
    QTextEdit *textContent;
    QWidget *doodleTab;
    QVBoxLayout *verticalLayout_2;
    QGraphicsView *doodleCanvas;
    QWidget *doodleToolBar;
    QHBoxLayout *horizontalLayout_3;
    QLabel *brushSizeLabel;
    QSlider *brushSizeSlider;
    QToolButton *brushColorButton;
    QWidget *widget;
    QHBoxLayout *horizontalLayout_4;
    QPushButton *saveNoteButton;
    QLabel *errorLabel;
    QPushButton *cancelNoteButton;

    void setupUi(QWidget *CreateNote)
    {
        if (CreateNote->objectName().isEmpty())
            CreateNote->setObjectName("CreateNote");
        CreateNote->resize(400, 300);
        verticalLayout = new QVBoxLayout(CreateNote);
        verticalLayout->setObjectName("verticalLayout");
        titleLabel = new QLabel(CreateNote);
        titleLabel->setObjectName("titleLabel");

        verticalLayout->addWidget(titleLabel);

        titleLineEdit = new QLineEdit(CreateNote);
        titleLineEdit->setObjectName("titleLineEdit");

        verticalLayout->addWidget(titleLineEdit);

        modeTabWidget = new QTabWidget(CreateNote);
        modeTabWidget->setObjectName("modeTabWidget");
        textTab = new QWidget();
        textTab->setObjectName("textTab");
        horizontalLayout = new QHBoxLayout(textTab);
        horizontalLayout->setObjectName("horizontalLayout");
        textColorLabel = new QLabel(textTab);
        textColorLabel->setObjectName("textColorLabel");

        horizontalLayout->addWidget(textColorLabel);

        textColorButton = new QToolButton(textTab);
        textColorButton->setObjectName("textColorButton");

        horizontalLayout->addWidget(textColorButton);

        textToolBar = new QWidget(textTab);
        textToolBar->setObjectName("textToolBar");
        horizontalLayout_2 = new QHBoxLayout(textToolBar);
        horizontalLayout_2->setObjectName("horizontalLayout_2");
        textContent = new QTextEdit(textToolBar);
        textContent->setObjectName("textContent");

        horizontalLayout_2->addWidget(textContent);


        horizontalLayout->addWidget(textToolBar);

        modeTabWidget->addTab(textTab, QString());
        doodleTab = new QWidget();
        doodleTab->setObjectName("doodleTab");
        verticalLayout_2 = new QVBoxLayout(doodleTab);
        verticalLayout_2->setObjectName("verticalLayout_2");
        doodleCanvas = new QGraphicsView(doodleTab);
        doodleCanvas->setObjectName("doodleCanvas");

        verticalLayout_2->addWidget(doodleCanvas);

        doodleToolBar = new QWidget(doodleTab);
        doodleToolBar->setObjectName("doodleToolBar");
        horizontalLayout_3 = new QHBoxLayout(doodleToolBar);
        horizontalLayout_3->setObjectName("horizontalLayout_3");
        brushSizeLabel = new QLabel(doodleToolBar);
        brushSizeLabel->setObjectName("brushSizeLabel");

        horizontalLayout_3->addWidget(brushSizeLabel);

        brushSizeSlider = new QSlider(doodleToolBar);
        brushSizeSlider->setObjectName("brushSizeSlider");
        brushSizeSlider->setOrientation(Qt::Orientation::Horizontal);

        horizontalLayout_3->addWidget(brushSizeSlider);

        brushColorButton = new QToolButton(doodleToolBar);
        brushColorButton->setObjectName("brushColorButton");

        horizontalLayout_3->addWidget(brushColorButton);


        verticalLayout_2->addWidget(doodleToolBar);

        modeTabWidget->addTab(doodleTab, QString());

        verticalLayout->addWidget(modeTabWidget);

        widget = new QWidget(CreateNote);
        widget->setObjectName("widget");
        horizontalLayout_4 = new QHBoxLayout(widget);
        horizontalLayout_4->setObjectName("horizontalLayout_4");
        saveNoteButton = new QPushButton(widget);
        saveNoteButton->setObjectName("saveNoteButton");

        horizontalLayout_4->addWidget(saveNoteButton);

        errorLabel = new QLabel(widget);
        errorLabel->setObjectName("errorLabel");
        errorLabel->setCursor(QCursor(Qt::CursorShape::ArrowCursor));
        errorLabel->setStyleSheet(QString::fromUtf8("color: red;"));

        horizontalLayout_4->addWidget(errorLabel);

        cancelNoteButton = new QPushButton(widget);
        cancelNoteButton->setObjectName("cancelNoteButton");

        horizontalLayout_4->addWidget(cancelNoteButton);


        verticalLayout->addWidget(widget);


        retranslateUi(CreateNote);

        modeTabWidget->setCurrentIndex(0);


        QMetaObject::connectSlotsByName(CreateNote);
    } // setupUi

    void retranslateUi(QWidget *CreateNote)
    {
        CreateNote->setWindowTitle(QCoreApplication::translate("CreateNote", "Form", nullptr));
        titleLabel->setText(QCoreApplication::translate("CreateNote", "Note Title:", nullptr));
        textColorLabel->setText(QCoreApplication::translate("CreateNote", "Text Color:", nullptr));
        textColorButton->setText(QCoreApplication::translate("CreateNote", "...", nullptr));
        modeTabWidget->setTabText(modeTabWidget->indexOf(textTab), QCoreApplication::translate("CreateNote", "Text", nullptr));
        brushSizeLabel->setText(QCoreApplication::translate("CreateNote", "Brush Size:", nullptr));
        brushColorButton->setText(QCoreApplication::translate("CreateNote", "...", nullptr));
        modeTabWidget->setTabText(modeTabWidget->indexOf(doodleTab), QCoreApplication::translate("CreateNote", "Doodle", nullptr));
        saveNoteButton->setText(QCoreApplication::translate("CreateNote", "Save", nullptr));
        errorLabel->setText(QString());
        cancelNoteButton->setText(QCoreApplication::translate("CreateNote", "Cancel", nullptr));
    } // retranslateUi

};

namespace Ui {
    class CreateNote: public Ui_CreateNote {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CREATENOTE_H
