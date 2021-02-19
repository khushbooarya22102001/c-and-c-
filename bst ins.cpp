#include<stdio.h>
#include<stdlib.h>
struct node{
	int data;
	struct node* left;
	struct node* right;
};
struct node* getnode(int x)
{
	struct node* newnode;
	newnode=(struct node*)malloc(sizeof(struct node));
	newnode->data=x;
	newnode->left=NULL;
	newnode->right=NULL;
	return newnode;
}
struct node* ins(struct node* root,int d)
{
	if(root==0)
	{
		root=getnode(d);
	}
	else if(d<=root->data)
	{
		root->left=ins(root->left,d);
	}
	else if(d>root->data)
	{
		root->right=ins(root->right,d);
	}
	return root;
}
bool search(struct node* root,int key)
{
	if(root==0)
	{
		return false;
	}
	else if(key==root->data)
	{
		return true;
	}
	else if(key<root->data)
	{
		return search(root->left,key);
	}
	else if(key>root->data)
	{
		return search(root->right,key);
	}
	return false;
	
}
struct node* findmin(struct node* root)
{
	struct node* curr=root;
	while(curr && curr->left!=NULL)
	{
		curr=curr->left;
	}
	return curr;
}
int inorder(struct node *root)
{
	if(root!=NULL)
	{
	inorder(root->left);
	printf("%d  ",root->data);
	inorder(root->right);
}
}
struct node* del(struct node* root,int x)
{
	if(root==0)
	{
		return root;
	}
	else if(x<root->data)
	{
		root->left=del(root->left,x);
	}
	else if(x>root->data)
	{
		root->right=del(root->right,x);
	}
	else{
		if(root->left==NULL && root->right==NULL)
		{
			free(root);
			root=0;
			return root;
		}
		else if(root->left==NULL)
		{
			struct node* temp=root;
			root=root->right;
			free(temp);
			return root;
		}
		else if(root->right==NULL)
		{
			struct node* temp=root;
			root=root->left;
			free(temp);
			return root;
		}
		else
		{
			struct node* temp=findmin(root->right);
			root->data=temp->data;
			root->right=del(root->right,temp->data);
			return root;
		}
	}
}
int main()
{
	struct node* root;
	root=0;
	root=ins(root,50);
	root=ins(root,30);
	root=ins(root,20);
	root=ins(root,40);
	root=ins(root,70);
	root=ins(root,60);
	root=ins(root,80);
	inorder(root);
	printf("\n");
	del(root,20);
	inorder(root);
	printf("\n");
	del(root,50);
	inorder(root);
}
