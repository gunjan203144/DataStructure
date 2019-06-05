#include<stdio.h>
#include<stdlib.h>
struct node
{
	int data;
	struct node *left;
	struct node *right;
};
typedef struct node Node;
Node* getNode(int x)
{
	Node *temp = (Node*)malloc(sizeof(Node));
	temp->data = x;
	temp->left = NULL;
	temp->right = NULL;
	return temp;
}
Node * insert(Node* root, int x)
{
	if ( root == NULL){
        root = getNode(x);
	}
	else if (x <= root->data){
        root->left = insert(root->left,x);
	}
	else if ( x> root->data){
        root->right = insert(root->right,x);
	}
	return root;
}
void preorder(Node * root)
{
	    if (root !=NULL)
        {
        	printf("%d,",root->data);
        	preorder(root->left);
        	preorder(root->right);
    	}
}
void inorder(Node * root)
{
    	if (root !=NULL)
    	{
    	    inorder(root->left);
    	    printf("%d,",root->data);
    	    inorder(root->right);
    	}
}
void postorder(Node * root)
{
    	if (root !=NULL)
    	{
     		postorder(root->left);
        	postorder(root->right);
        	printf("%d,",root->data);
    	}
}
int contains(Node *root,int i)
{
	int flag=0;
 	if(root!=NULL)
	{
		if(root->data>=i)
		{
			if(root->data==i)
				flag=1;
        		else
			flag=contains(root->left,i);
		}
                else{	
			flag=contains(root->right,i);
		}
	}
       return flag;
}
int min(Node *root)
{
	int k=-1;
	if(root==NULL)
      		k=-1;
	else{
	if(root->left==NULL)	
		k=root->data;
        else
		k=min(root->left);
	}
	return k;
}

int max(Node *root)
{
	int k=-1;
	if(root==NULL)
      		k=-1;
	else{
		if(root->right==NULL)
			k=root->data;
        	else
			k=max(root->right);
	}
	return k;
}
int isComplete(Node* root)
{
	int flag=0,c,l,r;
	if(root==NULL)
		c=1;
	else 
	{
		if(root->left!=NULL && root->right!=NULL)
		{
			l=isComplete(root->left);
			r=isComplete(root->right);	
			c=l&r;
		}
		else if(root->left==NULL && root->right==NULL)
			c=1;
		else
			c=0;				
	}	
	return c;
}		
Node* min_addr(Node* root)
{
	if(root->left!=NULL)
		root=min_addr(root->left);
	return root;
} 
Node* delete(Node* root,int i)
{
	Node* temp;
	int b;
	b=contains(root,i);
	if(root==NULL || b==0)
		return root;
	else if(b==1){
		if(i<root->data )
			root->left=delete(root->left,i);
		else if(i>root->data)
			root->right=delete(root->right,i);	
		else
		{	
			if(root->left==NULL && root->right==NULL)
			{
				free(root);
				root=NULL;
				return root;
			}
			else if(root->left==NULL)
			{
				temp=root;
				root=root->right;
				free(temp);
				return root;		
			}
			else if(root->right==NULL)
			{
				temp=root;
				root=root->left;
				free(temp);
				return root;		
			}
			else
			{
				temp=min_addr(root->right);
				root->data=temp->data;
				root->right=delete(root->right,temp->data);
				return root;
			}	
		}
	}
	return root;
}

int main()
{
	int choice,data,b;
	Node *root;
	while(1)
	{
		printf("1.Contains\n2.Insert\n3.Delete\n4.Min\n5.Max\n6.Complete\n7.Inorder traversal\n0.To exit\n");
		scanf("%d",&choice);
		switch(choice)
		{
			case 0: exit(0);
					break;
			case 1: printf("Enter the element\n");
					scanf("%d",&data);
					b=contains(root,data);
					if(b==1)
						printf("True\n");
					else
						printf("False\n");
					break;
			case 2: printf("Enter the element to be inserted\n");
					scanf("%d",&data);
					root=insert(root,data);
					break;
			case 3: printf("Enter the data to be deleted\n");
					scanf("%d",&data);
					root=delete(root,data);
					break;
			case 4: data=min(root);
					printf("Minimum element is %d\n",data); 
					break;
			case 5: data=max(root);
					printf("Maximum element is %d\n",data); 
					break;
			case 6: b=isComplete(root);
					if(b==1)
						printf("True\n");
					else
						printf("False\n");
					break;			
			case 7: inorder(root);
					printf("\n");
					break;
			default: printf("Invalid choice");
					 break;
		}
	}
	   
}
