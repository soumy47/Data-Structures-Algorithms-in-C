#include<stdio.h>
#include<stdlib.h>

struct node{
    int data;
    struct node* left, *right;
};

struct node* MinInRS(struct node*root)
{
    if(root==NULL)
    {
        return root;
    }
    while(root->left)
    {
        root=root->left;
    }
    return root;
}


void inorder(struct node* root)
{
    if(root==NULL)
        return;
    inorder(root->left);
    printf("%d ",root->data);
    inorder(root->right);   
}


struct node* DeleteNode(struct node *root, int data) {
	if(root == NULL) return root; 
	else if(data < root->data) 
        root->left = DeleteNode(root->left,data);
	else if (data > root->data) root->right = DeleteNode(root->right,data);
	// Wohoo... I found you, Get ready to be deleted	
	else {
		// Case 1:  No child
		if(root->left == NULL && root->right == NULL) { 
			 free(root);
			root = NULL;
		}
		//Case 2: One child 
      //either rightchild
		else if(root->right!= NULL) {
			struct node *temp = root;
			root = root->right;
			free(temp);
		}
      //or leftchild
		else if(root->left!= NULL) {
			struct node *temp = root;
			root = root->left;
			free(temp);
		}
		// case 3: 2 children
		else { 
			struct node *temp = MinInRS(root->right);
			root->data = temp->data;
			root->right = DeleteNode(root->right,temp->data);
		}
	}
	return root;
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

    root=insert(root,20);
    root=insert(root,75);
    root=insert(root,50);
    root=insert(root,14);
    root=insert(root,9);
    root=insert(root,42);
    root=insert(root,60);
    root=insert(root,59);
    root=insert(root,47);
    root=insert(root,22);

    printf("Before deletion of the node: ");
    inorder(root);
    printf("\n");
    root =DeleteNode(root,9);
    printf("After deletion of the node: ");
    printf("Inorder: ");
    inorder(root);
    printf("\n");
    return 0;
}
