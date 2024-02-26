#pragma once

#include <QMainWindow>
#include <QPushButton>

#include "ui_ConexComponents.h"
#include "AdjacencyList.h"

class ConexComponents : public QMainWindow
{
	Q_OBJECT

public:
	ConexComponents(QWidget *parent = nullptr);
	~ConexComponents();

	QPushButton* pushButton;

	void mouseMoveEvent(QMouseEvent* mouseEvent);
	void mouseReleaseEvent(QMouseEvent* mouseEvent);
	void mousePressEvent(QMouseEvent* mouseEvent);
	void paintEvent(QPaintEvent* event);

private slots:
	void DoneButtonClicked();

private:
	Ui::ConexComponentsClass ui;

	AdjacencyList m_adjacencyList;
	Node* m_node{};
};
