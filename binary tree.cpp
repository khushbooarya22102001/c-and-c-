#include<stdio.h>
#include<stdlib.h>
struct node{
	int data;
	struct node *left;
	struct node *right;
};
struct node *root,*newnode;
struct node* create()
{
	int x;
	newnode=(struct node *)malloc(sizeof(struct node));
	printf("\n enter data or enter -1");
	scanf("%d",&x);
	if(x==-1)
	{
		return 0;
	}
	else{
		newnode->data=x;
		printf("\nleft child:%d",x);
		newnode->left=create();
		printf("\n right child:%d",x);
		newnode->right=create();
		return newnode;
		
	}
	
}
void preorder(struct node *t)
{
	if(t!=0){
	
		printf("%d\t",t->data);
		preorder(t->left);
		preorder(t->right);
	}
}
int main()
{
	
	root=create();
	printf("\n preorder:");
	preorder(root);
	
}
