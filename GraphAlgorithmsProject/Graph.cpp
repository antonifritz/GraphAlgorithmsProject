#include "Graph.h"
#include "Heap.h"
#include "List.h"
#include "ListElement.h"
#include <iostream>

Graph::Graph(int numberOfVertexes)
{
	this->numberOfVertexes = numberOfVertexes;
	listArray = new List[numberOfVertexes];
}

void Graph::fillGraph()
{
	for (int i = 0; i < numberOfEdges; i++)
	{
		listArray[edgeArray[i].vertex].listSize++;
		listArray[edgeArray[i].destinationVertex].listSize++;

		if (listArray[edgeArray[i].vertex].listSize == 0)
		{
			listArray[edgeArray[i].vertex].head = new ListElement(&edgeArray[i]);
		}
		else {
			listArray[edgeArray[i].vertex].insertListBeginning(new ListElement(&edgeArray[i]));
		}

		if (listArray[edgeArray[i].destinationVertex].listSize == 0)
		{
			listArray[edgeArray[i].destinationVertex].head = 
				new ListElement(new Edge(edgeArray[i].destinationVertex, edgeArray[i].vertex, edgeArray[i].weight));
		}
		else {
			listArray[edgeArray[i].destinationVertex].
				insertListBeginning(new ListElement(new Edge(edgeArray[i].destinationVertex, edgeArray[i].vertex, edgeArray[i].weight)));
		}
	}
}

void Graph::addEdges()
{

}

void Graph::addEdgesManually()
{
	int vertex, destinationVertex, weight;
	for (int i = 0; i < numberOfEdges; i = i + 1)
	{
		std::cout << "i = " << i << " " << "Enter starting vertex: ";
		std::cin >> vertex;
		std::cout << "i = " << i << " " << "Enter end vertex: ";
		std::cin >> destinationVertex;
		std::cout << "i = " << i << " " << "Enter weight of vertex: ";
		std::cin >> weight;

		Edge* edge = new Edge(vertex, destinationVertex, weight);
		edgeArray[i] = *edge;
	}
}

void Graph::generateGraphIndirected(int density)
{
	int maxEdges = (numberOfVertexes * (numberOfVertexes - 1)) / 2;
	int minEdges = numberOfVertexes - 1;

	bool* doesEgdeExists = new bool[numberOfVertexes * numberOfVertexes];

	int displacement;
	int randomWeight;

	numberOfEdges = (density / 100) * (maxEdges - minEdges) + minEdges;
	std::cout << "Number of edges: "<<numberOfEdges<<std::endl;
	int availaibleConnections = numberOfEdges;
	int counter = 0;

	edgeArray = new Edge[numberOfEdges];

	for (int i = 0; i < numberOfVertexes * numberOfVertexes; i++)  //initialazing bool array as false
	{
		doesEgdeExists[i] = false;
	}

	for (int i = 0; i < numberOfVertexes; i++)
	{
		doesEgdeExists[i * numberOfVertexes + i] = true;  //eliminating possibility to create edge from vertex to itself
	}

	for (int i = 0; i < minEdges; i++)   //creating connections between vertexes
	{
		doesEgdeExists[i * numberOfVertexes + i + 1] = true;
		doesEgdeExists[(i + 1) * numberOfVertexes + i] = true;
		randomWeight = rand() % 10 + 1;
		edgeArray[i] = new Edge(i, i + 1, randomWeight);
		availaibleConnections--;
		counter++;
	}

	
	int j = 0;

	for (int k = counter; k < numberOfEdges; k++)
	{
		j = 0;
		displacement = rand() % availaibleConnections;

		for (int i = 0; i < numberOfVertexes * numberOfVertexes; i++)
		{
			if (doesEgdeExists[i] == false)
			{
				if (j == displacement)
				{
					randomWeight = rand() % 10 + 1;

					edgeArray[counter] = new Edge(i / numberOfVertexes, i % numberOfVertexes, randomWeight);
					doesEgdeExists[i] = true;
					doesEgdeExists[((i % numberOfVertexes) * numberOfVertexes) + (i/numberOfVertexes)] = true;

					counter++;
					availaibleConnections--;
					break;
				}
				else
				{
					j++;
				}
			}
		}
	}
}

void Graph::printMST(List* list)
{
	ListElement* iterator = list->head;

	while (iterator->nextEdge != nullptr)
	{
		std::cout << iterator->edge->vertex << " " << iterator->edge->destinationVertex << " " << iterator->edge->weight << std::endl;
		iterator = iterator->nextEdge;
	}
	std::cout << iterator->edge->vertex << " " << iterator->edge->destinationVertex << " " << iterator->edge->weight << std::endl;
}


List* Graph::primAlgorithm()
{
	bool* visitedVertexes = new bool[numberOfVertexes];

	List* MST = new List;

	for (int i = 0; i < numberOfVertexes; i++)
	{
		visitedVertexes[i] = false;
	}

	int vertex = 0;

	visitedVertexes[vertex] = true;
	Edge* e;
	ListElement* iterator;
	Heap* edgeQueue = new Heap();
	for (int i = 1; i < numberOfVertexes; i++)
	{
		
			iterator = listArray[vertex].head;

			while (iterator != nullptr)
			{
				if (visitedVertexes[iterator->edge->destinationVertex] == false)
				{
					edgeQueue->push(iterator->edge);
				}
				iterator = iterator->nextEdge;
			}
			std::cout << vertex << std::endl;
			for (int i = 0; i < edgeQueue->size; i++)
			{
				std::cout <<"v: "<< edgeQueue->array[i].vertex << std::endl;
			}

			do
			{
				e = new Edge(edgeQueue->front()); 
				edgeQueue->pop();
			} while (visitedVertexes[e->destinationVertex] == true);

			if (MST->listSize == 0)
			{
				MST->head = new ListElement(e);
				MST->listSize++;
			}
			else
			{
				MST->insertListBeginning(new ListElement(e));
				MST->listSize++;
			}

			visitedVertexes[e->destinationVertex] = true;
			vertex = e->destinationVertex;
	}
	return MST;
}
