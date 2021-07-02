#include "cqssfile.h"

CQssFile::CQssFile()
{

}

CQssFile *CQssFile::getInstance()
{
    static CQssFile instance;

    return &instance;
}

QString CQssFile::getMainWindow()
{
    return QString("./qss/style_mainWindow.qss");
}

QString CQssFile::getFileListWidget()
{
    return QString("./qss/style_fileListWidget.qss");
}
