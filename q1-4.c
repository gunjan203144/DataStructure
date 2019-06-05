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
void inorder(Node * root)
{
    if (root !=NULL)
    {
        inorder(root->left);
        printf("%d,",root->data);
        inorder(root->right);
    }
}
void btw(Node *root,int x,int y)
{
	if(root==NULL)
		return;
	else{
		if(root->data>=x)
		{
			if(root->data<=y)
			{
				printf("%d, ",root->data);
				btw(root->right,x,y);
			}	
			else
				btw(root->left,x,y);
			btw(root->left,x,y);
		}
		else	
		btw(root->right,x,y);	
	}
}
main()
{
Node *root;
int n,i,data,x,y;
printf("Enter number of elements\n");
scanf("%d",&n);
for(i=0;i<n;i++)
{
	scanf("%d",&data);
	root=insert(root,data);
}
inorder(root);
printf("\n");
scanf("%d%d",&x,&y);
btw(root,x,y);
printf("\n");
}
