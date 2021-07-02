#include "imagewidget.h"
#include "ui_imagewidget.h"
#include <QGridLayout>
#include <QPalette>
#include <QDebug>

ImageWidget::ImageWidget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::ImageWidget)
{
    ui->setupUi(this);
    InitForm();
}

ImageWidget::~ImageWidget()
{
    delete ui;
}

void ImageWidget::SetImageColor(QList<quint8> &list)
{
    QLabel *pLabel = NULL;
    QMap<quint32, QLabel *>::const_iterator i;
    QPalette palette;
    quint8 rgb;

    for(i = m_LableMap.begin(); i != m_LableMap.end(); i++){
        pLabel = i.value();
        rgb = list.at(i.key());
        palette.setColor(QPalette::Background, QColor(rgb, rgb, rgb));
        pLabel->setPalette(palette);
    }
}


void ImageWidget::InitForm()
{
    quint32 i,j;
    quint32 k = 0;
    QLabel *pLable = NULL;
    QGridLayout *pLayout = new QGridLayout(ui->widget);

    for(i = 0; i < 16; i++){
        for(j = 0; j < 16; j++){
            pLable = new QLabel;
            pLable->setAutoFillBackground(true);
            pLable->setFocusPolicy(Qt::TabFocus);
            pLayout->addWidget(pLable, i, j);
            pLayout->setSpacing(0);
            m_LableMap.insert(k++, pLable);
        }
    }
    ui->widget->setLayout(pLayout);
}
