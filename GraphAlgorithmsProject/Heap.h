#pragma once
#include "Edge.h"
class Heap
{
public:
	Heap();

	void push(Edge* e);
	void pop();

	Edge* front();

	void Heapify(int i);
	void HeapSort();

	int parent(int index);
	int left(int index);
	int right(int index);

	int size = 0;
	int pos;
	Edge* array;
};

