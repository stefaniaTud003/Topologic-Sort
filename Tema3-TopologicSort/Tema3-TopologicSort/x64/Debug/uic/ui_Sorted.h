/********************************************************************************
** Form generated from reading UI file 'Sorted.ui'
**
** Created by: Qt User Interface Compiler version 6.6.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_SORTED_H
#define UI_SORTED_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_SortedClass
{
public:

    void setupUi(QWidget *SortedClass)
    {
        if (SortedClass->objectName().isEmpty())
            SortedClass->setObjectName("SortedClass");
        SortedClass->resize(600, 400);

        retranslateUi(SortedClass);

        QMetaObject::connectSlotsByName(SortedClass);
    } // setupUi

    void retranslateUi(QWidget *SortedClass)
    {
        SortedClass->setWindowTitle(QCoreApplication::translate("SortedClass", "Sorted", nullptr));
    } // retranslateUi

};

namespace Ui {
    class SortedClass: public Ui_SortedClass {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_SORTED_H
