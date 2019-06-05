#include<stdio.h>
#include<stdlib.h>
struct graph
{
	int v;
	int e;
	int **adj;
};
typedef struct graph graph;
struct arrayStack
{
	int top;
	int capacity;
	int *array;
};
struct arrayStack* createStack(int cap)
{
	struct arrayStack *stack;
	stack=malloc(sizeof(struct arrayStack));
	stack->capacity=cap;
	stack->top=-1;
	stack->array=malloc(sizeof(int)*stack->capacity);
	return stack;
};
int isFull(struct arrayStack *stack)
{
	if(stack->top==stack->capacity-1)
		return 1;
	else
		return 0;
}
int isEmpty(struct arrayStack *stack)
{
	if(stack->top==-1)
		return 1;
	else 
		return 0;
}
void push(struct arrayStack *stack,int data)
{
	if(!isFull(stack))
	{
		stack->top++;
		stack->array[stack->top]=data;
	}
	else
	printf("\n Stack overflowed\n");	
}
int pop(struct arrayStack *stack)
{
	int item;
	if(!isEmpty(stack))
	{
		item=stack->array[stack->top];
		stack->top--;
		return item;
	}
	return -1;	
}
graph* adjMatrixofgraph()
{
	int u,v,i,flag=0;
	graph *g;
	g=(graph *)malloc(sizeof(graph));
	printf("Enter number of nodes and number of edges\n");
	scanf("%d%d",&g->v,&g->e);
	printf("If graph is directed press 1\n");
	scanf("%d",&flag);
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
		if(flag!=1)		
		g->adj[v][u]=1;
	}	
	return g;
}
void dfs(graph *g)
{
	int n,i,u=0,p,flag;
	struct arrayStack *stack;
	n=g->v;
	stack=createStack(n);
	int a[n];
	for(i=0;i<n;i++)
		a[i]=1;
	push(stack,u);
	while(!isEmpty(stack))
	{
		p=pop(stack);
		printf("%d, ",p);
		flag=0;
		a[p]=3;
		for(i=0;i<g->v;i++)
		{
			if(g->adj[p][i]==1 && a[i]!=3 && a[i]!=2)
			{
				push(stack,i);
				a[i]=2;
				flag=1;
			}
		}
		if(flag==0 && p<n-1 && a[p+1]==1)
				push(stack,p+1);
	}
}
main()
{
	graph *g;
	g=adjMatrixofgraph();
	dfs(g);
}
