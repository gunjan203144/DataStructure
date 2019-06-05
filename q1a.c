/*#include<stdio.h>
#include<stdlib.h>
/*Stack implementation through array*/
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
/*main()
{
int i, data,n;
struct arrayStack *stack;
scanf("%d",&n);
stack=createStack(n);
for(i=0;i<n;i++)
{
	scanf("%d",&data);
	push(stack,data);
}
data=pop(stack);
printf("%d",data);
}*/





