#include "Graph.h"
#include "PriorityQueue.h"
#include "List.h"
#include "ListElement.h"
#include <iostream>
#include <stdio.h>

Graph::Graph(int numberOfVertexes)
{
	this->numberOfVertexes = numberOfVertexes;
	listArray = new List[numberOfVertexes];
	MST = new Edge[numberOfVertexes - 1];

	adjacencyMatrix = new int* [numberOfVertexes];
	for (int i = 0; i < numberOfVertexes; i++)
	{
		adjacencyMatrix[i] = new int[numberOfVertexes];
	}
}

Graph::Graph(int numberOfEdges, int numberOfVertexes)
{
	this->numberOfEdges = numberOfEdges;
	this->numberOfVertexes = numberOfVertexes;
	edgeArray = new Edge[numberOfEdges];
	listArray = new List[numberOfVertexes];
	MST = new Edge[numberOfVertexes - 1];

	adjacencyMatrix = new int* [numberOfVertexes];
	for (int i = 0; i < numberOfVertexes; i++)
	{
		adjacencyMatrix[i] = new int[numberOfVertexes];
	}

	for (int i = 0; i < numberOfVertexes; i++)
	{
		for (int j = 0; j < numberOfVertexes; j++)
		{
			adjacencyMatrix[i][j] = 0;
		}
	}
}

Graph::~Graph()
{
	delete[] MST;

	for (int i = 0; i < numberOfVertexes; i++)
	{
		ListElement* iterator = listArray[i].head;
		for (int j = 0; j < listArray[i].listSize - 2; j++)
		{
			iterator = iterator->nextEdge;
		}
		for (int j = 0; j < listArray[i].listSize - 3; j++)
		{
			delete iterator->nextEdge;
			iterator = iterator->prevEdge;
		}
		delete iterator->prevEdge;
		delete iterator;
	}
	delete[] listArray;
	delete[] edgeArray;


	for (int i = 0; i < numberOfVertexes; i++)
	{
		delete[] adjacencyMatrix[i];
	}
	delete[] adjacencyMatrix;
}

void Graph::fillAdjacencyList()
{
	for (int i = 0; i < numberOfEdges; i++)
	{
		listArray[edgeArray[i].vertex].insertListBeginning(new ListElement(&edgeArray[i]));
		listArray[edgeArray[i].destinationVertex].
			insertListBeginning(new ListElement
			(new Edge(edgeArray[i].destinationVertex, edgeArray[i].vertex, edgeArray[i].weight)));
	}

}

void Graph::fillIncidenceMatrixIndirected()
{
	for (int i = 0; i < numberOfVertexes; i++)
	{
		for (int j = 0; j < numberOfEdges; j++)
		{
			incidenceMatrix[i][j] = 0;
		}
	}

	printIncidenceMatrix();

	for (int i = 0; i < numberOfEdges; i++)
	{
		printf("%d, %d, %d\n", edgeArray[i].vertex, edgeArray[i].destinationVertex, edgeArray[i].weight);
	}

	for (int i = 0; i < numberOfEdges; i++)
	{
		incidenceMatrix[edgeArray[i].vertex][i] = edgeArray[i].weight;
		incidenceMatrix[edgeArray[i].destinationVertex][i] = edgeArray[i].weight;
		printIncidenceMatrix();
	}
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

	numberOfEdges = (int)((density / 100.0) * (maxEdges - minEdges) + minEdges);
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
	delete[] doesEgdeExists;
}

void Graph::printIncidenceMatrix()
{
	printf("\nIncidence matrix:\n\n    ");
	for (int i = 0; i < numberOfEdges; i++)
	{
		printf("%3d", i);
	}

	printf("\n");

	printf("----");

	for (int i = 0; i < numberOfEdges; i++)
	{
		printf("---");
	}
	
	printf("\n");

	for (int i = 0; i < numberOfVertexes; i++)
	{
		printf("%3d|", i);
		for (int j = 0; j < numberOfEdges; j++)
		{
			printf("%3d", incidenceMatrix[i][j]);
		}

		printf("\n");
	}
}

