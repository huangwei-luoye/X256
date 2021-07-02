#ifndef NETCONTROLLER_H
#define NETCONTROLLER_H

#include <QObject>
#include <QTcpSocket>
#include <QTcpServer>
#include <QFile>

enum NetCtrlErr
{
  ErrNo,
  ErrConnect,
  ErrDisConnect,
  ErrWrite,
};

class NetController : public QObject
{
    Q_OBJECT
public:
    explicit NetController(QObject *parent = 0);
    virtual ~NetController();

    Q_SLOT bool OnConnectTcpNetwork(const QString &ip, quint16 port);
    Q_SLOT void OnDisconnectTcpNetwork();
    void SendTcpNetWorkData(const QByteArray& NetData);

private:
    QFile m_logFile;
    QTcpSocket *m_pTcpSocket;
    QTcpServer *m_pTcpServerSocket;

    void StartServer();

    Q_SLOT void OnNewClient();
    Q_SLOT void OnProcessTcpReadData();
    Q_SLOT void OnTcpNetDisconnected();
    Q_SLOT void OnNetStatus(QAbstractSocket::SocketState);

    Q_SIGNAL void TcpNetControllErrSignal(NetCtrlErr err);
    Q_SIGNAL void TcpNetConnectedSignal();
    Q_SIGNAL void TcpNetDisconnectedSignal();
    Q_SIGNAL void TcpProcessReciveDataSignal(const QByteArray& Data);


};

#endif // NETCONTROLLER_H
