#pragma once
class Edge
{
public:
	int vertex;
	int destinationVertex;
	int weight;

	Edge() {}
	Edge(int vertex, int destinatonVertex, int weight);
};

