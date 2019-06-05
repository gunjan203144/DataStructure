#include<stdio.h>
#include<malloc.h>
struct Node
{
	int data;
	struct Node *link;
};
struct Node *start=NULL;
struct Node* createNode()
{
	struct Node *n;
	n=(struct Node*)malloc(sizeof(struct Node));
	return(n);
}
struct Node* insertNode(struct Node *start,int data)
{
	struct Node *temp,*t;
	temp=createNode();
	temp->data=data;
	temp->link=NULL;
	if(start==NULL)
		start=temp;
	else
	{
		t=start;
		while(t->link!=NULL)
			t=t->link;
		t->link=temp;
	}
 return(start);
}
struct Node* insertnode_at(struct Node *start,int data,int pos)
{
	struct Node *t,*temp,*tem;
	int count=0,i=1;
	temp=createNode();
	temp->data=data;
	t=start;
	while(t!=NULL)
	{	t=t->link;
		count++;
	}
	t=start;
	if(pos>count)
		return NULL;
	while(i<pos-1)
	{
		t=t->link;
		i++;
	}
	if(pos==1)
	{
	temp->link=t;
	start=temp;
	}
	else{
	tem=t->link;
	t->link=temp;
	temp->link=tem;
	}
	return start;
}
void deleteNode()
{
	struct Node *remove;
	if(start==NULL)
		printf("List is Empty\n");
	else
	{
		remove=start;
		start=start->link;
		free(remove);
	}
}

void printList(struct Node *start)
{
	struct Node *t;
	t=start;
	if(start=NULL)
		printf("List is empty\n");
	else
	{
		while(t!=NULL)
		{
		printf("%d->",t->data);
		t=t->link;
		}
	}
}
int main()
{
int data,n,i,pos;
int a;
printf("Enter number of data\n");
scanf("%d",&n);
for(i=1;i<=n;i++)
{
	printf("Enter data\n");
	scanf("%d",&data);
	start =insertNode(start,data);
}
printList(start);
printf("Enter position to insertnode\n");
scanf("%d",&pos);
printf("Enter data");
scanf("%d",&data);
start=insertnode_at(start,data,pos);
printList(start);
printf("\nTo delete node press '0'\n");
scanf("%d",&a);
if(a==0)
deleteNode();
printList(start);
}

