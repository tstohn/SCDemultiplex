#include "seqblockparameters.h"
#include "ui_seqblockparameters.h"

seqBlockParameters::seqBlockParameters(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::seqBlockParameters)
{
    ui->setupUi(this);
}

seqBlockParameters::~seqBlockParameters()
{
    delete ui;
}
