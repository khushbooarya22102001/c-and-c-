#include<stdio.h>
#include<stdlib.h>
struct node{
	int data;
	struct node *left;
	struct node *right;
};
struct node* create()
{
	struct node* p;
	p=(struct node *)malloc(sizeof(struct node));
	int x;
	printf("\n enter data(-1 for no data)");
	scanf("%d",&x);
	if(x==-1)
	{
		return 0;
	}
	p->data=x;
	printf("\n left child:%d",x);
	p->left=create();
	printf("\n right chile:%d",x);
	p->right=create();
	return p;
}
void preorder(struct node *t)
{
	if(t==0)
	{
		return;
	}
	else{
		printf("\n data:%d\t",t->data);
		preorder(t->left);
		preorder(t->right);
	}
}
int main()
{
	struct node *root;
	root=create();
	printf("\npreorder");
	preorder(root);
}
