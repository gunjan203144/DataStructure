#include<stdio.h>
#include<stdlib.h>
int count = 0; 
struct node
{
    int info;
    struct node *next;
}*front,*rear,*temp,*front1;

/* Create an empty queue */
void create()
{
    front = rear = NULL;
}
 
/* Returns queue size */
void queuesize()
{
    printf("\n Queue size is : %d", count);
}
 
/* enqueing the queue */
void enqueue(int data)
{
    if (rear == NULL)
    {
        rear = (struct node *)malloc(1*sizeof(struct node));
        rear->next = NULL;
        rear->info = data;
        front = rear;
    }
    else
    {
        temp=(struct node *)malloc(1*sizeof(struct node));
        rear->next = temp;
        temp->info = data;
        temp->next = NULL;
        rear = temp;
    }
}
 
/* Displaying the queue elements */
void display()
{
    front1 = front;
 
    if (front1 == NULL && rear == NULL)
    {
        printf("Queue is empty");
        return;
    }
    while (front1 != rear)
    {
        printf("%d ", front1->info);
        front1 = front1->next;
    }
    if (front1 == rear)
        printf("%d", front1->info);
}
 
/* Dequeing the queue */
void deq()
{
    front1 = front;
 
    if (front1 == NULL)
    {
        printf("\nTrying to display elements from empty queue");
        return;
    }
    else
        if (front1->next != NULL)
        {
            front1 = front1->next;
            printf("\n Dequed value : %d", front->info);
            free(front);
            front = front1;
        }
        else
        {
            printf("\n Dequed value : %d", front->info);
            free(front);
            front = NULL;
            rear = NULL;
        }
        count--;
}
 
/* Returns the front element of queue */
int frontelement()
{
    if ((front != NULL) && (rear != NULL))
        return(front->info);
    else
        return 0;
}
 
/* Display if queue is empty or not */
void empty()
{
     if ((front == NULL) && (rear == NULL))
        printf("\n Queue empty");
    else
       printf("Queue not empty");
}
/*
void main()
{
    int no, ch, e;
 
    printf("\n 1 - enqueue");
    printf("\n 2 - Deque");
    printf("\n 3 - Front element");
    printf("\n 4 - Empty");
    printf("\n 5 - Display");
    printf("\n 6 - Queue size");
    printf("\n 7 - Exit");
    create();
    while (1)
    {
        printf("\n Enter choice : ");
        scanf("%d", &ch);
        switch (ch)
        {
        case 1:
            printf("Enter data : ");
            scanf("%d", &no);
            enqueue(no);
            break;
        case 2:
            deq();
            break;
        case 3:
            e = frontelement();
            if (e != 0)
                printf("Front element : %d", e);
            else
                printf("\n No front element in Queue as queue is empty");
            break;
        case 4:
            empty();
            break;
        case 5:
            display();
            break;
        case 6:
            queuesize();
            break;
        case 7:
            exit(0);
        default:
            printf("Wrong choice, Please enter correct choice  ");
            break;
        }
    }
}*/
 

