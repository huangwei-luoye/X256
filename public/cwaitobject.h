#ifndef CWAITOBJECT_H
#define CWAITOBJECT_H

#include <QObject>
#include <QEventLoop>
#include <QTimer>

class CWaitObject : public QObject
{
    Q_OBJECT
public:
    explicit CWaitObject(QObject *parent = 0);
    virtual ~CWaitObject();

    void setInterval(quint32 ms);
    bool wait();
    void wake();

signals:

public slots:
    void slotTimeout();
private:
    QTimer m_delayr;
    QEventLoop m_loop;

    quint32 m_nInterval;
    bool m_isRunning;
};

#endif // CWAITOBJECT_H
