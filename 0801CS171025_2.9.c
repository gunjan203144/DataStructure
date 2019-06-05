#include<stdio.h>
#include<malloc.h>
struct node 
{
int coeff;
int pow;
struct node *link;
};
struct node *start=NULL;
struct node *start1=NULL;
struct node *start2=NULL;
struct node* createnode(int coeff,int pow)
{
	struct node *n;
	n = (struct node *)malloc(sizeof(struct node));
	n->coeff=coeff;
	n->pow=pow;
	return(n);
}
struct node* insertnode(struct node *start,int coeff,int pow)
{
	struct node *temp,*t;
	temp=createnode(coeff,pow);
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
			printf("|%d|%d|->",t->coeff,t->pow);
			t= t->link;
			} }
}
struct node* add(struct node *start,struct node *start1)
{
	struct node *t,*t1,*t2;
	int coeff,pow;
	t=start;
	t1=start1;
	t2=start2;
	while(t!=NULL&&t1!=NULL)
	{	
	if(t->pow==t1->pow)
	{	coeff=(t->coeff)+(t1->coeff);
		pow=t->pow;	
		start2=insertnode(start2,coeff,pow);
	}
	else
	{
	start2=insertnode(start2,t->coeff,t->pow);		
	start2=insertnode(start2,t1->coeff,t1->pow);		
	}
	t1=t1->link;	
	t=t->link;
	}	
	return start2;
}
main()
{
	int n,i=1,coeff,pow;
	printf("Enter number of terms\n");
	scanf("%d",&n);
	while(i<=n)
	{
		printf("Enter coefficient and power\n");
		scanf("%d%d",&coeff,&pow);
		start=insertnode(start,coeff,pow);
		i++;
	}
	displaylist(start);
	i=1;
	printf("\n");
	 while(i<=n)
        {
                printf("Enter coefficient and power\n");
                scanf("%d%d",&coeff,&pow);
                start1=insertnode(start1,coeff,pow);
                i++;
        }
        displaylist(start1);
	printf("\n");
	start2 =add(start,start1);
	displaylist(start2);
}











