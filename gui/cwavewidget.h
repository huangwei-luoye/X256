#ifndef CWAVEWIDGET_H
#define CWAVEWIDGET_H

#include <QWidget>
#include <QChart>
#include <QChartView>
#include <QSplineSeries>
#include "chartview.h"

namespace Ui {
class CWaveWidget;
}

class CWaveWidget : public QWidget
{
    Q_OBJECT

public:
    explicit CWaveWidget(QWidget *parent = 0);
    ~CWaveWidget();

private slots:
    void on_pushButton_open_file_clicked();

private:
    Ui::CWaveWidget *ui;
    void InitForm();

    QSplineSeries *pSeries;
    QChart *m_pChart;
    ChartView *m_pCharView;
};

#endif // CWAVEWIDGET_H
