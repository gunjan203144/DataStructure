#include<stdio.h>
#include<malloc.h>
struct node
{
	int data;
	struct node *link;
};
struct node *start=NULL;
struct node* createnode()
{
	struct node *n;
	n=(struct node *)malloc(sizeof(struct node));
	return(n);
}
void insertnode()
{
	struct node *temp,*t;
	temp=createnode();
	printf("Enter a number\n");
	scanf("%d",&temp->data);
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
}
void displaylist(struct node *start)
{
	struct node *t;
	if(start==NULL)
		printf("List is Empty\n");
	else
		{
		t=start;
		while(t!=NULL)
			{
			printf("%d->",t->data);
			t= t->link;
			} }
}
void count(int search)
{
	struct node *t;
	int count=0;
	t=start;
	while(t!=NULL)
	{
		if(t->data==search)
		count++;
		t=t->link;	
	}
	printf("\n%d",count);
}
main()
{
	int n,i=1,search;
	printf("Enter number of elements\n");
	scanf("%d",&n);
	while(i<=n)
	{
	insertnode();
	i++;
	}		
	displaylist(start);
	scanf("%d",&search);
	count(search);
}

