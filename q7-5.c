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
	}	
	return g;
}
int check(graph *g)
{
	int u,v,i=0,a[g->v];
	if(g->e > g->v)
		return 1;
	
		}
	}
}
main()
{
	int i=-1;
	graph *g;
	g=adjMatrixofgraph();
	i=check(g);
	if(i==1)
		printf("True\n");
	else
		printf("False\n");
}

	
