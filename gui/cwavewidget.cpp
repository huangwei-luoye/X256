#include "cwavewidget.h"
#include "ui_cwavewidget.h"
#include <QXYSeries>
#include <QValueAxis>
#include "../public/myhelper.h"
#include <QDebug>
#include <QPointF>
#include <QList>
#include <QStringList>
#include "public/cdatahandleclass.h"
#include "QHBoxLayout"

CWaveWidget::CWaveWidget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::CWaveWidget)
{
    ui->setupUi(this);
    connect(CDataHandleClass::getInstance(), SIGNAL(RefreshWaveSignal()), this, SLOT(OnRefreshWave()));
    InitForm();
}

CWaveWidget::~CWaveWidget()
{
    delete ui;
}

void CWaveWidget::InitForm()
{

    m_pChart = new QChart();
    //m_pChart->setTitle("采集波形");
    m_pChart->legend()->hide();
    //m_pChart->legend()->setAlignment(Qt::AlignRight);
    m_pChart->setTheme(QChart::ChartThemeBlueCerulean);

    QValueAxis *asisX = new QValueAxis();
    QValueAxis *asisY = new QValueAxis();
    //asisX->setGridLineVisible(false);
    //asisY->setGridLineVisible(false);
    asisX->setRange(0, 1000);
    asisY->setRange(-9000,9000);
    asisX->setTickCount(10+1);
    asisY->setTickCount(5+1);
    asisX->setTitleText("时间（微秒）");
    asisY->setTitleText("电压");
    asisX->setLabelFormat("%.2f");
    asisY->setLabelFormat("%.1f");

    pSeries = new QSplineSeries(m_pChart);
    pSeries->append(20,4);
    pSeries->append(500,2);
    pSeries->append(900,1);
    //pSeries->setPen(QPen(Qt::blue));

    m_pChart->addSeries(pSeries);
    m_pChart->setAxisX(asisX,pSeries);
    m_pChart->setAxisY(asisY,pSeries);

    m_pCharView = new ChartView(m_pChart);
    m_pCharView->setRenderHint(QPainter::Antialiasing);
    m_pCharView->SetZoomIsvalid(true);

    //ui->horizontalLayout->addWidget(m_pCharView);
    QHBoxLayout *layout = new QHBoxLayout(ui->widget);
    layout->addWidget(m_pCharView);
    layout->setMargin(0);
    ui->widget->setLayout(layout);

    //ui->pushButton_open_file->hide();
#if 1
    QStringList list;
    for(quint32 i = 1; i <= 256; i++){
        list << QString("%1").arg(i);
    }
    ui->comboBox->addItems(list);
#endif
}

#if 0
void CWaveWidget::on_pushButton_open_file_clicked()
{
    QString str = myHelper::GetFileName(QString("*.bin"));
    //qDebug()<<str;
    QFile WaveFile(str);
    QByteArray WaveDataArray;
    QList<QPointF> WavePoint,ShowWavePoint;
    QList<QPointF>::const_iterator i;

    if(WaveFile.open(QIODevice::ReadOnly)){
         WaveDataArray = WaveFile.readAll();
         WavePoint = myHelper::BumaTosrcma(WaveDataArray, 0, 5000);
         pSeries->replace(WavePoint);
         WaveFile.close();
    }
}

#endif

void CWaveWidget::on_comboBox_currentIndexChanged(int index)
{
    QMap<quint8, QList<QPointF> > map = CDataHandleClass::getInstance()->getWaveMap();

    if(map.contains(index)){
        pSeries->replace(map.find(index).value());
    }
}

void CWaveWidget::OnRefreshWave()
{
    QMap<quint8, QList<QPointF> > map = CDataHandleClass::getInstance()->getWaveMap();

    if(map.contains(0)){
        ui->comboBox->setCurrentIndex(0);
        pSeries->replace(map.find(0).value());
    }
}

