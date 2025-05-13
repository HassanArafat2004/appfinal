#ifndef DOODLEVIEW_H
#define DOODLEVIEW_H

#include <QGraphicsView>
#include <QMouseEvent>
#include <QGraphicsPathItem>
#include <QPainterPath>

class DoodleView : public QGraphicsView {
    Q_OBJECT

public:
    explicit DoodleView(QWidget *parent = nullptr);
    void setPenWidth(int width);
    void setPenColor(const QColor &color);
    bool exportAsImage(const QString &filePath);
    void clear();
    void setEraserMode(bool enabled);
    bool hasVisibleContent();

protected:
    void mousePressEvent(QMouseEvent *event) override;
    void mouseMoveEvent(QMouseEvent *event) override;
    void mouseReleaseEvent(QMouseEvent *event) override;

private:
    QPainterPath currentPath;
    QGraphicsPathItem *pathItem;
    bool drawing;
    bool eraserMode;
    int penWidth = 2;
    QColor penColor = Qt::black;
    QColor lastColor = Qt::black;

signals:
    void pathAdded();
};

#endif // DOODLEVIEW_H
