#include<stdio.h>
#include<stdlib.h>
struct node
{
    int data;
    int ht;
    struct node *left;
    struct node *right;
};
typedef struct node Node;
Node* getNode(int x)
{
    Node *temp = (Node*)malloc(sizeof(Node));
    temp->data = x;
    temp->left = NULL;
    temp->ht=1;
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
        root->left->ht=root->ht+1;
    }
    else if ( x> root->data){
        root->right = insert(root->right,x);
        root->right->ht=root->ht+1;
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
int height(Node *T)
{
    int lh,rh;
    if(T==NULL)
        return(0);
    lh=height(T->left);
    rh=height(T->right);
    if(lh>rh)
        return(1+lh);
    else
	return 1+rh;	
}
maxLength(Node* root,int *maxl, int *maxr)
{
	Node *p;
	int l=-1,r=-1,lm=-1,rm=-1;
	p=root;
	if(root==NULL)
		return;
	else{
	while(p->left!=NULL)
	{
		l=height(p->left);
		r=height(p->right);
		/*if(lm<l)
                        lm=l;
		if(rm<r)
			rm=r;*/
		if(*maxl+*maxr < l+r)
		{
			*maxl=l;
			*maxr=r;
		}
		if(p->left->right!=NULL)
			p->right=p->left->right;
		p->left=p->left->left;
	}
	p=root;
	while(p->right!=NULL)
	{
		l=height(p->left);
		r=height(p->right);
		 if(*maxl+*maxr < l+r)
                {
                        *maxl=l;
                        *maxr=r;
                }
		if(p->right->left!=NULL)
			p->left=p->right->left;
		p->right=p->right->right;
	}	
	}
}
int main()
{
    int i,n,j,maxl=0,maxr=0;
    Node * root = NULL;
    printf("Enter number of elements\n");
    scanf("%d",&j);
    for(i=1; i<=j; i++)
    {
 	scanf("%d",&n);
        root = insert(root,n);
    }
     printf("\nInorder : ");
     inorder(root);
     maxLength(root,&maxl,&maxr);
     printf("\nLongest path of tree is : %d\n",maxl+maxr);
}
