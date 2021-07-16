#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "LogOpreate/LogOperateWidget.h"
#include <QVBoxLayout>
#include "./controlservice/devicecontroller.h"
#include "./public/myhelper.h"
#include "./public/iconhelper.h"
#include "gloabl.h"
#include <QDateTime>
#include <QRect>
#include <QFile>
#include <QDataStream>
#include <QToolButton>
#include <QMetaType>
#include "./gui/cwavewidget.h"
#include "./gui/imagewidget.h"
#include "./public/cdatahandleclass.h"
#include <QHBoxLayout>
#include "public/statusinfomation.h"
#include "controlservice/systemminitorservice.h"
#include <QtEndian>
#include "public/paramrangmanage.h"

#define X256_IP "192.168.1.100"
#define DIAN_NAO_IP "192.168.1.X"
#define X256_COMMOND_PORT 9001
#define X256_RTN_WAVE_PORT 9002
#define SRC_DATA_PATH "./src_data/"


MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    qRegisterMetaType<QList<quint8> >("QList<quint8>");/*注册自定义类型*/
    qRegisterMetaType<QList<quint8> >("QList<quint8>&");/*应用需要单独注册*/
    connect(&m_timer, SIGNAL(timeout()), this, SLOT(TimeOutSlot()));
    connect(SystemMinitorService::getInstance(), SIGNAL(UpdateStatusSignal()), this, SLOT(OnUpdateStatus()));
    InitUI();

    m_timer.start(8000);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::TimeOutSlot()
{
    InitNet();
}

void MainWindow::InitUI()
{
    this->setProperty("canMove", true);
    //ui->widget_title->setProperty("canMove",true);
    this->setWindowFlags(Qt::FramelessWindowHint | Qt::WindowSystemMenuHint | Qt::WindowMinMaxButtonsHint);
    myHelper::FormInCenter(this);
    IconHelper::getInstance()->SetIcon(ui->label_icon, QChar(0xf015), 16);
    IconHelper::getInstance()->SetIcon(ui->pushButton_min, QChar(0xf068), 10);
    IconHelper::getInstance()->SetIcon(ui->pushButton_max, QChar(0xf096),10);
    IconHelper::getInstance()->SetIcon(ui->pushButton_close, QChar(0xf00d), 10);
    IconHelper::getInstance()->SetIcon(ui->label_icon_temp, QChar(0xf2c7), 24);

    QVBoxLayout *pVbox = new QVBoxLayout(ui->widget_log);
    LogOperateWidget *pLogOperateWidget = new LogOperateWidget;
    pVbox->addWidget(pLogOperateWidget);
    pVbox->setMargin(0);
    ui->widget_log->setLayout(pVbox);


    pVbox = new QVBoxLayout(ui->widget_wave);
    CWaveWidget *pCwaveWidget = new CWaveWidget;
    pVbox->addWidget(pCwaveWidget);
    pVbox->setMargin(0);
    ui->widget_wave->setLayout(pVbox);

    pVbox = new QVBoxLayout(ui->widget_image);
    ImageWidget *pImageWidget = new ImageWidget;
    pVbox->addWidget(pImageWidget);
    ui->widget_image->setLayout(pVbox);
    connect(this, SIGNAL(SetImageSignal(QList<quint8>)), pImageWidget, SLOT(SetImageColor(QList<quint8>)));

    InitToolsButton();
    InitZuJian();
    ui->widget_huangwei->setEnabled(false);

    QFile style(":/qss/navy.css");
    if(style.open(QIODevice::ReadOnly)){
        QString qss = QLatin1String(style.readAll());
        this->setStyleSheet(qss);
    }

#if 0
    /*测试图片*/
    QList<quint8> list;
    for(quint32 i = 0; i < 256; i++){
        list.append(i);
    }
    emit SetImageSignal(list);


#endif
}

void MainWindow::InitToolsButton()
{
    QList<QToolButton*> ToolButtonList;
    ToolButtonList = ui->widgetLeft->findChildren<QToolButton *>();
    foreach (QToolButton *pTbtn, ToolButtonList) {
        pTbtn->setCheckable(true);
        connect(pTbtn, SIGNAL(clicked()), this, SLOT(OnToolClicked()));
    }

    ui->toolButton_set->click();
}

