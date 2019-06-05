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
	else
		return;
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
	for(i=(n-3)/2;i>=0;i--)			//bottom up
		percolateDown(h,i);
}
void heapSort(int a[],int n)
{
	heap *h;
	int oldsize,i,temp;
	h= createHeap(n);
	buildHeap(h,a,n);
	oldsize=h->count;
	for(i=n-1;i>0;i--)
	{
		temp=h->array[0];
		h->array[0]=h->array[h->count-1];
		h->array[h->count-1]=temp;
		h->count--;
		percolateDown(h,0);
	}
	h->count=oldsize;
	printf("Sorted array is \n");
	for(i=0;i<n;i++)
		printf("%d, ",h->array[i]);	
}
main()
{
int i,n;
printf("Enter number of elements\n");
scanf("%d",&n);
int a[n];
for(i=0;i<n;i++)
	scanf("%d",&a[i]);
heapSort(a,n);
}







