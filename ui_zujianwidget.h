/********************************************************************************
** Form generated from reading UI file 'zujianwidget.ui'
**
** Created by: Qt User Interface Compiler version 5.8.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_ZUJIANWIDGET_H
#define UI_ZUJIANWIDGET_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QFrame>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QScrollArea>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_ZuJianWidget
{
public:
    QVBoxLayout *verticalLayout;
    QPushButton *pushButton;
    QFrame *line;
    QScrollArea *scrollArea;
    QWidget *widget;

    void setupUi(QWidget *ZuJianWidget)
    {
        if (ZuJianWidget->objectName().isEmpty())
            ZuJianWidget->setObjectName(QStringLiteral("ZuJianWidget"));
        ZuJianWidget->resize(150, 469);
        QSizePolicy sizePolicy(QSizePolicy::Preferred, QSizePolicy::Preferred);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(ZuJianWidget->sizePolicy().hasHeightForWidth());
        ZuJianWidget->setSizePolicy(sizePolicy);
        verticalLayout = new QVBoxLayout(ZuJianWidget);
        verticalLayout->setSpacing(2);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        pushButton = new QPushButton(ZuJianWidget);
        pushButton->setObjectName(QStringLiteral("pushButton"));
        pushButton->setStyleSheet(QStringLiteral(""));

        verticalLayout->addWidget(pushButton);

        line = new QFrame(ZuJianWidget);
        line->setObjectName(QStringLiteral("line"));
        line->setFrameShape(QFrame::HLine);
        line->setFrameShadow(QFrame::Sunken);

        verticalLayout->addWidget(line);

        scrollArea = new QScrollArea(ZuJianWidget);
        scrollArea->setObjectName(QStringLiteral("scrollArea"));
        scrollArea->setEnabled(true);
        scrollArea->setStyleSheet(QStringLiteral(""));
        scrollArea->setWidgetResizable(true);
        widget = new QWidget();
        widget->setObjectName(QStringLiteral("widget"));
        widget->setGeometry(QRect(0, 0, 148, 434));
        widget->setStyleSheet(QStringLiteral(""));
        scrollArea->setWidget(widget);

        verticalLayout->addWidget(scrollArea);


        retranslateUi(ZuJianWidget);

        QMetaObject::connectSlotsByName(ZuJianWidget);
    } // setupUi

    void retranslateUi(QWidget *ZuJianWidget)
    {
        ZuJianWidget->setWindowTitle(QApplication::translate("ZuJianWidget", "Form", Q_NULLPTR));
        pushButton->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class ZuJianWidget: public Ui_ZuJianWidget {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_ZUJIANWIDGET_H
