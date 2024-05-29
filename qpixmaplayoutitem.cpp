#include "qpixmaplayoutitem.h"

QPixmapLayoutItem::QPixmapLayoutItem(QPixmap pixmap, QGraphicsItem *parent)
    : QGraphicsLayoutItem(), QGraphicsItem(parent),
      m_pix(pixmap)
{
    setGraphicsItem(this);
}

void QPixmapLayoutItem::paint(QPainter *painter, const QStyleOptionGraphicsItem *option,
                       QWidget *widget)
{
    Q_UNUSED(widget);
    Q_UNUSED(option);

    QRectF frame(QPointF(0, 0), geometry().size());
    const QSize pmSize = m_pix.size();
    QGradientStops stops;

    // paint a background rect (with gradient)
    //QLinearGradient gradient(frame.topLeft(), frame.topLeft() + QPointF(200,200));
    //stops << QGradientStop(0.0, QColor(60, 60,  60));
    //stops << QGradientStop(frame.height() / 2 / frame.height(), QColor(102, 176, 54));

    //stops << QGradientStop(((frame.height() + h)/2 )/frame.height(), QColor(157, 195,  55));
    //stops << QGradientStop(1.0, QColor(215, 215, 215));
    //gradient.setStops(stops);
    //painter->setBrush(QBrush(gradient));
    //painter->drawRoundedRect(frame, 10.0, 10.0);

    // paint a rect around the pixmap (with gradient)
    QPointF pixpos = frame.center() - (QPointF(pmSize.width(), pmSize.height()) / 2);
    QRectF innerFrame(pixpos, pmSize);
    //innerFrame.adjust(-4, -4, 4, 4);
    //gradient.setStart(innerFrame.topLeft());
    //gradient.setFinalStop(innerFrame.bottomRight());
    //stops.clear();
    //stops << QGradientStop(0.0, QColor(215, 255, 200));
    //stops << QGradientStop(0.5, QColor(102, 176, 54));
    //stops << QGradientStop(1.0, QColor(0, 0,  0));
    //gradient.setStops(stops);
    //painter->setBrush(QBrush(gradient));
    //painter->drawRoundedRect(innerFrame, 10.0, 10.0);
    painter->drawPixmap(pixpos, m_pix);
}

QRectF QPixmapLayoutItem::boundingRect() const
{
    return QRectF(QPointF(0, 0), geometry().size());
}

void QPixmapLayoutItem::setGeometry(const QRectF &geom)
{
    prepareGeometryChange();
    QGraphicsLayoutItem::setGeometry(geom);
    setPos(geom.topLeft());
}

QSizeF QPixmapLayoutItem::sizeHint(Qt::SizeHint which, const QSizeF &constraint) const
{
    switch (which) {
    case Qt::MinimumSize:
    case Qt::PreferredSize:
        // Do not allow a size smaller than the pixmap with two frames around it.
        return m_pix.size() + QSize(12, 12);
    case Qt::MaximumSize:
        return QSizeF(1000,1000);
    default:
        break;
    }
    return constraint;
}
