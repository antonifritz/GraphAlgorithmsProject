#pragma once
#include<queue>
#include<list>
#include"Edge.h"

class Graph
{
public:
	Graph(int size);
	void primAlghorithmMST();

private:
	int size;
	int ** matrix = new int* [size];
	std::queue<Edge> edgeQueue;
	bool * visited = new bool[size];
	std::vector<Edge> MST;

	void setZerosMatrix(int size);
	void setVisitedFalse(int size);
};

