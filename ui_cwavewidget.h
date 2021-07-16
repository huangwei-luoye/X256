/********************************************************************************
** Form generated from reading UI file 'cwavewidget.ui'
**
** Created by: Qt User Interface Compiler version 5.8.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_CWAVEWIDGET_H
#define UI_CWAVEWIDGET_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_CWaveWidget
{
public:
    QVBoxLayout *verticalLayout;
    QWidget *widget;
    QHBoxLayout *horizontalLayout_1;
    QSpacerItem *horizontalSpacer;
    QLabel *label;
    QComboBox *comboBox;
    QSpacerItem *horizontalSpacer_2;

    void setupUi(QWidget *CWaveWidget)
    {
        if (CWaveWidget->objectName().isEmpty())
            CWaveWidget->setObjectName(QStringLiteral("CWaveWidget"));
        CWaveWidget->resize(694, 476);
        CWaveWidget->setAutoFillBackground(false);
        CWaveWidget->setStyleSheet(QStringLiteral(""));
        verticalLayout = new QVBoxLayout(CWaveWidget);
        verticalLayout->setSpacing(0);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        widget = new QWidget(CWaveWidget);
        widget->setObjectName(QStringLiteral("widget"));
        widget->setStyleSheet(QStringLiteral("background-color: rgb(0,0,255,0);"));

        verticalLayout->addWidget(widget);

        horizontalLayout_1 = new QHBoxLayout();
        horizontalLayout_1->setObjectName(QStringLiteral("horizontalLayout_1"));
        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_1->addItem(horizontalSpacer);

        label = new QLabel(CWaveWidget);
        label->setObjectName(QStringLiteral("label"));
        label->setMinimumSize(QSize(0, 0));

        horizontalLayout_1->addWidget(label);

        comboBox = new QComboBox(CWaveWidget);
        comboBox->setObjectName(QStringLiteral("comboBox"));
        comboBox->setMinimumSize(QSize(80, 0));

        horizontalLayout_1->addWidget(comboBox);

        horizontalSpacer_2 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_1->addItem(horizontalSpacer_2);


        verticalLayout->addLayout(horizontalLayout_1);


        retranslateUi(CWaveWidget);

        QMetaObject::connectSlotsByName(CWaveWidget);
    } // setupUi

    void retranslateUi(QWidget *CWaveWidget)
    {
        CWaveWidget->setWindowTitle(QApplication::translate("CWaveWidget", "Form", Q_NULLPTR));
        label->setText(QApplication::translate("CWaveWidget", "\346\230\276\347\244\272\351\200\232\351\201\223\357\274\232", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class CWaveWidget: public Ui_CWaveWidget {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CWAVEWIDGET_H
