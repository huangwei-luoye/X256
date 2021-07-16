#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QTimer>
#include "./public/cwaitobject.h"
#include "./gui/zujianwidget.h"
#include "./gui/adcwidget.h"
#include <QList>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();
signals:
    void SetImageSignal(QList<quint8> &list);

public slots:
    void TimeOutSlot();

private slots:
    //void on_pushButton_status_chaxun_clicked();
    void OnCanShuSetAck(const QByteArray &data);
    void OnStartCollectAck(const QByteArray &data);

    void on_pushButton_canshu_set_clicked();

    void on_pushButton_start_collect_clicked();

    void OnStartTransAck(const QByteArray &data);
    void on_pushButton_start_trans_clicked();

    void OnDianYaCtrlAck(const QByteArray &data);
    void on_pushButton_dianya_ctrl_clicked();

    void OnDianYaZuJianAck(const QByteArray &data);
    void on_pushButton_dianya_zujian_clicked();

    void on_pushButton_src_shangchuan_clicked();

    void on_pushButton_close_clicked();

    void on_pushButton_min_clicked();

    void on_pushButton_max_clicked();

    void OnToolClicked();

    void on_pushButton_dianya_set_clicked();

    void OnUpdateStatus();

private:
    Ui::MainWindow *ui;
    QTimer m_timer;/*定时连网*/
    CWaitObject m_waitObject;
    QMap<quint8, ZuJianWidget* > m_ZuJianVolMap;
    QMap<quint8, AdcWidget * > m_adcWidgetMap;

    void InitUI();
    void InitToolsButton();
    void InitNet();
    void InitZuJian();
};

#endif // MAINWINDOW_H
