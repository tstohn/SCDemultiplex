#ifndef QPIXMAPLAYOUTITEM_H
#define QPIXMAPLAYOUTITEM_H

#include <QGraphicsLayout>
#include <QGraphicsItem>
#include <QLinearGradient>
#include <QPainter>

class QPixmapLayoutItem : public QGraphicsLayoutItem, public QGraphicsItem
{
public:
    QPixmapLayoutItem(QPixmap pixmap, QGraphicsItem *parent = nullptr);

    // Inherited from QGraphicsLayoutItem
    void setGeometry(const QRectF &geom) override;
    QSizeF sizeHint(Qt::SizeHint which, const QSizeF &constraint = QSizeF()) const override;

    // Inherited from QGraphicsItem
    QRectF boundingRect() const override;
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget = nullptr) override;

private:
    QPixmap m_pix;
};

#endif // QPIXMAPLAYOUTITEM_H
