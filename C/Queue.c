/*
Write a program to implement QUEUE using arrays that performs following operations
(a) INSERT (b) DELETE (c) DISPLAY
*/

#include <stdio.h>
#include <stdlib.h>

#define MAX  3

void QPUSH();
void Display();
void QPOP();

int queue[MAX];

int rear = -1,front = -1;

void QPUSH()
{
	int element;
	if (rear == MAX-1)
	{
		printf("\n Queue is Overflow.");
	}
	else
	{
		printf("\n Enter element to be inserted in a queue.");
		scanf("%d",&element);
		if (front==-1)
		{
			front=rear=0;
		}
		else
		{
			rear++;			
		}
			queue[rear]=element;
			printf("\n inserted element is: %d",element);
	}
}

void QPOP()
{
	int del_element;
	if (front == -1)
	{
		printf("\n Queue is Underflow.\n");
	}
	else
	{
		del_element=queue[front];
		if (front==rear)
		{
			front=rear=-1;
		}	
		else
		{
			front++;
		}
		printf("\n Element Deleted. %d \n",del_element);
	}
}

void Display()
{
	if (front==-1)
	{
		printf("\n Queue is Empty.\n");
	}
	else
	{
		for (int i = front; i <= rear ; i++)
		{
			printf("\n %d\t ",queue[i]);
		}
	}
}

int main()
{

	int choice;
	while(1)
	{
		printf("\n\n 1. Insert element to queue. \n 2. Delete element from queue \n 3. Display data in a queue. \n 4. Exit");
		printf("\n\n Enter your choice: ");
		scanf("%d",&choice);

		switch(choice)
		{
			case 1:
				// printf("\n Insert");
					QPUSH();
			break;

			case 2:
				// printf("\n Delete");
					QPOP();
			break;

			case 3:
				// printf("\n Display");
					Display();
			break;

			case 4:
				exit(0);
			break;

			default:
				printf("\n Enter valid choice.");
			break;			
		}

	}
	return 0;
}
