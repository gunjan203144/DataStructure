#include<stdio.h>
#include<stdlib.h>
struct list 
{
	int vno;
	struct list *next;
};
struct graph
{
	int v;
	int e;
	struct list *adj;
};
typedef struct graph graph;
graph* adjListofgraph()
{
	int i,x,y;
	struct list *temp;
	struct list *t;
	graph *g;
	g=(graph *)malloc(sizeof(graph));
	printf("Enter number of vertex and number of edges\n");
	scanf("%d%d",&g->v,&g->e);
	g->adj=(struct list *)malloc(sizeof(struct list)*g->v);
	for(i=0;i<g->v;i++)
	{
		g->adj[i].vno=i;
		g->adj[i].next= g->adj + i;	
	}
	for(i=0;i<g->e;i++)
	{
		printf("Enter source node and destination node of edge\n");
		scanf("%d%d",&x,&y);
		temp=(struct list *)malloc(sizeof(struct list));
		temp->vno=y;
		temp->next=g->adj+x;
		t=g->adj+x;
		while(t->next != (g->adj+x))
			t=t->next;
		t->next=temp;
	}
	return g;
}
main()
{
	graph *k;
	k=adjListofgraph();
}







