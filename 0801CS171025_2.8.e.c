#include<stdio.h>
#include<malloc.h>
struct node
{
	int data;
	struct node *link;
};
struct node *start1=NULL,*start2=NULL,*start3=NULL;
struct node* createnode()
{
	struct node *n;
	n=(struct node *)malloc(sizeof(struct node));
	return(n);
}
struct node* insertnode(struct node *start)
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
	return start;		
}
struct node* merge(struct node *start1,struct node *start2)
{
	struct node *temp,*t1,*t2;
	if(start1==NULL &&  start2==NULL)
	return(NULL);
	temp=start1;
	t1=start1;
	t2=start2;
	start3=temp;
	t1=t1->link;
	while(t1!=NULL&&t2!=NULL)
	{
		temp->link=t2;
		t2=t2->link;
		temp->link->link=t1;
		t1=t1->link;
		temp=temp->link->link;	
	}
temp->link=t1;
return start3;
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

main()
{
	int n,i=1;
	printf("Enter number of elements\n");
	scanf("%d",&n);
	while(i<=n)
	{
		start1=insertnode(start1);
		i++;
	}	
	i=1;
	displaylist(start1);
	printf("\n");
	while(i<=n-1)
	{
		start2=insertnode(start2);
		i++;
	}
	displaylist(start2);	
	start3 =merge(start1,start2);
        printf("\n");
	displaylist(start3);	
}
