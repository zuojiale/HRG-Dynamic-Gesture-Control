#ifndef SETPARAM_H
#define SETPARAM_H

/*
 * 1.包含torch头文件
*/
#include <torch/script.h>
#include <torch/torch.h>  //注意：这个torch.h需要放在最顶端，这是最坑的

#include <QDialog>
#include <QProgressDialog>

namespace Ui {
class setparam;
}


class setparam : public QDialog
{
    Q_OBJECT
signals:
    void SendIPandPort(std::vector<QString> IPandPort);
    void CanShowConnectDialog();

public:
    explicit setparam(QWidget *parent = 0);
    ~setparam();

private slots:
    void on_buttonCancel_clicked();

    void on_buttonOk_released();

    void on_buttonOk_pressed();

    void on_radioUSB_clicked();

private:
    Ui::setparam *ui;
};

#endif // SETPARAM_H
