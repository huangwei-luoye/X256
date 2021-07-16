#include "adcwidget.h"
#include "ui_adcwidget.h"
#include "../public/iconhelper.h"
#include <QDebug>
#include "../LogOpreate/LogOperate.h"
#include "../public/statusinfomation.h"
#include "../controlservice/devicecontroller.h"
#include "../gloabl.h"
#include <QDebug>
#include <QPair>
#include "../public/myhelper.h"
#include "../public/paramrangmanage.h"

AdcWidget::AdcWidget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::AdcWidget)
{
    ui->setupUi(this);

    IconHelper::getInstance()->SetIcon(ui->label_icon_title,QChar(0xf06c),10);
    IconHelper::getInstance()->SetIcon(ui->label_icon_dianya,QChar(0xf0eb),10);
    IconHelper::getInstance()->SetIcon(ui->label_icon_dianliu,QChar(0xf043),10);

    m_timer.start(1000);
}

AdcWidget::~AdcWidget()
{
    delete ui;
}

void AdcWidget::setTitle(QString name)
{
    ui->label_title->setText(name);
}

void AdcWidget::setDianYa(qint8 dianya)
{
    ui->label_dianya->setText(QString::number(dianya));
}

void AdcWidget::setDianLiu(qint8 dianliu)
{
    ui->label_dianliu->setText(QString::number(dianliu));
}

void AdcWidget::setAdcCs(const quint8 &AdcCs)
{
    m_AdcCs = AdcCs;
}

void AdcWidget::setHiddenButton()
{
    ui->pushButton->hide();
}

bool AdcWidget::getVol(float &vol)
{
    bool ok;
    vol = ui->lineEdit->text().toFloat(&ok);
    if(!ok){
        LogOperate::getinstance()->LogOperaterUi(QString("通道%1参数输入错误,请检查输入！").arg(m_AdcCs),LOG_ERROR);
        return false;
    }else{
        if(m_AdcCs <= 5){
            if(vol > ParamRangManage::getShiSiFuVolRangMax() || vol < ParamRangManage::getShiSiFuVolRangMin()){
                   LogOperate::getinstance()->LogOperaterUi(QString("通道%1参数超出范围[%2~%3],请检查输入！").arg(m_AdcCs)
                                                            .arg(ParamRangManage::getShiSiFuVolRangMin())
                                                            .arg(ParamRangManage::getShiSiFuVolRangMax()),LOG_ERROR);
                   return false;
            }
        }else if(m_AdcCs > 5 && m_AdcCs < 12){
            if(vol > ParamRangManage::getFuWuFuVolRangMax() || vol < ParamRangManage::getFuWuFuVolRangMin()){
                   LogOperate::getinstance()->LogOperaterUi(QString("通道%1参数超出范围[%2~%3],请检查输入！").arg(m_AdcCs)
                                                            .arg(ParamRangManage::getFuWuFuVolRangMin())
                                                            .arg(ParamRangManage::getFuWuFuVolRangMax()),LOG_ERROR);
                   return false;
            }
        }else if((m_AdcCs >= 12) &&(m_AdcCs < 18)){
            if(vol > ParamRangManage::getZhengWuFuVolRangMax() || vol < ParamRangManage::getZhengWuFuVolRangMin()){
                   LogOperate::getinstance()->LogOperaterUi(QString("通道%1参数超出范围[%2~%3],请检查输入！").arg(m_AdcCs)
                                                            .arg(ParamRangManage::getZhengWuFuVolRangMin())
                                                            .arg(ParamRangManage::getZhengWuFuVolRangMax()),LOG_ERROR);
                   return false;
            }
        }else{
            if(vol > ParamRangManage::getYiDianSiFuVolRangMax() || vol < ParamRangManage::getYiDianSiFuVolRangMin()){
                   LogOperate::getinstance()->LogOperaterUi(QString("通道%1参数超出范围[%2~%3],请检查输入！").arg(m_AdcCs)
                                                            .arg(ParamRangManage::getYiDianSiFuVolRangMin())
                                                            .arg(ParamRangManage::getYiDianSiFuVolRangMax()),LOG_ERROR);
                   return false;
            }
        }

    }
    return true;
}

void AdcWidget::on_pushButton_clicked()
{

    if(ui->pushButton->text() == "打开"){
        ui->pushButton->setText("关闭");
        StatusInfomation::getInstance()->setDyStatus((1<<m_AdcCs) | StatusInfomation::getInstance()->getDyStatus());
    }else{
        ui->pushButton->setText("打开");
        StatusInfomation::getInstance()->setDyStatus(~(1<<m_AdcCs) & StatusInfomation::getInstance()->getDyStatus());
    }

    DeviceController *pDev = DeviceController::getInstance();

    BaseCommond sendCmd;

    sendCmd.bc_head.type = DIAN_YA_KONG_ZHI;
    quint32 dyStatus = StatusInfomation::getInstance()->getDyStatus();

    sendCmd.yuliu[0] = (dyStatus >> 24) & 0xFF;
    sendCmd.yuliu[1] = (dyStatus >> 16) & 0xFF;
    sendCmd.yuliu[2] = (dyStatus >> 8) & 0xFF;
    sendCmd.yuliu[3] = dyStatus & 0xFF;

    QByteArray sendArray(sizeof(BaseCommond),Qt::Uninitialized);
    memcpy(sendArray.data(), &sendCmd, sizeof(BaseCommond));
    //qDebug()<<myHelper::ByteArrayToHexStr(sendArray);

    pDev->SendMonitorData(sendArray);
}

void AdcWidget::OnTimerOut()
{
    StatusInfomation *pStatus = StatusInfomation::getInstance();
    QMap<quint8, QPair<quint16, quint16> > dyMap = pStatus->getDydlMap();
    quint16 dy,dl;

    if(dyMap.contains(m_AdcCs)){
        dy = dyMap.find(m_AdcCs).value().first;
        dl = dyMap.find(m_AdcCs).value().second;
        ui->label_dianya->setText(QString("%1 V").arg(dy));
        ui->label_dianliu->setText(QString("%1 A").arg(dl));
    }
}
