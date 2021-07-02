#include "iconhelper.h"

IconHelper *IconHelper:: instance = NULL;

IconHelper::IconHelper(QObject *parent) : QObject(parent)
{
    int id = QFontDatabase::addApplicationFont(":/image/fontawesome-webfont.ttf");
    QString fontName = QFontDatabase::applicationFontFamilies(id).at(0);
    iconFont = QFont(fontName);
}

IconHelper *IconHelper::getInstance()
{
    static QMutex mutex;
    if(!instance){
        QMutexLocker locker(&mutex);
        instance = new IconHelper;
    }
    return instance;
}
void IconHelper::SetIcon(QLabel* lab, QChar c, int size)
{
    iconFont.setPointSize(size);
    lab->setFont(iconFont);
    lab->setText(c);
}

void IconHelper::SetIcon(QPushButton* btn, QChar c, int size)
{
    iconFont.setPointSize(size);
    btn->setFont(iconFont);
    btn->setText(c);
}


