#include<stdio.h>
#include<stdlib.h>
struct node{
	int data;
	struct node *link;
};
struct node *top=0;
struct node *newnode;
void push(int x)
{
	newnode=(struct node*)malloc(sizeof(struct node));
	newnode->data=x;
	newnode->link=top;
	top=newnode;
}
void pop()
{
	struct node *temp;
	temp=top;
	top=top->link;
	free(temp);
}
void display()
{
	struct node *temp;
	temp=top;
	while(temp!=0)
	{
		printf("%d\t",temp->data);
		temp=temp->link;
	}
}
int main()
{
	push(2);
	push(3);
	push(4);
	push(5);
	display();
	pop();
	pop();
	printf("\n");
	display();
}
