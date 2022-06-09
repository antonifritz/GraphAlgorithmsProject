#include "incidenceMatrixGraph.h"

incidenceMatrixGraph::incidenceMatrixGraph(int numberOfVertexes, int numberOfEdges)
{
	this->numberOfEdges = numberOfEdges;
	this->numberOfVertexes = numberOfVertexes;

	this->incidenceMatrix = new int* [numberOfVertexes];
	for (int i = 0; i < numberOfVertexes; i++)
	{
		this->incidenceMatrix[i] = new int[numberOfEdges];
	}
}
