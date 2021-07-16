#include "zujianwidget.h"
#include "ui_zujianwidget.h"
#include <QVBoxLayout>
#include <QDebug>
#include "../controlservice/devicecontroller.h"
#include "../gloabl.h"
#include <QDebug>

ZuJianWidget::ZuJianWidget(QWidget *parent, quint8 base,quint8 zu) :
    QWidget(parent),m_baseChannel(base),m_dijizu(zu),
    ui(new Ui::ZuJianWidget)
{
    ui->setupUi(this);
    InitUI();
}

ZuJianWidget::~ZuJianWidget()
{
    delete ui;
}

void ZuJianWidget::setPushButtonText(const QString text)
{
    ui->pushButton->setText(text);
}

void ZuJianWidget::InitList()
{

}

void ZuJianWidget::InitUI()
{

    QVBoxLayout *pVbox = new QVBoxLayout(ui->widget);
    //ui->widget->setEnabled();
    for(quint8 i = 0; i < 3; i++){
        AdcWidget *pAdcWidget = new AdcWidget;
        if(i == 0){
            pAdcWidget->setTitle(QString("-5V"));
            pAdcWidget->setAdcCs(m_baseChannel);
            m_map.insert(m_baseChannel, pAdcWidget);
        }else if(i == 1){
            pAdcWidget->setTitle(QString("+5V"));
            pAdcWidget->setAdcCs(m_baseChannel + 6);
            m_map.insert(m_baseChannel + 6, pAdcWidget);
        }else{
            pAdcWidget->setTitle(QString("+14V"));
            pAdcWidget->setAdcCs(m_baseChannel - 6);
            m_map.insert(m_baseChannel - 6, pAdcWidget);
        }

        pVbox->addWidget(pAdcWidget);
    }
    pVbox->setMargin(0);
    //ui->scrollArea->setStyleSheet("border::none");
    ui->widget->setLayout(pVbox);

    QFile style(":/qss/zujian_widget.css");
    if(style.open(QIODevice::ReadOnly)){
        this->setStyleSheet(style.readAll());
        style.close();
    }

}

void ZuJianWidget::on_pushButton_clicked()
{
    static quint8 ZuJianBit;
    if(m_dijizu == 1){
        if(ui->pushButton->text() == "第1组打开"){
            ui->pushButton->setText("第1组关闭");
            ui->widget->setEnabled(false);
            ZuJianBit |= 1<<((m_dijizu - 1));
        }else{
            ui->pushButton->setText("第1组打开");
            ui->widget->setEnabled(true);
            ZuJianBit &= ~(1<<(m_dijizu - 1));
        }
    }else if(m_dijizu == 2){
        if(ui->pushButton->text() == "第2组打开"){
            ui->pushButton->setText("第2组关闭");
            ui->widget->setEnabled(false);
            ZuJianBit |= 1<<(m_dijizu - 1);
        }else{
            ui->pushButton->setText("第2组打开");
            ui->widget->setEnabled(true);
            ZuJianBit &= ~(1<<(m_dijizu - 1));
        }
    }else if(m_dijizu == 3){
        if(ui->pushButton->text() == "第3组打开"){
            ui->pushButton->setText("第3组关闭");
            ui->widget->setEnabled(false);
            ZuJianBit |= 1<<(m_dijizu-1);
        }else{
            ui->pushButton->setText("第3组打开");
            ui->widget->setEnabled(true);
            ZuJianBit &= ~(1<<(m_dijizu - 1));
        }
    }else if(m_dijizu == 4){
        if(ui->pushButton->text() == "第4组打开"){
            ui->pushButton->setText("第4组关闭");
            ui->widget->setEnabled(false);
            ZuJianBit |= 1<<(m_dijizu - 1);
        }else{
            ui->pushButton->setText("第4组打开");
            ui->widget->setEnabled(true);
            ZuJianBit &= ~(1<<(m_dijizu - 1));
        }
    }else if(m_dijizu == 5){
        if(ui->pushButton->text() == "第5组打开"){
            ui->pushButton->setText("第5组关闭");
            ui->widget->setEnabled(false);
            ZuJianBit |= 1<<(m_dijizu - 1);
        }else{
            ui->pushButton->setText("第5组打开");
            ui->widget->setEnabled(true);
            ZuJianBit &= ~(1<<(m_dijizu - 1));
        }
    }else if(m_dijizu == 6){
        if(ui->pushButton->text() == "第6组打开"){
            ui->pushButton->setText("第6组关闭");
            ui->widget->setEnabled(false);
            ZuJianBit |= 1<<(m_dijizu - 1);
        }else{
            ui->pushButton->setText("第6组打开");
            ui->widget->setEnabled(true);
            ZuJianBit &= ~(1<<(m_dijizu - 1));
        }
    }

    DeviceController *pDev = DeviceController::getInstance();
    BaseCommond sendCmd;

    sendCmd.bc_head.type = DIAN_YA_ZU_JIAN;
    sendCmd.yuliu[0] = ZuJianBit;

    QByteArray sendArray(sizeof(BaseCommond),Qt::Uninitialized);
    memcpy(sendArray.data(), &sendCmd, sizeof(BaseCommond));

    pDev->SendMonitorData(sendArray);
}

QMap<quint8, AdcWidget *> ZuJianWidget::getVolMap() const
{
    return m_map;
}
