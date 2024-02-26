#pragma once

#include <list>
#include <qpoint.h>
#include <vector>

struct Node
{
	int x;
	int y;
	int value;
	bool visited;
	int conexComponent;

	void SetCoord(const QPoint& position);
	void SetValue(int newValue);
	void setVisited(bool visited);
};

class AdjacencyList
{
public:
	AdjacencyList() = default;
	~AdjacencyList();

	AdjacencyList& operator=(const AdjacencyList& other);

	void SetSelectedNode(Node* newNode);

	std::vector<Node*> GetNodes();
	std::vector<std::list<Node*>> GetAdjacencyList();
	Node* GetNode(int node);
	Node* GetSelectedNode();
	std::list<Node*> GetAdjacencies(int node);

	void AddNode(int x, int y, int value);
	void AddNode(const QPoint& position);
	void AddNeighbor(int node, int neighbor, bool oriented);

	bool DFS();
	int FindConnectedComponents();

private:
	std::vector<Node*> m_nodes;
	std::vector<std::list<Node*>> m_adjacencyList;
	Node* m_selectedNode;

	void DeepCopy(const AdjacencyList& other);
};


