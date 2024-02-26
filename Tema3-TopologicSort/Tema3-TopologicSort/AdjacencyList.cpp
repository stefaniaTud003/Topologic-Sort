#include "AdjacencyList.h"

#include <algorithm>
#include <fstream>
#include <stack>
#include <unordered_map>

void Node::SetCoord(const QPoint& position)
{
    this->x = position.x();
    this->y = position.y();
}

void Node::SetValue(int newValue)
{
    this->value = newValue;
}

void Node::setVisited(bool visited)
{
    this->visited = visited;
}

AdjacencyList::~AdjacencyList()
{
    for (const Node* node : m_nodes)
    {
        delete node;
    }
}

AdjacencyList& AdjacencyList::operator=(const AdjacencyList& other)
{
    if (this != &other)
    {
        // Clear existing data
        for (const Node* node : m_nodes)
        {
            delete node;
        }
        m_nodes.clear();
        m_adjacencyList.clear();

        // Deep copy nodes and adjacency lists from 'other'
        DeepCopy(other);
    }

    return *this;
}

void AdjacencyList::SetSelectedNode(Node* newNode)
{
    m_selectedNode = newNode;
}

std::vector<Node*> AdjacencyList::GetNodes()
{
    return m_nodes;
}

std::vector<std::list<Node*>> AdjacencyList::GetAdjacencyList()
{
    return m_adjacencyList;
}

Node* AdjacencyList::GetNode(int node)
{
    if (m_nodes.size() == 0) return nullptr;
    return m_nodes[node];
}

Node* AdjacencyList::GetSelectedNode()
{
    return m_selectedNode;
}

std::list<Node*> AdjacencyList::GetAdjacencies(int node)
{
    return m_adjacencyList[node];
}

void AdjacencyList::AddNode(const int x, const int y, const int value)
{
    Node* newNode = new Node{ x, y, value };
    m_nodes.push_back(newNode);
    m_adjacencyList.emplace_back(); 

}

void AdjacencyList::AddNode(const QPoint& position)
{
    AddNode(position.x(), position.y(), m_nodes.size());
}

void AdjacencyList::AddNeighbor(int node, int neighbor, bool oriented)
{
    m_adjacencyList[node].push_back(m_nodes[neighbor]);

    if(!oriented)
        m_adjacencyList[neighbor].push_back(m_nodes[node]);
}

bool AdjacencyList::DFS()
{
    AdjacencyList adjacency;
    int t = 1;
    int kNodes = m_nodes.size();
    std::stack<Node*> nodeStack;
    std::stack<Node*> tempNodeStack;
    std::vector<bool> visited;
    std::vector<int> startTime;
    std::vector<int> endTime;
    std::vector<bool> state;
    visited.resize(kNodes, false);
    startTime.resize(kNodes, 0);
    endTime.resize(kNodes, 0);
    state.resize(kNodes, false);

    // Ensure all nodes are added to the adjacency list
    for (Node* node : m_nodes)
    {
        adjacency.AddNode(node->x, node->y, node->value);
    }

    Node* startNode = m_nodes[0];
    visited.at(startNode->value) = true;
    startTime.at(startNode->value) = t++;
    nodeStack.push(startNode);
    startNode->setVisited(false);

    while (!nodeStack.empty())
    {
        Node* currentNode = nodeStack.top();
        state.at(currentNode->value) = true;
        bool exists = false;

        for (Node* neighbor : m_adjacencyList[currentNode->value])
        {
            if (!visited.at(neighbor->value))
            {
                if (adjacency.GetNode(currentNode->value) != nullptr && adjacency.GetNode(neighbor->value) != nullptr)
                {
                    adjacency.AddNeighbor(currentNode->value, neighbor->value, true);
                }

                neighbor->setVisited(false);
                nodeStack.push(neighbor);
                visited.at(neighbor->value) = true;
                startTime.at(neighbor->value) = t++;
                exists = true;
                break;
            }
            else
            {
                tempNodeStack = nodeStack;
                while (!tempNodeStack.empty())
                {
                    if (neighbor->value == tempNodeStack.top()->value)
                        return false;
                    tempNodeStack.pop();
                }
            }
        }

        if (!exists)
        {
            nodeStack.pop();
            endTime.at(currentNode->value) = t++;
        }

        if (nodeStack.empty())
        {
            for (Node* nodes : m_nodes)
            {
                if (!visited.at(nodes->value))
                {
                    visited.at(nodes->value) = true;
                    nodeStack.push(nodes);
                    nodes->setVisited(false);
                    startTime.at(nodes->value) = t++;
                    break;
                }
            }
        }
    }

    std::vector<std::pair<int, int>> nodeTimes;
    for (int i = 0; i < kNodes; ++i) {
        nodeTimes.push_back(std::make_pair(i, endTime.at(i)));
    }

    std::sort(nodeTimes.begin(), nodeTimes.end(), [](const auto& a, const auto& b) {
        return a.second > b.second;
        });

    std::ofstream file("out.txt");
    file << "Sortare topologica: ";
    for (const auto& node : nodeTimes)
    {
        file << node.first << " ";
    }

	*this = adjacency;

    return true;
}

void AdjacencyList::DeepCopy(const AdjacencyList& other)
{
    for (const Node* node : other.m_nodes)
    {
        Node* newNode = new Node{ node->x, node->y, node->value, node->visited };
        m_nodes.push_back(newNode);
    }

    for (const std::list<Node*>& adjList : other.m_adjacencyList)
    {
        std::list<Node*> newList;
        for (const Node* node : adjList)
        {
            if (node->value < m_nodes.size()) {
                newList.push_back(m_nodes[node->value]);
            }
        }
        m_adjacencyList.push_back(newList);
    }
}

int AdjacencyList::FindConnectedComponents()
{
    std::vector<bool> visited(m_nodes.size(), false);
    int conexComponentIndex = 0;

    for (Node* startNode : m_nodes)
    {
        if (!visited[startNode->value])
        {
            std::stack<Node*> nodeStack;

            nodeStack.push(startNode);
            visited[startNode->value] = true;
            startNode->conexComponent = conexComponentIndex;

            while (!nodeStack.empty())
            {
                Node* currentNode = nodeStack.top();
                nodeStack.pop();

                for (Node* neighbor : GetAdjacencies(currentNode->value))
                {
                    if (!visited[neighbor->value])
                    {
                        visited[neighbor->value] = true;
                        nodeStack.push(neighbor);

                        neighbor->conexComponent = conexComponentIndex;
                    }
                }
            }

            conexComponentIndex++;
        }
    }

    
    return conexComponentIndex;
}