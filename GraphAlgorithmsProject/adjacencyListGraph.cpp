#include "AdjacencyListGraph.h"
#include "Heap.h"
#include "List.h"
#include "ListElement.h"

AdjacencyListGraph::AdjacencyListGraph(int numberOfVertexes, int numberOfEdges)
{
	this->numberOfEdges = numberOfEdges;
	this->numberOfVertexes = numberOfVertexes;
	listArray = new List[numberOfVertexes];
	edgeArray = new Edge[numberOfEdges];
}

void AdjacencyListGraph::fillGraph()
{
	for (int i = 0; i < numberOfEdges; i++)
	{
		if (listArray[edgeArray[i].vertex].listSize == 0)
		{
			listArray[edgeArray[i].vertex].head = new ListElement(&edgeArray[i]);
			listArray[edgeArray[i].vertex].listSize++;
		}
		else {
			listArray[edgeArray[i].vertex].insertListBeginning(new ListElement(&edgeArray[i]));
		}
	}
}

void AdjacencyListGraph::addEdges()
{
	Edge* edge1 = new Edge();

	edge1->vertex = 0;
	edge1->destinationVertex = 1;
	edge1->weight = 1;

	Edge* edge2 = new Edge();

	edge2->vertex = 0;
	edge2->destinationVertex = 3;
	edge2->weight = 2;

	Edge* edge3 = new Edge();

	edge3->vertex = 0;
	edge3->destinationVertex = 2;
	edge3->weight = 4;

	Edge* edge4 = new Edge();

	edge4->vertex = 1;
	edge4->destinationVertex = 2;
	edge4->weight = 2;

	Edge* edge5 = new Edge();

	edge5->vertex = 2;
	edge5->destinationVertex = 4;
	edge5->weight = 5;

	Edge* edge6 = new Edge();

	edge6->vertex = 4;
	edge6->destinationVertex = 3;
	edge6->weight = 6;

	edgeArray[0] = *edge1;
	edgeArray[1] = *edge2;
	edgeArray[2] = *edge3;
	edgeArray[3] = *edge4;
	edgeArray[4] = *edge5;
	edgeArray[5] = *edge6;
}

void AdjacencyListGraph::primAlgorithm()
{
	Heap* edgeQueue = new Heap();

	bool* visitedVertexes = new bool[this->numberOfVertexes];

	List* MST = new List;

	for (int i = 0; i < this->numberOfVertexes; i++)
	{
		visitedVertexes[i] = false;
	}

	int vertex = 0;

	visitedVertexes[vertex] = true;

	Edge* e;

	for (int i = 1; i < this->numberOfVertexes; i++)
	{
		std::list<Edge>::iterator it;

		for (it = adjacencyList[vertex].begin(); it != adjacencyList[vertex].end(); it++)
		{
			if (visitedVertexes[it->destinationVertex] == false)
			{
				e = new Edge(vertex, it->destinationVertex, it->weight);
				edgeQueue->push(*e);
			}
		}
		do
		{
			e = edgeQueue->front();
			edgeQueue->pop();
		} while (visitedVertexes[e->destinationVertex] == true);

		MST->insertListBeginning(e);
		visitedVertexes[it->destinationVertex] == true;
		vertex = it->destinationVertex;
	}
}
