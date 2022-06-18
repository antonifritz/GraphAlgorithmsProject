#include "List.h"
#include <iostream>

void List::insertListBeginning(ListElement* newElement)
{
	if (listSize == 0)
	{
		head = newElement;
		listSize++;
	}
	else 
	{
		newElement->nextEdge = head;
		head->prevEdge = newElement;
		head = newElement;
		listSize++;
	}
}
