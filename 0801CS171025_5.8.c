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
int connect(graph *g)
{
	int u,v,count;
	for(u=0;u<g->v;u++)
	{
	count=0;
		for(v=0;v<g->v;v++)
			if(g->adj[u][v]==0)
				count++;
	if(count==g->v || g->e < g->v-1)
		return 0;
	else
		return 1;	
	}
}
main()
{
	int b;
	graph *g;
	g=adjMatrixofgraph();
	b=connect(g);
	if(b==1)
		printf("True\n");
	else
		printf("False\n");
}
