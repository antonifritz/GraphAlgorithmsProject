#pragma once
class Vertex
{
private:
	int key;
	Vertex* predessor;
public:
	int getKey();
	void setKey(int key);
	Vertex* getPredessor();
	void serPredessor(Vertex* predessor);
};

