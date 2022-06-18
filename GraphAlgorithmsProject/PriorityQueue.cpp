#include "PriorityQueue.h"
#include <iostream>

PriorityQueue::PriorityQueue()
{

}

void PriorityQueue::push(Edge* edge)
{
    if (size == 0)
    {
        array = new Edge[1];
        array[0] = *edge;
        size++;
    }
    else
    {
        Edge* oldArray = array;
        Edge* newArray = new Edge[size + 1];
        for (int i = 0; i < size; i++)
        {
            newArray[i] = array[i];
        }
        newArray[size] = *edge;
        array = newArray;
        delete[] oldArray;
        size++;
        QuickSort(0, size - 1);
    }
}


void PriorityQueue::pop()
{
    Edge* oldArray = array;
    Edge* newArray = new Edge[size - 1];

    for (int i = 0; i < size - 1; i++)
    {
        newArray[i] = array[i + 1];
    }
    array = newArray;
    delete[] oldArray;
    size--;
}

Edge* PriorityQueue::front()
{
    return &array[0];
}

void PriorityQueue::QuickSort(int start, int end)
{
    if (start >= end)
        return;

    int p = partition(start, end);

    QuickSort(start, p - 1);

    QuickSort(p + 1, end);
}

int PriorityQueue::partition(int start, int end)
{
    int pivot = array[start].weight;

    int count = 0;
    for (int i = start + 1; i <= end; i++) {
        if (array[i].weight <= pivot)
            count++;
    }

    int pivotIndex = start + count;
    std::swap(array[pivotIndex], array[start]);

    int i = start, j = end;

    while (i < pivotIndex && j > pivotIndex) {

        while (array[i].weight <= pivot) {
            i++;
        }

        while (array[j].weight > pivot) {
            j--;
        }

        if (i < pivotIndex && j > pivotIndex) {
            std::swap(array[i++], array[j--]);
        }
    }

    return pivotIndex;
}

int PriorityQueue::parent(int index)
{
    return ((index - 1) / 2);
}

int PriorityQueue::left(int index)
{
    return (index * 2 + 1);
}

int PriorityQueue::right(int index)
{
    return (index * 2 + 2);
}
