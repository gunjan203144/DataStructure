#include<stdio.h>
#include<stdlib.h>
struct node
{
int data;
struct node *next;
struct node *prev;
};
typedef struct node node;
node *start=NULL;
node* createnode()
{
	node *t;
	t=(node*)malloc(sizeof(node));
	t->next=NULL;
	t->prev=NULL;
	return t;
}
node* insertNode(node *start,int data)
{
	node *temp,*t,*p;
	temp=createnode();
	temp->data=data;
	temp->prev=NULL;
	temp->next=NULL;
	if(start==NULL)
		{
		temp->prev=start;
		start=temp;		
		}
	else
	{
		t=start;
		while(t->next!=NULL)
			t=t->next;	
	t->next=temp;
	temp->prev=t;		
	}
return start;
}
node* deleteNode(node *start)
{
	struct node *remove,*temp;
	temp=start;
	remove=start;
	start=temp->next;
	temp->prev=NULL;
	free(remove);
return start;
}
node* insertNode_at(node *start,int pos)
{
	node *t=start,*temp;
	int count=0,i=1;
	while(t!=NULL)
	{
		t=t->next;
		count++;
	}
	if(pos>count)
		return NULL;
	t=start;
	while(i<pos-1)
	{
		t=t->next;
		i++;
	}	
	temp=createnode();
	scanf("%d",&temp->data);
	if(pos==1)
	{
		temp->next=start;
		start=temp;
		temp->prev=NULL;
	}
	else
	{
		temp->next=t->next;
		t->next->prev=temp;
		t->next=temp;
		temp->prev=t;
	}
return start;	
}
void printList(node *start)
{
	node *t,*temp=start;
	if(start==NULL)
	printf("List is empty\n");
	else
	{
	t=start;
		while(t!=NULL)
		{
			printf("%d->",t->data);
			t=t->next;		
		}
		while(temp->next!=NULL)
		{
			temp=temp->next;
		}
		
		printf("\n");
		while(temp!=NULL)
		{
			printf("%d->",temp->data);
			temp=temp->prev;
		}
	}
}
/*main()
{
int n,i,data,pos;
scanf("%d",&n);
for(i=1;i<=n;i++)
{	scanf("%d",&data);
	start=insertNode(start,data);
}
printList(start);
printf("\n");
start= deleteNode(start);
printList(start);
scanf("%d",&pos);
start=insertNode_at(start,pos);
printList(start);
}*/




