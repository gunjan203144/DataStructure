#include<stdio.h>
#include<stdlib.h>
struct graph
{
	int v;
	int e;
	int **adj;
};
typedef struct graph graph;
struct arrayQueue
{
	int front,rear;
	int capacity;
	int *array;
};
struct arrayQueue* createQueue(int capacity)
{
	struct arrayQueue *q;
	q = malloc(sizeof(struct arrayQueue));
	q->capacity=capacity;
	q->rear=q->front=-1;
	q->array=malloc(q->capacity*(sizeof(int)));
	return q;	
}
int isEmptyQueue(struct arrayQueue *q)
{
	return (q->front==-1);
}
int isFullQueue(struct arrayQueue *q)
{
	return((q->rear+1)%q->capacity==q->front);
}
void enQueue(struct arrayQueue *q,int data)
{
	if(isFullQueue(q))
		printf("Queue overflow\n");
	else
	{
		q->rear=(q->rear+1)%q->capacity;
		q->array[q->rear]=data;
		if(q->front==-1)
			q->front=q->rear;
	}
}
int deQueue(struct arrayQueue *q)
{
	int data=-1;
	if(isEmptyQueue(q))
	{
		printf("Queue is empty\n");
		return(-1);
	}
	else
	{
		data=q->array[q->front];
		if(q->front==q->rear)
			q->front=q->rear=-1;
		else
			q->front=(q->front+1)%q->capacity;
	}
	return data;
}
graph* adjMatrixofgraph()
{
	int flag=0,u,v,i;
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
	printf("If graph is directed press 1\n");
	scanf("%d",&flag);
	printf("Enter node number in pairs that connects an edge\n");
	for(i=0;i<g->e;i++)
	{
		scanf("%d%d",&u,&v);	
		g->adj[u][v]=1;
		if(flag!=1)		
		g->adj[v][u]=1;
	}	
	return g;
}
void bfs(graph *g)
{
	int n,i,u=0,p,j,flag;
	struct arrayQueue *queue;
	n=g->v;
	queue=createQueue(n);
	int a[n];
	for(i=0;i<n;i++)
		a[i]=1;
	enQueue(queue,u);
	while(!isEmptyQueue(queue))
	{
		p=deQueue(queue);
		flag=0;
		printf("%d, ",p);
		a[p]=3;
		for(i=0;i<g->v;i++)
		{
			if(g->adj[p][i]==1 && a[i]!=3 && a[i]!=2)
			{
				enQueue(queue,i);
				a[i]=2;
				flag=1;
			}
		}
		if(flag==0 && p<n-1 && a[p+1]==1)
				enQueue(queue,p+1);
	}
}
main()
{
	graph *g;
	g=adjMatrixofgraph();
	bfs(g);
}
