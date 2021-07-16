#include "statusinfomation.h"

StatusInfomation::StatusInfomation(QObject *parent) : QObject(parent)
{
    m_dyStatus = 0;
}

StatusInfomation *StatusInfomation::getInstance()
{
    static StatusInfomation instance;

    return &instance;
}

QString StatusInfomation::getWorkStatus() const
{
    return m_workStatus;
}

void StatusInfomation::setWorkStatus(const QString &workStatus)
{
    m_workStatus = workStatus;
}

QString StatusInfomation::getLiuChengStatus() const
{
    return m_liuChengStatus;
}

void StatusInfomation::setLiuChengStatus(const QString &liuChengStatus)
{
    m_liuChengStatus = liuChengStatus;
}

QString StatusInfomation::getCaiJiFpgaTemp() const
{
    return m_caiJiFpgaTemp;
}

void StatusInfomation::setCaiJiFpgaTemp(const QString &caiJiFpgaTemp)
{
    m_caiJiFpgaTemp = caiJiFpgaTemp;
}

QString StatusInfomation::getDianYaFpgaTemp() const
{
    return m_dianYaFpgaTemp;
}

void StatusInfomation::setDianYaFpgaTemp(const QString &dianYaFpgaTemp)
{
    m_dianYaFpgaTemp = dianYaFpgaTemp;
}

quint32 StatusInfomation::getDyStatus() const
{
    return m_dyStatus;
}

void StatusInfomation::setDyStatus(const quint32 &dyStatus)
{
    m_dyStatus = dyStatus;
}

QMap<quint8, QPair<quint16, quint16> > StatusInfomation::getDydlMap() const
{
    return m_dydlMap;
}
