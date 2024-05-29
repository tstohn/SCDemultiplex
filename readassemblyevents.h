#ifndef READASSEMBLYEVENTS_H
#define READASSEMBLYEVENTS_H

#include <QLabel>
#include <QGraphicsView>
#include <QDragMoveEvent>
#include <QDropEvent>
#include <QPixmap>
#include <QPoint>
#include <QWidget>
#include <QMouseEvent>
#include <QByteArray>
#include <QDrag>
#include <QMimeData>
#include <QMap>
#include <QVector>
#include <QEvent>
#include <QWheelEvent>

class SeqBlockLabel : public QLabel
{
    Q_OBJECT
    using QLabel::QLabel;

public:
    explicit SeqBlockLabel(QWidget* widget = nullptr);
private:
    void create_drag(const QPoint& pos, QWidget* widget);
protected:
    void mousePressEvent(QMouseEvent *event) override;
};

class RedSeqGraphicsView : public QGraphicsView
{
    Q_OBJECT

public:
    explicit RedSeqGraphicsView(QWidget* widget = nullptr);
    //Map that stores for every sequence Block from the drag menue (variable, constant, ... sequences) the end coordiantes of this block in the GraphicsView
   QVector<double> seqBlockEnd;

signals:
    void itemdrop(QPixmap);
protected:
    void dragEnterEvent(QDragEnterEvent* event) override;
    void dragLeaveEvent(QDragLeaveEvent* event) override;
    void dragMoveEvent(QDragMoveEvent* event) override;
    void dropEvent(QDropEvent* event) override;
    using QGraphicsView::QGraphicsView;

};

#endif // READASSEMBLYEVENTS_H
