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
#include <QtWidgets/QComboBox>
#include <QtWidgets/QFrame>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QPushButton>
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
    QGroupBox *groupBox;
    QVBoxLayout *verticalLayout_5;
    QFrame *frame;
    QGridLayout *gridLayout;
    QLabel *label_5;
    QComboBox *comboBox;
    QLabel *label_3;
    QLineEdit *lineEdit_3;
    QLabel *label_4;
    QLineEdit *lineEdit_4;
    QPushButton *pushButton_canshu_set;
    QGroupBox *groupBox_2;
    QPushButton *pushButton_dianya_ctrl;
    QLabel *label_9;
    QGroupBox *groupBox_3;
    QPushButton *pushButton_dianya_zujian;
    QLabel *label_24;
    QLabel *label;
    QWidget *page_2;
    QPushButton *pushButton_status_chaxun;
    QLabel *label_10;
    QLabel *label_11;
    QLabel *label_12;
    QLabel *label_13;
    QLabel *label_14;
    QLabel *label_15;
    QLabel *label_16;
    QLabel *label_19;
    QLabel *label_20;
    QLabel *label_21;
    QLabel *label_22;
    QLabel *label_23;
    QGroupBox *groupBox_4;
    QGridLayout *gridLayout_2;
    QLabel *label_6;
    QComboBox *comboBox_2;
    QLabel *label_7;
    QLineEdit *lineEdit_5;
    QLabel *label_8;
    QLineEdit *lineEdit_6;
    QLabel *label_17;
    QLineEdit *lineEdit_13;
    QLabel *label_18;
    QLineEdit *lineEdit_14;
    QPushButton *pushButton;
    QWidget *page_3;
    QPushButton *pushButton_start_collect;
    QPushButton *pushButton_start_trans;
    QPushButton *pushButton_src_shangchuan;
    QWidget *widget_wave;
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
        groupBox = new QGroupBox(page_1);
        groupBox->setObjectName(QStringLiteral("groupBox"));
        groupBox->setGeometry(QRect(40, 40, 241, 181));
        verticalLayout_5 = new QVBoxLayout(groupBox);
        verticalLayout_5->setSpacing(6);
        verticalLayout_5->setContentsMargins(11, 11, 11, 11);
        verticalLayout_5->setObjectName(QStringLiteral("verticalLayout_5"));
        frame = new QFrame(groupBox);
        frame->setObjectName(QStringLiteral("frame"));
        frame->setFrameShape(QFrame::StyledPanel);
        frame->setFrameShadow(QFrame::Raised);
        gridLayout = new QGridLayout(frame);
        gridLayout->setSpacing(6);
        gridLayout->setContentsMargins(11, 11, 11, 11);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        label_5 = new QLabel(frame);
        label_5->setObjectName(QStringLiteral("label_5"));

        gridLayout->addWidget(label_5, 0, 0, 1, 1);

        comboBox = new QComboBox(frame);
        comboBox->setObjectName(QStringLiteral("comboBox"));

        gridLayout->addWidget(comboBox, 0, 1, 1, 1);

        label_3 = new QLabel(frame);
        label_3->setObjectName(QStringLiteral("label_3"));

        gridLayout->addWidget(label_3, 1, 0, 1, 1);

        lineEdit_3 = new QLineEdit(frame);
        lineEdit_3->setObjectName(QStringLiteral("lineEdit_3"));

        gridLayout->addWidget(lineEdit_3, 1, 1, 1, 1);

        label_4 = new QLabel(frame);
        label_4->setObjectName(QStringLiteral("label_4"));

        gridLayout->addWidget(label_4, 2, 0, 1, 1);

        lineEdit_4 = new QLineEdit(frame);
        lineEdit_4->setObjectName(QStringLiteral("lineEdit_4"));

        gridLayout->addWidget(lineEdit_4, 2, 1, 1, 1);


        verticalLayout_5->addWidget(frame);

        pushButton_canshu_set = new QPushButton(groupBox);
        pushButton_canshu_set->setObjectName(QStringLiteral("pushButton_canshu_set"));

        verticalLayout_5->addWidget(pushButton_canshu_set);

        groupBox_2 = new QGroupBox(page_1);
        groupBox_2->setObjectName(QStringLiteral("groupBox_2"));
        groupBox_2->setGeometry(QRect(600, 100, 301, 171));
        pushButton_dianya_ctrl = new QPushButton(groupBox_2);
        pushButton_dianya_ctrl->setObjectName(QStringLiteral("pushButton_dianya_ctrl"));
        pushButton_dianya_ctrl->setGeometry(QRect(150, 110, 131, 41));
        label_9 = new QLabel(groupBox_2);
        label_9->setObjectName(QStringLiteral("label_9"));
        label_9->setGeometry(QRect(160, 50, 111, 21));
        groupBox_3 = new QGroupBox(page_1);
        groupBox_3->setObjectName(QStringLiteral("groupBox_3"));
        groupBox_3->setGeometry(QRect(600, 290, 301, 141));
        pushButton_dianya_zujian = new QPushButton(groupBox_3);
        pushButton_dianya_zujian->setObjectName(QStringLiteral("pushButton_dianya_zujian"));
        pushButton_dianya_zujian->setGeometry(QRect(160, 90, 131, 41));
        label_24 = new QLabel(groupBox_3);
        label_24->setObjectName(QStringLiteral("label_24"));
        label_24->setGeometry(QRect(40, 50, 71, 21));
        QFont font;
        font.setFamily(QString::fromUtf8("\345\276\256\350\275\257\351\233\205\351\273\221"));
        label_24->setFont(font);
        label = new QLabel(page_1);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(200, 330, 61, 31));
        label->setAutoFillBackground(false);
        stackedWidget->addWidget(page_1);
        page_2 = new QWidget();
        page_2->setObjectName(QStringLiteral("page_2"));
        pushButton_status_chaxun = new QPushButton(page_2);
        pushButton_status_chaxun->setObjectName(QStringLiteral("pushButton_status_chaxun"));
        pushButton_status_chaxun->setGeometry(QRect(760, 370, 129, 20));
        label_10 = new QLabel(page_2);
        label_10->setObjectName(QStringLiteral("label_10"));
        label_10->setGeometry(QRect(90, 60, 61, 21));
        label_11 = new QLabel(page_2);
        label_11->setObjectName(QStringLiteral("label_11"));
        label_11->setGeometry(QRect(160, 60, 41, 21));
        label_12 = new QLabel(page_2);
        label_12->setObjectName(QStringLiteral("label_12"));
        label_12->setGeometry(QRect(90, 100, 61, 16));
        label_13 = new QLabel(page_2);
        label_13->setObjectName(QStringLiteral("label_13"));
        label_13->setGeometry(QRect(160, 97, 61, 21));
        label_14 = new QLabel(page_2);
        label_14->setObjectName(QStringLiteral("label_14"));
        label_14->setGeometry(QRect(93, 280, 81, 31));
        label_15 = new QLabel(page_2);
        label_15->setObjectName(QStringLiteral("label_15"));
        label_15->setGeometry(QRect(90, 320, 81, 31));
        label_16 = new QLabel(page_2);
        label_16->setObjectName(QStringLiteral("label_16"));
        label_16->setGeometry(QRect(90, 360, 61, 21));
        label_19 = new QLabel(page_2);
        label_19->setObjectName(QStringLiteral("label_19"));
        label_19->setGeometry(QRect(90, 400, 81, 16));
        label_20 = new QLabel(page_2);
        label_20->setObjectName(QStringLiteral("label_20"));
        label_20->setGeometry(QRect(100, 150, 71, 21));
        label_21 = new QLabel(page_2);
        label_21->setObjectName(QStringLiteral("label_21"));
        label_21->setGeometry(QRect(100, 190, 111, 21));
        label_22 = new QLabel(page_2);
        label_22->setObjectName(QStringLiteral("label_22"));
        label_22->setGeometry(QRect(100, 230, 91, 21));
        label_23 = new QLabel(page_2);
        label_23->setObjectName(QStringLiteral("label_23"));
        label_23->setGeometry(QRect(100, 260, 91, 21));
        groupBox_4 = new QGroupBox(page_2);
        groupBox_4->setObjectName(QStringLiteral("groupBox_4"));
        groupBox_4->setGeometry(QRect(420, 60, 211, 211));
        gridLayout_2 = new QGridLayout(groupBox_4);
        gridLayout_2->setSpacing(6);
        gridLayout_2->setContentsMargins(11, 11, 11, 11);
        gridLayout_2->setObjectName(QStringLiteral("gridLayout_2"));
        label_6 = new QLabel(groupBox_4);
        label_6->setObjectName(QStringLiteral("label_6"));

        gridLayout_2->addWidget(label_6, 0, 0, 1, 1);

        comboBox_2 = new QComboBox(groupBox_4);
        comboBox_2->setObjectName(QStringLiteral("comboBox_2"));

        gridLayout_2->addWidget(comboBox_2, 0, 1, 1, 1);

        label_7 = new QLabel(groupBox_4);
        label_7->setObjectName(QStringLiteral("label_7"));

        gridLayout_2->addWidget(label_7, 1, 0, 1, 1);

        lineEdit_5 = new QLineEdit(groupBox_4);
        lineEdit_5->setObjectName(QStringLiteral("lineEdit_5"));

        gridLayout_2->addWidget(lineEdit_5, 1, 1, 1, 1);

        label_8 = new QLabel(groupBox_4);
        label_8->setObjectName(QStringLiteral("label_8"));

        gridLayout_2->addWidget(label_8, 2, 0, 1, 1);

        lineEdit_6 = new QLineEdit(groupBox_4);
        lineEdit_6->setObjectName(QStringLiteral("lineEdit_6"));

        gridLayout_2->addWidget(lineEdit_6, 2, 1, 1, 1);

        label_17 = new QLabel(groupBox_4);
        label_17->setObjectName(QStringLiteral("label_17"));

        gridLayout_2->addWidget(label_17, 3, 0, 1, 1);

        lineEdit_13 = new QLineEdit(groupBox_4);
        lineEdit_13->setObjectName(QStringLiteral("lineEdit_13"));

        gridLayout_2->addWidget(lineEdit_13, 3, 1, 1, 1);

        label_18 = new QLabel(groupBox_4);
        label_18->setObjectName(QStringLiteral("label_18"));

        gridLayout_2->addWidget(label_18, 4, 0, 1, 1);

        lineEdit_14 = new QLineEdit(groupBox_4);
        lineEdit_14->setObjectName(QStringLiteral("lineEdit_14"));

        gridLayout_2->addWidget(lineEdit_14, 4, 1, 1, 1);

        pushButton = new QPushButton(groupBox_4);
        pushButton->setObjectName(QStringLiteral("pushButton"));

        gridLayout_2->addWidget(pushButton, 5, 0, 1, 2);

        stackedWidget->addWidget(page_2);
        page_3 = new QWidget();
        page_3->setObjectName(QStringLiteral("page_3"));
        pushButton_start_collect = new QPushButton(page_3);
        pushButton_start_collect->setObjectName(QStringLiteral("pushButton_start_collect"));
        pushButton_start_collect->setGeometry(QRect(120, 100, 129, 20));
        pushButton_start_trans = new QPushButton(page_3);
        pushButton_start_trans->setObjectName(QStringLiteral("pushButton_start_trans"));
        pushButton_start_trans->setGeometry(QRect(120, 150, 129, 20));
        pushButton_src_shangchuan = new QPushButton(page_3);
        pushButton_src_shangchuan->setObjectName(QStringLiteral("pushButton_src_shangchuan"));
        pushButton_src_shangchuan->setGeometry(QRect(120, 200, 129, 20));
        pushButton_src_shangchuan->setMinimumSize(QSize(0, 0));
        widget_wave = new QWidget(page_3);
        widget_wave->setObjectName(QStringLiteral("widget_wave"));
        widget_wave->setGeometry(QRect(280, 30, 751, 421));
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

        verticalLayout_3->setStretch(0, 2);
        verticalLayout_3->setStretch(1, 1);

        verticalLayout_4->addWidget(widget_huangwei);

        MainWindow->setCentralWidget(centralWidget);

        retranslateUi(MainWindow);

        stackedWidget->setCurrentIndex(1);


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
        groupBox->setTitle(QApplication::translate("MainWindow", "256\350\267\257ADC", Q_NULLPTR));
        label_5->setText(QApplication::translate("MainWindow", "ADC\351\200\232\351\201\223\357\274\232", Q_NULLPTR));
        comboBox->clear();
        comboBox->insertItems(0, QStringList()
         << QApplication::translate("MainWindow", "1", Q_NULLPTR)
         << QApplication::translate("MainWindow", "2", Q_NULLPTR)
         << QApplication::translate("MainWindow", "3", Q_NULLPTR)
         << QApplication::translate("MainWindow", "4", Q_NULLPTR)
        );
        label_3->setText(QApplication::translate("MainWindow", "\351\207\207\351\233\206\347\202\271\357\274\232", Q_NULLPTR));
        label_4->setText(QApplication::translate("MainWindow", "\345\242\236\347\233\212\345\200\274\357\274\232", Q_NULLPTR));
        pushButton_canshu_set->setText(QApplication::translate("MainWindow", "\345\217\202\346\225\260\350\256\276\347\275\256", Q_NULLPTR));
        groupBox_2->setTitle(QApplication::translate("MainWindow", "GroupBox", Q_NULLPTR));
        pushButton_dianya_ctrl->setText(QApplication::translate("MainWindow", "\347\224\265\345\216\213\346\216\247\345\210\266", Q_NULLPTR));
        label_9->setText(QApplication::translate("MainWindow", "26\350\267\257\347\224\265\345\216\213\345\274\200\345\205\263\350\256\276\350\256\241\357\274\232", Q_NULLPTR));
        groupBox_3->setTitle(QApplication::translate("MainWindow", "GroupBox", Q_NULLPTR));
        pushButton_dianya_zujian->setText(QApplication::translate("MainWindow", "\347\224\265\345\216\213\347\273\204\346\216\247", Q_NULLPTR));
        label_24->setText(QApplication::translate("MainWindow", "\347\224\265\345\216\213\347\273\204\351\200\211\346\213\251\357\274\232", Q_NULLPTR));
        label->setText(QString());
        pushButton_status_chaxun->setText(QApplication::translate("MainWindow", "\347\212\266\346\200\201\346\237\245\350\257\242", Q_NULLPTR));
        label_10->setText(QApplication::translate("MainWindow", "\345\267\245\344\275\234\347\212\266\346\200\201\357\274\232", Q_NULLPTR));
        label_11->setText(QApplication::translate("MainWindow", "\345\260\261\347\273\252", Q_NULLPTR));
        label_12->setText(QApplication::translate("MainWindow", "\346\265\201\347\250\213\347\212\266\346\200\201\357\274\232", Q_NULLPTR));
        label_13->setText(QApplication::translate("MainWindow", "\347\255\211\345\276\205\350\256\276\347\275\256", Q_NULLPTR));
        label_14->setText(QApplication::translate("MainWindow", "26\350\267\257DAC\347\212\266\346\200\201\357\274\232", Q_NULLPTR));
        label_15->setText(QApplication::translate("MainWindow", "52\350\267\257ADC\347\212\266\346\200\201\357\274\232", Q_NULLPTR));
        label_16->setText(QApplication::translate("MainWindow", "FPGA\346\270\251\345\272\246\357\274\232", Q_NULLPTR));
        label_19->setText(QApplication::translate("MainWindow", "\347\224\265\345\216\213FPGA\346\270\251\345\272\246\357\274\232", Q_NULLPTR));
        label_20->setText(QApplication::translate("MainWindow", "16\347\211\207ADC\347\212\266\346\200\201\357\274\232", Q_NULLPTR));
        label_21->setText(QApplication::translate("MainWindow", "26\350\267\257\347\224\265\345\216\213\350\276\223\345\207\272\347\212\266\346\200\201\357\274\232", Q_NULLPTR));
        label_22->setText(QApplication::translate("MainWindow", "26\350\267\257\347\224\265\346\265\201\347\273\223\346\236\234\357\274\232", Q_NULLPTR));
        label_23->setText(QApplication::translate("MainWindow", "26\350\267\257\347\224\265\345\216\213\347\273\223\346\236\234\357\274\232", Q_NULLPTR));
        groupBox_4->setTitle(QApplication::translate("MainWindow", "26\350\267\257DAC", Q_NULLPTR));
        label_6->setText(QApplication::translate("MainWindow", "DAC\351\200\232\351\201\223\357\274\232", Q_NULLPTR));
        comboBox_2->clear();
        comboBox_2->insertItems(0, QStringList()
         << QApplication::translate("MainWindow", "1", Q_NULLPTR)
         << QApplication::translate("MainWindow", "2", Q_NULLPTR)
         << QApplication::translate("MainWindow", "3", Q_NULLPTR)
         << QApplication::translate("MainWindow", "4", Q_NULLPTR)
        );
        label_7->setText(QApplication::translate("MainWindow", "\347\224\265\345\216\213\345\217\202\346\225\260\344\270\200\357\274\232", Q_NULLPTR));
        label_8->setText(QApplication::translate("MainWindow", "\347\224\265\345\216\213\345\217\202\346\225\260\344\272\214\357\274\232", Q_NULLPTR));
        label_17->setText(QApplication::translate("MainWindow", "\347\224\265\345\216\213\345\217\202\346\225\260\344\270\211\357\274\232", Q_NULLPTR));
        label_18->setText(QApplication::translate("MainWindow", "\347\224\265\345\216\213\345\217\202\346\225\260\345\233\233\357\274\232", Q_NULLPTR));
        pushButton->setText(QApplication::translate("MainWindow", "\350\256\276\347\275\256", Q_NULLPTR));
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
