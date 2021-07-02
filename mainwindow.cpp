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

#define X256_IP "192.168.1.100"
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
    InitUI();

    m_timer.start(5000);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::TimeOutSlot()
{
    //InitNet();
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

    QVBoxLayout *pVbox = new QVBoxLayout(ui->widget_log);
    LogOperateWidget *pLogOperateWidget = new LogOperateWidget;
    pVbox->addWidget(pLogOperateWidget);
    pVbox->setMargin(0);
    ui->widget_log->setLayout(pVbox);


    pVbox = new QVBoxLayout(ui->widget_wave);
    CWaveWidget *pCwaveWidget = new CWaveWidget;
    pVbox->addWidget(pCwaveWidget);
    ui->widget_wave->setLayout(pVbox);

    pVbox = new QVBoxLayout(ui->widget_image);
    ImageWidget *pImageWidget = new ImageWidget;
    pVbox->addWidget(pImageWidget);
    ui->widget_image->setLayout(pVbox);
    connect(this, SIGNAL(SetImageSignal(QList<quint8>)), pImageWidget, SLOT(SetImageColor(QList<quint8>)));

    InitToolsButton();
    QFile style(":/qss/navy.css");
    if(style.open(QIODevice::ReadOnly)){
        QString qss = QLatin1String(style.readAll());
        this->setStyleSheet(qss);
    }

#if 1
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
    }
}

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

void MainWindow::OnChaXunAck(const QByteArray &data)
{
    ZhuangTaiAck status;

    m_waitObject.wake();
    memset(&status, 0, sizeof(ZhuangTaiAck));
    memcpy(&status, data.data(), sizeof(ZhuangTaiAck));

    if(status.bc_head.type == ZHUANG_TAI_CHA_XUN){
        /*补充数据显示*/
    }
}

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
}

void MainWindow::OnStartCollectAck(const QByteArray &data)
{
    BaseCommond ack;

    m_waitObject.wake();
    memcpy(&ack, data.data(), sizeof(BaseCommond));
    if(ack.bc_head.type == KAI_SHI_CAI_JI){
        if(ack.yuliu[0] == 0x11)
            LogOperate::getinstance()->LogOperaterUi(QString("参数设置成功"));
        else
            LogOperate::getinstance()->LogOperaterUi(QString("参数设置失败"));
    }
}

void MainWindow::on_pushButton_canshu_set_clicked()
{
    CanShuSetInfo CanShuSetCmd;
    bool wait_rtn;
    QByteArray SendData(sizeof(CanShuSetInfo), Qt::Uninitialized);

    DeviceController *pDeviceCtrl = DeviceController::getInstance();
    connect(pDeviceCtrl, SIGNAL(ProcessMonitorDataSignal(QByteArray)), this, SLOT(OnCanShuSetAck(QByteArray)));

    CanShuSetCmd.bc_head.type = CAN_SHU_SHE_ZHI;
    //CanShuSetCmd.caijidianshu = ;
    //CanShuSetCmd.zengyizhi = ;

    memcpy(SendData.data(), &CanShuSetCmd, sizeof(CanShuSetInfo));
    pDeviceCtrl->SendMonitorData(SendData);
    wait_rtn = m_waitObject.wait();
    if(!wait_rtn)
        LogOperate::getinstance()->LogOperaterUi(QString("参数设置回复超时。。。"),LOG_ERROR);
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

    m_waitObject.wake();
    memcpy(&ack, data.data(), sizeof(ShangChuanAck));
    if(ack.bc_head.type == KAI_SHI_SHANG_CHUAN){
        /*采集处理结果*/
    }
}

void MainWindow::on_pushButton_start_trans_clicked()
{
    BaseCommond StartTransCmd;
    bool wait_rtn;
    QByteArray SendData(sizeof(BaseCommond), Qt::Uninitialized);

    DeviceController *pDeviceCtrl = DeviceController::getInstance();
    connect(pDeviceCtrl, SIGNAL(ProcessMonitorDataSignal(QByteArray)), this, SLOT(OnStartTransAck(QByteArray)));

    StartTransCmd.bc_head.type = KAI_SHI_SHANG_CHUAN;
    memcpy(SendData.data(), &StartTransCmd, sizeof(BaseCommond));
    pDeviceCtrl->SendMonitorData(SendData);
    wait_rtn = m_waitObject.wait();
    if(!wait_rtn)
        LogOperate::getinstance()->LogOperaterUi(QString("上传回复超时。。。"),LOG_ERROR);
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
    QString SrcDataPathStr;

    DeviceController *pDeviceCtrl = DeviceController::getInstance();

    QString TimeStr = QDateTime::currentDateTime().toString("yy_MM_dd_hh_mm_ss.bin");

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
