#ifndef CONNECTTHREAD_H
#define CONNECTTHREAD_H

/*
 * 1.包含torch头文件
*/
#include <torch/script.h>
#include <torch/torch.h>  //注意：这个torch.h需要放在最顶端，这是最坑的

#include <QObject>
#include <QWidget>
#include <vector>

/*
 * 4.包含自己头文件
*/
extern "C++"
{
    #include "HrgTofApi.h"
    #include "setparam.h"
    #include "connectthread.h"  //多线程
}

class ConnectThread : public QObject
{
    Q_OBJECT
public:
    explicit ConnectThread(QWidget *parent = nullptr);
    void connectHRG(std::vector<QString> IPandPort, Hrg_Dev_Info *dev, Hrg_Dev_Handle *handle);

signals:
    void S_openedHRG();
    void F_openedHRG();
public slots:
};

#endif // CONNECTTHREAD_H
