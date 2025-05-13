#ifndef CREATENOTE_H
#define CREATENOTE_H

#include <QMainWindow>
#include <QGraphicsScene>
#include <QGraphicsPathItem>
#include <QPainterPath>
#include <QPen>
#include <QPointF>
#include "doodleview.h"

namespace Ui {
class CreateNote;
}

class CreateNote : public QMainWindow {
    Q_OBJECT

public:
    explicit CreateNote(const QString &username = QString(), QWidget *parent = nullptr);
    ~CreateNote();
    void loadNote(const QString &title, const QString &content);

signals:
    void backToDashboardRequested();

private slots:
    void on_saveNoteButton_clicked();
    void on_cancelNoteButton_clicked();
    void on_textColorButton_clicked();
    void on_brushColorButton_clicked();
    void on_brushSizeSlider_valueChanged(int value);
    void validateInputs();
    void resetUI();

private:
    Ui::CreateNote *ui;
    QGraphicsScene *doodleScene;
    QList<QGraphicsPathItem*> paths;
    QPen currentPen;
    QPointF lastPoint;
    QPainterPath *currentPath;
    bool isDrawing;
    QString m_username;
    void setupDoodleCanvas();
    void setupTextEditor();
};

#endif // CREATENOTE_H

