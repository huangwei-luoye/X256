#ifndef CEXPERIMENTFILEOPERAT_H
#define CEXPERIMENTFILEOPERAT_H

#include <QObject>
#include <QThread>
#include <QMap>
#include <QFile>
#include <QMutex>
#include <QMutexLocker>

class CExperimentFileOperat : public QObject
{
    Q_OBJECT
public:
    explicit CExperimentFileOperat(QObject *parent = 0);
    virtual ~CExperimentFileOperat();

    void SetFileName(const QMap<quint32,QString> &fileName);
    void SetFileName(quint32 id, const QString& fileName);
    void MainThreadAppendArrayData(const QByteArray &data);

signals:
    void RecvAdcDataFinishSignal();
public slots:

private:
    QThread m_workThread;
    QMap<quint32, QString> m_FileNameMap;
    QMap<quint32, QFile*> m_FileMap;
    QMutex mutex;
    QFile *pFile;

    QList<QByteArray> m_fileDataList;
    Q_SIGNAL void Save1GSizeFinishSignal(bool isOkFinish);

    Q_SLOT void OnOperatResultData(quint32 id, const QByteArray& data, bool isEnd);
    Q_SLOT void OnSaveDataToFile(quint32 id, quint64 size, quint64 netSlect);
    Q_SLOT void OnSaveDateToFile(const QString FileName);


};

#endif // CEXPERIMENTFILEOPERAT_H
