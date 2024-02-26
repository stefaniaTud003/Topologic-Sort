#include "MainWindow.h"
#include "TopologicSort.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
{
    ui.setupUi(this);
    connect(ui.pushButton, SIGNAL(clicked()), this, SLOT(ButtonScreen1Clicked()));
    connect(ui.pushButton2, SIGNAL(clicked()), this, SLOT(ButtonScreen2Clicked()));

}

MainWindow::~MainWindow()
{}

void MainWindow::ButtonScreen1Clicked()
{
    m_TS = new TopologicSort;

    this->hide();
    m_TS->show();
}

void MainWindow::ButtonScreen2Clicked()
{
    m_CC = new ConexComponents;

    this->hide();
    m_CC->show();
}

