#pragma once
#include "Edge.h"
#include "SetInstance.h"

class KruskalSet
{
public:
	SetInstance* sets;

	KruskalSet(int numberOfVertexes);
	void makeSet(int vertex);
	int findSet(int vertex);
	void mergeSets(Edge e);
};