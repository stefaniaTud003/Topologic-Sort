#include "Sorted.h"

#include <QPainter>

Sorted::Sorted(AdjacencyList& adjacencyList,QWidget *parent)
	: QWidget(parent)
{
	ui.setupUi(this);
    m_adjacencyList = adjacencyList;
}

Sorted::~Sorted()
{}

void Sorted::paintEvent(QPaintEvent* paintEvent)
{
    QPainter paint(this);
    std::vector<Node*> nodes = m_adjacencyList.GetNodes();

    for (Node* node : nodes)
    {
        QRect rectangle(node->x - 10, node->y - 10, 20, 20);
        paint.drawEllipse(rectangle);
        QString string;
        string.setNum(node->value);
        paint.drawText(rectangle, Qt::AlignCenter, string);
    }


    std::vector<std::list<Node*>> adjacencies = m_adjacencyList.GetAdjacencyList();
    for (int nodeIdx = 0; nodeIdx < adjacencies.size(); ++nodeIdx)
    {
        Node* currentNode = m_adjacencyList.GetNode(nodeIdx);

        for (Node* neighbor : adjacencies[nodeIdx])
        {
            QPoint firstPoint(currentNode->x, currentNode->y);
            QPoint secondPoint(neighbor->x, neighbor->y);

            paint.drawLine(firstPoint, secondPoint);

            double arrowLength = 8;
            double angle = atan2(secondPoint.y() - firstPoint.y(), secondPoint.x() - firstPoint.x());
            QPoint arrowPoint(
                secondPoint.x() - arrowLength * cos(angle),
                secondPoint.y() - arrowLength * sin(angle)
            );

            paint.drawLine(secondPoint, arrowPoint);

            int arrowSize = 10;
            QPoint arrowP1(arrowPoint.x() - arrowSize * cos(angle - M_PI / 6), arrowPoint.y() - arrowSize * sin(angle - M_PI / 6));
            QPoint arrowP2(arrowPoint.x() - arrowSize * cos(angle + M_PI / 6), arrowPoint.y() - arrowSize * sin(angle + M_PI / 6));
            paint.drawLine(arrowPoint, arrowP1);
            paint.drawLine(arrowPoint, arrowP2);
        }
    }
}
