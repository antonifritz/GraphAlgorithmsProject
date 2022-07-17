#include "KruskalSet.h"

KruskalSet::KruskalSet(int numberOfVertexes)
{
	sets = new SetInstance[numberOfVertexes];
}

void KruskalSet::makeSet(int vertex)
{
	sets[vertex].up = vertex;
	sets[vertex].rank = 0;
}

int KruskalSet::findSet(int vertex)
{
	if (sets[vertex].up != vertex)
	{
		sets[vertex].up = findSet(sets[vertex].up);
	}
	return sets[vertex].up;
}

void KruskalSet::mergeSets(Edge e)
{
	int rootU = findSet(e.vertex);  
	int rootV = findSet(e.destinationVertex); 

	if (rootU != rootV)           
	{
		if (sets[rootU].rank > sets[rootV].rank)
		{
			sets[rootV].up = rootU;
		}
		else
		{
			sets[rootU].up = rootV;  
			if (sets[rootU].rank == sets[rootV].rank)
			{
				sets[rootV].rank++;
			}
		}
	}
}
