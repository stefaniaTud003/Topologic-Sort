#include "TopologicSort.h"
#include <QMessageBox>

TopologicSort::TopologicSort(QWidget *parent)
	: QWidget(parent)
{
	m_TSUI.setupUi(this);
    connect(m_TSUI.pushButton, SIGNAL(clicked()), this, SLOT(DoneButtonClicked()));
}

TopologicSort::~TopologicSort()
{}

void TopologicSort::DoneButtonClicked()
{
    if (!m_adjacencyList.DFS())
        QMessageBox::information(this, "Error", "Graful are circuite! :(");
    else
    {
	    m_sortedWindow = new Sorted(m_adjacencyList);
    	this->hide();
    	m_sortedWindow->show();
    }
}

void TopologicSort::mouseMoveEvent(QMouseEvent* mouseEvent) {
    if (m_adjacencyList.GetSelectedNode() != nullptr) {
        m_adjacencyList.GetSelectedNode()->SetCoord(mouseEvent->pos());
        update();
    }
}

void TopologicSort::mouseReleaseEvent(QMouseEvent* mouseEvent) {
    if (m_adjacencyList.GetSelectedNode() != nullptr) {
        m_adjacencyList.SetSelectedNode(nullptr);
    }
}


void TopologicSort::mousePressEvent(QMouseEvent* mouseEvent)
{
    if (mouseEvent->button() == Qt::RightButton)
    {
        std::vector<Node*> nodes = m_adjacencyList.GetNodes();
        bool overlap = false;

        for (Node* node : nodes)
        {
            if (abs(mouseEvent->pos().x() - node->x) < 20 &&
                abs(mouseEvent->pos().y() - node->y) < 20)
            {
                overlap = true;
                m_adjacencyList.SetSelectedNode(node);
                break;
            }
        }

        if (!overlap)
        {
            m_adjacencyList.AddNode(mouseEvent->pos());
            update();
        }

    }
    else if (mouseEvent->button() == Qt::LeftButton)
    {
        std::vector<Node*> nodes = m_adjacencyList.GetNodes();
        for (Node* node : nodes)
        {
            if (abs(mouseEvent->pos().x() - node->x) < 10 &&
                abs(mouseEvent->pos().y() - node->y) < 10)
            {

                if (m_node == nullptr)
                    m_node = node;
                else
                {
                    m_adjacencyList.AddNeighbor(m_node->value,node->value, true);
                    m_node = nullptr;
                }
                update();
                break;
            }
        }
    }
}

void TopologicSort::paintEvent(QPaintEvent* event)
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