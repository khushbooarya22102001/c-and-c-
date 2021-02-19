#include<stdio.h>
#include<stdlib.h>
struct node{
	int data;
	struct node *next;
	struct node *prev;
};
struct node *head,*tail,*newnode,*temp;
void create()
{
	int n,i;
	printf("enter no of nodes:");
	scanf("%d",&n);
	for(i=0;i<n;i++)
	{
		newnode=(struct node*)malloc(sizeof(struct node));
		printf("\nenter data:");
		scanf("%d",&newnode->data);
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
void delbeg()
{
	temp=head;
	head=head->next;
	head->prev=tail;
	tail->next=head;
	free(temp);
}
void delend()
{
	temp=tail;
	if(head==0)
	{
		printf("empty");
	}
	else if(head->next==head)
	{
		head=tail=0;
		free(temp);
	}
	else{
		tail=tail->prev;
		tail->next=head;
		head->prev=tail;
		free(temp);
		
	}
	
}
void delspe()
{
	int pos;
	int i=1;
	printf("\nenter pos:");
	scanf("%d",&pos);
	temp=head;
	while(i<pos)
	{
		temp=temp->next;
		i++;
		
	}
	temp->prev->next=temp->next;
	temp->next->prev=temp->prev;
	if(tail->next==head)
	{
		temp->prev->next=head;
		free(temp);
	}
	else{
		free(temp);
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
	printf("%d",temp->data);
}
int main()
{
	create();
	display();
	delbeg();
	printf("\n");
	display();
	delend();
	printf("\n");
	display();
	delspe();
	printf("\n");
	display();

}
