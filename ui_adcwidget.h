/********************************************************************************
** Form generated from reading UI file 'adcwidget.ui'
**
** Created by: Qt User Interface Compiler version 5.8.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_ADCWIDGET_H
#define UI_ADCWIDGET_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QFrame>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_AdcWidget
{
public:
    QVBoxLayout *verticalLayout;
    QFrame *frame;
    QHBoxLayout *horizontalLayout;
    QSpacerItem *horizontalSpacer;
    QLabel *label_icon_title;
    QLabel *label_title;
    QSpacerItem *horizontalSpacer_2;
    QFrame *frame_2;
    QGridLayout *gridLayout;
    QLabel *label_icon_dianya;
    QLabel *label_4;
    QLabel *label_dianya;
    QLabel *label_icon_dianliu;
    QLabel *label_5;
    QLabel *label_dianliu;
    QLabel *label;
    QLineEdit *lineEdit;
    QPushButton *pushButton;

    void setupUi(QWidget *AdcWidget)
    {
        if (AdcWidget->objectName().isEmpty())
            AdcWidget->setObjectName(QStringLiteral("AdcWidget"));
        AdcWidget->resize(125, 125);
        AdcWidget->setStyleSheet(QStringLiteral(""));
        verticalLayout = new QVBoxLayout(AdcWidget);
        verticalLayout->setSpacing(0);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        frame = new QFrame(AdcWidget);
        frame->setObjectName(QStringLiteral("frame"));
        frame->setStyleSheet(QStringLiteral(""));
        frame->setFrameShape(QFrame::StyledPanel);
        frame->setFrameShadow(QFrame::Raised);
        horizontalLayout = new QHBoxLayout(frame);
        horizontalLayout->setSpacing(2);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        horizontalLayout->setContentsMargins(0, 0, 0, 0);
        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer);

        label_icon_title = new QLabel(frame);
        label_icon_title->setObjectName(QStringLiteral("label_icon_title"));
        QSizePolicy sizePolicy(QSizePolicy::Preferred, QSizePolicy::Preferred);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(label_icon_title->sizePolicy().hasHeightForWidth());
        label_icon_title->setSizePolicy(sizePolicy);
        label_icon_title->setMinimumSize(QSize(0, 0));
        label_icon_title->setStyleSheet(QStringLiteral("border:none"));

        horizontalLayout->addWidget(label_icon_title);

        label_title = new QLabel(frame);
        label_title->setObjectName(QStringLiteral("label_title"));
        sizePolicy.setHeightForWidth(label_title->sizePolicy().hasHeightForWidth());
        label_title->setSizePolicy(sizePolicy);
        label_title->setStyleSheet(QStringLiteral("border:none;"));

        horizontalLayout->addWidget(label_title);

        horizontalSpacer_2 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer_2);


        verticalLayout->addWidget(frame);

        frame_2 = new QFrame(AdcWidget);
        frame_2->setObjectName(QStringLiteral("frame_2"));
        QSizePolicy sizePolicy1(QSizePolicy::Preferred, QSizePolicy::Expanding);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(frame_2->sizePolicy().hasHeightForWidth());
        frame_2->setSizePolicy(sizePolicy1);
        frame_2->setStyleSheet(QStringLiteral(""));
        frame_2->setFrameShape(QFrame::StyledPanel);
        frame_2->setFrameShadow(QFrame::Raised);
        gridLayout = new QGridLayout(frame_2);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        label_icon_dianya = new QLabel(frame_2);
        label_icon_dianya->setObjectName(QStringLiteral("label_icon_dianya"));
        label_icon_dianya->setAlignment(Qt::AlignCenter);

        gridLayout->addWidget(label_icon_dianya, 0, 0, 1, 1);

        label_4 = new QLabel(frame_2);
        label_4->setObjectName(QStringLiteral("label_4"));
        label_4->setAlignment(Qt::AlignCenter);

        gridLayout->addWidget(label_4, 0, 1, 1, 1);

        label_dianya = new QLabel(frame_2);
        label_dianya->setObjectName(QStringLiteral("label_dianya"));
        sizePolicy.setHeightForWidth(label_dianya->sizePolicy().hasHeightForWidth());
        label_dianya->setSizePolicy(sizePolicy);
        label_dianya->setAlignment(Qt::AlignCenter);

        gridLayout->addWidget(label_dianya, 0, 2, 1, 1);

        label_icon_dianliu = new QLabel(frame_2);
        label_icon_dianliu->setObjectName(QStringLiteral("label_icon_dianliu"));
        label_icon_dianliu->setAlignment(Qt::AlignCenter);

        gridLayout->addWidget(label_icon_dianliu, 1, 0, 1, 1);

        label_5 = new QLabel(frame_2);
        label_5->setObjectName(QStringLiteral("label_5"));
        label_5->setAlignment(Qt::AlignCenter);

        gridLayout->addWidget(label_5, 1, 1, 1, 1);

        label_dianliu = new QLabel(frame_2);
        label_dianliu->setObjectName(QStringLiteral("label_dianliu"));
        sizePolicy.setHeightForWidth(label_dianliu->sizePolicy().hasHeightForWidth());
        label_dianliu->setSizePolicy(sizePolicy);
        label_dianliu->setAlignment(Qt::AlignCenter);

        gridLayout->addWidget(label_dianliu, 1, 2, 1, 1);

        label = new QLabel(frame_2);
        label->setObjectName(QStringLiteral("label"));
        label->setAlignment(Qt::AlignCenter);

        gridLayout->addWidget(label, 2, 1, 1, 1);

        lineEdit = new QLineEdit(frame_2);
        lineEdit->setObjectName(QStringLiteral("lineEdit"));
        QSizePolicy sizePolicy2(QSizePolicy::Maximum, QSizePolicy::Fixed);
        sizePolicy2.setHorizontalStretch(0);
        sizePolicy2.setVerticalStretch(0);
        sizePolicy2.setHeightForWidth(lineEdit->sizePolicy().hasHeightForWidth());
        lineEdit->setSizePolicy(sizePolicy2);
        lineEdit->setMaximumSize(QSize(65, 16));
        lineEdit->setStyleSheet(QStringLiteral(""));

        gridLayout->addWidget(lineEdit, 2, 2, 1, 1);

        pushButton = new QPushButton(frame_2);
        pushButton->setObjectName(QStringLiteral("pushButton"));
        pushButton->setStyleSheet(QStringLiteral(""));

        gridLayout->addWidget(pushButton, 3, 0, 1, 3);


        verticalLayout->addWidget(frame_2);


        retranslateUi(AdcWidget);

        QMetaObject::connectSlotsByName(AdcWidget);
    } // setupUi

    void retranslateUi(QWidget *AdcWidget)
    {
        AdcWidget->setWindowTitle(QApplication::translate("AdcWidget", "Form", Q_NULLPTR));
        label_icon_title->setText(QString());
        label_title->setText(QApplication::translate("AdcWidget", "ADC1", Q_NULLPTR));
        label_icon_dianya->setText(QString());
        label_4->setText(QApplication::translate("AdcWidget", "\347\224\265\345\216\213\357\274\232", Q_NULLPTR));
        label_dianya->setText(QApplication::translate("AdcWidget", "25v", Q_NULLPTR));
        label_icon_dianliu->setText(QString());
        label_5->setText(QApplication::translate("AdcWidget", "\347\224\265\346\265\201\357\274\232", Q_NULLPTR));
        label_dianliu->setText(QApplication::translate("AdcWidget", "32a", Q_NULLPTR));
        label->setText(QApplication::translate("AdcWidget", "\347\224\265\345\216\213\357\274\232", Q_NULLPTR));
        lineEdit->setText(QApplication::translate("AdcWidget", "0.0", Q_NULLPTR));
        pushButton->setText(QApplication::translate("AdcWidget", "\346\211\223\345\274\200", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class AdcWidget: public Ui_AdcWidget {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_ADCWIDGET_H
