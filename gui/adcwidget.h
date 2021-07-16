#ifndef ADCWIDGET_H
#define ADCWIDGET_H

#include <QWidget>
#include <QTimer>

namespace Ui {
class AdcWidget;
}

class AdcWidget : public QWidget
{
    Q_OBJECT

public:
    explicit AdcWidget(QWidget *parent = 0);
    ~AdcWidget();

    void setTitle(QString name);
    void setDianYa(qint8 dianya);
    void setDianLiu(qint8 dianliu);
    void setAdcCs(const quint8 &AdcCs);
    void setHiddenButton();
    bool getVol(float &vol);

private slots:
    void on_pushButton_clicked();
    void OnTimerOut();

private:
    Ui::AdcWidget *ui;

    QTimer m_timer;
    quint8 m_AdcCs;/*16片ADC,从0开始*/
};

#endif // ADCWIDGET_H
