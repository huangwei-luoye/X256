#ifndef DEVICECONTROLLER_H
#define DEVICECONTROLLER_H

#include <QObject>
#include "./network/netcontroller.h"
#include <QFile>
#include "./cexperimentfileoperat.h"

class DeviceController : public QObject
{
    Q_OBJECT
public:
    explicit DeviceController(QObject *parent = 0);
    ~DeviceController();

    static DeviceController *getInstance();

    bool OpenTcpMonitor(const QString &ip, quint16 port);
    bool OpenTcpWave(const QString &ip, quint16 port);

    void SendMonitorData(const QByteArray &tcpdata);
    void SendWaveData(const QByteArray &tcpdata);

    void SetFileNameAndIntoLoop(const QString name);

signals:

public slots:

private:
    NetController m_TcpMonitorCtrl;
    NetController m_TcpWaveCtrl;

    CExperimentFileOperat m_FileOperate;

    Q_SIGNAL void ProcessMonitorDataSignal(const QByteArray& data);
    Q_SIGNAL void ProcessWaveDataSignal(const QByteArray& data);
    Q_SIGNAL void TcpNetDisconnectedSignal();
    Q_SIGNAL void StartFileThreadSignal(const QString name);

    Q_SLOT void OnRecvSrcFile(const QByteArray &data);

};

#endif // DEVICECONTROLLER_H
