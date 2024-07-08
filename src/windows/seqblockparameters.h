#ifndef SEQBLOCKPARAMETERS_H
#define SEQBLOCKPARAMETERS_H

#include <QMainWindow>

namespace Ui {
class seqBlockParameters;
}

class seqBlockParameters : public QMainWindow
{
    Q_OBJECT

public:
    explicit seqBlockParameters(QWidget *parent = nullptr);
    ~seqBlockParameters();

private:
    Ui::seqBlockParameters *ui;
};

#endif // SEQBLOCKPARAMETERS_H
