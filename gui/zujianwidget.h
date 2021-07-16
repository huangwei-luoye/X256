#ifndef ZUJIANWIDGET_H
#define ZUJIANWIDGET_H

#include <QWidget>
#include <QList>
#include <QMap>
#include "adcwidget.h"

namespace Ui {
class ZuJianWidget;
}

class ZuJianWidget : public QWidget
{
    Q_OBJECT

public:
    explicit ZuJianWidget(QWidget *parent, quint8 base, quint8 zu);
    ~ZuJianWidget();

    void setPushButtonText(const QString text);
    void InitList();

    QMap<quint8, AdcWidget *> getVolMap() const;

private slots:
    void on_pushButton_clicked();

private:
    Ui::ZuJianWidget *ui;
    QMap<quint8, AdcWidget *> m_map;
    quint8 m_baseChannel;
    quint8 m_dijizu;

    void InitUI();

};

#endif // ZUJIANWIDGET_H
