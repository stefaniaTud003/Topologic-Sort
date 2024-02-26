/********************************************************************************
** Form generated from reading UI file 'TopologicSort.ui'
**
** Created by: Qt User Interface Compiler version 6.6.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_TOPOLOGICSORT_H
#define UI_TOPOLOGICSORT_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_TopologicSortClass
{
public:
    QPushButton *pushButton;

    void setupUi(QWidget *TopologicSortClass)
    {
        if (TopologicSortClass->objectName().isEmpty())
            TopologicSortClass->setObjectName("TopologicSortClass");
        TopologicSortClass->resize(600, 400);
        pushButton = new QPushButton(TopologicSortClass);
        pushButton->setObjectName("pushButton");
        pushButton->setGeometry(QRect(250, 290, 75, 24));

        retranslateUi(TopologicSortClass);

        QMetaObject::connectSlotsByName(TopologicSortClass);
    } // setupUi

    void retranslateUi(QWidget *TopologicSortClass)
    {
        TopologicSortClass->setWindowTitle(QCoreApplication::translate("TopologicSortClass", "TopologicSort", nullptr));
        pushButton->setText(QCoreApplication::translate("TopologicSortClass", "Done", nullptr));
    } // retranslateUi

};

namespace Ui {
    class TopologicSortClass: public Ui_TopologicSortClass {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_TOPOLOGICSORT_H
