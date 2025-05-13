/********************************************************************************
** Form generated from reading UI file 'createnote.ui'
**
** Created by: Qt User Interface Compiler version 6.8.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_CREATENOTE_H
#define UI_CREATENOTE_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenu>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSlider>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTabWidget>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QToolButton>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>
#include "doodleview.h"

QT_BEGIN_NAMESPACE

class Ui_CreateNote
{
public:
    QWidget *createNoteCentralWidget;
    QVBoxLayout *verticalLayout;
    QLabel *titleLabel;
    QLineEdit *titleLineEdit;
    QTabWidget *modeTabWidget;
    QWidget *textTab;
    QVBoxLayout *textNoteLayout;
    QHBoxLayout *textColorLayout;
    QLabel *textColorLabel;
    QToolButton *textColorButton;
    QTextEdit *textContent;
    QWidget *doodleTab;
    QVBoxLayout *doodleNoteLayout;
    QGroupBox *doodleToolsGroupBox;
    QHBoxLayout *doodleToolsLayout;
    QPushButton *clearButton;
    QPushButton *eraseButton;
    QLabel *brushSizeLabel;
    QSlider *brushSizeSlider;
    QLabel *brushSizeValueLabel;
    QToolButton *brushColorButton;
    DoodleView *doodleCanvas;
    QHBoxLayout *buttonLayout;
    QPushButton *saveNoteButton;
    QLabel *errorLabel;
    QPushButton *cancelNoteButton;
    QMenuBar *createNoteMenuBar;
    QMenu *menu;
    QStatusBar *createNoteStatusBar;

    void setupUi(QMainWindow *CreateNote)
    {
        if (CreateNote->objectName().isEmpty())
            CreateNote->setObjectName("CreateNote");
        CreateNote->resize(1280, 720);
        CreateNote->setMinimumSize(QSize(1280, 720));
        createNoteCentralWidget = new QWidget(CreateNote);
        createNoteCentralWidget->setObjectName("createNoteCentralWidget");
        verticalLayout = new QVBoxLayout(createNoteCentralWidget);
        verticalLayout->setSpacing(24);
        verticalLayout->setObjectName("verticalLayout");
        verticalLayout->setContentsMargins(32, 32, 32, 32);
        titleLabel = new QLabel(createNoteCentralWidget);
        titleLabel->setObjectName("titleLabel");
        QFont font;
        font.setFamilies({QString::fromUtf8("Segoe UI")});
        font.setWeight(QFont::DemiBold);
        titleLabel->setFont(font);

        verticalLayout->addWidget(titleLabel);

        titleLineEdit = new QLineEdit(createNoteCentralWidget);
        titleLineEdit->setObjectName("titleLineEdit");

        verticalLayout->addWidget(titleLineEdit);

        modeTabWidget = new QTabWidget(createNoteCentralWidget);
        modeTabWidget->setObjectName("modeTabWidget");
        textTab = new QWidget();
        textTab->setObjectName("textTab");
        textNoteLayout = new QVBoxLayout(textTab);
        textNoteLayout->setSpacing(16);
        textNoteLayout->setObjectName("textNoteLayout");
        textColorLayout = new QHBoxLayout();
        textColorLayout->setObjectName("textColorLayout");
        textColorLabel = new QLabel(textTab);
        textColorLabel->setObjectName("textColorLabel");

        textColorLayout->addWidget(textColorLabel);

        textColorButton = new QToolButton(textTab);
        textColorButton->setObjectName("textColorButton");

        textColorLayout->addWidget(textColorButton);


        textNoteLayout->addLayout(textColorLayout);

        textContent = new QTextEdit(textTab);
        textContent->setObjectName("textContent");

        textNoteLayout->addWidget(textContent);

        modeTabWidget->addTab(textTab, QString());
        doodleTab = new QWidget();
        doodleTab->setObjectName("doodleTab");
        doodleNoteLayout = new QVBoxLayout(doodleTab);
        doodleNoteLayout->setSpacing(16);
        doodleNoteLayout->setObjectName("doodleNoteLayout");
        doodleToolsGroupBox = new QGroupBox(doodleTab);
        doodleToolsGroupBox->setObjectName("doodleToolsGroupBox");
        doodleToolsLayout = new QHBoxLayout(doodleToolsGroupBox);
        doodleToolsLayout->setSpacing(16);
        doodleToolsLayout->setObjectName("doodleToolsLayout");
        clearButton = new QPushButton(doodleToolsGroupBox);
        clearButton->setObjectName("clearButton");

        doodleToolsLayout->addWidget(clearButton);

        eraseButton = new QPushButton(doodleToolsGroupBox);
        eraseButton->setObjectName("eraseButton");
        eraseButton->setCheckable(true);

        doodleToolsLayout->addWidget(eraseButton);

        brushSizeLabel = new QLabel(doodleToolsGroupBox);
        brushSizeLabel->setObjectName("brushSizeLabel");

        doodleToolsLayout->addWidget(brushSizeLabel);

        brushSizeSlider = new QSlider(doodleToolsGroupBox);
        brushSizeSlider->setObjectName("brushSizeSlider");
        brushSizeSlider->setMinimum(1);
        brushSizeSlider->setMaximum(20);
        brushSizeSlider->setValue(5);
        brushSizeSlider->setOrientation(Qt::Orientation::Horizontal);

        doodleToolsLayout->addWidget(brushSizeSlider);

        brushSizeValueLabel = new QLabel(doodleToolsGroupBox);
        brushSizeValueLabel->setObjectName("brushSizeValueLabel");

        doodleToolsLayout->addWidget(brushSizeValueLabel);

        brushColorButton = new QToolButton(doodleToolsGroupBox);
        brushColorButton->setObjectName("brushColorButton");

        doodleToolsLayout->addWidget(brushColorButton);


        doodleNoteLayout->addWidget(doodleToolsGroupBox);

        doodleCanvas = new DoodleView(doodleTab);
        doodleCanvas->setObjectName("doodleCanvas");
        QSizePolicy sizePolicy(QSizePolicy::Policy::Expanding, QSizePolicy::Policy::Expanding);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(doodleCanvas->sizePolicy().hasHeightForWidth());
        doodleCanvas->setSizePolicy(sizePolicy);
        doodleCanvas->setMinimumSize(QSize(0, 400));
        doodleCanvas->viewport()->setProperty("cursor", QVariant(QCursor(Qt::CursorShape::CrossCursor)));
        doodleCanvas->setMouseTracking(true);

        doodleNoteLayout->addWidget(doodleCanvas);

        modeTabWidget->addTab(doodleTab, QString());

        verticalLayout->addWidget(modeTabWidget);

        buttonLayout = new QHBoxLayout();
        buttonLayout->setSpacing(24);
        buttonLayout->setObjectName("buttonLayout");
        saveNoteButton = new QPushButton(createNoteCentralWidget);
        saveNoteButton->setObjectName("saveNoteButton");

        buttonLayout->addWidget(saveNoteButton);

        errorLabel = new QLabel(createNoteCentralWidget);
        errorLabel->setObjectName("errorLabel");

        buttonLayout->addWidget(errorLabel);

        cancelNoteButton = new QPushButton(createNoteCentralWidget);
        cancelNoteButton->setObjectName("cancelNoteButton");

        buttonLayout->addWidget(cancelNoteButton);


        verticalLayout->addLayout(buttonLayout);

        CreateNote->setCentralWidget(createNoteCentralWidget);
        createNoteMenuBar = new QMenuBar(CreateNote);
        createNoteMenuBar->setObjectName("createNoteMenuBar");
        createNoteMenuBar->setGeometry(QRect(0, 0, 1280, 24));
        menu = new QMenu(createNoteMenuBar);
        menu->setObjectName("menu");
        CreateNote->setMenuBar(createNoteMenuBar);
        createNoteStatusBar = new QStatusBar(CreateNote);
        createNoteStatusBar->setObjectName("createNoteStatusBar");
        CreateNote->setStatusBar(createNoteStatusBar);

        createNoteMenuBar->addAction(menu->menuAction());

        retranslateUi(CreateNote);

        modeTabWidget->setCurrentIndex(1);


        QMetaObject::connectSlotsByName(CreateNote);
    } // setupUi

    void retranslateUi(QMainWindow *CreateNote)
    {
        CreateNote->setWindowTitle(QCoreApplication::translate("CreateNote", "Create Note", nullptr));
        CreateNote->setStyleSheet(QCoreApplication::translate("CreateNote", "QWidget {\n"
"    background-color: #f5f7fa;\n"
"    font-family: \"Segoe UI\", \"Helvetica Neue\", Arial, sans-serif;\n"
"    font-size: 14px;\n"
"    color: #000000;\n"
"}\n"
"QLabel {\n"
"    color: #000000;\n"
"}\n"
"QLabel#titleLabel {\n"
"    font-size: 24px;\n"
"    font-weight: 600;\n"
"    color: #1a1a1a;\n"
"}\n"
"QLineEdit, QTextEdit {\n"
"    background: #ffffff;\n"
"    border: 1px solid #e2e8f0;\n"
"    border-radius: 6px;\n"
"    padding: 8px 12px;\n"
"    color: #000000;\n"
"    font-size: 14px;\n"
"}\n"
"QLineEdit:focus, QTextEdit:focus {\n"
"    border: 2px solid #2563eb;\n"
"    outline: none;\n"
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
"QPushButton#cancelNoteButton {\n"
"    background"
                        "-color: #e5e7eb;\n"
"    color: #1a1a1a;\n"
"}\n"
"QPushButton#cancelNoteButton:hover {\n"
"    background-color: #d1d5db;\n"
"}\n"
"QTabWidget::pane {\n"
"    border: 1px solid #e2e8f0;\n"
"    border-radius: 8px;\n"
"    padding: 16px;\n"
"    background: #ffffff;\n"
"}\n"
"QTabBar::tab {\n"
"    background: #f5f7fa;\n"
"    padding: 8px 16px;\n"
"    border-top-left-radius: 6px;\n"
"    border-top-right-radius: 6px;\n"
"    color: #4a5568;\n"
"    font-weight: 500;\n"
"    margin-right: 4px;\n"
"}\n"
"QTabBar::tab:selected {\n"
"    background: #ffffff;\n"
"    color: #2563eb;\n"
"    border: 1px solid #e2e8f0;\n"
"    border-bottom: none;\n"
"}\n"
"QTabBar::tab:hover:!selected {\n"
"    background: #edf2f7;\n"
"}\n"
"QGroupBox {\n"
"    background-color: #ffffff;\n"
"    border: 1px solid #e2e8f0;\n"
"    border-radius: 8px;\n"
"    margin-top: 16px;\n"
"    padding: 16px;\n"
"}\n"
"QGroupBox::title {\n"
"    color: #2d3748;\n"
"    font-size: 16px;\n"
"    font-weight: 600;\n"
"    subcontrol-origin: marg"
                        "in;\n"
"    subcontrol-position: top left;\n"
"    padding: 0 8px;\n"
"}\n"
"QSlider::groove:horizontal {\n"
"    border: 1px solid #e2e8f0;\n"
"    height: 8px;\n"
"    background: #edf2f7;\n"
"    margin: 2px 0;\n"
"    border-radius: 4px;\n"
"}\n"
"QSlider::handle:horizontal {\n"
"    background: #2563eb;\n"
"    border: none;\n"
"    width: 16px;\n"
"    height: 16px;\n"
"    margin: -4px 0;\n"
"    border-radius: 8px;\n"
"}\n"
"QSlider::handle:horizontal:hover {\n"
"    background: #1d4ed8;\n"
"}\n"
"QSlider::sub-page:horizontal {\n"
"    background: #2563eb;\n"
"    border-radius: 4px;\n"
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
"}", nullptr));
        titleLabel->setText(QCoreApplication::translate("CreateNote", "Create New Note", nullptr));
        titleLineEdit->setPlaceholderText(QCoreApplication::translate("CreateNote", "Enter note title...", nullptr));
        textColorLabel->setText(QCoreApplication::translate("CreateNote", "Text Color:", nullptr));
        textColorButton->setText(QCoreApplication::translate("CreateNote", "Choose Color", nullptr));
        textContent->setPlaceholderText(QCoreApplication::translate("CreateNote", "Enter your note content here...", nullptr));
        modeTabWidget->setTabText(modeTabWidget->indexOf(textTab), QCoreApplication::translate("CreateNote", "Text Note", nullptr));
        doodleToolsGroupBox->setTitle(QCoreApplication::translate("CreateNote", "Drawing Tools", nullptr));
        clearButton->setText(QCoreApplication::translate("CreateNote", "Clear Canvas", nullptr));
        eraseButton->setText(QCoreApplication::translate("CreateNote", "Erase", nullptr));
        brushSizeLabel->setText(QCoreApplication::translate("CreateNote", "Brush Size:", nullptr));
        brushSizeValueLabel->setText(QString());
        brushColorButton->setText(QCoreApplication::translate("CreateNote", "Brush Color", nullptr));
        doodleCanvas->setStyleSheet(QCoreApplication::translate("CreateNote", "QGraphicsView {\n"
"    background-color: #ffffff;\n"
"    border: 1px solid #e2e8f0;\n"
"    border-radius: 6px;\n"
"}", nullptr));
        modeTabWidget->setTabText(modeTabWidget->indexOf(doodleTab), QCoreApplication::translate("CreateNote", "Doodle Note", nullptr));
        saveNoteButton->setText(QCoreApplication::translate("CreateNote", "Save Note", nullptr));
        errorLabel->setStyleSheet(QCoreApplication::translate("CreateNote", "color: red;", nullptr));
        cancelNoteButton->setText(QCoreApplication::translate("CreateNote", "Cancel", nullptr));
        menu->setTitle(QCoreApplication::translate("CreateNote", "\342\200\216 ", nullptr));
    } // retranslateUi

};

namespace Ui {
    class CreateNote: public Ui_CreateNote {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CREATENOTE_H
