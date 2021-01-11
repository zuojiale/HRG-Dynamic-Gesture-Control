#include "connectthread.h"
#include <QDebug>
#include <QThread>
#include <vector>


ConnectThread::ConnectThread(QWidget *parent) : QObject(parent)
{

}
void ConnectThread::connectHRG(std::vector<QString> IPandPort, Hrg_Dev_Info *dev, Hrg_Dev_Handle *handle)
{
    //子线程函数
    //0.解析数据
    QString IP = IPandPort[0];
    QByteArray byteArray = IP.toUtf8();
    char * IP1 = byteArray.data();
    int port = IPandPort[1].toInt();

    Hrg_LogConfig(HRG_LOG_LEVEL_INFO);
    //2.新建一个hrg相机的类对象，并给定连接参数
    dev->type = Dev_Eth;
    dev->Info.eth.addr = IP1;//ip，需要根据连接模式更改
    dev->Info.eth.port = port; //端口
    dev->frameReady = NULL; //回调函数
    //3.hrg相机的句柄

    if(0 == Hrg_OpenDevice(dev, handle))
    {
        Hrg_SetRangeMode(handle, Mode_Range_L);  //模式：远距离L
        Hrg_SetFrameRate(handle, 10);   //帧率10
        Hrg_SetAmplitudeThreshold(handle, 30);  //幅度<30,depth滤除
        Hrg_StartStream(handle);
        emit S_openedHRG();
        return;
    }
    emit F_openedHRG();
    //qDebug() << "子线程开始拉！ID:" << QThread::currentThreadId();
}
