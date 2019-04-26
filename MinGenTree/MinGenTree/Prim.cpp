/* Prim */
#include<iostream>
#include<cstdio>
#define INFINITY 65535;
const int MaxVex = 9;
struct MGraph
{
	char vex[MaxVex];
	int arc[MaxVex][MaxVex];
	int numVertexes;
	int numEdges;
};
void MiniSpanTree_Prim(MGraph G)
{
	int min, i, j, k;
	int adjvex[MaxVex];		/*保存相关顶点的下标*/
	int lowcost[MaxVex];
	lowcost[0] = 0;
	adjvex[0] = 0;
	for (i = 1; i < G.numVertexes; i++)
	{
		lowcost[i] = G.arc[0][i];
		adjvex[i] = 0;
	}
	for (i = 1; i < G.numVertexes; i++)
	{
		min = INFINITY;

		j = 1; k = 0;
		while (j < G.numEdges)
		{
			if (lowcost[j] != 0 && lowcost[j] < min)
			{
				min = lowcost[j];
				k = j;
			}
			j++;
		}
		printf("(%d,%d", adjvex[k], k);
		lowcost[k] = 0;
		for (j = 1; j < G.numVertexes; j++)
		{
			if (lowcost[j] != 0 && G.arc[k][j] < lowcost[j])
			{
				lowcost[j] = G.arc[k][j];
				adjvex[j] = k;
			}
		}
	}
}
int Fibo(int n)
{
	if (n == 1)
		return 1;
	if (n == 2)
		return 1;
	return Fibo(n - 1) + Fibo(n - 2);
}
int main()
{
	for(int i=1;i<20;i++)
		std::cout<<Fibo(i)<<"\n";
	std::cin.get();
	//int n = 0;
	//if (n == 0)
	//	std::cout << "n==0"<<std::endl;
	//if(n>-1)
	//	std::cout << "n>-1" << std::endl;
	//std::cin.get();


	return 0;
}
