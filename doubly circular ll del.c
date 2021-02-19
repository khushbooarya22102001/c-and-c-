#include<stdio.h>
#include<stdlib.h>
struct node{
	int data;
	struct node *next;
	struct node *prev;
};
struct node *head,*temp,*newnode,*tail;
void create()
{
	int n,i;
	printf("enter no of nodes:");
	scanf("%d",&n);
	for(i=0;i<n;i++)
	{
		newnode=(struct node*)malloc(sizeof(struct node));
		printf("%d",&newnode->data);
		if(head==0)
		{
			head=tail=newnode;
			newnode->next=head;
			newnode->prev=head;
		}
		else{
			tail->next=newnode;
			newnode->prev=tail;
			newnode->next=head;
			head->prev=newnode;
			tail=newnode;
		}
	}
}
void display()
{
	temp=head;
	while(temp->next!=head)
	{
		printf("%d\t",temp->data);
		temp=temp->next;
	}
	printf("%d",data);
}
int main()
{
	create();
	display();
}