void MainWindow::InitNet()
{
    bool TcpOpenStatus1,TcpOpenStatus2;

    DeviceController *pDeviceCtrl = DeviceController::getInstance();

    TcpOpenStatus1 = pDeviceCtrl->OpenTcpMonitor(X256_IP, X256_COMMOND_PORT);
    TcpOpenStatus2 = pDeviceCtrl->OpenTcpWave(X256_IP, X256_RTN_WAVE_PORT);
    if(!TcpOpenStatus1 || !TcpOpenStatus2)
        LogOperate::getinstance()->LogOperaterUi(QString("网络连接失败。。。"),LOG_ERROR);
    else{
        LogOperate::getinstance()->LogOperaterUi(QString("网络连接成功。。。"),LOG_INFO);
        m_timer.stop();
        SystemMinitorService::getInstance()->StartSystemMinitor();
        ui->widget_huangwei->setEnabled(true);
    }
}

void MainWindow::InitZuJian()
{
    QHBoxLayout *pHbox = new QHBoxLayout(ui->scrollAreaWidgetContents);
    for(quint8 i = 0; i < 6; i++){
        ZuJianWidget *pWidget = new ZuJianWidget(NULL,6+i, i+1);
        pWidget->setPushButtonText(QString("第%1组打开").arg(i+1));
        pHbox->addWidget(pWidget);
        m_ZuJianVolMap.insert(i+1, pWidget);
    }
    ui->scrollAreaWidgetContents->setLayout(pHbox);

    pHbox = new QHBoxLayout(ui->scrollAreaWidgetContents_2);
    for(quint8 i = 0; i < 8; i++){
        AdcWidget *pWidget = new AdcWidget;
        pWidget->setTitle(QString("+1.4V"));
        pWidget->setAdcCs(18+i);
        pWidget->setHiddenButton();
        pHbox->addWidget(pWidget);
        m_adcWidgetMap.insert(i,pWidget);
    }

    /*初始化私有通道变量*/


    ui->scrollAreaWidgetContents_2->setLayout(pHbox);
}

#if 0
/**
 * @brief MainWindow::on_pushButton_status_chaxun_clicked 按钮状态查询
 */
void MainWindow::on_pushButton_status_chaxun_clicked()
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
#endif

void MainWindow::OnCanShuSetAck(const QByteArray &data)
{
    BaseCommond ack;

    m_waitObject.wake();
    memcpy(&ack, data.data(), sizeof(BaseCommond));
    if(ack.bc_head.type == CAN_SHU_SHE_ZHI){
        if(ack.yuliu[0] == 0x11)
            LogOperate::getinstance()->LogOperaterUi(QString("参数设置成功"));
        else
            LogOperate::getinstance()->LogOperaterUi(QString("参数设置失败"));
    }
    ui->pushButton_canshu_set->setEnabled(true);
    ui->pushButton_dianya_set->setEnabled(true);
}

void MainWindow::OnStartCollectAck(const QByteArray &data)
{
    BaseCommond ack;

    m_waitObject.wake();
    memcpy(&ack, data.data(), sizeof(BaseCommond));
    if(ack.bc_head.type == KAI_SHI_CAI_JI){
        if(ack.yuliu[0] == 0x11)
            LogOperate::getinstance()->LogOperaterUi(QString("采集成功"));
        else
            LogOperate::getinstance()->LogOperaterUi(QString("采集失败"));
    }
}

