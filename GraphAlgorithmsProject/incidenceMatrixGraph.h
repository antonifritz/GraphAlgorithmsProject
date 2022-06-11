#pragma once
class IncidenceMatrixGraph
{
public:
	int numberOfVertexes;
	int numberOfEdges;

	int** incidenceMatrix;

	IncidenceMatrixGraph(int numberOfVertexes, int numberOfEdges);

};

