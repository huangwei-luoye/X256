#ifndef STATUSINFOMATION_H
#define STATUSINFOMATION_H

#include <QObject>
#include <QMap>
#include <QPair>

class StatusInfomation : public QObject
{
    Q_OBJECT
public:
    explicit StatusInfomation(QObject *parent = 0);    
    static StatusInfomation *getInstance();

    QString getWorkStatus() const;
    void setWorkStatus(const QString &workStatus);

    QString getLiuChengStatus() const;
    void setLiuChengStatus(const QString &liuChengStatus);

    QString getCaiJiFpgaTemp() const;
    void setCaiJiFpgaTemp(const QString &caiJiFpgaTemp);

    QString getDianYaFpgaTemp() const;
    void setDianYaFpgaTemp(const QString &dianYaFpgaTemp);

    quint32 getDyStatus() const;
    void setDyStatus(const quint32 &dyStatus);

    QMap<quint8, QPair<quint16, quint16> > getDydlMap() const;

signals:

public slots:

private:
    QString m_workStatus;
    QString m_liuChengStatus;
    QString m_caiJiFpgaTemp;
    QString m_dianYaFpgaTemp;
    QMap<quint8, QPair<quint16,quint16>> m_dydlMap;

    quint32 m_dyStatus;/*电压开关状态指示位*/

};

#endif // STATUSINFOMATION_H
