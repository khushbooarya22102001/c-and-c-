#include<stdio.h>
#include<stdlib.h>
struct node{
	int data;
	struct node *link;
};
struct node *front=0;
struct node *rear=0;
struct node *newnode,*temp;
void enq(int x)
{
	newnode=(struct node*)malloc(sizeof(struct node));
	newnode->data=x;
	if(front==0)
	{
		front=rear=newnode;
	}
	else{
		rear->link=newnode;
		rear=newnode;
		
	}
}
void deq()
{
	temp=front;
	front=front->link;
	free(temp);
}
void display()
{
	temp=front;
	while(temp!=0)
	{
		printf("%d\t",temp->data);
		temp=temp->link;
	}
	
}
int main()
{
	enq(9);
	enq(8);
	enq(7);
	enq(6);
	
	

}
