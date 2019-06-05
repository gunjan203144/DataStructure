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
int check(int 
float adjMatrixofgraph()
{
	int j,u,v,i,clusters;
	float s;
	graph *g;
	g=(graph *)malloc(sizeof(graph));
	printf("Enter number of clusters\n");
	scanf("%d",&clusters);
	printf("Enter number of points\n");
	scanf("%d",&g->v);
	int x[g->v],y[g->v],x1[g->v],y1[g->v],min[(g->v)/clusters],n;
	n=(g->v)/clusters;
	g->adj=(float **)malloc(sizeof(float)*g->v);
	for(i=0;i<g->v;i++)
		g->adj[i]=(float *)malloc(sizeof(float)*g->v);
	for(i=0;i<g->v;i++)
		scanf("%d%d",&x[i],&y[i]);
	for(u=0;u<g->v;u++)
		for(v=1;v<g->v;v++)
			if(u!=v)
			g->adj[u][v]=weight(x[u],y[u],x[v],y[v]);
			else
			g->adj[u][v]=9999;
	for(u=0;u<clusters;u++)
	{
		for(i=0;i<n;i++) 	
			min[i]=9999;
		j=u*n;
		/*x1[j]=x[];
		y1[j]=y[u];*/
		for(v=1;v<g->v;v++)
		{
			if(u!=v && check())
			{
				
			}			
		}		
	}				
	return g;
}
main()
{
	graph *g;
	float s;
	s=adjMatrixofgraph();
	printf("%f\n",s);
}

