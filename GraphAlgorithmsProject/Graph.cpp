#include "Graph.h"
#include "PriorityQueue.h"
#include "List.h"
#include "ListElement.h"
#include "KruskalSet.h"
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

	for (int i = 0; i < numberOfVertexes; i++)
	{
		for (int j = 0; j < numberOfVertexes; j++)
		{
			adjacencyMatrix[i][j] = 0;
		}
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
		if (listArray[i].listSize != 0)
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
	}
	delete[] listArray;
	delete[] edgeArray;

	for (int i = 0; i < numberOfVertexes; i++)
	{
		delete[] adjacencyMatrix[i];
	}
	delete[] adjacencyMatrix;

	if (predessor != nullptr)
	{
		delete[] predessor;
	}

	if (distance != nullptr)
	{
		delete[] distance;
	}

}

void Graph::fillAdjacencyListIndirected()
{
	for (int i = 0; i < numberOfEdges; i++)
	{
		listArray[edgeArray[i].vertex].insertListBeginning(new ListElement(&edgeArray[i]));
		listArray[edgeArray[i].destinationVertex].
			insertListBeginning(new ListElement
			(new Edge(edgeArray[i].destinationVertex, edgeArray[i].vertex, edgeArray[i].weight)));
	}

}

void Graph::fillAdjacencyMatrixIndirected()
{
	for (int i = 0; i < numberOfEdges; i++)
	{
		adjacencyMatrix[edgeArray[i].vertex][edgeArray[i].destinationVertex] = edgeArray[i].weight;
		adjacencyMatrix[edgeArray[i].destinationVertex][edgeArray[i].vertex] = edgeArray[i].weight;
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

	for (int i = 0; i < numberOfEdges; i++)
	{
		incidenceMatrix[edgeArray[i].vertex][i] = edgeArray[i].weight;
		incidenceMatrix[edgeArray[i].destinationVertex][i] = edgeArray[i].weight;
	}
}

void Graph::fillAdjacencyMatrixDirected()
{
	for (int i = 0; i < numberOfEdges; i++)
	{
		adjacencyMatrix[edgeArray[i].vertex][edgeArray[i].destinationVertex] = edgeArray[i].weight;
	}
}

void Graph::fillAdjacencyListDirected()
{
	for (int i = 0; i < numberOfEdges; i++)
	{
		listArray[edgeArray[i].vertex].insertListBeginning(new ListElement(&edgeArray[i]));
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
	std::cout << "Liczba krawedzi: "<<numberOfEdges<<std::endl;
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

void Graph::generateGraphDirected(int density)
{
	int maxEdges = (numberOfVertexes * (numberOfVertexes - 1));
	int minEdges = numberOfVertexes - 1;
	bool* doesEgdeExists = new bool[numberOfVertexes * numberOfVertexes];

	int displacement;
	int randomWeight;

	numberOfEdges = (int)((density / 100.0) * (maxEdges - minEdges) + minEdges);
	std::cout << "Liczba krawedzi: " << numberOfEdges << std::endl;
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

	printf("\nLista sasiedztwa:\n\n");

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

	printf("\n");
}

void Graph::printMST()
{
	printf("MST:\n");
	for (int i = 0; i < numberOfVertexes - 1; i++)
	{
		printf("v1 = %2d, v2 = %2d, weight = %2d\n", MST[i].vertex, MST[i].destinationVertex, MST[i].weight);
	}
}

void Graph::printShortestPaths()
{
	int src = 0;
	printf("Najkrotsza sciezka:");
	for (int i = 1; i < numberOfVertexes; i++) {
		if (distance[i] == INT_MAX)
		{
			printf("\n%2d -> %2d   Sciezka nie istnieje!", src, i);
		}
		else
		{
			printf("\n%2d -> %2d    %2d    %2d ", src, i, distance[i], src);
			printPath(i);
		}
	}
	printf("\n\n");
}

int Graph::minDistance(int distance[], bool isSet[])
{
	int min = INT_MAX;
	int index = INT_MAX;

	for (int i = 0; i < numberOfVertexes; i++)
	{
		if (isSet[i] == false && distance[i] <= min)
		{
			min = distance[i];
			index = i;
		}
	}
	
	return index;
}

void Graph::printPath(int j)
{
	if (predessor[j] == -1)
		return;
	printPath(predessor[j]);
	std::cout << j << " ";
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

	delete edgeQueue;
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
	delete edgeQueue;
}

void Graph::primAlgorithmAdjacencyMatrix()
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

	for (int i = 0; i < numberOfVertexes - 1; i++)
	{
		for (int j = 0; j < numberOfVertexes; j++)
		{
			if (adjacencyMatrix[vertex][j] != 0 && visitedVertexes[j] == false)
			{
				edgeQueue->push(new Edge(vertex, j, adjacencyMatrix[vertex][j]));
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

	delete edgeQueue;
	

}

void Graph::dijkstraAlgorithmAdjacencyMatrix()
{
	distance = new int[numberOfVertexes];
	predessor = new int[numberOfVertexes];
	bool* isSet = new bool[numberOfVertexes];


	for (int i = 0; i < numberOfVertexes; i++)
	{
		distance[i] = INT_MAX;
		predessor[i] = -1;
		isSet[i] = false;
	}
	distance[0] = 0;

	for (int i = 0; i < numberOfVertexes - 1; i++) {

		int u = minDistance(distance, isSet);

		isSet[u] = true;

		for (int v = 0; v < numberOfVertexes; v++)
		{
			if (!isSet[v] && adjacencyMatrix[u][v] && distance[u] + adjacencyMatrix[u][v] < distance[v])
			{
				predessor[v] = u;
				distance[v] = distance[u] + adjacencyMatrix[u][v];
			}
		}
	}

	delete[] isSet;
}

void Graph::dijkstraAlgorithmAdjacencyList()
{
	distance = new int[numberOfVertexes];
	predessor = new int[numberOfVertexes];
	bool* isSet = new bool[numberOfVertexes];

	for (int i = 0; i < numberOfVertexes; i++)
	{
		distance[i] = INT_MAX;
		predessor[i] = -1;
		isSet[i] = false;
	}
	distance[0] = 0;

	for (int i = 0; i < numberOfVertexes - 1; i++) {

		int u = minDistance(distance, isSet);

		isSet[u] = true;

		if (listArray[u].listSize != 0)
		{
			ListElement* iterator = listArray[u].head;

			for (int j = 0; j < listArray[u].listSize; iterator = iterator->nextEdge, j++)
			{
				if(!isSet[iterator->edge->destinationVertex] &&
					distance[u] + iterator->edge->weight < distance[iterator->edge->destinationVertex])
				{
					predessor[iterator->edge->destinationVertex] = u;
					distance[iterator->edge->destinationVertex] = distance[u] + iterator->edge->weight;
				}
			}
		}
	}

	delete[] isSet;
}

void Graph::kruskalAlgorithmAdjacencyMatrix()
{
	PriorityQueue* Queue = new PriorityQueue();
	KruskalSet* Set = new KruskalSet(numberOfVertexes);
	Edge* edge;

	for (int i = 0; i < numberOfVertexes; i++)
		Set->makeSet(i);

	for (int i = 0; i < numberOfVertexes; i++)
	{
		for (int j = 0; j < numberOfVertexes; j++)
		{
			if (adjacencyMatrix[i][j] != 0)
			{
				Queue->push(new Edge(i, j, adjacencyMatrix[i][j]));
			}
		}
	}

	for (int i = 1; i < numberOfVertexes; i++)
	{
		do
		{
			edge = new Edge(Queue->front());
			Queue->pop();
		} while (Set->findSet(edge->vertex) == Set->findSet(edge->destinationVertex));
		MST[i - 1] = edge;
		Set->mergeSets(edge);
		delete edge;
	}

	delete[] Set->sets;
	delete Set;
	delete[] Queue->array;
	delete Queue;
}

void Graph::kruskalAlgorithmAdjacencyList()
{
	PriorityQueue* Queue = new PriorityQueue();
	KruskalSet* Set = new KruskalSet(numberOfVertexes);
	Edge* edge;
	ListElement* iterator;

	for (int i = 0; i < numberOfVertexes; i++)
		Set->makeSet(i);      

	for (int i = 0; i < numberOfVertexes; i++)
	{
		iterator = listArray[i].head;
		for (int j = 0; j < listArray[i].listSize; j++, iterator = iterator->nextEdge)
		{
			Queue->push(iterator->edge);
		}
	}

	for (int i = 1; i < numberOfVertexes; i++) 
	{
		do
		{
			edge = new Edge(Queue->front());      
			Queue->pop(); 
		} while (Set->findSet(edge->vertex) == Set->findSet(edge->destinationVertex));
		MST[i - 1] = edge;  
		Set->mergeSets(edge);  
		delete edge;
	}

	delete[] Set->sets;
	delete Set;
	delete[] Queue->array;
	delete Queue;
}
