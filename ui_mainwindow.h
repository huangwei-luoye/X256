/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.8.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QScrollArea>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QStackedWidget>
#include <QtWidgets/QToolButton>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralWidget;
    QVBoxLayout *verticalLayout_4;
    QWidget *widget_title;
    QHBoxLayout *horizontalLayout;
    QLabel *label_icon;
    QLabel *label_title;
    QSpacerItem *horizontalSpacer;
    QPushButton *pushButton_min;
    QPushButton *pushButton_max;
    QPushButton *pushButton_close;
    QWidget *widget_huangwei;
    QVBoxLayout *verticalLayout_3;
    QWidget *widget_main;
    QVBoxLayout *verticalLayout_2;
    QHBoxLayout *horizontalLayout_2;
    QWidget *widgetLeft;
    QVBoxLayout *verticalLayout;
    QToolButton *toolButton_set;
    QToolButton *toolButton_chaxun;
    QToolButton *toolButton_caijiboxing;
    QToolButton *toolButton_tuxinagchengxiang;
    QSpacerItem *verticalSpacer;
    QStackedWidget *stackedWidget;
    QWidget *page_1;
    QGroupBox *groupBox_adc;
    QVBoxLayout *verticalLayout_5;
    QGridLayout *gridLayout_4;
    QLineEdit *lineEdit_adc1;
    QLabel *label;
    QLabel *label_28;
    QLineEdit *lineEdit_adc9;
    QLabel *label_2;
    QLabel *label_33;
    QLineEdit *lineEdit_adc2;
    QLineEdit *lineEdit_adc10;
    QLabel *label_30;
    QLineEdit *lineEdit_11;
    QLabel *label_13;
    QLineEdit *lineEdit_adc3;
    QLabel *label_11;
    QLineEdit *lineEdit_adc12;
    QLabel *label_20;
    QLineEdit *lineEdit_adc4;
    QLineEdit *lineEdit_adc5;
    QLabel *label_25;
    QLabel *label_35;
    QLineEdit *lineEdit_adc6;
    QLineEdit *lineEdit_adc13;
    QLabel *label_31;
    QLineEdit *lineEdit_adc7;
    QLabel *label_26;
    QLineEdit *lineEdit_adc14;
    QLineEdit *lineEdit_adc15;
    QLabel *label_27;
    QLineEdit *lineEdit_adc8;
    QLabel *label_29;
    QLabel *label_34;
    QLabel *label_32;
    QLineEdit *lineEdit_adc16;
    QLabel *label_3;
    QLineEdit *lineEdit_caijidian;
    QHBoxLayout *horizontalLayout_7;
    QSpacerItem *horizontalSpacer_7;
    QPushButton *pushButton_canshu_set;
    QSpacerItem *horizontalSpacer_6;
    QLabel *label_fpga_wendu;
    QWidget *layoutWidget;
    QHBoxLayout *horizontalLayout_4;
    QSpacerItem *horizontalSpacer_4;
    QLabel *label_10;
    QLabel *label_work_status;
    QSpacerItem *horizontalSpacer_2;
    QLabel *label_12;
    QLabel *label_liuchang_status;
    QSpacerItem *horizontalSpacer_3;
    QLabel *label_16;
    QLabel *label_caiji_wendu;
    QSpacerItem *horizontalSpacer_5;
    QWidget *page_2;
    QHBoxLayout *horizontalLayout_6;
    QVBoxLayout *verticalLayout_8;
    QScrollArea *scrollArea;
    QWidget *scrollAreaWidgetContents;
    QScrollArea *scrollArea_2;
    QWidget *scrollAreaWidgetContents_2;
    QVBoxLayout *verticalLayout_7;
    QHBoxLayout *horizontalLayout_5;
    QLabel *label_icon_temp;
    QLabel *label_dy;
    QLabel *label_dy_temp;
    QSpacerItem *verticalSpacer_2;
    QPushButton *pushButton_dianya_set;
    QWidget *page_3;
    QHBoxLayout *horizontalLayout_3;
    QWidget *widget_wave;
    QVBoxLayout *verticalLayout_6;
    QPushButton *pushButton_start_collect;
    QPushButton *pushButton_start_trans;
    QPushButton *pushButton_src_shangchuan;
    QWidget *page_4;
    QGridLayout *gridLayout_3;
    QWidget *widget_image;
    QWidget *widget_log;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QStringLiteral("MainWindow"));
        MainWindow->resize(1076, 760);
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        verticalLayout_4 = new QVBoxLayout(centralWidget);
        verticalLayout_4->setSpacing(0);
        verticalLayout_4->setContentsMargins(11, 11, 11, 11);
        verticalLayout_4->setObjectName(QStringLiteral("verticalLayout_4"));
        verticalLayout_4->setContentsMargins(0, 0, 0, 0);
        widget_title = new QWidget(centralWidget);
        widget_title->setObjectName(QStringLiteral("widget_title"));
        QSizePolicy sizePolicy(QSizePolicy::Preferred, QSizePolicy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(widget_title->sizePolicy().hasHeightForWidth());
        widget_title->setSizePolicy(sizePolicy);
        horizontalLayout = new QHBoxLayout(widget_title);
        horizontalLayout->setSpacing(0);
        horizontalLayout->setContentsMargins(11, 11, 11, 11);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        horizontalLayout->setContentsMargins(0, 0, 0, 0);
        label_icon = new QLabel(widget_title);
        label_icon->setObjectName(QStringLiteral("label_icon"));
        QSizePolicy sizePolicy1(QSizePolicy::Minimum, QSizePolicy::Expanding);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(label_icon->sizePolicy().hasHeightForWidth());
        label_icon->setSizePolicy(sizePolicy1);
        label_icon->setMinimumSize(QSize(0, 0));
        label_icon->setAlignment(Qt::AlignCenter);

        horizontalLayout->addWidget(label_icon);

        label_title = new QLabel(widget_title);
        label_title->setObjectName(QStringLiteral("label_title"));
        label_title->setAutoFillBackground(false);
        label_title->setStyleSheet(QString::fromUtf8("font: 12pt \"\345\276\256\350\275\257\351\233\205\351\273\221\";"));

        horizontalLayout->addWidget(label_title);

        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer);

        pushButton_min = new QPushButton(widget_title);
        pushButton_min->setObjectName(QStringLiteral("pushButton_min"));
        QSizePolicy sizePolicy2(QSizePolicy::Minimum, QSizePolicy::Fixed);
        sizePolicy2.setHorizontalStretch(0);
        sizePolicy2.setVerticalStretch(0);
        sizePolicy2.setHeightForWidth(pushButton_min->sizePolicy().hasHeightForWidth());
        pushButton_min->setSizePolicy(sizePolicy2);
        pushButton_min->setMinimumSize(QSize(31, 0));
        pushButton_min->setFocusPolicy(Qt::NoFocus);

        horizontalLayout->addWidget(pushButton_min);

        pushButton_max = new QPushButton(widget_title);
        pushButton_max->setObjectName(QStringLiteral("pushButton_max"));
        pushButton_max->setMinimumSize(QSize(31, 0));
        pushButton_max->setFocusPolicy(Qt::NoFocus);

        horizontalLayout->addWidget(pushButton_max);

        pushButton_close = new QPushButton(widget_title);
        pushButton_close->setObjectName(QStringLiteral("pushButton_close"));
        pushButton_close->setMinimumSize(QSize(31, 0));
        pushButton_close->setFocusPolicy(Qt::NoFocus);

        horizontalLayout->addWidget(pushButton_close);


        verticalLayout_4->addWidget(widget_title);

        widget_huangwei = new QWidget(centralWidget);
        widget_huangwei->setObjectName(QStringLiteral("widget_huangwei"));
        widget_huangwei->setStyleSheet(QStringLiteral(""));
        verticalLayout_3 = new QVBoxLayout(widget_huangwei);
        verticalLayout_3->setSpacing(0);
        verticalLayout_3->setContentsMargins(11, 11, 11, 11);
        verticalLayout_3->setObjectName(QStringLiteral("verticalLayout_3"));
        verticalLayout_3->setContentsMargins(0, 0, 0, 0);
        widget_main = new QWidget(widget_huangwei);
        widget_main->setObjectName(QStringLiteral("widget_main"));
        widget_main->setMinimumSize(QSize(0, 20));
        widget_main->setStyleSheet(QStringLiteral(""));
        verticalLayout_2 = new QVBoxLayout(widget_main);
        verticalLayout_2->setSpacing(0);
        verticalLayout_2->setContentsMargins(11, 11, 11, 11);
        verticalLayout_2->setObjectName(QStringLiteral("verticalLayout_2"));
        verticalLayout_2->setContentsMargins(0, 0, 0, 0);
        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setSpacing(0);
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
        widgetLeft = new QWidget(widget_main);
        widgetLeft->setObjectName(QStringLiteral("widgetLeft"));
        widgetLeft->setStyleSheet(QStringLiteral(""));
        verticalLayout = new QVBoxLayout(widgetLeft);
        verticalLayout->setSpacing(0);
        verticalLayout->setContentsMargins(11, 11, 11, 11);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        toolButton_set = new QToolButton(widgetLeft);
        toolButton_set->setObjectName(QStringLiteral("toolButton_set"));
        QIcon icon;
        icon.addFile(QStringLiteral(":/image/infoextend.png"), QSize(), QIcon::Normal, QIcon::Off);
        toolButton_set->setIcon(icon);
        toolButton_set->setIconSize(QSize(50, 50));
        toolButton_set->setToolButtonStyle(Qt::ToolButtonTextUnderIcon);

        verticalLayout->addWidget(toolButton_set);

        toolButton_chaxun = new QToolButton(widgetLeft);
        toolButton_chaxun->setObjectName(QStringLiteral("toolButton_chaxun"));
        toolButton_chaxun->setMinimumSize(QSize(0, 0));
        QIcon icon1;
        icon1.addFile(QStringLiteral(":/image/speedtest.png"), QSize(), QIcon::Normal, QIcon::Off);
        toolButton_chaxun->setIcon(icon1);
        toolButton_chaxun->setIconSize(QSize(50, 50));
        toolButton_chaxun->setToolButtonStyle(Qt::ToolButtonTextUnderIcon);

        verticalLayout->addWidget(toolButton_chaxun);

        toolButton_caijiboxing = new QToolButton(widgetLeft);
        toolButton_caijiboxing->setObjectName(QStringLiteral("toolButton_caijiboxing"));
        QIcon icon2;
        icon2.addFile(QStringLiteral(":/image/positiontest.png"), QSize(), QIcon::Normal, QIcon::Off);
        toolButton_caijiboxing->setIcon(icon2);
        toolButton_caijiboxing->setIconSize(QSize(50, 50));
        toolButton_caijiboxing->setToolButtonStyle(Qt::ToolButtonTextUnderIcon);

        verticalLayout->addWidget(toolButton_caijiboxing);

        toolButton_tuxinagchengxiang = new QToolButton(widgetLeft);
        toolButton_tuxinagchengxiang->setObjectName(QStringLiteral("toolButton_tuxinagchengxiang"));
        QIcon icon3;
        icon3.addFile(QStringLiteral(":/image/websitetest.png"), QSize(), QIcon::Normal, QIcon::Off);
        toolButton_tuxinagchengxiang->setIcon(icon3);
        toolButton_tuxinagchengxiang->setIconSize(QSize(50, 50));
        toolButton_tuxinagchengxiang->setToolButtonStyle(Qt::ToolButtonTextUnderIcon);

        verticalLayout->addWidget(toolButton_tuxinagchengxiang);

        verticalSpacer = new QSpacerItem(20, 44, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout->addItem(verticalSpacer);


        horizontalLayout_2->addWidget(widgetLeft);

        stackedWidget = new QStackedWidget(widget_main);
        stackedWidget->setObjectName(QStringLiteral("stackedWidget"));
        page_1 = new QWidget();
        page_1->setObjectName(QStringLiteral("page_1"));
        groupBox_adc = new QGroupBox(page_1);
        groupBox_adc->setObjectName(QStringLiteral("groupBox_adc"));
        groupBox_adc->setGeometry(QRect(70, 50, 374, 319));
        verticalLayout_5 = new QVBoxLayout(groupBox_adc);
        verticalLayout_5->setSpacing(6);
        verticalLayout_5->setContentsMargins(11, 11, 11, 11);
        verticalLayout_5->setObjectName(QStringLiteral("verticalLayout_5"));
        gridLayout_4 = new QGridLayout();
        gridLayout_4->setSpacing(6);
        gridLayout_4->setObjectName(QStringLiteral("gridLayout_4"));
        lineEdit_adc1 = new QLineEdit(groupBox_adc);
        lineEdit_adc1->setObjectName(QStringLiteral("lineEdit_adc1"));

        gridLayout_4->addWidget(lineEdit_adc1, 0, 1, 1, 1);

        label = new QLabel(groupBox_adc);
        label->setObjectName(QStringLiteral("label"));
        label->setAutoFillBackground(false);

        gridLayout_4->addWidget(label, 0, 0, 1, 1);

        label_28 = new QLabel(groupBox_adc);
        label_28->setObjectName(QStringLiteral("label_28"));
        label_28->setAutoFillBackground(false);

        gridLayout_4->addWidget(label_28, 0, 2, 1, 1);

        lineEdit_adc9 = new QLineEdit(groupBox_adc);
        lineEdit_adc9->setObjectName(QStringLiteral("lineEdit_adc9"));

        gridLayout_4->addWidget(lineEdit_adc9, 0, 3, 1, 1);

        label_2 = new QLabel(groupBox_adc);
        label_2->setObjectName(QStringLiteral("label_2"));
        label_2->setAutoFillBackground(false);

        gridLayout_4->addWidget(label_2, 1, 0, 1, 1);

        label_33 = new QLabel(groupBox_adc);
        label_33->setObjectName(QStringLiteral("label_33"));
        label_33->setAutoFillBackground(false);

        gridLayout_4->addWidget(label_33, 1, 2, 1, 1);

        lineEdit_adc2 = new QLineEdit(groupBox_adc);
        lineEdit_adc2->setObjectName(QStringLiteral("lineEdit_adc2"));

        gridLayout_4->addWidget(lineEdit_adc2, 1, 1, 1, 1);

        lineEdit_adc10 = new QLineEdit(groupBox_adc);
        lineEdit_adc10->setObjectName(QStringLiteral("lineEdit_adc10"));

        gridLayout_4->addWidget(lineEdit_adc10, 1, 3, 1, 1);

        label_30 = new QLabel(groupBox_adc);
        label_30->setObjectName(QStringLiteral("label_30"));
        label_30->setAutoFillBackground(false);

        gridLayout_4->addWidget(label_30, 2, 2, 1, 1);

        lineEdit_11 = new QLineEdit(groupBox_adc);
        lineEdit_11->setObjectName(QStringLiteral("lineEdit_11"));

        gridLayout_4->addWidget(lineEdit_11, 2, 3, 1, 1);

        label_13 = new QLabel(groupBox_adc);
        label_13->setObjectName(QStringLiteral("label_13"));
        label_13->setAutoFillBackground(false);

        gridLayout_4->addWidget(label_13, 3, 0, 1, 1);

        lineEdit_adc3 = new QLineEdit(groupBox_adc);
        lineEdit_adc3->setObjectName(QStringLiteral("lineEdit_adc3"));

        gridLayout_4->addWidget(lineEdit_adc3, 2, 1, 1, 1);

        label_11 = new QLabel(groupBox_adc);
        label_11->setObjectName(QStringLiteral("label_11"));
        label_11->setAutoFillBackground(false);

        gridLayout_4->addWidget(label_11, 2, 0, 1, 1);

        lineEdit_adc12 = new QLineEdit(groupBox_adc);
        lineEdit_adc12->setObjectName(QStringLiteral("lineEdit_adc12"));

        gridLayout_4->addWidget(lineEdit_adc12, 3, 3, 1, 1);

        label_20 = new QLabel(groupBox_adc);
        label_20->setObjectName(QStringLiteral("label_20"));
        label_20->setAutoFillBackground(false);

        gridLayout_4->addWidget(label_20, 4, 0, 1, 1);

        lineEdit_adc4 = new QLineEdit(groupBox_adc);
        lineEdit_adc4->setObjectName(QStringLiteral("lineEdit_adc4"));

        gridLayout_4->addWidget(lineEdit_adc4, 3, 1, 1, 1);

        lineEdit_adc5 = new QLineEdit(groupBox_adc);
        lineEdit_adc5->setObjectName(QStringLiteral("lineEdit_adc5"));

        gridLayout_4->addWidget(lineEdit_adc5, 4, 1, 1, 1);

        label_25 = new QLabel(groupBox_adc);
        label_25->setObjectName(QStringLiteral("label_25"));
        label_25->setAutoFillBackground(false);

        gridLayout_4->addWidget(label_25, 5, 0, 1, 1);

        label_35 = new QLabel(groupBox_adc);
        label_35->setObjectName(QStringLiteral("label_35"));
        label_35->setAutoFillBackground(false);

        gridLayout_4->addWidget(label_35, 4, 2, 1, 1);

        lineEdit_adc6 = new QLineEdit(groupBox_adc);
        lineEdit_adc6->setObjectName(QStringLiteral("lineEdit_adc6"));

        gridLayout_4->addWidget(lineEdit_adc6, 5, 1, 1, 1);

        lineEdit_adc13 = new QLineEdit(groupBox_adc);
        lineEdit_adc13->setObjectName(QStringLiteral("lineEdit_adc13"));

        gridLayout_4->addWidget(lineEdit_adc13, 4, 3, 1, 1);

        label_31 = new QLabel(groupBox_adc);
        label_31->setObjectName(QStringLiteral("label_31"));
        label_31->setAutoFillBackground(false);

        gridLayout_4->addWidget(label_31, 5, 2, 1, 1);

        lineEdit_adc7 = new QLineEdit(groupBox_adc);
        lineEdit_adc7->setObjectName(QStringLiteral("lineEdit_adc7"));

        gridLayout_4->addWidget(lineEdit_adc7, 6, 1, 1, 1);

        label_26 = new QLabel(groupBox_adc);
        label_26->setObjectName(QStringLiteral("label_26"));
        label_26->setAutoFillBackground(false);

        gridLayout_4->addWidget(label_26, 6, 0, 1, 1);

        lineEdit_adc14 = new QLineEdit(groupBox_adc);
        lineEdit_adc14->setObjectName(QStringLiteral("lineEdit_adc14"));

        gridLayout_4->addWidget(lineEdit_adc14, 5, 3, 1, 1);

        lineEdit_adc15 = new QLineEdit(groupBox_adc);
        lineEdit_adc15->setObjectName(QStringLiteral("lineEdit_adc15"));

        gridLayout_4->addWidget(lineEdit_adc15, 6, 3, 1, 1);

        label_27 = new QLabel(groupBox_adc);
        label_27->setObjectName(QStringLiteral("label_27"));
        label_27->setAutoFillBackground(false);

        gridLayout_4->addWidget(label_27, 7, 0, 1, 1);

        lineEdit_adc8 = new QLineEdit(groupBox_adc);
        lineEdit_adc8->setObjectName(QStringLiteral("lineEdit_adc8"));

        gridLayout_4->addWidget(lineEdit_adc8, 7, 1, 1, 1);

        label_29 = new QLabel(groupBox_adc);
        label_29->setObjectName(QStringLiteral("label_29"));
        label_29->setAutoFillBackground(false);

        gridLayout_4->addWidget(label_29, 6, 2, 1, 1);

        label_34 = new QLabel(groupBox_adc);
        label_34->setObjectName(QStringLiteral("label_34"));
        label_34->setAutoFillBackground(false);

        gridLayout_4->addWidget(label_34, 7, 2, 1, 1);

        label_32 = new QLabel(groupBox_adc);
        label_32->setObjectName(QStringLiteral("label_32"));
        label_32->setAutoFillBackground(false);

        gridLayout_4->addWidget(label_32, 3, 2, 1, 1);

        lineEdit_adc16 = new QLineEdit(groupBox_adc);
        lineEdit_adc16->setObjectName(QStringLiteral("lineEdit_adc16"));

        gridLayout_4->addWidget(lineEdit_adc16, 7, 3, 1, 1);

        label_3 = new QLabel(groupBox_adc);
        label_3->setObjectName(QStringLiteral("label_3"));

        gridLayout_4->addWidget(label_3, 8, 0, 1, 1);

        lineEdit_caijidian = new QLineEdit(groupBox_adc);
        lineEdit_caijidian->setObjectName(QStringLiteral("lineEdit_caijidian"));

        gridLayout_4->addWidget(lineEdit_caijidian, 8, 1, 1, 1);


        verticalLayout_5->addLayout(gridLayout_4);

        horizontalLayout_7 = new QHBoxLayout();
        horizontalLayout_7->setSpacing(6);
        horizontalLayout_7->setObjectName(QStringLiteral("horizontalLayout_7"));
        horizontalSpacer_7 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_7->addItem(horizontalSpacer_7);

        pushButton_canshu_set = new QPushButton(groupBox_adc);
        pushButton_canshu_set->setObjectName(QStringLiteral("pushButton_canshu_set"));
        QSizePolicy sizePolicy3(QSizePolicy::Preferred, QSizePolicy::Preferred);
        sizePolicy3.setHorizontalStretch(0);
        sizePolicy3.setVerticalStretch(0);
        sizePolicy3.setHeightForWidth(pushButton_canshu_set->sizePolicy().hasHeightForWidth());
        pushButton_canshu_set->setSizePolicy(sizePolicy3);
        pushButton_canshu_set->setMinimumSize(QSize(150, 22));
        pushButton_canshu_set->setMaximumSize(QSize(50, 40));

        horizontalLayout_7->addWidget(pushButton_canshu_set);

        horizontalSpacer_6 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_7->addItem(horizontalSpacer_6);


        verticalLayout_5->addLayout(horizontalLayout_7);

        label_fpga_wendu = new QLabel(page_1);
        label_fpga_wendu->setObjectName(QStringLiteral("label_fpga_wendu"));
        label_fpga_wendu->setGeometry(QRect(470, 350, 54, 12));
        layoutWidget = new QWidget(page_1);
        layoutWidget->setObjectName(QStringLiteral("layoutWidget"));
        layoutWidget->setGeometry(QRect(40, 10, 921, 31));
        horizontalLayout_4 = new QHBoxLayout(layoutWidget);
        horizontalLayout_4->setSpacing(6);
        horizontalLayout_4->setContentsMargins(11, 11, 11, 11);
        horizontalLayout_4->setObjectName(QStringLiteral("horizontalLayout_4"));
        horizontalLayout_4->setContentsMargins(0, 0, 0, 0);
        horizontalSpacer_4 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_4->addItem(horizontalSpacer_4);

        label_10 = new QLabel(layoutWidget);
        label_10->setObjectName(QStringLiteral("label_10"));

        horizontalLayout_4->addWidget(label_10);

        label_work_status = new QLabel(layoutWidget);
        label_work_status->setObjectName(QStringLiteral("label_work_status"));

        horizontalLayout_4->addWidget(label_work_status);

        horizontalSpacer_2 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_4->addItem(horizontalSpacer_2);

        label_12 = new QLabel(layoutWidget);
        label_12->setObjectName(QStringLiteral("label_12"));

        horizontalLayout_4->addWidget(label_12);

        label_liuchang_status = new QLabel(layoutWidget);
        label_liuchang_status->setObjectName(QStringLiteral("label_liuchang_status"));

        horizontalLayout_4->addWidget(label_liuchang_status);

        horizontalSpacer_3 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_4->addItem(horizontalSpacer_3);

        label_16 = new QLabel(layoutWidget);
        label_16->setObjectName(QStringLiteral("label_16"));

        horizontalLayout_4->addWidget(label_16);

        label_caiji_wendu = new QLabel(layoutWidget);
        label_caiji_wendu->setObjectName(QStringLiteral("label_caiji_wendu"));

        horizontalLayout_4->addWidget(label_caiji_wendu);

        horizontalSpacer_5 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_4->addItem(horizontalSpacer_5);

        stackedWidget->addWidget(page_1);
        page_2 = new QWidget();
        page_2->setObjectName(QStringLiteral("page_2"));
        horizontalLayout_6 = new QHBoxLayout(page_2);
        horizontalLayout_6->setSpacing(6);
        horizontalLayout_6->setContentsMargins(11, 11, 11, 11);
        horizontalLayout_6->setObjectName(QStringLiteral("horizontalLayout_6"));
        verticalLayout_8 = new QVBoxLayout();
        verticalLayout_8->setSpacing(6);
        verticalLayout_8->setObjectName(QStringLiteral("verticalLayout_8"));
        scrollArea = new QScrollArea(page_2);
        scrollArea->setObjectName(QStringLiteral("scrollArea"));
        scrollArea->setStyleSheet(QStringLiteral("background-color: rgba(0, 0, 255, 0);"));
        scrollArea->setWidgetResizable(true);
        scrollAreaWidgetContents = new QWidget();
        scrollAreaWidgetContents->setObjectName(QStringLiteral("scrollAreaWidgetContents"));
        scrollAreaWidgetContents->setGeometry(QRect(0, 0, 98, 28));
        scrollArea->setWidget(scrollAreaWidgetContents);

        verticalLayout_8->addWidget(scrollArea);

        scrollArea_2 = new QScrollArea(page_2);
        scrollArea_2->setObjectName(QStringLiteral("scrollArea_2"));
        scrollArea_2->setStyleSheet(QStringLiteral("background-color: rgba(0, 0, 255, 0);"));
        scrollArea_2->setWidgetResizable(true);
        scrollAreaWidgetContents_2 = new QWidget();
        scrollAreaWidgetContents_2->setObjectName(QStringLiteral("scrollAreaWidgetContents_2"));
        scrollAreaWidgetContents_2->setGeometry(QRect(0, 0, 98, 28));
        scrollArea_2->setWidget(scrollAreaWidgetContents_2);

        verticalLayout_8->addWidget(scrollArea_2);

        verticalLayout_8->setStretch(0, 3);
        verticalLayout_8->setStretch(1, 1);

        horizontalLayout_6->addLayout(verticalLayout_8);

        verticalLayout_7 = new QVBoxLayout();
        verticalLayout_7->setSpacing(6);
        verticalLayout_7->setObjectName(QStringLiteral("verticalLayout_7"));
        horizontalLayout_5 = new QHBoxLayout();
        horizontalLayout_5->setSpacing(6);
        horizontalLayout_5->setObjectName(QStringLiteral("horizontalLayout_5"));
        label_icon_temp = new QLabel(page_2);
        label_icon_temp->setObjectName(QStringLiteral("label_icon_temp"));
        sizePolicy.setHeightForWidth(label_icon_temp->sizePolicy().hasHeightForWidth());
        label_icon_temp->setSizePolicy(sizePolicy);
        label_icon_temp->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        horizontalLayout_5->addWidget(label_icon_temp);

        label_dy = new QLabel(page_2);
        label_dy->setObjectName(QStringLiteral("label_dy"));
        sizePolicy.setHeightForWidth(label_dy->sizePolicy().hasHeightForWidth());
        label_dy->setSizePolicy(sizePolicy);
        QFont font;
        font.setFamily(QString::fromUtf8("\345\276\256\350\275\257\351\233\205\351\273\221"));
        font.setPointSize(16);
        font.setBold(false);
        font.setWeight(50);
        label_dy->setFont(font);

        horizontalLayout_5->addWidget(label_dy);

        label_dy_temp = new QLabel(page_2);
        label_dy_temp->setObjectName(QStringLiteral("label_dy_temp"));
        sizePolicy3.setHeightForWidth(label_dy_temp->sizePolicy().hasHeightForWidth());
        label_dy_temp->setSizePolicy(sizePolicy3);
        QFont font1;
        font1.setFamily(QString::fromUtf8("\345\276\256\350\275\257\351\233\205\351\273\221"));
        font1.setPointSize(16);
        label_dy_temp->setFont(font1);

        horizontalLayout_5->addWidget(label_dy_temp);


        verticalLayout_7->addLayout(horizontalLayout_5);

        verticalSpacer_2 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout_7->addItem(verticalSpacer_2);

        pushButton_dianya_set = new QPushButton(page_2);
        pushButton_dianya_set->setObjectName(QStringLiteral("pushButton_dianya_set"));
        QSizePolicy sizePolicy4(QSizePolicy::Minimum, QSizePolicy::Minimum);
        sizePolicy4.setHorizontalStretch(0);
        sizePolicy4.setVerticalStretch(0);
        sizePolicy4.setHeightForWidth(pushButton_dianya_set->sizePolicy().hasHeightForWidth());
        pushButton_dianya_set->setSizePolicy(sizePolicy4);
        pushButton_dianya_set->setMinimumSize(QSize(40, 40));

        verticalLayout_7->addWidget(pushButton_dianya_set);


        horizontalLayout_6->addLayout(verticalLayout_7);

        horizontalLayout_6->setStretch(0, 3);
        stackedWidget->addWidget(page_2);
        page_3 = new QWidget();
        page_3->setObjectName(QStringLiteral("page_3"));
        horizontalLayout_3 = new QHBoxLayout(page_3);
        horizontalLayout_3->setSpacing(6);
        horizontalLayout_3->setContentsMargins(11, 11, 11, 11);
        horizontalLayout_3->setObjectName(QStringLiteral("horizontalLayout_3"));
        horizontalLayout_3->setContentsMargins(9, 9, 9, 9);
        widget_wave = new QWidget(page_3);
        widget_wave->setObjectName(QStringLiteral("widget_wave"));
        QSizePolicy sizePolicy5(QSizePolicy::Expanding, QSizePolicy::Preferred);
        sizePolicy5.setHorizontalStretch(0);
        sizePolicy5.setVerticalStretch(0);
        sizePolicy5.setHeightForWidth(widget_wave->sizePolicy().hasHeightForWidth());
        widget_wave->setSizePolicy(sizePolicy5);

        horizontalLayout_3->addWidget(widget_wave);

        verticalLayout_6 = new QVBoxLayout();
        verticalLayout_6->setSpacing(6);
        verticalLayout_6->setObjectName(QStringLiteral("verticalLayout_6"));
        pushButton_start_collect = new QPushButton(page_3);
        pushButton_start_collect->setObjectName(QStringLiteral("pushButton_start_collect"));
        pushButton_start_collect->setMinimumSize(QSize(100, 30));

        verticalLayout_6->addWidget(pushButton_start_collect);

        pushButton_start_trans = new QPushButton(page_3);
        pushButton_start_trans->setObjectName(QStringLiteral("pushButton_start_trans"));
        pushButton_start_trans->setMinimumSize(QSize(100, 30));

        verticalLayout_6->addWidget(pushButton_start_trans);

        pushButton_src_shangchuan = new QPushButton(page_3);
        pushButton_src_shangchuan->setObjectName(QStringLiteral("pushButton_src_shangchuan"));
        pushButton_src_shangchuan->setMinimumSize(QSize(100, 30));

        verticalLayout_6->addWidget(pushButton_src_shangchuan);


        horizontalLayout_3->addLayout(verticalLayout_6);

        stackedWidget->addWidget(page_3);
        page_4 = new QWidget();
        page_4->setObjectName(QStringLiteral("page_4"));
        gridLayout_3 = new QGridLayout(page_4);
        gridLayout_3->setSpacing(6);
        gridLayout_3->setContentsMargins(11, 11, 11, 11);
        gridLayout_3->setObjectName(QStringLiteral("gridLayout_3"));
        widget_image = new QWidget(page_4);
        widget_image->setObjectName(QStringLiteral("widget_image"));

        gridLayout_3->addWidget(widget_image, 0, 0, 1, 1);

        stackedWidget->addWidget(page_4);

        horizontalLayout_2->addWidget(stackedWidget);


        verticalLayout_2->addLayout(horizontalLayout_2);


        verticalLayout_3->addWidget(widget_main);

        widget_log = new QWidget(widget_huangwei);
        widget_log->setObjectName(QStringLiteral("widget_log"));

        verticalLayout_3->addWidget(widget_log);

        verticalLayout_3->setStretch(0, 3);
        verticalLayout_3->setStretch(1, 1);

        verticalLayout_4->addWidget(widget_huangwei);

        MainWindow->setCentralWidget(centralWidget);

        retranslateUi(MainWindow);

        stackedWidget->setCurrentIndex(0);


        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "MainWindow", Q_NULLPTR));
        label_icon->setText(QString());
        label_title->setText(QApplication::translate("MainWindow", "X256\345\271\205\345\272\246\351\207\207\351\233\206\347\263\273\347\273\237", Q_NULLPTR));
        pushButton_min->setText(QString());
        pushButton_max->setText(QString());
        pushButton_close->setText(QString());
        toolButton_set->setText(QApplication::translate("MainWindow", "\351\207\207\351\233\206\346\235\277\345\215\241", Q_NULLPTR));
        toolButton_chaxun->setText(QApplication::translate("MainWindow", "\347\224\265\346\272\220\346\235\277\345\215\241", Q_NULLPTR));
        toolButton_caijiboxing->setText(QApplication::translate("MainWindow", "\351\207\207\351\233\206\346\263\242\345\275\242", Q_NULLPTR));
        toolButton_tuxinagchengxiang->setText(QApplication::translate("MainWindow", "\346\225\260\346\215\256\346\210\220\345\203\217", Q_NULLPTR));
        groupBox_adc->setTitle(QApplication::translate("MainWindow", "16\347\211\207ADC", Q_NULLPTR));
        label->setText(QApplication::translate("MainWindow", "ADC1\345\242\236\347\233\212:", Q_NULLPTR));
        label_28->setText(QApplication::translate("MainWindow", "ADC9\345\242\236\347\233\212:", Q_NULLPTR));
        label_2->setText(QApplication::translate("MainWindow", "ADC2\345\242\236\347\233\212:", Q_NULLPTR));
        label_33->setText(QApplication::translate("MainWindow", "ADC10\345\242\236\347\233\212:", Q_NULLPTR));
        label_30->setText(QApplication::translate("MainWindow", "ADC11\345\242\236\347\233\212:", Q_NULLPTR));
        label_13->setText(QApplication::translate("MainWindow", "ADC4\345\242\236\347\233\212:", Q_NULLPTR));
        label_11->setText(QApplication::translate("MainWindow", "ADC3\345\242\236\347\233\212:", Q_NULLPTR));
        label_20->setText(QApplication::translate("MainWindow", "ADC5\345\242\236\347\233\212:", Q_NULLPTR));
        label_25->setText(QApplication::translate("MainWindow", "ADC6\345\242\236\347\233\212:", Q_NULLPTR));
        label_35->setText(QApplication::translate("MainWindow", "ADC13\345\242\236\347\233\212:", Q_NULLPTR));
        label_31->setText(QApplication::translate("MainWindow", "ADC14\345\242\236\347\233\212:", Q_NULLPTR));
        label_26->setText(QApplication::translate("MainWindow", "ADC7\345\242\236\347\233\212:", Q_NULLPTR));
        label_27->setText(QApplication::translate("MainWindow", "ADC8\345\242\236\347\233\212:", Q_NULLPTR));
        label_29->setText(QApplication::translate("MainWindow", "ADC15\345\242\236\347\233\212:", Q_NULLPTR));
        label_34->setText(QApplication::translate("MainWindow", "ADC16\345\242\236\347\233\212:", Q_NULLPTR));
        label_32->setText(QApplication::translate("MainWindow", "ADC12\345\242\236\347\233\212:", Q_NULLPTR));
        label_3->setText(QApplication::translate("MainWindow", "\351\207\207\351\233\206\347\202\271\357\274\232", Q_NULLPTR));
        pushButton_canshu_set->setText(QApplication::translate("MainWindow", "\345\217\202\346\225\260\350\256\276\347\275\256", Q_NULLPTR));
        label_fpga_wendu->setText(QString());
        label_10->setText(QApplication::translate("MainWindow", "\345\267\245\344\275\234\347\212\266\346\200\201\357\274\232", Q_NULLPTR));
        label_work_status->setText(QApplication::translate("MainWindow", "\345\260\261\347\273\252", Q_NULLPTR));
        label_12->setText(QApplication::translate("MainWindow", "\346\265\201\347\250\213\347\212\266\346\200\201\357\274\232", Q_NULLPTR));
        label_liuchang_status->setText(QApplication::translate("MainWindow", "\347\255\211\345\276\205\350\256\276\347\275\256", Q_NULLPTR));
        label_16->setText(QApplication::translate("MainWindow", "FPGA\346\270\251\345\272\246\357\274\232", Q_NULLPTR));
        label_caiji_wendu->setText(QString());
        label_icon_temp->setText(QString());
        label_dy->setText(QApplication::translate("MainWindow", "\346\270\251\345\272\246\357\274\232", Q_NULLPTR));
        label_dy_temp->setText(QApplication::translate("MainWindow", "00.0\342\204\203", Q_NULLPTR));
        pushButton_dianya_set->setText(QApplication::translate("MainWindow", "\347\224\265\345\216\213\350\256\276\347\275\256", Q_NULLPTR));
        pushButton_start_collect->setText(QApplication::translate("MainWindow", "\345\274\200\345\247\213\351\207\207\351\233\206", Q_NULLPTR));
        pushButton_start_trans->setText(QApplication::translate("MainWindow", "\345\274\200\345\247\213\344\270\212\344\274\240", Q_NULLPTR));
        pushButton_src_shangchuan->setText(QApplication::translate("MainWindow", "\345\216\237\346\226\207\344\273\266\344\270\212\344\274\240", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
