#pragma once

#include <QWidget>
#include "ui_Sorted.h"
#include "AdjacencyList.h"

class Sorted : public QWidget
{
	Q_OBJECT

public:
	Sorted(AdjacencyList& adjacencyList, QWidget *parent = nullptr);
	~Sorted();

	void paintEvent(QPaintEvent* paintEvent);

private:
	Ui::SortedClass ui;
	AdjacencyList m_adjacencyList;
};
