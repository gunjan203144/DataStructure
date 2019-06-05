#include<stdio.h>
#include<string.h>
#include<malloc.h>
struct node{
	char st_name[30];
	int year;
	int ac_no;
	char ac_name[20];
	char ac_type[20];
	char cand_name[100];
	char cand_sex;
	char partyname[30];
	char partyabbre[10];
	long int totalvotpoll;
	long int electors;
	struct node *link;
};
struct node *start=NULL;
struct node* createnode()
{
	struct node *n;
	n=(struct node *)malloc(sizeof(struct node));
	return(n);
};
struct node* insertNode(struct node *start,char st_name[],int year,int ac_no,char ac_name[],char ac_type[],char cand_name[],char cand_sex,char partyname[],char partyabbre[],long int totalvotpoll,long int electors)
{
	struct node *temp,*t;
	temp=createnode();
	temp->year=year;
	temp->ac_no=ac_no;
	strcpy(temp->ac_name,ac_name);
	strcpy(temp->ac_type,ac_type);
	strcpy(temp->cand_name,cand_name);
	temp->cand_sex=cand_sex;
	strcpy(temp->partyname,partyname);
	strcpy(temp->partyabbre,partyabbre);
	temp->totalvotpoll=totalvotpoll;
	temp->electors=electors;
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
 return(start);
};
main()
{
	struct node *temp,*w;
	float male=0,female=0;
	FILE *fp;
	int i=0,fpr,j;
	char st_name[30];
	int year,tmp;
	int ac_no;
	char ac_name[20];
	char ac_type[20];
	char cand_name[100];
	char cand_sex;
	char partyname[30];
	char partyabbre[10];
	long int totalvotpoll;
	long int electors;
	fp = fopen("Indore_Election_data_modified.txt","r");
	while(1)
	{
	fpr=	fscanf(fp,"%[^\n\t]\t%d\t%d\t%s\t%s\t%[^\n\t]\t%c\t%[^\n\t]\t%s\t%ld\t%ld\n", 					st_name,&year,&ac_no,ac_name,ac_type,cand_name,&cand_sex,partyname,partyabbre,&totalvotpoll,&electors);

	start= insertNode(start,st_name,year,ac_no,ac_name,ac_type,cand_name,cand_sex,partyname,partyabbre,totalvotpoll,electors); 
	i++;
	if(fpr==-1)
		break;
	}
	j=i;
	temp=start;
	while(temp!=NULL)
	{
	w->link=temp;
	tmp=temp->year;
	while(tmp==temp->year)
	{
	if(temp->link->totalvotpoll > temp->totalvotpoll)
	{
		temp=temp->link;
		w->link=temp;
	}
	else
		temp=temp->link;	
	}
	printf("Winner of election of year %d\tis %s\n",w->year,w->cand_name);
	printf("Percentage of vote given: %f% \n\n",100.00*w->totalvotpoll/w->electors);

	temp=temp->link;
	}
	temp=start;
	while(temp!=NULL)
	{
		if(temp->cand_sex=='M')
		male++;
		else if(temp->cand_sex=='F')
		female++;
		temp=temp->link;
	}
	printf("\n\n\n\n\nPercentage of male candidates is %f%\n",100*male/(male+female));
	printf("Percentage of female candidates is %f%\n\n\n\n",100*female/(male+female));
}





