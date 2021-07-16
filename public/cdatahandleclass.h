#ifndef CDATAHANDLECLASS_H
#define CDATAHANDLECLASS_H

#include <QObject>
#include <QMap>
#include <QPointF>
#include <QList>
#include <QByteArray>

class CDataHandleClass : public QObject
{
    Q_OBJECT
public:
    explicit CDataHandleClass(QObject *parent = 0);
    static CDataHandleClass *getInstance();
    QMap<quint8, QList<QPointF> > getWaveMap() const;
    void setWaveMap(const QMap<quint8, QList<QPointF> > &WaveMap);

    quint32 m_CurrentCaiYangDian;

signals:
    void RefreshWaveSignal();
public slots:

    void OnRecvWaveData(const QByteArray &data);
    void HandleWaveData();

private:
    QMap<quint8, QList<QPointF>> m_WaveMap;
    QByteArray m_data;

};

#endif // CDATAHANDLECLASS_H
