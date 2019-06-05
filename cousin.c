#include<stdio.h>
//#include<math.h>
#define INF 9999
int main()
{
	int n,b;
	printf("Enter number of nodes\n");
	scanf("%d",&n);
	int a[n],i,s,c,p,u,cousin,l;
	printf("Enter data\n");
	for(i=0;i<n;i++)
		scanf("%d",&a[i]);
	printf("Enter node data to find cousin\n");	
	scanf("%d",&cousin);
	for(i=0;i<n;i++)
	{
		if(a[i]==cousin)
		{
			c=i;
			break;
	}}
	if(c<3)
	{
		printf("-1\n");
		return 0;
	}	
	p=(c-1)/2;
	s=2*p+1;
	if(c==s)
		a[c+1]=INF;
	else
		a[c-1]=INF;
	a[c]=INF;
	s=2;	
	for(i=1;i<n;i++)
	{
		l=s;
		u=(2*s)+2;
		s=u;
		b=i;
		if(l<c && c<(u+1))
			break;		
	}
	l++;
	while(1)
	{
		if(a[l]!=INF)
			printf("%d, ",a[l]);
		l++;
		if(l==u+1 || l>n-1)
			break;
	}
	return 0;	
}
