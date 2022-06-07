#include "Graph.h"

Graph::Graph(int size)
{
	this->size = size;
	setZerosMatrix(size);
}

void Graph::primAlghorithmMST()
{

}

void Graph::setVisitedFalse(int size)
{
	for (int i = 0; i < size; i++)
	{
		this->visited[i] = false;
	}
}

void Graph::setZerosMatrix(int size)
{
	for (int i = 0; i < size; i++)
	{
		for (int j = 0; j < size; j++)
		{
			this->matrix[i][j] = 0;
		}
	}
}


