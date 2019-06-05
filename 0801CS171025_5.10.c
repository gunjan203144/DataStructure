#include<stdio.h>
#include<stdlib.h>
struct graph
{
	int v;
	int e;
	int **adj;
};
typedef struct graph graph;
graph* adjMatrixofgraph()
{
	int u,v,i;
	graph *g;
	g=(graph *)malloc(sizeof(graph));
	printf("Enter number of nodes and number of edges\n");
	scanf("%d%d",&g->v,&g->e);
	g->adj=(int **)malloc(sizeof(int)*g->v);
	for(i=0;i<g->v;i++)
		g->adj[i]=(int *)malloc(sizeof(int)*g->v);
	for(u=0;u<g->v;u++)
		for(v=0;v<g->v;v++)
			g->adj[u][v]=0;
	printf("Enter node number in pairs that connects an edge\n");
	for(i=0;i<g->e;i++)
	{
		scanf("%d%d",&u,&v);	
		g->adj[u][v]=1;		
		g->adj[v][u]=1;
	}	
	return g;
}
int motherVertex(graph *g)
{
	int i,j,count=0,max=-1,mother,k;
	for(i=0;i<g->v;i++)
	{
	count=0;	
	k=0;
	for(j=0;j<g->v;j++)
		{
			if(g->adj[i][j]==1)
				count++;
			else if(g->adj[i][j]==0)
				k++;		
		}
	if(k==g->v)
		return -1;
	if(count>max)
		mother=i;
	}
	return mother;
}
main()
{
	int b;
	graph *g;
	g=adjMatrixofgraph();
	b=motherVertex(g);
	printf("%d\n",b);
}
