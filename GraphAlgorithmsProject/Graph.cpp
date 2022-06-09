#include "Graph.h"

Graph::Graph(int size)
{
	this->size = size;
}

void Graph::primAlghorithmMST()
{
	this->setVisitedFalse();
	int i = 0;
	visited[i] = true;
	for (; i < this->size; i++)
	{
		visited[findAdjacencyVertex(i)] = true;
	}
}



void Graph::setVisitedFalse()
{
	for (int i = 0; i < this->size; i++)
	{
		this->visited[i] = false;
	}
}

void Graph::setInfinityMatrix()
{
	for (int i = 0; i < this->size; i++)
	{
		for (int j = 0; j < this->size; j++)
		{
			this->matrix[i][j] = INT_MAX;
		}
	}
}

int Graph::findAdjacencyVertex(int vertexIndex)
{
	int closestVertexIndex = INT_MAX;
	for (int i = 0; i < this->size; i++)
	{
		if (this->matrix[vertexIndex][i] < closestVertexIndex && this->visited[i] == false)
		{
			closestVertexIndex = i;
		}
	}
	return closestVertexIndex;
}