void MainWindow::on_pushButton_canshu_set_clicked()
{
    ui->pushButton_canshu_set->setEnabled(false);
    CanShuSetInfo CanShuSetCmd;
    bool wait_rtn;
    QByteArray SendData(sizeof(CanShuSetInfo), Qt::Uninitialized);

    DeviceController *pDeviceCtrl = DeviceController::getInstance();
    connect(pDeviceCtrl, SIGNAL(ProcessMonitorDataSignal(QByteArray)), this, SLOT(OnCanShuSetAck(QByteArray)));

    CanShuSetCmd.bc_head.type = CAN_SHU_SHE_ZHI;
    quint16 temp = (ui->lineEdit_caijidian->text().toUShort());
    temp = ((temp >> 8)&0xFF) | ((temp << 8)&0xFF00);
    CanShuSetCmd.caijidianshu = temp;
    CDataHandleClass::getInstance()->m_CurrentCaiYangDian = ui->lineEdit_caijidian->text().toUShort();

    for(quint8 i = 1; i <= 16; i++){
        QLineEdit *p = ui->groupBox_adc->findChild<QLineEdit *>(QString("lineEdit_adc%1").arg(i));
        if(p){
            CanShuSetCmd.zengyizhi[i - 1] = qFromBigEndian(p->text().toUShort());
        }
    }

    memcpy(SendData.data(), &CanShuSetCmd, sizeof(CanShuSetInfo));
    //qDebug()<<myHelper::ByteArrayToHexStr(SendData);
    pDeviceCtrl->SendMonitorData(SendData);
    wait_rtn = m_waitObject.wait();
    if(!wait_rtn){
        LogOperate::getinstance()->LogOperaterUi(QString("参数设置回复超时。。。"),LOG_ERROR);
        ui->pushButton_canshu_set->setEnabled(true);
    }

    disconnect(pDeviceCtrl, SIGNAL(ProcessMonitorDataSignal(QByteArray)), this, SLOT(OnCanShuSetAck(QByteArray)));
}

void MainWindow::on_pushButton_start_collect_clicked()
{
    BaseCommond CollectCmd;
    bool wait_rtn;
    QByteArray SendData(sizeof(BaseCommond), Qt::Uninitialized);

    DeviceController *pDeviceCtrl = DeviceController::getInstance();
    connect(pDeviceCtrl, SIGNAL(ProcessMonitorDataSignal(QByteArray)), this, SLOT(OnStartCollectAck(QByteArray)));

    CollectCmd.bc_head.type = KAI_SHI_CAI_JI;
    memcpy(SendData.data(), &CollectCmd, sizeof(BaseCommond));
    pDeviceCtrl->SendMonitorData(SendData);
    wait_rtn = m_waitObject.wait();
    if(!wait_rtn)
        LogOperate::getinstance()->LogOperaterUi(QString("采集回复超时。。。"),LOG_ERROR);
    disconnect(pDeviceCtrl, SIGNAL(ProcessMonitorDataSignal(QByteArray)), this, SLOT(OnStartCollectAck(QByteArray)));
}

void MainWindow::OnStartTransAck(const QByteArray &data)
{
    ShangChuanAck ack;
    QList<quint8> list;
    quint32 i;

    m_waitObject.wake();
    memcpy(&ack, data.data(), sizeof(ShangChuanAck));
    if(ack.bc_head.type == KAI_SHI_SHANG_CHUAN){
        /*采集处理结果*/
        for(i = 0; i < 256; i++){
            list.append(qFromBigEndian(ack.caiji_result[i]));
        }
        emit SetImageSignal(list);
    }
    SystemMinitorService::getInstance()->StartSystemMinitor();
}

void MainWindow::on_pushButton_start_trans_clicked()
{
    BaseCommond StartTransCmd;
    bool wait_rtn;
    QByteArray SendData(sizeof(BaseCommond), Qt::Uninitialized);

    DeviceController *pDeviceCtrl = DeviceController::getInstance();
    SystemMinitorService::getInstance()->StopSystemMinitor();
    connect(pDeviceCtrl, SIGNAL(ProcessMonitorDataSignal(QByteArray)), this, SLOT(OnStartTransAck(QByteArray)));

    StartTransCmd.bc_head.type = KAI_SHI_SHANG_CHUAN;
    memcpy(SendData.data(), &StartTransCmd, sizeof(BaseCommond));
    pDeviceCtrl->SendMonitorData(SendData);
    wait_rtn = m_waitObject.wait();
    if(!wait_rtn){
         LogOperate::getinstance()->LogOperaterUi(QString("上传回复超时。。。"),LOG_ERROR);
         SystemMinitorService::getInstance()->StartSystemMinitor();
    }

    disconnect(pDeviceCtrl, SIGNAL(ProcessMonitorDataSignal(QByteArray)), this, SLOT(OnStartTransAck(QByteArray)));
}

