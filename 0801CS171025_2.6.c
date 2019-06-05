int compare(Node *start1,Node *start2)
{
    Node *temp1=start1,*temp2=start2;
    while(temp1!=NULL&&temp2!=NULL)
    {
        temp1=temp1->link;
        temp2=temp2->link;
    }
    if((temp1==NULL)&&(temp2==NULL))
    {
        temp1=start1;
        temp2=start2;
        while(temp1->link!=NULL)
            temp1=temp1->link;
        while(temp2->link!=NULL)
            temp2=temp2->link;
        while(temp1!=NULL)
        {
            if((temp1->data)>(temp2->data))
                return 1;
            if((temp1->data)<(temp2->data))
                return 2;
            temp1=temp1->prev;
            temp2=temp2->prev;

        }
        return 1;
    }
    else if(temp1==NULL)
            return 2;
    else
        return 1;

}
Node* add_list(Node *start1,Node *start2)
{
    int rem=0,t;
    Node *temp1=start1,*temp2=start2,*head=NULL;
    while(temp1!=NULL&&temp2!=NULL)
    {
        temp1->data+=rem;
        t=temp1->data+temp2->data;
        head=insert_at_end(head,t%10);
        rem=t/10;
        temp1=temp1->link;
        temp2=temp2->link;
    }
    if(temp1==NULL)
    {
        while(temp2!=NULL)
        {
            t=temp2->data+rem;
            head=insert_at_end(head,t%10);
            rem=t/10;
            temp2=temp2->link;
        }
    }
    else if(temp2==NULL)
    {
        while(temp1!=NULL)
        {
            t=temp1->data+rem;
            head=insert_at_end(head,t%10);
            rem=t/10;
            temp1=temp1->link;
        }
    }
     if(rem!=0)
            head=insert_at_end(head,rem);
     return head;
}
Node* subtract_list(Node *start1,Node *start2)
{
    int carry_over=0,t,flag;
    Node *temp;
    flag=compare(start1,start2);
    if(flag==2)
    {
        temp=start1;
        start1=start2;
        start2=temp;
    }
    Node *temp1=start1,*temp2=start2,*head=NULL;
    while(temp1!=NULL&&temp2!=NULL)
     {
        temp1->data-=carry_over;
        carry_over=0;
        if(temp1->data<temp2->data)
        {
                carry_over=1;
                t=temp1->data+10-temp2->data;
                head=insert_at_end(head,t);
                temp1=temp1->link;
                temp2=temp2->link;
        }
        else
        {
            t=temp1->data-temp2->data;
            head=insert_at_end(head,t);
            temp1=temp1->link;
            temp2=temp2->link;
        }
     }
     while(carry_over)
     {
         t=temp1->data-1;
         carry_over=0;
         if(t<0)
         {
             carry_over=1;
             t+=10;
             head=insert_at_end(head,t);
         }
         temp1=temp1->link;
     }
     while(temp1!=NULL)
     {
         head=insert_at_end(head,temp1->data);
         temp1=temp1->link;
     }
     return head;
}
Node* multiply_list(Node *start1,Node *start2)
{
    Node *temp1=start1,*temp2=start2,*sub1=NULL,*head=NULL;
    int flag;
    sub1=insert_at_beg(sub1,1);
    while(temp2->link!=NULL||temp2->data!=0)
    {
        head=add_list(head,start1);
        flag=compare(temp2,sub1);
        if(flag==1)
            temp2=subtract_list(temp2,sub1);
        else
            return head;
    }
    return head;
}
