#include<stdio.h>
void test(int a[],int i)
{
	a[i]=i;
	i++;
	if(i<10)
	test(a,i);
}
main()
{
	int a[100];
	int n=10,i;
	test(a,0);
	for(i=0;i<n;i++)
	printf("%d, ",a[i]);
}
