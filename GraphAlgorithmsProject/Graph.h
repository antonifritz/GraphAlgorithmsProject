#pragma once
#include<queue>
#include<list>
#include"Edge.h"
#include "Vertex.h"

class Graph
{
public:
	Graph(int size);
	void primAlghorithmMST();

private:
	int size = 0;
	int ** matrix = new int* [size];
	std::queue<Edge> edgeQueue;
	std::queue<Vertex> vertexQueue;
	bool * visited = new bool[size];
	std::vector<Edge> MST;

	void setInfinityMatrix();
	void setVisitedFalse();
	int findAdjacencyVertex(int vertexIndex);
};

