#ifndef SYSTEMMINITORSERVICE_H
#define SYSTEMMINITORSERVICE_H

#include <QObject>
#include <QTimer>
#include "../public/cwaitobject.h"

class SystemMinitorService : public QObject
{
    Q_OBJECT
public:
    explicit SystemMinitorService(QObject *parent = 0);
    static SystemMinitorService *getInstance();
    void StartSystemMinitor();
    void StopSystemMinitor();
signals:
    void UpdateStatusSignal();

public slots:
    void OnTimeOut();
    void OnChaXunAck(const QByteArray &data);

private:
    QTimer m_timer;

    CWaitObject m_waitObject;
};

#endif // SYSTEMMINITORSERVICE_H
