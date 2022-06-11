#pragma once
#include "ListElement.h"
class List
{
public:

	void insertListBeginning(ListElement* newElement);

	int listSize = 0;
	ListElement* head;
};
