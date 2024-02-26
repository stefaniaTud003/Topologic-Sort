/********************************************************************************
** Form generated from reading UI file 'ConexComponents.ui'
**
** Created by: Qt User Interface Compiler version 6.6.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_CONEXCOMPONENTS_H
#define UI_CONEXCOMPONENTS_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_ConexComponentsClass
{
public:
    QWidget *centralWidget;
    QPushButton *pushButton;
    QMenuBar *menuBar;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *ConexComponentsClass)
    {
        if (ConexComponentsClass->objectName().isEmpty())
            ConexComponentsClass->setObjectName("ConexComponentsClass");
        ConexComponentsClass->resize(600, 400);
        centralWidget = new QWidget(ConexComponentsClass);
        centralWidget->setObjectName("centralWidget");
        pushButton = new QPushButton(centralWidget);
        pushButton->setObjectName("pushButton");
        pushButton->setGeometry(QRect(240, 290, 75, 24));
        ConexComponentsClass->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(ConexComponentsClass);
        menuBar->setObjectName("menuBar");
        menuBar->setGeometry(QRect(0, 0, 600, 22));
        ConexComponentsClass->setMenuBar(menuBar);
        mainToolBar = new QToolBar(ConexComponentsClass);
        mainToolBar->setObjectName("mainToolBar");
        ConexComponentsClass->addToolBar(Qt::TopToolBarArea, mainToolBar);
        statusBar = new QStatusBar(ConexComponentsClass);
        statusBar->setObjectName("statusBar");
        ConexComponentsClass->setStatusBar(statusBar);

        retranslateUi(ConexComponentsClass);

        QMetaObject::connectSlotsByName(ConexComponentsClass);
    } // setupUi

    void retranslateUi(QMainWindow *ConexComponentsClass)
    {
        ConexComponentsClass->setWindowTitle(QCoreApplication::translate("ConexComponentsClass", "ConexComponents", nullptr));
        pushButton->setText(QCoreApplication::translate("ConexComponentsClass", "Done", nullptr));
    } // retranslateUi

};

namespace Ui {
    class ConexComponentsClass: public Ui_ConexComponentsClass {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CONEXCOMPONENTS_H
