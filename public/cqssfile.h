#ifndef CQSSFILE_H
#define CQSSFILE_H
#include <QString>

class CQssFile
{
public:
    CQssFile();

    static CQssFile *getInstance();

    QString getMainWindow();
    QString getFileListWidget();

};

#endif // CQSSFILE_H
