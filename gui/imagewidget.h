#ifndef IMAGEWIDGET_H
#define IMAGEWIDGET_H

#include <QWidget>
#include <QLabel>
#include <QMap>
#include <QList>

namespace Ui {
class ImageWidget;
}

class ImageWidget : public QWidget
{
    Q_OBJECT

public:
    explicit ImageWidget(QWidget *parent = 0);
    ~ImageWidget();

public slots:
    void SetImageColor(QList<quint8> &list);

protected:
    bool eventFilter(QObject *obj, QEvent *evt);
private:
    Ui::ImageWidget *ui;
    void InitForm();

    QMap<quint32, QLabel *> m_LableMap;
};

#endif // IMAGEWIDGET_H