void MainWindow::OnDianYaCtrlAck(const QByteArray &data)
{
    BaseCommond ack;

    m_waitObject.wake();
    memcpy(&ack, data.data(), sizeof(BaseCommond));
    if(ack.bc_head.type == DIAN_YA_KONG_ZHI){
        if(ack.yuliu[0] == 0x11)
            LogOperate::getinstance()->LogOperaterUi(QString("参数设置成功"));
        else
            LogOperate::getinstance()->LogOperaterUi(QString("参数设置失败"));
    }
}

void MainWindow::on_pushButton_dianya_ctrl_clicked()
{
    BaseCommond DianYaCtrlCmd;
    bool wait_rtn;
    QByteArray SendData(sizeof(BaseCommond), Qt::Uninitialized);

    DeviceController *pDeviceCtrl = DeviceController::getInstance();
    connect(pDeviceCtrl, SIGNAL(ProcessMonitorDataSignal(QByteArray)), this, SLOT(OnDianYaCtrlAck(QByteArray)));

    DianYaCtrlCmd.bc_head.type = DIAN_YA_KONG_ZHI;
    //DianYaCtrlCmd.yuliu[0] =
    //DianYaCtrlCmd.yuliu[0] =
    //DianYaCtrlCmd.yuliu[0] =
    //DianYaCtrlCmd.yuliu[0] =
    memcpy(SendData.data(), &DianYaCtrlCmd, sizeof(BaseCommond));
    pDeviceCtrl->SendMonitorData(SendData);
    wait_rtn = m_waitObject.wait();
    if(!wait_rtn)
        LogOperate::getinstance()->LogOperaterUi(QString("电压控制回复超时。。。"),LOG_ERROR);
    disconnect(pDeviceCtrl, SIGNAL(ProcessMonitorDataSignal(QByteArray)), this, SLOT(OnDianYaCtrlAck(QByteArray)));
}

void MainWindow::OnDianYaZuJianAck(const QByteArray &data)
{
    BaseCommond ack;

    m_waitObject.wake();
    memcpy(&ack, data.data(), sizeof(BaseCommond));
    if(ack.bc_head.type == DIAN_YA_KONG_ZHI){
        if(ack.yuliu[0] == 0x11)
            LogOperate::getinstance()->LogOperaterUi(QString("电压组件设置成功"));
        else
            LogOperate::getinstance()->LogOperaterUi(QString("电压组件设置失败"));
    }
}

void MainWindow::on_pushButton_dianya_zujian_clicked()
{
    BaseCommond DianYaZuJianCmd;
    bool wait_rtn;
    QByteArray SendData(sizeof(BaseCommond), Qt::Uninitialized);

    DeviceController *pDeviceCtrl = DeviceController::getInstance();
    connect(pDeviceCtrl, SIGNAL(ProcessMonitorDataSignal(QByteArray)), this, SLOT(OnDianYaZuJianAck(QByteArray)));

    DianYaZuJianCmd.bc_head.type = DIAN_YA_ZU_JIAN;
    //DianYaCtrlCmd.yuliu[0] =
    //DianYaCtrlCmd.yuliu[0] =
    //DianYaCtrlCmd.yuliu[0] =
    //DianYaCtrlCmd.yuliu[0] =
    memcpy(SendData.data(), &DianYaZuJianCmd, sizeof(BaseCommond));
    pDeviceCtrl->SendMonitorData(SendData);
    wait_rtn = m_waitObject.wait();
    if(!wait_rtn)
        LogOperate::getinstance()->LogOperaterUi(QString("电压组件回复超时。。。"),LOG_ERROR);
    disconnect(pDeviceCtrl, SIGNAL(ProcessMonitorDataSignal(QByteArray)), this, SLOT(OnDianYaZuJianAck(QByteArray)));
}

