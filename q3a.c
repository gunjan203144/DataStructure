#include<stdio.h>
#include<string.h>
#include<stdlib.h>
struct wordsStack
{
	char word[50];
};
char* remove_space(char *s)
{
	char *p;
	int i=0,j=0;
	p=malloc(strlen(s)+1);
	while(*(s+i))
	{	while(*(s+i)==' ')
			i++;
	while(*(s+i)!=' ' && *(s+i)!='\0')
	{
		*(p+j)=*(s+i);
		i++;
		j++;
	}
	if(*(s+i)=='\0'&&*(p+j-1)==' ') 
		j--;
	*(p+j)=*(s+i);
	j++;
	}
	return p;
}
int count_words(char *s)
{
	int i=0,count=0;
	while(*(s+i))
	{
		if(*(s+i)==' ')
			count++;
		i++;
	}
	return count+1;
}
char* reverseWordsOfSentence(struct wordsStack *ptr,char *s)
{
char temp[50],*q;
int i=0,j,top=0;
while(*(s+i))
{	j=0;
	while(*(s+i)!=' '&& *(s+i)!='\0')
	{
		temp[j]=*(s+i);
		j++;
		i++;
	}
	if(*(s+i)==' ')
	i++;
	temp[j]='\0';
	strcpy(ptr[top].word,temp);
	top++;
}
q=(char*)malloc(strlen(s)+1);
*(q+0)='\0';
top--;
while(top)
{
	strcat(q,ptr[top].word);
	strcat(q," ");
	top--;
}	
strcat(q,ptr[0].word);
return q;
}
main()
{
int no_words;
char str[256];
struct wordsStack *ptr;
printf("Enter string\n");
gets(str);
strcpy(str,remove_space(str));
no_words=count_words(str);
ptr=(struct wordsStack *)calloc(no_words,sizeof(struct wordsStack));
strcpy(str,reverseWordsOfSentence(ptr,str));
printf("Reversed String is\n%s \n",str);
}




