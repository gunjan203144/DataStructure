#include<stdio.h>
#include<malloc.h>
struct listItem 
{
	int data;
	struct listItem *next;
};
struct listItem *getNode(int a)
{
	struct listItem *newNode;
	newNode=(struct listItem*)malloc(sizeof(struct listItem));
	newNode->data=a;
	return newNode;
}
struct listItem* insert_at_start(struct listItem *head,int a)
{
	struct listItem *makeNode;
	makeNode=getNode(a);
	if(head==NULL)
		head=makeNode;
	else
	{	makeNode->next=head;
		head=makeNode;
	}	
	return head;
}
void displayList(struct listItem *head)
{
	struct listItem *temp;
	temp=head;
	while(temp!=NULL)
	{
		printf("%d->",temp->data);
		temp=temp->next;
	}
}

main()
{
struct listItem *head=NULL;
int i;
for(i=1;i<7;i++)
head=insert_at_start(head,i);
displayList(head);
}



