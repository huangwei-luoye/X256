#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QTimer>
#include "./public/cwaitobject.h"
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
    void on_pushButton_status_chaxun_clicked();
    void OnChaXunAck(const QByteArray &data);
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


private:
    Ui::MainWindow *ui;
    QTimer m_timer;
    CWaitObject m_waitObject;

    void InitUI();
    void InitToolsButton();
    void InitNet();
};

#endif // MAINWINDOW_H
