#include<stdio.h>
#include<stdlib.h>
#include<math.h>
struct graph
{
	int v;
	int e;
	float **adj;
};
float weight(int x1,int y1,int x2,int y2)
{
	int d1,d2;
	float d;
	d1=x1-x2;
	d1=d1*d1;
	d2=y1-y2;
	d2=d2*d2;
	d=sqrt(d1+d2);
	return d; 	
} 
typedef struct graph graph;
graph* adjMatrixofgraph()
{
	int u,v,i;
	graph *g;
	g=(graph *)malloc(sizeof(graph));
	printf("Enter number of nodes\n");
	scanf("%d",&g->v);
	int x[g->v],y[g->v];
	g->adj=(float **)malloc(sizeof(float)*g->v);
	for(i=0;i<g->v;i++)
		g->adj[i]=(float *)malloc(sizeof(float)*g->v);
	/*for(u=0;u<g->v;u++)
		for(v=0;v<g->v;v++)
			g->adj[u][v]=65000;*/
	printf("Enter coordinates of vertices\n");
	for(i=0;i<g->v;i++)
		scanf("%d%d",&x[i],&y[i]);
	for(u=0;u<g->v;u++)
		for(v=u+1;v<g->v;v++)
			g->adj[u][v]=weight(x[u],y[u],x[v],y[v]);		
	return g;
}
float shortest(graph *g)
{
	int u,v,flag;
	float sum=0,min=10000;
	for(u=0;u<g->v;u++)
	{
		min=10000;
		flag=0;
		for(v=u+1;v<g->v;v++)
		{
			if(min>g->adj[u][v])
			{
				min=g->adj[u][v];		
				flag=1;
			}
		}
		if(flag==1)
		sum=sum+min;
	}	
	return sum;
}
main()
{
	graph *g;
	float s;
	g=adjMatrixofgraph();
	s=shortest(g);
	printf("%f\n",s);
}