void MainWindow::on_pushButton_src_shangchuan_clicked()
{
    SystemMinitorService::getInstance()->StopSystemMinitor();
    QString SrcDataPathStr;
    BaseCommond SrcShangChuanCmd;
    QByteArray SendData(sizeof(BaseCommond), Qt::Uninitialized);

    DeviceController *pDeviceCtrl = DeviceController::getInstance();

    QString TimeStr = QDateTime::currentDateTime().toString("yy_MM_dd_hh_mm_ss.bin");
    SrcShangChuanCmd.bc_head.type = SRC_FILE_SHANG_CHUAN;
    memcpy(SendData.data(), &SrcShangChuanCmd, sizeof(BaseCommond));
    pDeviceCtrl->SendMonitorData(SendData);

    SrcDataPathStr = QString(SRC_DATA_PATH) + TimeStr;

    pDeviceCtrl->SetFileNameAndIntoLoop(SrcDataPathStr);

    LogOperate::getinstance()->LogOperaterUi(QString("源数据上传中，请稍后。。。"), LOG_INFO);
}

void MainWindow::on_pushButton_close_clicked()
{
    this->close();
}

void MainWindow::on_pushButton_min_clicked()
{
    this->setWindowState(Qt::WindowMinimized);
}

void MainWindow::on_pushButton_max_clicked()
{
    static bool isMax = false;
    static QRect rect = this->geometry();
    if(!isMax){
        this->setGeometry(qApp->desktop()->availableGeometry());
        IconHelper::getInstance()->SetIcon(ui->pushButton_max, QChar(0xf079), 10);
        ui->pushButton_max->setToolTip(QString("还原"));
    }else{
        this->setGeometry(rect);
        IconHelper::getInstance()->SetIcon(ui->pushButton_max, QChar(0xf096), 10);
        ui->pushButton_max->setToolTip(QString("最大化"));
    }
    this->setProperty("canMove", isMax);
    //ui->widget_title->setProperty("canMove",isMax);
    isMax = !isMax;
}

void MainWindow::OnToolClicked()
{
    QList<QToolButton *> btnList;
    QToolButton *pBtn = (QToolButton *)sender();
    QString btnName = pBtn->text();

    btnList = ui->widgetLeft->findChildren<QToolButton *>();
    foreach (QToolButton *btn, btnList) {
        if(btn->text() == btnName){
            btn->setChecked(true);
        }else{
            btn->setChecked(false);
        }
    }
    if(btnName == "采集板卡"){
        ui->stackedWidget->setCurrentIndex(0);
    } else if ( btnName == "电源板卡"){
        ui->stackedWidget->setCurrentIndex(1);
    }else if(btnName == "采集波形"){
        ui->stackedWidget->setCurrentIndex(2);
    }else if(btnName == "数据成像"){
        ui->stackedWidget->setCurrentIndex(3);
    }
}
/**
 * @brief MainWindow::on_pushButton_dianya_set_clicked
 * 参数设置，即设置电压
 */
