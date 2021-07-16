#include "cwaitobject.h"

CWaitObject::CWaitObject(QObject *parent) : QObject(parent)
{
       m_nInterval = 10000;
       m_isRunning = false;
       connect(&m_delayr, SIGNAL(timeout()), this, SLOT(slotTimeout()));
       m_delayr.setSingleShot(true);
}

CWaitObject::~CWaitObject()
{
    if(m_loop.isRunning())
    {
        m_loop.exit(false);
    }
}

void CWaitObject::setInterval(quint32 ms)
{
    m_nInterval = ms;
}

bool CWaitObject::wait()
{
    if(!m_isRunning)
    {
        m_delayr.setInterval(m_nInterval);
        m_delayr.start();
        return m_loop.exec();
    }
    return true;
}

void CWaitObject::wake()
{
    m_delayr.stop();
    m_loop.exit(true);
}

void CWaitObject::slotTimeout()
{
    m_loop.exit(false);
}
