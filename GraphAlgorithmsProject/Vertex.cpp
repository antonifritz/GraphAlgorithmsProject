#include "Vertex.h"

int Vertex::getKey()
{
    return this->key;
}

void Vertex::setKey(int key)
{
    this->key = key;
}

Vertex* Vertex::getPredessor()
{
    return this->predessor;
}

void Vertex::serPredessor(Vertex* predessor)
{
    this->predessor = predessor;
}
