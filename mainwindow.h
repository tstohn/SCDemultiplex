#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QGraphicsScene>
#include <QLabel>
#include <QGraphicsPixmapItem>
#include <QGraphicsWidget>
#include <QGraphicsGridLayout>
#include <qpixmaplayoutitem.h>
#include <iostream>
#include "seqblockparameters.h"
#include <QGraphicsProxyWidget>
#include <QEvent>
#include <QGestureEvent>

//two finger movements inside the seqBlockParameters.ui causes crash
//therefore disable this event
class NoTwoFingerGestureFilter : public QObject {
protected:
    bool eventFilter(QObject *obj, QEvent *event) override {
        if (event->type() == QEvent::GraphicsSceneWheel ) {
            return true; // Ignore the touch and gesture events
        }
        return QObject::eventFilter(obj, event);
    }
};

namespace Ui
{
    class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

    public:
        explicit MainWindow(QWidget *parent = nullptr);
        ~MainWindow();

    private:
        Ui::MainWindow *ui;
        QGraphicsScene* scene;
        QGraphicsGridLayout *layout;
        QGraphicsWidget *form;
        int numberSeqBlocks = 0;

        std::vector<QGraphicsProxyWidget*> seqBlockProxyList;
        std::vector<seqBlockParameters*> seqBlockUiList;
        std::vector<QPixmapLayoutItem*> seqBlockImages;
        std::vector<NoTwoFingerGestureFilter*> seqBlockFilters;

    private slots:
        void seqBlock_enters_ReadSeqView(QPixmap seqBlock);
        void clear_selection();
        void on_HomeButton_clicked();
};

#endif // MAINWINDOW_H
