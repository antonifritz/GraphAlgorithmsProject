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
    adjList->generateGraphIndirected(100);

    for (int i = 0; i < adjList->numberOfEdges; i++)
    {
        std::cout << adjList->edgeArray[i].vertex << " " 
            << adjList->edgeArray[i].destinationVertex << " " <<
            adjList->edgeArray[i].weight << std::endl;
    }


    //adjList->addEdges();
    /*
    adjList->generateGraphIndirected(100);

    adjList->addEdgesManually();
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

    adjList->printMST(adjList->primAlgorithm());
    */
    return 0;
}

