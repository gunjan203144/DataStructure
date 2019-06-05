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


int main()
{
    int i,n,j;
    Node * root = NULL;
    printf("Enter number of elements\n");
    scanf("%d",&j);
    for(i=1; i<=j; i++)
    {
 	scanf("%d",&n);
        root = insert(root,n);
    }
            //root = insert(root,rand()%100);
     printf("\nPostorder :");
     postorder(root);
     printf("\nPreorder :");
     preorder(root);
     printf("\nInorder : ");
     inorder(root);
}
