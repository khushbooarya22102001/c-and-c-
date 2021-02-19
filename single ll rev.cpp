#include<stdio.h>
#include<stdlib.h>
struct node{
	int data;
	struct node *next;
};
struct node *head,*temp,*newnode;
void create()
{
	int n,i;
	printf("\n enter no of nodes:");
	scanf("%d",&n);
	for(i=0;i<n;i++)
	{
	
	newnode=(struct node*)malloc(sizeof(struct node));
	printf("\n enter data:");
	scanf("%d",&newnode->data);
	if(head==0)
	{
		head=temp=newnode;
	}
	else{
		temp->next=newnode;
		temp=newnode;
	}
}
}
void display()
{
	temp=head;
	while(temp!=0)
	{
		printf("%d\t",temp->data);
		temp=temp->next;
	}
}
void rev()
{
	struct node *curr,*nextnode,*prev;
	prev=0;
	curr=nextnode=head;
	while(nextnode!=0)
	{
		nextnode=nextnode->next;
		curr->next=prev;
		prev=curr;
		curr=nextnode;
	}
	head=prev;
}
int main()
{
	create();
	display();
	rev();
	display();
}
