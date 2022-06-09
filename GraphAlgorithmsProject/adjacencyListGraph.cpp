#include "adjacencyListGraph.h"

adjacencyListGraph::adjacencyListGraph(int numberOfVertexes)
{
	this->numberOfVertexes = numberOfVertexes;
	this->adjacencyList = new std::list<int> [numberOfVertexes];
	this->edgeList = new std::list<edge>;
}

void adjacencyListGraph::fillGraph()
{
	std::list<edge>::iterator it;
	
	for (it = this->edgeList->begin(); it != this->edgeList->end(); it++)
	{
		this->adjacencyList[it->vertex].push_back(it->destinationVertex);
	}
}

void adjacencyListGraph::addEdges()
{
	edge* edge1 = new edge();

	edge1->vertex = 0;
	edge1->destinationVertex = 1;
	edge1->weight = 2;

	edge* edge2 = new edge();

	edge2->vertex = 0;
	edge2->destinationVertex = 2;
	edge2->weight = 1;

	edge* edge3 = new edge();

	edge3->vertex = 2;
	edge3->destinationVertex = 3;
	edge3->weight = 3;

	edge* edge4 = new edge();

	edge4->vertex = 2;
	edge4->destinationVertex = 1;
	edge4->weight = 3;

	edge* edge5 = new edge();

	edge5->vertex = 2;
	edge5->destinationVertex = 3;
	edge5->weight = 3;

	this->edgeList->push_back(*edge1);
	this->edgeList->push_back(*edge2);
	this->edgeList->push_back(*edge3);
	this->edgeList->push_back(*edge4);
	this->edgeList->push_back(*edge5);
}
