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
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_CWaveWidget
{
public:
    QVBoxLayout *verticalLayout;
    QHBoxLayout *horizontalLayout;
    QHBoxLayout *horizontalLayout_2;
    QSpacerItem *horizontalSpacer;
    QPushButton *pushButton_open_file;

    void setupUi(QWidget *CWaveWidget)
    {
        if (CWaveWidget->objectName().isEmpty())
            CWaveWidget->setObjectName(QStringLiteral("CWaveWidget"));
        CWaveWidget->resize(685, 451);
        verticalLayout = new QVBoxLayout(CWaveWidget);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));

        verticalLayout->addLayout(horizontalLayout);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_2->addItem(horizontalSpacer);

        pushButton_open_file = new QPushButton(CWaveWidget);
        pushButton_open_file->setObjectName(QStringLiteral("pushButton_open_file"));
        pushButton_open_file->setMinimumSize(QSize(80, 0));

        horizontalLayout_2->addWidget(pushButton_open_file);


        verticalLayout->addLayout(horizontalLayout_2);


        retranslateUi(CWaveWidget);

        QMetaObject::connectSlotsByName(CWaveWidget);
    } // setupUi

    void retranslateUi(QWidget *CWaveWidget)
    {
        CWaveWidget->setWindowTitle(QApplication::translate("CWaveWidget", "Form", Q_NULLPTR));
        pushButton_open_file->setText(QApplication::translate("CWaveWidget", "\346\265\217\350\247\210", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class CWaveWidget: public Ui_CWaveWidget {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CWAVEWIDGET_H
