#pragma once
#include "List.h"
#include "Edge.h"

class AdjacencyListGraph
{
public:
	int numberOfVertexes;
	int numberOfEdges;

	List* listArray;
	Edge* edgeArray;

	AdjacencyListGraph(int numberOfVertexes, int numberOfEdges);

	void addEdges();
	void fillGraph();

	void primAlgorithm();
};

