#include <cstdio>
const int MaxVex = 9;
const int MaxEdge = 15;
struct MGraph
{
	char vex[MaxVex];
	int arc[MaxVex][MaxVex];
	int numVertexes;
	int numEdges;
};
struct Edge
{
	int begin;
	int end;
	int weight;
};

int Find(int *parent, int f)
{
	while (parent[f] > 0)
		f = parent[f];
	return f;
}

void MiniSpanTree_Kruskal(MGraph G)
{
	int i, m, n;
	Edge edges[MaxEdge];
	int parent[MaxVex];

	for (i = 0; i < G.numVertexes; i++)
		parent[i] = 0;
	for (i = 0; i < G.numEdges; i++)
	{
		m = Find(parent, edges[i].begin);
		n = Find(parent, edges[i].end);
		if (m != n)
		{
			parent[m] = n;
			printf("(%d,%d) %d", edges[i].begin, edges[i].end, edges[i].weight);
		}
	}
}
