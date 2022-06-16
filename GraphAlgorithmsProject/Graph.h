#pragma once
#include "List.h"
#include "Edge.h"

class Graph
{
public:
	int numberOfVertexes = 0;
	int numberOfEdges = 0;

	List* listArray;
	Edge* edgeArray;

	Graph(int numberOfVertexes);

	void addEdgesManually();
	void fillGraph();
	
	void generateGraphIndirected(int density);

	void printAdjacencyList();

	List* primAlgorithm();
	void printMST(List* list);
};

