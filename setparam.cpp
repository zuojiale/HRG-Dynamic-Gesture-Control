#include "setparam.h"
#include "ui_setparam.h"

#include <QButtonGroup>
#include <QDebug>
#include <QMessageBox>

setparam::setparam(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::setparam)
{
    ui->setupUi(this);
    //对话框名称
    this->setWindowTitle("Connecting Options");
    QButtonGroup * linkwaygroup = new QButtonGroup(this);
    linkwaygroup->addButton(ui->radioNET);
    linkwaygroup->addButton(ui->radioUSB);
    //互斥
    linkwaygroup->setExclusive(true);
    ui->lineIP->setEnabled(false);
    ui->linePort->setEnabled(false);
}

setparam::~setparam()
{
    delete ui;
}


void setparam::on_buttonCancel_clicked()
{
    //"cancel"被按下
    close();
}


void setparam::on_buttonOk_released()
{
    //1. "ok"按按下
    if(ui->radioUSB->isChecked() == false && ui->radioNET->isChecked()==false)
    {
        QMessageBox::about(this,"Warning!","You should at least cheak one Connecting Way!");
        return;
    }
    if(ui->radioNET->isChecked())
    {
        QMessageBox::about(this,"Warning!","The NET connection way is on the way!");
        return;
    }
    //读取输入的ip和port
    QString IP = ui->lineIP->text();
    QString port = ui->linePort->text();
    qDebug() << IP << ',' << port;
    //组包
    std::vector<QString> IPandPort;
    IPandPort.push_back(IP);
    IPandPort.push_back(port);

    //发射信号
    emit SendIPandPort(IPandPort);
    close();
}

void setparam::on_buttonOk_pressed()
{
    emit CanShowConnectDialog();
}

void setparam::on_radioUSB_clicked()
{
    ui->lineIP->setEnabled(true);
    ui->linePort->setEnabled(true);
}
