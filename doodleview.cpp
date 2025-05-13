#include "doodleview.h"
#include <QGraphicsScene>
#include <QPen>

DoodleView::DoodleView(QWidget *parent) 
    : QGraphicsView(parent)
    , pathItem(nullptr)
    , drawing(false)
    , eraserMode(false) {
    setScene(new QGraphicsScene(this));
    setRenderHint(QPainter::Antialiasing);
    setBackgroundBrush(Qt::white);
    setViewportUpdateMode(QGraphicsView::FullViewportUpdate);
}

void DoodleView::mousePressEvent(QMouseEvent *event) {
    if (event->button() == Qt::LeftButton) {
        currentPath = QPainterPath();
        currentPath.moveTo(mapToScene(event->pos()));
        pathItem = new QGraphicsPathItem();
        
        if (eraserMode) {
            pathItem->setPen(QPen(Qt::white, penWidth, Qt::SolidLine, Qt::RoundCap, Qt::RoundJoin));
        } else {
            pathItem->setPen(QPen(penColor, penWidth));
        }
        
        pathItem->setPath(currentPath);
        scene()->addItem(pathItem);
        drawing = true;
    }
}

void DoodleView::mouseMoveEvent(QMouseEvent *event) {
    if (drawing && pathItem) {
        currentPath.lineTo(mapToScene(event->pos()));
        pathItem->setPath(currentPath);
    }
}

void DoodleView::setPenWidth(int width) {
    penWidth = width;
}

void DoodleView::setPenColor(const QColor &color) {
    if (!eraserMode) {
        penColor = color;
        lastColor = color;
    }
}

void DoodleView::setEraserMode(bool enabled) {
    eraserMode = enabled;
    if (!enabled) {
        penColor = lastColor;
    }
}

void DoodleView::mouseReleaseEvent(QMouseEvent *event) {
    if (event->button() == Qt::LeftButton && drawing) {
        drawing = false;
        pathItem = nullptr;
        emit pathAdded();
    }
}

void DoodleView::clear() {
    scene()->clear();
    pathItem = nullptr;
    drawing = false;
}

bool DoodleView::hasVisibleContent() {
    if (scene()->items().isEmpty()) {
        return false;
    }
    
    QImage image(scene()->sceneRect().size().toSize(), QImage::Format_RGB32);
    image.fill(Qt::white);
    
    QPainter painter(&image);
    scene()->render(&painter);
    painter.end();
    
    for (int y = 0; y < image.height(); y++) {
        for (int x = 0; x < image.width(); x++) {
            if (image.pixelColor(x, y) != Qt::white) {
                return true;
            }
        }
    }
    
    return false;
}

bool DoodleView::exportAsImage(const QString &filePath) {
    QImage image(scene()->sceneRect().size().toSize(), QImage::Format_RGB32);
    image.fill(Qt::white);

    QPainter painter(&image);
    scene()->render(&painter);
    return image.save(filePath, "JPG");
}

