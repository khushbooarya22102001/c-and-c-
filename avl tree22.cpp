#include<stdio.h>
#include<stdlib.h>
struct node{
	int data;
	struct node* left;
	struct node* right;
	int hei;
};
int max(int a,int b)
{
	if(a>b)
	return a;
	else{
		return b;
	}
}
int height(struct node* x)
{
	if(x==0)
	{
		return 0;
	}
	else{
		return x->hei;
	}
}
struct node* getnew(int x)
{
	struct node* newnode;
	newnode=(struct node*)malloc(sizeof(struct node));
	newnode->data=x;
	newnode->left=0;
	newnode->right=0;
	newnode->hei=1;
}
int getbal(struct node* root)
{
	if(root==NULL)
	{
		return 0;
	}
	else{
		return height(root->left)-height(root->right);
	}
}
struct node* lefrot(struct node* y)
{
	struct node* x=y->right;
	struct node* z=x->left;
	
	x->left=y;
	y->right=z;
	
	x->hei=max(height(x->left),height(x->right))+1;
	y->hei=max(height(y->left),height(y->right))+1;
	return x;
}
struct node* rigrot(struct node* x)
{
	struct node* y=x->left;
	struct node* z=y->right;
	
	y->right=x;
	x->left=z;
	
	x->hei=max(height(x->left),height(x->right))+1;
	y->hei=max(height(y->left),height(y->right))+1;
	
	return y;
}
void preorder(struct node* root)
{
	if(root!=NULL)
	{
		printf("%d  ",root->data);
		preorder(root->left);
		preorder(root->right);
	}
}
struct node* ins(struct node* root,int key)
{
	if(root==NULL)
	{
		return getnew(key);
	}
	else if(key<root->data)
	{
		root->left=ins(root->left,key);
	}
	else if(key>root->data)
	{
		root->right=ins(root->right,key);
	}
	root->hei=max(height(root->left),height(root->right))+1;
	int bal=getbal(root);
	if(bal>1 && key<root->left->data){
		
		return rigrot(root);
	}
	else if(bal>1 && key>root->left->data)
	{
		root->left=lefrot(root->left);
		return rigrot(root);
	}
	else if(bal<-1 && key>root->right->data)
	{
		return lefrot(root);
		
	}
	else if(bal<-1 && key<root->right->data)
	{
		root->right=rigrot(root->right);
		return lefrot(root);
	}
	return root;
}
int main()
{
	struct node* root=NULL;
	root=ins(root,10);
	root=ins(root,20);
	root=ins(root,30);
	root=ins(root,40);
	root=ins(root,50);
	root=ins(root,25);
	preorder(root);
}
