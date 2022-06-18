#pragma once
#include "List.h"
#include "Edge.h"

class Graph
{
public:
	int numberOfVertexes = 0;
	int numberOfEdges = 0;

	List* listArray;
	Edge* MST;
	Edge* edgeArray;

	int** incidenceMatrix;
	int** adjacencyMatrix;

	Graph(int numberOfVertexes);
	Graph() {};
	Graph(int numberOfEdges, int numberOfVertexes);
	~Graph();

	void addEdgesManually();
	void fillAdjacencyList();
	void fillIncidenceMatrixIndirected();
	
	void generateGraphIndirected(int density);

	void printIncidenceMatrix();
	void printAdjacencyMatrix();
	void printAdjacencyList();

	void primAlgorithmAdjacencyList();
	void primAlgorithmIncidenceMatrix();
	void primAlgorithmAdjacencyMatrix();
	void printMST();
};

