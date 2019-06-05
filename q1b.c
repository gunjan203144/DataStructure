/*#include<stdio.h>
#include<stdlib.h>
/*implementation of stack using linked list*/
struct linked_stack
{
	int data;
	struct linked_stack *next;
};
struct linked_stack *top=NULL;
typedef struct linked_stack sl;
sl* createStack()
{
	sl *stack;
	stack=(sl *)malloc(sizeof(struct linked_stack));
	return stack;
}
sl* push(int data)
{
	sl *new;
	new=createStack();
	new->data=data;
	new->next=top;
	top=new;
	return top;		
}
int pop()
{
	sl *r;
	r=top;
	int data;
	if(top==NULL)
		printf("Stack is underflow");
	else
	{
		data=r->data;
		top=top->next;
		free(r);
		return r;
	}
}
void display()
{
	st *p;
	p=top;
	if(top==NULL)
		printf("Stack is underflow\n");
	while(p!=NULL)
	{
		printf("%d\n",p->data);
		p=p->next;
	}		
}
