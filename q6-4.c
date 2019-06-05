#include<stdio.h>
#include<stdlib.h>
struct node
{
    int data;
    int hd;
    int vd;
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
    temp->hd=0;
    temp->vd=0;
    return temp;
}
Node* insert(Node* root, int x)
{
    if ( root == NULL){
        root = getNode(x);
    }
    else if (x <= root->data){
        root->left = insert(root->left,x);
        root->left->hd=root->hd+1;
        root->left->vd=root->vd+1;
    }
    else if ( x> root->data){
        root->right = insert(root->right,x);
        root->right->hd=root->hd-1;
        root->right->vd=root->vd+1;
    }
    return root;
}
void inorder(Node* root)
{
    if (root !=NULL)
    {
        inorder(root->left);
        printf("%d, ",root->data);
        inorder(root->right);
    }
}
void sum(Node *root,int *s,int hd)
{  
	if(root==NULL)
		 return;
	else{	
	 	if(root->hd==hd)
	 	{
	 		*s = *s + root->data;
	 	}
	 sum(root->left,s,hd);	
	 sum(root->right,s,hd);
	 }	
}
int verticalSum(Node* root)
{
	int max,hd=0,s=0;
	if(root==NULL)
		return;
	else{
		sum(root,&s,hd);
		max=s;
		hd++;
		while(root->left!=NULL)
		{
			s=0;
			sum(root,&s,hd);
			if(s>max)
				max=s;
			root->left=root->left->left;
			hd++;	
		}
		hd=-1;
		while(root->right!=NULL)
		{
			s=0;
			sum(root,&s,hd);
			if(s>max)
				max=s;
			root->right=root->right->right;
			hd--;	
		}
	}
	return max;
}
int height(Node *root)
{
	int lh,rh,h;
	if(root==NULL)
		return 0;
	lh=height(root->left);
	rh=height(root->right);
	if(lh>rh)
		h=1+lh;
	else
		h=1+rh;
	return h;
}
void hsum(Node *root,int *s,int vd)
{  
	if(root==NULL)
		 return;
	else{	
	 	if(root->vd==vd)
	 	{
	 		*s = *s + root->data;
	 	}
	 hsum(root->left,s,vd);	
	 hsum(root->right,s,vd);
	 }	
}
int horiSum(Node* root,int h)
{
int max=-1,vd=0,s=0;
	if(root==NULL)
		return;
	else{
		while(vd<=h)
		{
			s=0;
			hsum(root,&s,vd);
			if(s>max)
				max=s;
			vd++;
		}
	}
	return max;
}
main()
{
Node *root,*p;
int n,i,data,vsum,h;
printf("Enter number of elements\n");
scanf("%d",&n);
for(i=0;i<n;i++)
{
	scanf("%d",&data);
	root=insert(root,data);
}
inorder(root);
p=root;
h=height(p);
vsum=horiSum(root,h);
printf("\nMaximum horizontal sum=%d",vsum);
vsum=verticalSum(p);
printf("\nMaximum vertical sum=%d\n",vsum);
}







