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
void delete_alternate_Node()
{
	if(start==NULL)
		printf("List is Empty\n");
	struct Node *p=start;
	struct Node *q=p->link;
	while(p!=NULL && q!=NULL)
    	{	
        p->link=q->link;
        free(q);
        p=p->link;
        if(p!=NULL)
            q=p->link;
    	}
}
void displayList(struct Node *start)
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
main()
{
int data,n,i;
char a,r;
printf("Enter number of data\n");
scanf("%d",&n);
for(i=1;i<=n;i++)
{
	printf("Enter data\n");
	scanf("%d",&data);
	start =insertNode(start,data);
}
delete_alternate_Node();
displayList(start);
}

