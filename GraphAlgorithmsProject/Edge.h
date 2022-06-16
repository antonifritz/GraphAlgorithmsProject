#pragma once
class Edge
{
public:
	int vertex;
	int destinationVertex;
	int weight;

	Edge() {}
	Edge(Edge* edge);
	Edge(int vertex, int destinatonVertex, int weight);
};

