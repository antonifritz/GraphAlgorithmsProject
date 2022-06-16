// main.cpp : Ten plik zawiera funkcję „main”. W nim rozpoczyna się i kończy wykonywanie programu.
//

#include <iostream>
#include "Graph.h"

int main()
{
    srand(time(NULL));

    int numberOfVertexes;

    std::cout << "Enter number of vertexes: " << std::endl;
    std::cin >> numberOfVertexes;

    Graph* adjList = new Graph(numberOfVertexes);
    adjList->generateGraphIndirected(50);

    adjList->fillGraph();

    adjList->printAdjacencyList();

    adjList->printMST(adjList->primAlgorithm());

    return 0;
}

