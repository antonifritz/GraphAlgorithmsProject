// main.cpp : Ten plik zawiera funkcję „main”. W nim rozpoczyna się i kończy wykonywanie programu.
//

#include <iostream>
#include "adjacencyListGraph.h"

int main()
{
    adjacencyListGraph* adjList = new adjacencyListGraph(4);
    adjList->addEdges();
    adjList->fillGraph();

    for (int i = 0; i < adjList->numberOfVertexes; i++)
    {
        std::list<int>::iterator it;
        for (it = adjList->adjacencyList[i].begin(); it != adjList->adjacencyList[i].end(); it++)
        {
            std::cout << i <<": "<< *it << std::endl;
        }
    }


    int a = 4;


    return 0;
}

