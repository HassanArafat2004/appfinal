#include "createnote.h"
#include "ui_createnote.h"
#include <QColorDialog>
#include <QMessageBox>
#include <QTextCharFormat>
#include <QTextCursor>
#include <QRegularExpressionValidator>
#include <QDir>
#include <QFile>
#include <QTextStream>

CreateNote::CreateNote(const QString &username, QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::CreateNote)
    , doodleScene(nullptr)
    , currentPath(nullptr)
    , isDrawing(false)
    , m_username(username) {
    ui->setupUi(this);
    setWindowTitle("Create Note");
    showMaximized();

    connect(ui->brushSizeSlider, &QSlider::valueChanged, this, &CreateNote::on_brushSizeSlider_valueChanged);
    connect(ui->titleLineEdit, &QLineEdit::textChanged, this, &CreateNote::validateInputs);
    connect(ui->textContent, &QTextEdit::textChanged, this, &CreateNote::validateInputs);
    connect(ui->modeTabWidget, &QTabWidget::currentChanged, this, &CreateNote::validateInputs);

    QRegularExpressionValidator *validator = new QRegularExpressionValidator(QRegularExpression("[^\\s].*"), this);
    ui->titleLineEdit->setValidator(validator);

    setupTextEditor();
    setupDoodleCanvas();
    validateInputs();
}

void CreateNote::setupTextEditor() {
    QPalette textPalette = ui->textContent->palette();
    textPalette.setColor(QPalette::Text, Qt::black);
    ui->textContent->setPalette(textPalette);
    ui->textContent->setAcceptRichText(true);
    QTextCharFormat format;
    format.setForeground(Qt::black);
    QTextCursor cursor = ui->textContent->textCursor();
    cursor.select(QTextCursor::Document);
    cursor.mergeCharFormat(format);
    cursor.clearSelection();
    ui->textContent->setTextCursor(cursor);
}

void CreateNote::setupDoodleCanvas() {
    doodleScene = new QGraphicsScene(this);
    ui->doodleCanvas->setScene(doodleScene);
    ui->doodleCanvas->setRenderHint(QPainter::Antialiasing);
    ui->doodleCanvas->setRenderHint(QPainter::SmoothPixmapTransform);
    ui->doodleCanvas->setViewportUpdateMode(QGraphicsView::FullViewportUpdate);
    ui->doodleCanvas->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    ui->doodleCanvas->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    ui->doodleCanvas->setBackgroundBrush(Qt::white);
    doodleScene->setSceneRect(ui->doodleCanvas->viewport()->rect());
    currentPen.setColor(Qt::black);
    currentPen.setWidth(2);
    currentPen.setCapStyle(Qt::RoundCap);
    currentPen.setJoinStyle(Qt::RoundJoin);
    ui->brushSizeSlider->setRange(1, 20);
    ui->brushSizeSlider->setValue(2);

    connect(ui->doodleCanvas, &DoodleView::pathAdded, this, [this]() {
        validateInputs();
    });

    connect(ui->clearButton, &QPushButton::clicked, this, [this]() {
        auto canvas = qobject_cast<DoodleView *>(ui->doodleCanvas);
        if (canvas) {
            canvas->clear();
            validateInputs();
        }
    });

    connect(ui->eraseButton, &QPushButton::clicked, this, [this]() {
        auto canvas = qobject_cast<DoodleView *>(ui->doodleCanvas);
        if (canvas) {
            bool isEraser = ui->eraseButton->isChecked();
            canvas->setEraserMode(isEraser);
            ui->eraseButton->setText(isEraser ? "Draw" : "Erase");
        }
    });
}

void CreateNote::validateInputs() {
    bool valid = true;
    QString error;

    if (ui->titleLineEdit->text().trimmed().isEmpty()) {
        valid = false;
        error = "Title required";
    } else {
        if (ui->modeTabWidget->currentWidget() == ui->textTab) {
            if (ui->textContent->toPlainText().trimmed().isEmpty()) {
                valid = false;
                error = "Text required";
            }
        } else if (ui->modeTabWidget->currentWidget() == ui->doodleTab) {
            auto canvas = qobject_cast<DoodleView *>(ui->doodleCanvas);
            if (canvas) {
                if (!canvas->hasVisibleContent()) {
                valid = false;
                error = "Draw something";
                }
            }
        }
    }

    ui->saveNoteButton->setEnabled(valid);
    ui->errorLabel->setText(error);
}

