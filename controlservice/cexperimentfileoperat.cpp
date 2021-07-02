#include "cexperimentfileoperat.h"
#include <QDebug>
//#include <./public/CTools.h>
#include <QTime>

#define SIZE_1G (64*1024*1024)

CExperimentFileOperat::CExperimentFileOperat(QObject *parent) : QObject(parent)
{
    this->moveToThread(&m_workThread);
    m_workThread.start();
    m_workThread.setPriority(QThread::HighestPriority);
}

CExperimentFileOperat::~CExperimentFileOperat()
{
    QMap<quint32, QFile *> ::iterator it;
    for(it=m_FileMap.begin(); it!=m_FileMap.end(); ++it)
    {
        QFile * pFile = it.value();
        if(pFile && pFile->isOpen())
        {
            pFile->close();
            delete pFile;
            pFile = NULL;
        }
    }
    m_fileDataList.clear();
    m_FileMap.clear();
    m_FileNameMap.clear();
    m_workThread.quit();
    m_workThread.wait();
}

void CExperimentFileOperat::SetFileName(const QMap<quint32, QString> &fileName)
{

    m_FileNameMap = fileName;
}

void CExperimentFileOperat::SetFileName(quint32 id, const QString &fileName)
{
    //qDebug()<<"slave:"<<QThread::currentThreadId();
    m_FileNameMap.insert(id, fileName);
}

void CExperimentFileOperat::MainThreadAppendArrayData(const QByteArray &data)
{
    //QMutexLocker locker(&mutex);
    //qDebug()<<"112233...";
    mutex.lock();
    m_fileDataList.append(data);
    //qDebug()<<m_fileDataList.size();
    if(m_fileDataList.size() > 500)
    {
        //qDebug()<<m_fileDataList.size();
    }
    mutex.unlock();
}

void CExperimentFileOperat::OnOperatResultData(quint32 id, const QByteArray &data, bool isEnd)
{

     if(m_FileMap.contains(id))
     {
         QFile *pFile = m_FileMap.value(id);

         if(pFile && pFile->isOpen())
         {
             pFile->write(data);
             pFile->flush();
         }
         if(isEnd)
         {
             if(pFile && pFile->isOpen())
             {
                 pFile->close();
                 delete pFile;
                 pFile = NULL;
                 m_FileMap.remove(id);
                 m_FileNameMap.remove(id);
             }
         }
     }
     else
     {
         QFile *pFile = new QFile;

         pFile->setFileName(m_FileNameMap.value(id));
         if(pFile->open(QIODevice::WriteOnly))
         {
             pFile->write(data);
             pFile->flush();
             m_FileMap.insert(id, pFile);
         }
         if(isEnd)
         {
             if(pFile && pFile->isOpen())
             {
                 pFile->close();
                 delete pFile;
                 pFile = NULL;
                 m_FileMap.remove(id);
                 m_FileNameMap.remove(id);
             }
         }
     }


}
/**
 * @brief CExperimentFileOperat::OnSaveDataToFile 保存文件线程
 * @param id    文件ID
 * @param size  文件大小
 * @param netSlect  千兆网速度匹配选项
 */
void CExperimentFileOperat::OnSaveDataToFile(quint32 id, quint64 size, quint64 netSlect)
{
    QFile *pFile = new QFile;
    quint64 writeSize = 0;
    bool isOkFinish;
    quint32 flag = 0;
    QTime start,end;

    pFile->setFileName(m_FileNameMap.value(id));

    if(pFile->open(QIODevice::WriteOnly))
    {
        do{
            mutex.lock();
            if(!m_fileDataList.isEmpty()){
                QByteArray data = m_fileDataList.takeFirst();
                writeSize += data.size();
                mutex.unlock();
                flag = 0;
                pFile->write(data);    
            }else{
                mutex.unlock();
                if(!flag){
                    flag = 1;
                    start = QTime::currentTime();
                }else{
                    end = QTime::currentTime();
                    if(start.msecsTo(end) > 18000){
                        isOkFinish = false;
                        emit Save1GSizeFinishSignal(isOkFinish);
                        break;
                    }
                }
            }
        }while(writeSize != size);
        pFile->flush();
        pFile->close();
        emit Save1GSizeFinishSignal(true);
    }
}

void CExperimentFileOperat::OnSaveDateToFile(const QString FileName)
{
    QTime start,end;
    quint32 flag = 0;
    QFile *pFile = new QFile;

    pFile->setFileName(FileName);

    if(pFile->open(QIODevice::WriteOnly)){
        while(1){
            mutex.lock();
            if(!m_fileDataList.isEmpty()){
                QByteArray data = m_fileDataList.takeFirst();
                mutex.unlock();
                flag = 0;
                pFile->write(data);
            }else{
                mutex.unlock();
                if(!flag){
                    flag = 1;
                    start = QTime::currentTime();
                }else{
                    end = QTime::currentTime();
                    if(start.msecsTo(end) > 3000)/*无数据超时退出*/
                        break;
                }
            }
        }
        //emit
        pFile->flush();
        pFile->close();
        delete pFile;
    }
}


















