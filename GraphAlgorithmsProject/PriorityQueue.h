#pragma once
#include "Edge.h"
class PriorityQueue
{
public:
	PriorityQueue();

	void push(Edge* e);
	void pop();

	Edge* front();

	void QuickSort(int start, int end);
	int partition(int start, int end);

	int parent(int index);
	int left(int index);
	int right(int index);

	int size = 0;
	int pos;
	Edge* array;
};

