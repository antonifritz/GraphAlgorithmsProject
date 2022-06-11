#pragma once
#include "Edge.h"
class Heap
{
public:
	int size = 0;
	Edge* array = new Edge[size];

	void push(Edge e);
	void pop();
	Edge* front();
	int parent(int index);
	int left(int index);
	int right(int index);
};

