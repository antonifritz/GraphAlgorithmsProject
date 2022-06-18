#pragma once
#include "Edge.h"
class ListElement
{
public:

	ListElement(Edge* edge);

	Edge* edge;
	ListElement* nextEdge;
	ListElement* prevEdge = nullptr;
};

