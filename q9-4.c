#include<stdio.h>
#include<stdlib.h>
struct heap
{
	int *array;
	int count;
	int capacity;
};
typedef struct heap heap;
heap* createHeap(int capacity)
{
	heap *h;
	h=(heap *)malloc(sizeof(heap));
	h->count=0;
	h->capacity=capacity;
	h->array=(int *)malloc(sizeof(int)*h->capacity);
	return h;
}
int leftchild(heap *h,int i)
{
	int l;
	l=2*i+1;
	if(l>=h->count)
		return -1;
	return l;
}
int rightchild(heap *h,int i)
{
	int r;
	r=2*i+2;
	if(r>=h->count)
		return -1;
	return r;
}
void percolateDown(heap *h,int i)   //Heapify
{
	int l,r,max,temp;
	l=leftchild(h,i);
	r=rightchild(h,i);
	if(l!=-1 && h->array[l]>h->array[i])
		max=l;
	else
		max=i;
	if(r!=-1 && h->array[r]>h->array[max])
		max=r;
	if(max!=i)
	{
		temp=h->array[i];
		h->array[i]=h->array[max];
		h->array[max]=temp;
	}
	if(max==i)
		return;
	else
		percolateDown(h,max);
}
void buildHeap(heap *h,int a[],int n)
{
	int i;
	if(h==NULL)
		return;
	for(i=0;i<n;i++)
		h->array[i]=a[i];
	h->count=n;
	for(i=(n-3)/2;i>=0;i--)
		percolateDown(h,i);
}
main()
{
int n,i;
heap *h;
printf("Enter number of elements\n");
scanf("%d",&n);
int a[n];
for(i=0;i<n;i++)
	scanf("%d",&a[i]);
h=createHeap(n);
buildHeap(h,a,n);
for(i=0;i<n;i++)
	printf("%d, ",h->array[i]);
}
