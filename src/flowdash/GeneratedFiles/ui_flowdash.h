/********************************************************************************
** Form generated from reading UI file 'flowdash.ui'
**
** Created by: Qt User Interface Compiler version 5.6.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_FLOWDASH_H
#define UI_FLOWDASH_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_flowdashClass
{
public:
    QMenuBar *menuBar;
    QToolBar *mainToolBar;
    QWidget *centralWidget;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *flowdashClass)
    {
        if (flowdashClass->objectName().isEmpty())
            flowdashClass->setObjectName(QStringLiteral("flowdashClass"));
        flowdashClass->resize(600, 400);
        menuBar = new QMenuBar(flowdashClass);
        menuBar->setObjectName(QStringLiteral("menuBar"));
        flowdashClass->setMenuBar(menuBar);
        mainToolBar = new QToolBar(flowdashClass);
        mainToolBar->setObjectName(QStringLiteral("mainToolBar"));
        flowdashClass->addToolBar(mainToolBar);
        centralWidget = new QWidget(flowdashClass);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        flowdashClass->setCentralWidget(centralWidget);
        statusBar = new QStatusBar(flowdashClass);
        statusBar->setObjectName(QStringLiteral("statusBar"));
        flowdashClass->setStatusBar(statusBar);

        retranslateUi(flowdashClass);

        QMetaObject::connectSlotsByName(flowdashClass);
    } // setupUi

    void retranslateUi(QMainWindow *flowdashClass)
    {
        flowdashClass->setWindowTitle(QApplication::translate("flowdashClass", "flowdash", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class flowdashClass: public Ui_flowdashClass {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_FLOWDASH_H
