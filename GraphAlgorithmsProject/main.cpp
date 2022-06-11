// main.cpp : Ten plik zawiera funkcję „main”. W nim rozpoczyna się i kończy wykonywanie programu.
//

#include <iostream>
#include "AdjacencyListGraph.h"

int main()
{
    AdjacencyListGraph* adjList = new AdjacencyListGraph(5, 6);
    adjList->addEdges();
    adjList->fillGraph();

    for (int i = 0; i < adjList->numberOfVertexes; i++)
    {
        ListElement* iterator = adjList->listArray[i].head;

        for (int j = 0; j < adjList->listArray[i].listSize; j++)
        {       
            std::cout << i << ": " << iterator->edge->vertex << " " << iterator->edge->destinationVertex
                << " " << iterator->edge->weight << std::endl;
            iterator = iterator->nextEdge;
        }
    }

    return 0;
}

