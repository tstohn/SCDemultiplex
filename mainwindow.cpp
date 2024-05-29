#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "startwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    this->setStyleSheet("background-color: white;");

    //set style elements
    ui->TopBar->setPixmap(QPixmap(":media/TopBar.png").scaled(ui->TopBar->size(),Qt::KeepAspectRatio, Qt::SmoothTransformation));
    ui->TopBar->setParent(ui->centralwidget);

    //Load all PNGs for seauence blocks
    ui->ConstantBlock->setPixmap(QPixmap(":media/ConstantSeqBlock.png").scaled(ui->ConstantBlock->size(),Qt::KeepAspectRatio, Qt::SmoothTransformation));
    ui->ConstantBlock->setParent(ui->centralwidget);

    ui->VariableBlock->setPixmap(QPixmap(":media/VariableSeqBlock.png").scaled(ui->VariableBlock->size(),Qt::KeepAspectRatio, Qt::SmoothTransformation));
    ui->VariableBlock->setParent(ui->centralwidget);

    ui->UMIBlock->setPixmap(QPixmap(":media/UMISeqBlock.png").scaled(ui->UMIBlock->size(),Qt::KeepAspectRatio, Qt::SmoothTransformation));
    ui->UMIBlock->setParent(ui->centralwidget);

    ui->RNABlock->setPixmap(QPixmap(":media/RNASeqBlock.png").scaled(ui->RNABlock->size(),Qt::KeepAspectRatio, Qt::SmoothTransformation));

    //set progress bar to minimum
    ui->progressBar->reset();

    ui->RNABlock->setParent(ui->centralwidget);

    //create the main scene of aligned barcodes
    scene = new QGraphicsScene();
    form = new QGraphicsWidget;
    scene->addItem(form);
    layout = new QGraphicsGridLayout(form);

    ui->ReadSequenceGraphicsView->setScene(scene);

    connect(ui->ReadSequenceGraphicsView, SIGNAL(itemdrop(QPixmap)), this, SLOT(seqBlock_enters_ReadSeqView(QPixmap)) );
    connect(ui->ClearButton, &QPushButton::clicked, this, &MainWindow::clear_selection);

}

void MainWindow::clear_selection()
{
    //clear the scene
    delete form;
    scene->clear();

    //create new empty linear layout
    form = new QGraphicsWidget;
    scene->addItem(form);

    layout = new QGraphicsGridLayout(form);

    //set new scene
    ui->ReadSequenceGraphicsView->setScene(scene);
    ui->ReadSequenceGraphicsView->show();
}

void MainWindow::seqBlock_enters_ReadSeqView(QPixmap seqBlock)
{

    //add the new sequence Block without any coordiantes
    //scene->addPixmap()
    QPixmapLayoutItem* layoutItem = new QPixmapLayoutItem(seqBlock);
    //layout in grid: line, column, lines, columns to span
    layout->addItem(layoutItem, 0, numberSeqBlocks,1,1);

    //add the table of sequence parameters for demultiplexing
    seqBlockParameters* parameterUi = new seqBlockParameters();
    parameterUi->setFixedSize(parameterUi->width(), parameterUi->height());

    QGraphicsProxyWidget *proxy = new QGraphicsProxyWidget();
    //prohibit two finger movements
    NoTwoFingerGestureFilter *gestureFilter = new NoTwoFingerGestureFilter;
    proxy->installEventFilter(gestureFilter);

    proxy->setWidget(parameterUi);
    layout->addItem(proxy, 1, numberSeqBlocks,1,1);  // Add the widget to the first row and column

    //increase seqBlock count
    numberSeqBlocks++;
    //keeping track of all the sequence Elements that we create on heap
    seqBlockProxyList.push_back(proxy);
    seqBlockUiList.push_back(parameterUi);
    seqBlockImages.push_back(layoutItem);
    seqBlockFilters.push_back(gestureFilter);

}

MainWindow::~MainWindow()
{
    delete ui;
    delete scene;
    delete form;
    delete layout;

    seqBlockProxyList.clear();
    seqBlockUiList.clear();
    seqBlockImages.clear();
    seqBlockFilters.clear();
}

void MainWindow::on_HomeButton_clicked()
{
    StartWindow* startWindow = new StartWindow();
    startWindow->show();
    this->close();
}

