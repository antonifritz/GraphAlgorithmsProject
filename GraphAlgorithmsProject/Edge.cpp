#include "Edge.h"

Edge::Edge(Edge* edge)
{
	this->vertex = edge->vertex;
	this->destinationVertex = edge->destinationVertex;
	this->weight = edge->weight;
}

Edge::Edge(int vertex, int destinationVertex, int weight)
{
	this->vertex = vertex;
	this->destinationVertex = destinationVertex;
	this->weight = weight;
}
