#include <stdio.h>
#include <stdlib.h> 
struct node
{
    int data;
    struct node *left;
    struct node *right;
};
struct node* newNode (int data)
{
    struct node* temp = (struct node *) malloc(sizeof(struct node));
    temp->data = data;
    temp->left = temp->right = NULL;
    return temp;
}
struct node* constructTree(int pre[],int post[],int* preIndex,int l,int h, int size)
{
    if(*preIndex >= size || l > h)
        return NULL; 
    struct node* root = newNode ( pre[*preIndex] );
    ++*preIndex;
    if (l==h)//only one node
        return root;
    int i;
    for (i=l;i<=h;i++)//use i to divide array 
        if (pre[*preIndex] == post[i])
            break;
    if (i <= h)
    {
        root->left = constructTree(pre, post, preIndex, l, i, size);
        root->right = constructTree(pre, post, preIndex, i + 1, h, size);
    }
    return root;
}
struct node *construct_Tree (int pre[], int post[], int size)
{
    int preIndex = 0;
    return constructTree(pre,post,&preIndex,0,size-1,size);
}
void printInorder (struct node* node)
{
    if (node == NULL)
        return;
    printInorder(node->left);
    printf("%d ", node->data);
    printInorder(node->right);
}
int main ()
{
    int n,i;
    printf("Enter number of elements\n");
    scanf("%d",&n);
    int pre[n];
    int post[n];
    printf("Enter elements in pre order\n");
    for(i=0;i<n;i++)
	scanf("%d",&pre[i]);
    printf("Enter elements in post order\n");
    for(i=0;i<n;i++)
        scanf("%d",&post[i]);
    struct node *root = construct_Tree(pre,post,n);
    printf("Inorder traversal of the constructed tree: \n");
    printInorder(root);
    return 0;
}