void CreateNote::resetUI() {
    ui->titleLineEdit->clear();
    ui->textContent->clear();
    doodleScene->clear();
    paths.clear();
    validateInputs();
}

void CreateNote::on_textColorButton_clicked() {
    QColor color = QColorDialog::getColor(Qt::black, this, "Pick text color");
    if (!color.isValid()) return;
    QTextCharFormat format;
    format.setForeground(color);
    QTextCursor cursor = ui->textContent->textCursor();
    if (cursor.hasSelection()) {
        cursor.mergeCharFormat(format);
    } else {
        ui->textContent->setTextColor(color);
    }
}

void CreateNote::on_brushColorButton_clicked() {
    QColor color = QColorDialog::getColor(currentPen.color(), this, "Pick brush color");
    if (!color.isValid()) return;
    currentPen.setColor(color);
    auto canvas = qobject_cast<DoodleView *>(ui->doodleCanvas);
    if (canvas) {
        canvas->setPenColor(color);
    }
}

void CreateNote::on_saveNoteButton_clicked() {
    validateInputs();
    if (!ui->saveNoteButton->isEnabled()) return;

    QString title = ui->titleLineEdit->text().trimmed();
    
    QString userDir = QDir::homePath() + "/NotesApp/" + m_username;
    if (!QDir().mkpath(userDir)) {
        QMessageBox::critical(this, "Error", "Could not create user directory. Please check permissions.");
        return;
    }
    
    QFile::setPermissions(userDir, 
        QFile::ReadOwner | QFile::WriteOwner | QFile::ExeOwner |
        QFile::ReadUser | QFile::WriteUser | QFile::ExeUser);
    
    QString filePath = userDir + "/" + title + (ui->modeTabWidget->currentWidget() == ui->textTab ? ".txt" : ".jpg");
    if (QFile::exists(filePath)) {
        QMessageBox::warning(this, "Duplicate Note", "A note with this title already exists. Please choose a different title.");
        return;
    }

    if (ui->modeTabWidget->currentWidget() == ui->textTab) {
        QFile file(filePath);
        if (file.open(QIODevice::WriteOnly | QIODevice::Text)) {
            QTextStream out(&file);
            out << ui->textContent->toPlainText();
            file.close();
            
            QFile::setPermissions(filePath, 
                QFile::ReadOwner | QFile::WriteOwner |
                QFile::ReadUser | QFile::WriteUser);
        } else {
            QMessageBox::critical(this, "Error", "Could not save note: " + file.errorString());
            return;
        }
    }

    if (ui->modeTabWidget->currentWidget() == ui->doodleTab) {
        auto canvas = qobject_cast<DoodleView *>(ui->doodleCanvas);
        if (canvas) {
            if (canvas->exportAsImage(filePath)) {
                QFile::setPermissions(filePath, 
                    QFile::ReadOwner | QFile::WriteOwner |
                    QFile::ReadUser | QFile::WriteUser);
            } else {
                QMessageBox::critical(this, "Error", "Could not save doodle note.");
                return;
            }
        }
    }

    QMessageBox::information(this, "Saved", "Note saved successfully.");
    resetUI();
    this->hide();
    emit backToDashboardRequested();
}

void CreateNote::on_cancelNoteButton_clicked() {
    if (!ui->titleLineEdit->text().isEmpty() || !ui->textContent->toPlainText().isEmpty() || !doodleScene->items().isEmpty()) {
        auto reply = QMessageBox::question(this, "Cancel?", "Discard unsaved changes?", QMessageBox::Yes | QMessageBox::No);
        if (reply == QMessageBox::No) return;
    }
    resetUI();
    this->hide();
    emit backToDashboardRequested();
}

CreateNote::~CreateNote() {
    for (auto p : paths) delete p;
    delete currentPath;
    delete ui;
}

void CreateNote::on_brushSizeSlider_valueChanged(int value) {
    auto canvas = qobject_cast<DoodleView *>(ui->doodleCanvas);
    if (canvas) {
        canvas->setPenWidth(value);
    }
}

void CreateNote::loadNote(const QString &title, const QString &content)
{
    QString filePath = QDir::homePath() + "/NotesApp/" + m_username + "/" + title + ".txt";
    QFileInfo fileInfo(filePath);
    
    if (!fileInfo.exists() || !fileInfo.isReadable()) {
        QMessageBox::warning(this, "Access Denied", "You don't have permission to access this note.");
        return;
    }

    ui->titleLineEdit->setText(title);
    ui->textContent->setPlainText(content);
    validateInputs();
}

