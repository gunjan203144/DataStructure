#include<stdio.h>
#include<stdlib.h>
#define INF 9999
struct graph
{
	int v;
	int e,o,d;
	int **adj;
};
typedef struct graph graph;
graph* adjMatrixofgraph()
{
	int u,v,i;
	graph *g;
	g=(graph *)malloc(sizeof(graph));
	printf("Enter number of cities and number of flights\n");
	scanf("%d%d",&g->v,&g->e);
	g->adj=(int **)malloc(sizeof(int)*g->v);
	for(i=0;i<g->v;i++)
		g->adj[i]=(int *)malloc(sizeof(int)*g->v);
	for(u=0;u<g->v;u++)
		for(v=0;v<g->v;v++)
			g->adj[u][v]=INF;
	printf("Enter cities in pairs that are connected by flights\n");
	for(i=0;i<g->e;i++)
	{
		scanf("%d%d",&u,&v);	
		g->adj[u][v]=1;		
		g->adj[v][u]=1;
	}	
	printf("Enter cities for which you want to find number of flight segments\n");
	scanf("%d%d",&g->o,&g->d);
	return g;
}
int compute(graph *g)
{
	int i,count=0,min,f[g->v],v[g->v],nc;
	for(i=0;i<g->v;i++)
	{
		f[i]=g->adj[g->o][i];
		v[i]=0;
	}	
	f[g->o]=0;
	v[g->o]=1;
	count=1;
	while(count<g->v-1)
	{
		min=INF;
		for(i=0;i<g->v;i++)
			if(f[i]<min && v[i]!=1)
			{
				min=f[i];
				nc=i;
			}
		v[nc]=1;
		for(i=0;i<g->v;i++)
			if(!v[i])
				if((min+g->adj[nc][i])< f[i])
					f[i]=min+g->adj[nc][i];
	count++;	
	}
	return f[g->d];
}
main()
{
	int b;
	graph *g;
	g=adjMatrixofgraph();
	b=compute(g);
	printf("%d\n",b);
}
