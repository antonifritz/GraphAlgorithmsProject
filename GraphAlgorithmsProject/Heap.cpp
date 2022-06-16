#include "Heap.h"
#include <iostream>

Heap::Heap()
{

}

void Heap::push(Edge* edge)
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
        //Heapify(0);  
        bubbleSort(array, size);
    }
}

void Heap::Heapify(int i)
{
    int l = left(i);
    int r = right(i);
    int smallest = i;

    if (l < size && array[l].weight < array[i].weight)
    {
        smallest = l;
    }
    if (r < size && array[r].weight < array[smallest].weight)
    {
        smallest = r;
    }
    if (smallest != i)
    {
        std::swap(array[i], array[smallest]);
        Heapify(smallest);
    }
}

void Heap::bubbleSort(Edge* arr, int n)
{
    int i, j;
    for (i = 0; i < n - 1; i++)
        for (j = 0; j < n - i - 1; j++)
            if (arr[j].weight > arr[j + 1].weight)
                std::swap(arr[j], arr[j + 1]);
}

void Heap::pop()
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
    //bubbleSort(array, size);
}

Edge* Heap::front()
{
    for (int i = 0; i < size; i++)
        std::cout << array[i].vertex << " " << array[i].destinationVertex << " " << array[i].weight << std::endl;
    std::cout << std::endl;
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
