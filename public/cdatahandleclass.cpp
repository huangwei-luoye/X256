#include "cdatahandleclass.h"
#include "myhelper.h"
#include <QDebug>
#include "../LogOpreate/LogOperate.h"
#include <QFile>
#include "./controlservice/systemminitorservice.h"

#define  CSV_PATH "./csv/src.csv"


CDataHandleClass::CDataHandleClass(QObject *parent) : QObject(parent)
{

}

CDataHandleClass *CDataHandleClass::getInstance()
{
    static CDataHandleClass instance;
    return &instance;
}

void CDataHandleClass::OnRecvWaveData(const QByteArray &data)
{
    m_data += data;
}

void CDataHandleClass::HandleWaveData()
{
#if 0
    LogOperate::getinstance()->LogOperaterUi("原文件上传完成",LOG_INFO);
    qDebug()<<m_data.size();
#else
    quint32 i,j,k,m;
    QByteArray channel[256];
    QByteArray temp_data;
    quint32 OneAd16;/*1片ad16通道数据长度*/
    QFile csv(CSV_PATH);

    OneAd16 = 32 * m_CurrentCaiYangDian;

    i = m_data.size() / OneAd16;
    for(j = 0; j < i; j++){
        temp_data = QByteArray(m_data.data() + OneAd16*j, OneAd16);
        for(k = 0; k < m_CurrentCaiYangDian; k++){
            for(m = 0; m < 16; m++){
                channel[m + 16*j] += QByteArray(temp_data.data() + 2*m + 32*k, 2);
            }
        }
    }
    if(csv.open(QIODevice::Text | QIODevice::WriteOnly | QIODevice::Truncate)){
        for(i = 0; i < 256; i++){
            QList<QPointF> list = myHelper::PianYiMaToYuanMa(channel[i]);
            foreach (QPointF var, list) {
                csv.write(QString("%1,").arg(var.y()).toStdString().c_str());
            }
            csv.write("\n");
            m_WaveMap.insert(i,list);
        }
    }
    csv.close();
    m_data.clear();
    LogOperate::getinstance()->LogOperaterUi("源数据上传成功", LOG_INFO);
    emit RefreshWaveSignal();
    SystemMinitorService::getInstance()->StartSystemMinitor();
#endif
}

QMap<quint8, QList<QPointF> > CDataHandleClass::getWaveMap() const
{
    return m_WaveMap;
}

void CDataHandleClass::setWaveMap(const QMap<quint8, QList<QPointF> > &WaveMap)
{
    m_WaveMap = WaveMap;
}
