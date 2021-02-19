#include<stdio.h>
#include<stdlib.h>
struct node{
	int data;
	struct node *left;
	struct node *right;
};
struct node* create()
{
	int x;
	struct node* newnode;
	newnode=(struct node*)malloc(sizeof(struct node));
	printf("\n enter data(-1 for no data:)");
	scanf("%d",&x);
	if(x==-1)
	{
		return 0;
	}
	else{
		newnode->data=x;
		printf("\n enter left child:%d",x);
		newnode->left=create();
		printf("\n enter right child:%d",x);
		newnode->right=create();
	}
}
void preorder(struct node *root)
{
	if(root==0)
	{
		return;
	}
	else{
		printf("%d\t",root->data);
		preorder(root->left);
		preorder(root->right);
	}
}
void inorder(struct node *root)
{
	if(root==0)
	{
		return;
	}
	else{
		inorder(root->left);
		printf("%d\t",root->data);
		inorder(root->right);
	}
}
void postorder(struct node *root)
{
	if(root==0)
	{
		return;
	}
	else{
		postorder(root->left);
		postorder(root->right);
		printf("%d\t",root->data);
	}
}

int main()
{
	struct node *root;
	root=create();
	printf("\npreorder");
	preorder(root);
	printf("\n inorder:");
	inorder(root);
	printf("\n postorder:");
	postorder(root);
}