void Graph::printAdjacencyMatrix()
{
	printf("\nMacierz sasiedztwa:\n\n    ");
	for (int i = 0; i < numberOfVertexes; i++)
	{
		printf("%3d", i);
	}

	printf("\n");

	printf("----");

	for (int i = 0; i < numberOfVertexes; i++)
	{
		printf("---");
	}

	printf("\n");

	for (int i = 0; i < numberOfVertexes; i++)
	{
		printf("%3d|", i);
		for (int j = 0; j < numberOfVertexes; j++)
		{
			printf("%3d", adjacencyMatrix[i][j]);
		}

		printf("\n");
	}
}

void Graph::printAdjacencyList()
{
	ListElement* iterator;

	printf("\nAdjacency list:\n\n");

	for (int i = 0; i < numberOfVertexes; i++)
	{
		iterator = listArray[i].head;
		for (int j = 0; j < listArray[i].listSize; j++)
		{
			std::cout << i << ": " << iterator->edge->vertex << " "
				<< iterator->edge->destinationVertex << " " << iterator->edge->weight << std::endl;
			iterator = iterator->nextEdge;
		}
	}
}

void Graph::printMST()
{
	printf("MST:\n");
	for (int i = 0; i < numberOfVertexes - 1; i++)
	{
		printf("%d, %d, %d\n", MST[i].vertex, MST[i].destinationVertex, MST[i].weight);
	}
}

void Graph::primAlgorithmAdjacencyList()
{
	bool* visitedVertexes = new bool[numberOfVertexes];

	for (int i = 0; i < numberOfVertexes; i++)
	{
		visitedVertexes[i] = false;
	}

	int counter = 0;

	int vertex = 0;

	visitedVertexes[vertex] = true;
	Edge* e;
	ListElement* iterator;
	PriorityQueue* edgeQueue = new PriorityQueue();
	for (int i = 1; i < numberOfVertexes; i++)
	{
			iterator = listArray[vertex].head;

			for (int j = 0; j < listArray[vertex].listSize; j++)
			{
				if (visitedVertexes[iterator->edge->destinationVertex] == false)
				{
					edgeQueue->push(iterator->edge);
				}
				iterator = iterator->nextEdge;
			}

			do
			{
				e = new Edge(edgeQueue->front()); 
				edgeQueue->pop();
			} while (visitedVertexes[e->destinationVertex] == true);

			MST[counter] = e;

			counter++;

			visitedVertexes[e->destinationVertex] = true;
			vertex = e->destinationVertex;
	}
}

void Graph::primAlgorithmIncidenceMatrix()
{
	bool* visitedVertexes = new bool[numberOfVertexes];

	for (int i = 0; i < numberOfVertexes; i++)
	{
		visitedVertexes[i] = false;
	}

	int vertex = 0;
	int counter = 0;
	visitedVertexes[vertex] = true;
	Edge* e;
	ListElement* iterator;
	PriorityQueue* edgeQueue = new PriorityQueue();

	for (int i = 1; i < numberOfVertexes; i++)
	{
		for (int j = 0; j < numberOfEdges; j++)
		{
			if (incidenceMatrix[vertex][j] != 0)
			{
				for (int k = 0; k < numberOfVertexes; k++)
				{
					if (incidenceMatrix[k][j] != 0 && k != vertex && visitedVertexes[k] == false)
					{
						edgeQueue->push(new Edge(vertex, k, incidenceMatrix[k][j]));
					}
				}
			}
		}

		do
		{
			e = new Edge(edgeQueue->front());
			edgeQueue->pop();
		} while (visitedVertexes[e->destinationVertex] == true);

		MST[counter] = e;
		counter++;

		visitedVertexes[e->destinationVertex] = true;
		vertex = e->destinationVertex;
	}

}

void Graph::primAlgorithmAdjacencyMatrix()
{

}
