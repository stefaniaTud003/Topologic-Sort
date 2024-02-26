#pragma once

#include <QtWidgets/QMainWindow>

#include "TopologicSort.h"
#include "ConexComponents.h"
#include "ui_MainWindow.h"

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

    QPushButton* pushButton;
    QPushButton* pushButton2;

private slots:
    void ButtonScreen1Clicked();
    void ButtonScreen2Clicked();

private:
    Ui::MainWindowClass ui;
    TopologicSort *m_TS;
    ConexComponents* m_CC;
};
