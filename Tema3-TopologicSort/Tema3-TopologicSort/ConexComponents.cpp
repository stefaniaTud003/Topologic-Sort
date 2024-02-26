#include "ConexComponents.h"

#include <QMouseEvent>
#include <QPainter>

ConexComponents::ConexComponents(QWidget *parent)
	: QMainWindow(parent)
{
	ui.setupUi(this);
    connect(ui.pushButton, SIGNAL(clicked()), this, SLOT(DoneButtonClicked()));
}

ConexComponents::~ConexComponents()
{}

void ConexComponents::mouseMoveEvent(QMouseEvent* mouseEvent) {
    if (m_adjacencyList.GetSelectedNode() != nullptr) {
        m_adjacencyList.GetSelectedNode()->SetCoord(mouseEvent->pos());
        update();
    }
}

void ConexComponents::mouseReleaseEvent(QMouseEvent* mouseEvent) {
    if (m_adjacencyList.GetSelectedNode() != nullptr) {
        m_adjacencyList.SetSelectedNode(nullptr);
    }
}


void ConexComponents::mousePressEvent(QMouseEvent* mouseEvent)
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
                    m_adjacencyList.AddNeighbor(m_node->value, node->value, false);
                    m_node = nullptr;
                }
                update();
                break;
            }
        }
    }
}

void ConexComponents::paintEvent(QPaintEvent* event)
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

        }
    }

    DoneButtonClicked();
}

void ConexComponents::DoneButtonClicked()
{
    int numConnectedComponents = m_adjacencyList.FindConnectedComponents();
    std::vector<QColor> componentColors;

    for (int i = 0; i < numConnectedComponents; ++i)
    {
        componentColors.push_back(QColor::fromHsvF((double)i / numConnectedComponents, 1.0, 1.0));
    }

    for (int componentIndex = 0; componentIndex < numConnectedComponents; ++componentIndex)
    {
        QColor currentColor = componentColors[componentIndex % componentColors.size()];

        QPainter paint(this);
        QPen pen(currentColor);
        pen.setWidth(2);
        paint.setPen(pen);

        std::vector<std::list<Node*>> adjacencies = m_adjacencyList.GetAdjacencyList();

        for (int nodeIdx = 0; nodeIdx < adjacencies.size(); ++nodeIdx)
        {
            Node* currentNode = m_adjacencyList.GetNode(nodeIdx);

            if (currentNode->conexComponent == componentIndex)
            {
                for (Node* neighbor : adjacencies[nodeIdx])
                {
                    if (neighbor->conexComponent == componentIndex)
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
                    }
                }
            }
        }
    }
    update();
}
