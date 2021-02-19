#include<stdio.h>
#include<stdlib.h>
struct node{
	int data;
	struct node *left;
	struct node *right;
	
};
struct node *root;
struct node* search(int data)
{
	
	struct node* current=root;
	while(current->data!=data)
	{
		if(current!=0)
		{
			printf("\n%d",current->data);
			if(current->data>data)
			{
				current=current->left;
			}
			else{
				current=current->right;
			}
		}
	}
	return current;
}
struct node* create(int d)
{
	struct node* newnode;
	newnode=(struct node*)malloc(sizeof(struct node));
	newnode->data=d;
	newnode->left=newnode->right=0;
	return newnode;
	
}
struct node* insert(struct node* root,int data)
{
	if(root==0)
	{
		
		root=create(data);
	}
	else if(data<=root->data)
	{
		root->left=insert(root->left,data);
	}
	else{
		root->right=insert(root->right,data);
	}
	return root;
}
int main()
{
	struct node *root=0;
	insert(root,15);
	insert(root,10);
	insert(root,20);
	search(15);
}
