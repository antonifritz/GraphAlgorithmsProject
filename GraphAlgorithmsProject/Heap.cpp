#include "Heap.h"
#include <iostream>

void Heap::push(Edge e)
{
    size++;
    Edge* newArray = new Edge[size];
    for (int i = 0; i < size - 1; i++)
    {
        newArray[i] = array[i];
    }
    array = newArray;
    array[size - 1] = e;

    int index = size - 1;
    while (index != 0)
    {
        if (array[index].weight < array[parent(index)].weight)
        {
            Edge temp = array[index];
            array[index] = array[parent(index)];
            array[parent(index)] = temp;
        }
        index = parent(index);
    }
}

void Heap::pop()
{
    int index = 0;

    if (size == 0)
        return;
    size--;
    Edge* newArray = new Edge[size];
    for (int i = 0; i < size; i++)
    {
        newArray[i] = array[i + 1];
    }
    array = newArray;
}

Edge* Heap::front()
{
    return &array[0];
}

int Heap::parent(int index)
{
    return ((index - 1) / 2);
}

int Heap::left(int index)
{
    return (index * 2 + 1);
}

int Heap::right(int index)
{
    return (index * 2 + 2);
}
