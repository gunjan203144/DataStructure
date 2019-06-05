#include<stdio.h>
#include<stdlib.h>
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
	if(!q->array)
		return NULL;
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
int queueSize()
{
	return((q->capacity-q->front+q->rear+1)%q->capacity);
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
void deleteQueue()
{
	if(q)
		if(q->array)
			free(q->array);
	free(q);
}









