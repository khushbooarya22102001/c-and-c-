#include<stdio.h>
#include<stdlib.h>
struct node{
	int data;
	struct node* left;
	struct node* right;
	int lsize;
};
struct node* getnew(int x)
{
	struct node* newnode;
	newnode=(struct node*)malloc(sizeof(struct node));
	newnode->data=x;
	newnode->left=0;
	newnode->right=0;
	newnode->lsize=0;

	
}
struct node* insert(struct node* root,int key,int k)
{
	if(root==NULL)
	{
		return getnew(key);
	}
	else if(abs(key-root->data)<k)
	{
		return root;
	}
	else if(key<root->data)
	{
		root->left=insert(root->left,key,k);
		root->lsize++;
	}
	else if(key>root->data)
	{
		root->right=insert(root->right,key,k);
	}
	return root;
}
struct node* inorder(struct node* root)
{
	if(root==NULL)
	{
		return root;
	}
	inorder(root->left);
	printf("%d  ",root->data);
	inorder(root->right);
}
int rank(struct node* root,int x)
{
	if(root->data==x)
	{
		return root->lsize;
	}
	if(x<root->data)
	{
		if(!root->left)
		return 1;
		else{
			return rank(root->left,x);
		}
	}
	else{
		if(!root->right)
		return -1;
		else{
			int rsize=rank(root->right,x);
			if(rsize==-1)
			return -1;
			return root->lsize+1+rsize;
		}
	}
}
int main()
{
	struct node*root=0;
	root=insert(root,49,3);
	root=insert(root,46,3);
	root=insert(root,79,3);
	root=insert(root,43,3);
	root=insert(root,64,3);
	root=insert(root,83,3);
	inorder(root);
	printf("\n");
	printf("%d",rank(root,79));
	printf("\n%d",rank(root,49));
}


