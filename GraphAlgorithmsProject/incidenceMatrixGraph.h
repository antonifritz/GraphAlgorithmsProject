#pragma once
class incidenceMatrixGraph
{
public:
	int numberOfVertexes;
	int numberOfEdges;

	int** incidenceMatrix;

	incidenceMatrixGraph(int numberOfVertexes, int numberOfEdges);

};

