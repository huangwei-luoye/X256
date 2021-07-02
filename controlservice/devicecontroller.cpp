#include "devicecontroller.h"
#include <QDir>
#include <QDateTime>


DeviceController::DeviceController(QObject *parent) : QObject(parent)
{
    connect(this, SIGNAL(StartFileThreadSignal(QString)), &m_FileOperate, SLOT(OnSaveDateToFile(QString)));
    connect(&m_TcpWaveCtrl, SIGNAL(TcpProcessReciveDataSignal(QByteArray)), this, SLOT(OnRecvSrcFile(QByteArray)));
}

DeviceController::~DeviceController()
{

}

DeviceController *DeviceController::getInstance()
{
    static DeviceController instance;
    return &instance;
}

bool DeviceController::OpenTcpMonitor(const QString &ip, quint16 port)
{
    return m_TcpMonitorCtrl.OnConnectTcpNetwork(ip, port);
}

bool DeviceController::OpenTcpWave(const QString &ip, quint16 port)
{
    return m_TcpWaveCtrl.OnConnectTcpNetwork(ip, port);
}

void DeviceController::SendMonitorData(const QByteArray &tcpdata)
{
    m_TcpMonitorCtrl.SendTcpNetWorkData(tcpdata);
}

void DeviceController::SendWaveData(const QByteArray &tcpdata)
{
    m_TcpWaveCtrl.SendTcpNetWorkData(tcpdata);
}

void DeviceController::SetFileNameAndIntoLoop(const QString name)
{
    emit StartFileThreadSignal(name);
}

void DeviceController::OnRecvSrcFile(const QByteArray &data)
{
    m_FileOperate.MainThreadAppendArrayData(data);
}
