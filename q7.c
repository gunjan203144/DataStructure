#include<stdio.h>
#include<stdlib.h>
struct arrayQueue
{
	int front,rear;
	int capacity;
	int *petrol;
	int *distance;
}*q;
struct arrayQueue* createQueue(int capacity)
{
	struct arrayQueue *q;
	q = malloc(sizeof(struct arrayQueue));
	q->capacity=capacity;
	q->rear=q->front=-1;
	q->petrol=malloc(q->capacity*(sizeof(int)));
	q->distance=malloc(q->capacity*(sizeof(int)));	
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
void enQueue(struct arrayQueue *q,int petrol,int distance)
{
	if(isFullQueue(q))
		printf("Queue overflow\n");
	else
	{
		q->rear=(q->rear+1)%q->capacity;
		q->petrol[q->rear]=petrol;	
		q->distance[q->rear]=distance;
		if(q->front==-1)
			q->front=q->rear;
	}
}
void deQueue(struct arrayQueue *q,int *p,int *d)
{
	if(isEmptyQueue(q))
	{
		printf("Queue is empty\n");
	}
	else
	{
		*p=q->petrol[q->front];
		*d=q->distance[q->front];
		if(q->front==q->rear)
			q->front=q->rear=-1;
		else
			q->front=(q->front+1)%q->capacity;
	}
}
main()
{
	struct arrayQueue *q;
	int left,n,petrol,distance,i,sop=0,sod=0,start=-1,flag=0,p=0,d=0;
	printf("Enter number of petrol pumps\n");
	scanf("%d",&n);
	q=createQueue(n);
	for(i=1;i<=n;i++)
	{
		scanf("%d%d",&petrol,&distance);
		sop=sop + petrol;
		sod=sod + distance;
		enQueue(q,petrol,distance);
	}
	if(sod>sop)
		printf("Car can never complete marathon");
	else
	{
		while(1)
		{
			while(1)
			{
				deQueue(q,&p,&d);
				start++;
				left=p-d;
				if(left<0)
					enQueue(q,p,d);
				else
					break;
			}	
			for(i=start+1;i<n;i++);
			{
				left=left+q->petrol[i]-q->distance[i];
				if(left<0)
				{
					flag=1;
					break;	
				}
			}
			if(flag!=1)
				for(i=0;i<start;i++)
				{
					left=left+q->petrol[i]-q->distance[i];
					if(left<0)
					{
						flag=1;
						break;	
					}
				}
			enQueue(q,p,d);
			if(flag!=1)
				break;	
		}	
		printf("Car should start from %d petrol pump\n",start+1);
	}
}







