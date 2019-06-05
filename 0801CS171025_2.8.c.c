#include<stdio.h>
#include<malloc.h>
struct node
{
	int data;
	struct node *link;
};
struct node *start=NULL;
struct node* createNode()
{
	struct node *n;
	n= (struct node *)malloc(sizeof(struct node));
 	return(n);
}
struct node* insertNode(struct node *start,int data)
{
	struct node *temp,*t;
	temp= createNode();
	temp->data = data;
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
struct node*pairSwap(struct node *start)
{	
	if (start == NULL || start->link == NULL)
		return;
	struct node *prev = start;
	struct node *curr = start->link;
        start=curr; 
	while (1)
	{
        struct node *next = curr->link;
        curr->link = prev;
        if (next == NULL || next->link == NULL)
        {
            prev->link = next;
            break;
        }
        prev->link = next->link;
        prev = next;
        curr = prev->link;
    }
return start;
}
void displayNode(struct node *start)
{
	struct node *t;
	if(start==NULL)
		printf("List is Empty\n");
	else{
		t=start;
		while(t!=NULL)
		{	printf("%d->",t->data);
			t=t->link;
		}}	
}
main()
{
	int i=1,data,n;
	printf("Enter number of elements\n");
	scanf("%d",&n);
	for(i=1;i<=n;i++)
	{
		printf("Enter data\n");
		scanf("%d",&data);
		start=insertNode(start,data);
	}
start=pairSwap(start);
displayNode(start);

} 









