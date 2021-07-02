#ifndef ICONHELPER_H
#define ICONHELPER_H

#include <QObject>
#include <QMutex>
#include <QFontDatabase>
#include <QFont>
#include <QApplication>
#include <QPushButton>
#include <QLabel>

class IconHelper : public QObject
{
    Q_OBJECT
public:
    explicit IconHelper(QObject *parent = 0);

    static IconHelper *getInstance();
    void SetIcon(QPushButton *btn, QChar c, int size = 10);
    void SetIcon(QLabel *lab, QChar c, int size = 10);

signals:

public slots:

private:
    static IconHelper *instance;
    QFont iconFont;
};

#endif // ICONHELPER_H
