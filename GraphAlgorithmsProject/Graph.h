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

	int* predessor = nullptr;
	int* distance = nullptr;

	int** incidenceMatrix;
	int** adjacencyMatrix;

	Graph(int numberOfVertexes);
	Graph() {};
	Graph(int numberOfEdges, int numberOfVertexes);
	~Graph();

	void addEdgesManually();
	void fillAdjacencyListIndirected();
	void fillAdjacencyMatrixIndirected();
	void fillIncidenceMatrixIndirected();
	void fillAdjacencyMatrixDirected();
	void fillAdjacencyListDirected();
	
	void generateGraphIndirected(int density);
	void generateGraphDirected(int density);

	void printIncidenceMatrix();
	void printAdjacencyMatrix();
	void printAdjacencyList();

	void primAlgorithmAdjacencyList();
	void primAlgorithmIncidenceMatrix();
	void primAlgorithmAdjacencyMatrix();
	void dijkstraAlgorithmAdjacencyMatrix();
	void dijkstraAlgorithmAdjacencyList();
	void printMST();
	void printShortestPaths();
	int minDistance(int distance[], bool isSet[]);
	void printPath(int j);
};

