#pragma once
#include<list>
#include "edge.h"
class adjacencyListGraph
{
public:
	int numberOfVertexes;
	std::list<int>* adjacencyList;
	std::list<edge>* edgeList;

	adjacencyListGraph(int numberOfVertexes);

	void addEdges();
	void fillGraph();
};

