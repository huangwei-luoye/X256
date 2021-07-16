#include "netcontroller.h"
#include <QDebug>
#include <QHostAddress>
#include <QDir>
#include <QDateTime>
#include "../public/myhelper.h"

NetController::NetController(QObject *parent) : QObject(parent)
{
    m_pTcpSocket = NULL;
    m_pTcpServerSocket = NULL;
    //StartServer();
#if 0
    if(!QDir("./log/").exists()){
        QDir().mkpath("./log/");
    }
    QString fileName("./log/"+QDateTime::currentDateTime().toString("yyyy_MM_dd.hh_mm_ss") +".dat");
    m_logFile.setFileName(fileName);
    m_logFile.open(QIODevice::WriteOnly | QIODevice::Text);
#endif
}

NetController::~NetController()
{
    if(m_pTcpSocket)
    {
        m_pTcpSocket->close();
        delete m_pTcpSocket;
        m_pTcpSocket = NULL;
    }

#if 1
    if(m_pTcpSocket)
    {
        m_pTcpSocket->disconnect();
        m_pTcpSocket->close();
        delete m_pTcpSocket;
        m_pTcpSocket = NULL;
    }
#endif
    if(m_pTcpServerSocket)
    {
        m_pTcpServerSocket->close();
        delete m_pTcpServerSocket;
        m_pTcpServerSocket = NULL;
    }
}
/**
 * @brief NetController::OnConnectTcpNetwork 连接TCP服务器
 * @param ip
 * @param port
 * @param timeout
 * @return
 */
bool NetController::OnConnectTcpNetwork(const QString &ip, quint16 port)
{
    if(!m_pTcpSocket)
    {
        m_pTcpSocket = new QTcpSocket(this);
    }
    m_pTcpSocket->setSocketOption(QAbstractSocket::KeepAliveOption,1);

    connect(m_pTcpSocket, SIGNAL(readyRead()), this, SLOT(OnProcessTcpReadData()));
    connect(m_pTcpSocket, SIGNAL(connected()), this, SIGNAL(TcpNetConnectedSignal()));
    connect(m_pTcpSocket, SIGNAL(disconnected()), this, SIGNAL(TcpNetDisconnectedSignal()));
    //connect(m_pTcpSocket, SIGNAL(disconnected()), this, SLOT(OnTcpNetDisconnected()));/*能检测到网线断开*/
    //connect(m_pTcpSocket,SIGNAL(stateChanged(QAbstractSocket::SocketState)),this, SLOT(OnNetStatus(QAbstractSocket::SocketState)));

    m_pTcpSocket->connectToHost(ip, port);
    if(!m_pTcpSocket->waitForConnected(1000))
    {
        emit TcpNetControllErrSignal(ErrConnect);
        return false;
    }
    //m_pTcpSocket->setSocketOption(QAbstractSocket::ReceiveBufferSizeSocketOption, 1024*1024*100);
    //emit TcpNetControllErrSignal(ErrNo);
    return true;
}

void NetController::OnDisconnectTcpNetwork()
{
    if(m_pTcpSocket)
    {
        m_pTcpSocket->disconnectFromHost();
        delete m_pTcpSocket;
        m_pTcpSocket = NULL;
    }
}

void NetController::SendTcpNetWorkData(const QByteArray &NetData)
{
    if(!m_pTcpSocket)
        return;

    /*发送tcp数据*/
    int vnSize = m_pTcpSocket->write(NetData);

    if(NetData.length() != vnSize)
    {
        switch (vnSize)
        {
            case QAbstractSocket::UnknownSocketError:
                // "未知错误，请尝试重启程序";
                break;
            case QAbstractSocket::RemoteHostClosedError:
                // "服务端已关闭";
                break;
            case QAbstractSocket::SocketTimeoutError:
                // "UDP报文发送超时！";
                break;
            case QAbstractSocket::AddressInUseError:
                // "端口号：已经被占用，请修改端口号！"
                break;
            case QAbstractSocket::NetworkError:
                // "网络故障，可能网线松了"
                break;
            default:
                break;
        }
    }
}

void NetController::StartServer()
{
    if(!m_pTcpServerSocket)
    {
        m_pTcpServerSocket = new QTcpServer(this);
    }
    connect(m_pTcpServerSocket, SIGNAL(newConnection()), this, SLOT(OnNewClient()));
    m_pTcpServerSocket->listen(QHostAddress::Any, 5001);
}

void NetController::OnNewClient()
{
    m_pTcpSocket = m_pTcpServerSocket->nextPendingConnection();
    m_pTcpSocket->setSocketOption(QAbstractSocket::ReceiveBufferSizeSocketOption,1024*1024*100);
    m_pTcpSocket->setSocketOption(QAbstractSocket::KeepAliveOption,1);
    emit TcpNetConnectedSignal();
    connect(m_pTcpSocket, SIGNAL(readyRead()), this, SLOT(OnProcessTcpReadData()));
    //connect(m_pTcpSocket, SIGNAL(connected()), this, SIGNAL(TcpNetConnectedSignal()));
    connect(m_pTcpSocket, SIGNAL(disconnected()), this, SIGNAL(TcpNetDisconnectedSignal()));
    connect(m_pTcpSocket,SIGNAL(stateChanged(QAbstractSocket::SocketState)),this, SLOT(OnNetStatus(QAbstractSocket::SocketState)));
}

void NetController::OnProcessTcpReadData()
{
    QByteArray netData = m_pTcpSocket->readAll();
    //qDebug()<<myHelper::ByteArrayToHexStr(netData);
    //qDebug()<<netData.size();
    if(!netData.isEmpty())
    {
        emit TcpProcessReciveDataSignal(netData);
#if 0
        QString log = CTools::ByteArrayToString(netData);
        if(!log.isEmpty())
        {
            if(m_logFile.isOpen())
            {
                m_logFile.write(QString(QTime::currentTime().toString("hh:mm:ss.zzz") + " Recv: " + log + "\n").toStdString().c_str());
                m_logFile.flush();
            }
        }
#endif
    }
}

void NetController::OnTcpNetDisconnected()
{
    qDebug()<<"disconnect";
}

void NetController::OnNetStatus(QAbstractSocket::SocketState)
{
    qDebug()<<"wangxian jj";
}
