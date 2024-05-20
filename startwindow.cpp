#include "startwindow.h"
#include "ui_startwindow.h"
#include <QPixmap>
#include <QDir>
#include <QSvgWidget>
#include <QVBoxLayout>

#include "mainwindow.h"

StartWindow::StartWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::StartWindow)
{
    //SET BACKGROUND STYLE
    ui->setupUi(this);
    this->setStyleSheet("background-color: white;");


    //ADD SVG-IMAGE OF DEMULTIPELXING TOOL (assigned to QWidget in ui)
    QSvgWidget *svgWidget = new QSvgWidget(":media/DemultiplexingLogo.svg", ui->ImageWidget);
    int width = ui->ImageWidget->width();
    int height = static_cast<int>((static_cast<double>(svgWidget->sizeHint().height()) / svgWidget->sizeHint().width()) * width);
    // Set SVG widget size and show
    svgWidget->resize(width, height);

    //ADD START BUTTON
    ui->pushButton->setStyleSheet("QPushButton { font-weight: bold; }");
    ui->pushButton->setFixedSize(ui->pushButton->size());
}

StartWindow::~StartWindow()
{
    delete ui;
}

void StartWindow::on_pushButton_clicked()
{
    mw = new MainWindow();
    mw->show();
    this->close();
}

