int isLinkedListPalindrome(Node *head)
{
	Node *p,*q,*sec_head,*curr,*prev,*next;
	int count=0,count1=0;
	p=head;
	q=head;	
	while(1)
	{
		p=p->link->link;
		if(p->link==NULL);
		{	
			sec_head=q->link->link;
			break;
		}
		else if(p==NULL)
		{	
			sec_head=q->link;
			break;
		}
		q=q->link;
	}
	q->link=NULL;
	p=head;
	curr=sec_head;	
	prev=NULL;
	while(curr!=NULL)
	{
		next=curr->link;
		curr->link=prev;
		prev=curr;
		curr=next;
		count++;		
	}
	q=prev;
	while(p!=NULL && q!=NULL)
	{
		if(p->data==q->data)
		count1++;			
		p=p->link;
		q=q->link;
	}	
	if(count==count1)
	return 1;
	else
	return 0;
}
