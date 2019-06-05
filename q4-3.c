#include<stdio.h>
#include<stdlib.h>
#include<string.h>
struct arrayStack
{
	int top;
	int capacity;
	char *array;
};
struct arrayStack* createStack(int cap)
{
	struct arrayStack *stack;
	stack=malloc(sizeof(struct arrayStack));
	stack->capacity=cap;
	stack->top=-1;
	stack->array=malloc(sizeof(char)*stack->capacity);
	return stack;
};
int isFull(struct arrayStack *stack)
{
	if(stack->top==stack->capacity-1)
		return 1;
	else
		return 0;
}
int isEmpty(struct arrayStack *stack)
{
	if(stack->top==-1)
		return 1;
	else 
		return 0;
}
void push(struct arrayStack *stack,char data)
{
	if(!isFull(stack))
	{
		stack->top++;
		stack->array[stack->top]=data;
	}
	else
	printf("\n Stack overflowed\n");	
}
char pop(struct arrayStack *stack)
{
	char item;
	if(!isEmpty(stack))
	{
		item=stack->array[stack->top];
		stack->top--;
		return item;
	}
	return -1;	
}
char str[100];
int check(struct arrayStack *stack)
{
	char data;
	if(isEmpty(stack))
		return 1;
	data=pop(stack);
	push(stack,data);
	if(data=='/' || data=='^' || data=='*' || data=='+' || data=='-' || data=='%' || data==')')
		return 0;
	else
		return 1;
}
void prefix_to_infix()
{
	int n,i,j,k,l;
	char data,op[50],po,pc,c;
	po='(';
	pc=')';
	struct arrayStack *stack;
	n=strlen(str);
	stack=createStack(n+20);
	for(i=n-1;i>=0;i--)
	{
		data=str[i];
		if(data=='/' || data=='^' || data=='*' || data=='+' || data=='-' || data=='%')
		{
			op[0]=pop(stack);
			op[1]=pop(stack);
			if(op[0]!='(' && op[1]!='(')
			{
				push(stack,pc);
				push(stack,op[1]);
				push(stack,data);
				push(stack,op[0]);
				push(stack,po);
			}
			else{
				j=0;
				push(stack,op[1]);
				push(stack,op[0]);
				while(1)
				{
					op[j]=pop(stack);
					if(op[0]=='(')
					{
						if(op[j]==')' && check(stack))
							break;
					}
					else
						if(op[j]=='(' && check(stack) && op[0]!='(')
							break;		
					j++;
				}
				k=j;
				j=j+1;
				while(1)
				{
					op[j]=pop(stack);
					if(!isEmpty(stack))
					{
						c=pop(stack);
						push(stack,c);
					}
					if((op[j]==')' && c!=')') || isEmpty(stack))
						break;
					j++;
				}
				push(stack,pc);
				j++;
				for(l=j;l>0;l--)
				{
					if(l==k)
						push(stack,data);
					push(stack,op[l]);
				}
				push(stack,po);			
			}	
		}
		else
			push(stack,data);
	}
	while(!isEmpty(stack))
	{
		str[i]=pop(stack);
		printf("%c",str[i]);
		i++;
	}
	str[i]='\0';
}
main()
{
	fflush(stdin);
	gets(str);
	prefix_to_infix();
}





