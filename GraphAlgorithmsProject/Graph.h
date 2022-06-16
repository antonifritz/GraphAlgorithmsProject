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

	void addEdges();
	void addEdgesManually();
	void fillGraph();
	
	void generateGraphIndirected(int density);

	List* primAlgorithm();
	void printMST(List* list);
};

