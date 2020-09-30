
#include<stdio.h>
#include<stdlib.h>

struct node{
    int data;
    struct node* left, *right;
};

void postorder(struct node* root)
{
    if(root==NULL)
        return;
    postorder(root->left);
    postorder(root->right);
    printf("%d ",root->data);  
}


void preorder(struct node* root)
{
    if(root==NULL)
        return;
    printf("%d ",root->data);
    preorder(root->left);
    preorder(root->right);    
}


void inorder(struct node* root)
{
    if(root==NULL)
        return;
    inorder(root->left);
    printf("%d ",root->data);
    inorder(root->right);   
}

struct root* createNewNode(struct node* root,int data)
{
    struct node* newNode = (struct node*)malloc(sizeof(struct node));
    newNode->data=data;
    newNode->left=NULL;
    newNode->right=NULL;  
}


struct node* insert( struct node* root, int data ) {		
	if(root==NULL)
    {
        struct node* newnode=(struct node*)malloc(sizeof(struct node));
        newnode->data=data;
        newnode->left=NULL;
        newnode->right=NULL;
        root=newnode;
    }
    else if(data <= root->data)
    {
        root->left=insert(root->left,data);
    }
    else {
        root->right=insert(root->right, data);
    }
    return root;
}

int main()
{
    struct node *root=NULL;

    root=insert(root,25);
    root=insert(root,50);
    root=insert(root,15);
    root=insert(root,30);
    root=insert(root,9);
    root=insert(root,20);
    printf("Preorder: ");
    preorder(root);
    printf("Inorder: ");
    inorder(root);
    printf("Postorder: ");
    postorder(root);
    return 0;
}
