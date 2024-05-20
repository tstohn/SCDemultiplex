#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    this->setStyleSheet("background-color: white;");

    //Load all PNGs for seauence blocks
    ui->ConstantBlock->setPixmap(QPixmap(":media/ConstantBlock.png"));

    //create the main scene of aligned barcodes
    scene = new QGraphicsScene();
    connect(ui->ReadSequenceGraphicsView, SIGNAL(itemdrop(QPixmap)), this, SLOT(seqBlockEntersReadSeqView(QPixmap)) );

}

void MainWindow::seqBlockEntersReadSeqView(QPixmap seqBlock)
{
    scene->addPixmap(seqBlock);

    ui->ReadSequenceGraphicsView->setScene(scene);
    ui->ReadSequenceGraphicsView->viewport()->update();
    ui->ReadSequenceGraphicsView->update();
    ui->ReadSequenceGraphicsView->show();
}

MainWindow::~MainWindow()
{
    delete ui;
}
