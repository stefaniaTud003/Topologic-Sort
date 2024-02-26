#pragma once

#include <QPushButton>
#include <QWidget>
#include <QMouseEvent>
#include <QPainter>
#include "ui_TopologicSort.h"
#include "Sorted.h"
#include "AdjacencyList.h"

class TopologicSort : public QWidget
{
	Q_OBJECT

public:
	TopologicSort(QWidget *parent = nullptr);
	~TopologicSort();

	QPushButton* pushButton;

	void mouseMoveEvent(QMouseEvent* mouseEvent);
	void mouseReleaseEvent(QMouseEvent* mouseEvent);
	void mousePressEvent(QMouseEvent* mouseEvent);
	void paintEvent(QPaintEvent* event);

private slots:
	void DoneButtonClicked();

private:
	Ui::TopologicSortClass m_TSUI;
	Sorted* m_sortedWindow;

	AdjacencyList m_adjacencyList;
	Node* m_node{};
};
