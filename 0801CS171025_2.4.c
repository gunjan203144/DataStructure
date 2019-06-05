Node* mergeLinkesLists(Node * head1, Node * head2)
{
	Node *sorting,*new_head=NULL;
	if(head1==NULL)
		return head2;
	else if (head2==NULL)
		return head1;
	else if(head1!=NULL && head2!=NULL)
	{
		if(head1->data<=head2->data)
		{
			sorting=head1;
			head1=sorting->next;
		}
		else
		{
			sorting=head2;
			head2=sorting->next;	
		}
		new_head=sorting;
	while(head1!=NULL && head2!=NULL)
		{
			if(head1->data<=head2->data)
			{
				sorting->next=head1;
				sorting=head1;
				head1=sorting->next;
			}
			else
			{
				sorting->next=head2;
				sorting=head2;
				head2=sorting->next;
			}
		}
	if(head1==NULL)
		sorting->next=head2;
	else if(head2==NULL)
		sorting->next=head1;
	}
return new_head;
}