void MainWindow::on_pushButton_dianya_set_clicked()
{
    float f_vol,f_output;
    qint8 channel;
    quint16 output;
    quint8 error = 0;
    bool wait_rtn,isSuccess;
    QByteArray SendData(sizeof(CanShuSetInfo), Qt::Uninitialized);
    QMap<quint8, AdcWidget *> volMap;
    QMap<quint8, ZuJianWidget* >::const_iterator i;
    QMap<quint8, AdcWidget * >::const_iterator j;
    CanShuSetInfo cmd;
    DeviceController *pDeviceCtrl = DeviceController::getInstance();
    ui->pushButton_dianya_set->setEnabled(false);

    connect(pDeviceCtrl, SIGNAL(ProcessMonitorDataSignal(QByteArray)), this, SLOT(OnCanShuSetAck(QByteArray)));
    cmd.bc_head.type = CAN_SHU_SHE_ZHI;

    for(i = m_ZuJianVolMap.begin(); i != m_ZuJianVolMap.end(); i++){
        volMap = i.value()->getVolMap();
        for(j = volMap.begin(); j != volMap.end(); j++){
            channel = j.key();
            isSuccess = j.value()->getVol(f_vol);
            if(!isSuccess) error++;
            if( (channel >= 0) && (channel <= 5) ){
                float dyChaMax = ParamRangManage::getShiSiFuVolRangMax() - ParamRangManage::getShiSiFuVolRangMin();
                float dyShiJiCha = f_vol - ParamRangManage::getShiSiFuVolRangMin();
                if(dyShiJiCha < 0) continue;
                f_output = dyShiJiCha * 4096.0 / dyChaMax;
                output = qRound(f_output);
                cmd.dianyacanshu4[channel] = qFromBigEndian(output);
            }else if( (channel > 5) && (channel <= 11) ){
                float dyChaMax = ParamRangManage::getFuWuFuVolRangMax() - ParamRangManage::getFuWuFuVolRangMin();
                float dyShiJiCha = f_vol - ParamRangManage::getFuWuFuVolRangMin();
                if(dyShiJiCha < 0) continue;
                f_output = dyShiJiCha * 4096.0 / dyChaMax;
                output = qRound(f_output);
                cmd.dianyacanshu2[channel] = qFromBigEndian(output);
            }else if( (channel > 11) && (channel <= 17) ){
                float dyChaMax = ParamRangManage::getZhengWuFuVolRangMax() - ParamRangManage::getZhengWuFuVolRangMin();
                float dyShiJiCha = f_vol - ParamRangManage::getZhengWuFuVolRangMin();
                if(dyShiJiCha < 0) continue;
                f_output = dyShiJiCha * 4096.0 / dyChaMax;
                output = qRound(f_output);
                cmd.dianyacanshu3[channel] = qFromBigEndian(output);
            }else{
                float dyChaMax = ParamRangManage::getYiDianSiFuVolRangMax() - ParamRangManage::getYiDianSiFuVolRangMin();
                float dyShiJiCha = f_vol - ParamRangManage::getYiDianSiFuVolRangMin();
                if(dyShiJiCha < 0) continue;
                f_output = dyShiJiCha * 4096.0 / dyChaMax;
                output = qRound(f_output);
                cmd.dianyacanshu1[channel] = qFromBigEndian(output);
            }
        }
    }

    quint16 temp = (ui->lineEdit_caijidian->text().toUShort());
    temp = ((temp >> 8)&0xFF) | ((temp << 8)&0xFF00);
    cmd.caijidianshu = temp;

    for(quint8 i = 1; i <= 16; i++){
        QLineEdit *p = ui->groupBox_adc->findChild<QLineEdit *>(QString("lineEdit_adc%1").arg(i));
        if(p){
            cmd.zengyizhi[i - 1] = qFromBigEndian(p->text().toUShort());
        }
    }

    memcpy(SendData.data(), &cmd, sizeof(CanShuSetInfo));
    //qDebug()<<myHelper::ByteArrayToHexStr(SendData);
    if(error){
        ui->pushButton_canshu_set->setEnabled(true);
        ui->pushButton_dianya_set->setEnabled(true);
        disconnect(pDeviceCtrl, SIGNAL(ProcessMonitorDataSignal(QByteArray)), this, SLOT(OnCanShuSetAck(QByteArray)));
        return;
    }
    pDeviceCtrl->SendMonitorData(SendData);
    wait_rtn = m_waitObject.wait();
    if(!wait_rtn){
        LogOperate::getinstance()->LogOperaterUi(QString("参数设置回复超时。。。"),LOG_ERROR);
        ui->pushButton_canshu_set->setEnabled(true);
        ui->pushButton_dianya_set->setEnabled(true);
    }

    disconnect(pDeviceCtrl, SIGNAL(ProcessMonitorDataSignal(QByteArray)), this, SLOT(OnCanShuSetAck(QByteArray)));
}

void MainWindow::OnUpdateStatus()
{
    StatusInfomation *pStatus = StatusInfomation::getInstance();

    ui->label_caiji_wendu->setText(pStatus->getCaiJiFpgaTemp());

    ui->label_dy_temp->setText(pStatus->getDianYaFpgaTemp());

    ui->label_work_status->setText(pStatus->getWorkStatus());

    ui->label_liuchang_status->setText(pStatus->getLiuChengStatus());
}








