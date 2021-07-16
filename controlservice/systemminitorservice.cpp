#include "systemminitorservice.h"
#include "devicecontroller.h"
#include "../gloabl.h"
#include "../public/statusinfomation.h"
#include "../LogOpreate/LogOperate.h"
#include <QDebug>
#include <QtEndian>

SystemMinitorService::SystemMinitorService(QObject *parent) : QObject(parent)
{
    m_timer.setInterval(1000);
    connect(&m_timer, SIGNAL(timeout()),this, SLOT(OnTimeOut()));
}

SystemMinitorService *SystemMinitorService::getInstance()
{
    static SystemMinitorService instance;

    return &instance;
}

void SystemMinitorService::StartSystemMinitor()
{
    m_timer.start();
}

void SystemMinitorService::StopSystemMinitor()
{
    m_timer.stop();
}

void SystemMinitorService::OnTimeOut()
{

    BaseCommond ChaXunCmd;
    bool wait_rtn;
    QByteArray SendData(sizeof(BaseCommond), Qt::Uninitialized);

    DeviceController *pDeviceCtrl = DeviceController::getInstance();
    connect(pDeviceCtrl, SIGNAL(ProcessMonitorDataSignal(QByteArray)), this, SLOT(OnChaXunAck(QByteArray)));

    ChaXunCmd.bc_head.type = ZHUANG_TAI_CHA_XUN;
    memcpy(SendData.data(), &ChaXunCmd, sizeof(BaseCommond));
    pDeviceCtrl->SendMonitorData(SendData);
    wait_rtn = m_waitObject.wait();
    if(!wait_rtn)
        LogOperate::getinstance()->LogOperaterUi(QString("查询回复超时。。。"),LOG_ERROR);
    disconnect(pDeviceCtrl, SIGNAL(ProcessMonitorDataSignal(QByteArray)), this, SLOT(OnChaXunAck(QByteArray)));
}

void SystemMinitorService::OnChaXunAck(const QByteArray &data)
{
    ZhuangTaiAck status;
    double temp;
    QString str;
    StatusInfomation *p = StatusInfomation::getInstance();

    m_waitObject.wake();
    memset(&status, 0, sizeof(ZhuangTaiAck));
    memcpy(&status, data.data(), sizeof(ZhuangTaiAck));

    if(status.bc_head.type == ZHUANG_TAI_CHA_XUN){

        temp = qFromBigEndian(status.caiji_fpga_wendu) * 530.975 / 4096.0 - 273.15;
        str = QString::number(temp,'f', 1) + "℃";
        p->setCaiJiFpgaTemp(str);

        //qDebug()<<"11 = "<<QString::number(status.caiji_fpga_wendu,16);
        temp = qFromBigEndian(status.dianya_fpga_wendu) * 530.975 / 4096.0 - 273.15;
        str = QString::number(temp,'f', 1) + "℃";
        p->setDianYaFpgaTemp(str);
        //qDebug()<<"22 = "<<QString::number(status.dianya_fpga_wendu,16);

        str = status.work_status ? QString("就绪") : QString("板卡异常");
        p->setWorkStatus(str);

        switch(status.liucheng_status){
        case 0x01:str = QString("等待设置");break;
        case 0x02:str = QString("等待采集");break;
        case 0x03:str = QString("正在处理");break;
        case 0x04:str = QString("等待上传");break;
        case 0x05:str = QString("未开机完成");break;
        default:
            break;
        }
        p->setLiuChengStatus(str);
        emit UpdateStatusSignal();
    }
}
