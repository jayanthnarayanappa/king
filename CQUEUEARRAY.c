#include<stdio.h>
#include<stdlib.h>
#define MAX 10
 
int qarray[MAX];
int front=-1;
int rear=-1;
 
void display( );
void insert(int item);
int del();
int peek();
int isEmpty();
int isFull();
 
int main()
{
        int choice,item;
        while(1)
        {
                printf("\nEnter your choice : ");
                printf("\n1.Insert\n");
                printf("2.Delete\n");
                printf("3.Peek\n");
                printf("4.Display\n");
                printf("5.Quit\n");
                scanf("%d",&choice);
 
                switch(choice)
                {
                case 1 :
                        printf("\nEnter the element : \n");
                        scanf("%d",&item);
                        insert(item);
                        break;
                case 2 :
                        printf("\nElement deleted is : %d\n",del());
                        break;
                case 3:
                        printf("\nElement at the front is  : %d\n",peek());
                        break;
                case 4:
                        display();
                        break;
                case 5:
                        exit(1);
                default:
                        printf("\nWrong choice\n");
                }
        }
 
        return 0;
 
}
 
void insert(int item)
{
        if( isFull() )
        {
                printf("\nQueue Overflow\n");
                return;
        }
        if(front == -1 )
                front=0;
 
        if(rear==MAX-1)
                rear=0;
        else
                rear=rear+1;
        qarray[rear]=item ;
}
 
int del()
{
        int item;
        if( isEmpty() )
        {
                printf("\nQueue Underflow\n");
                exit(1);
        }
        item=qarray[front];
        if(front==rear)
        {
                front=-1;
                rear=-1;
        }
        else if(front==MAX-1)
                front=0;
        else
                front=front+1;
        return item;
}
 
int isEmpty()
{
        if(front==-1)
                return 1;
        else
                return 0;
}
 
int isFull()
{
        if((front==0 && rear==MAX-1) || (front==rear+1))
                return 1;
        else
                return 0;
}
 
int peek()
{
        if( isEmpty() )
        {
                printf("\nQueue Underflow\n");
                exit(1);
        }
        return qarray[front];
}
 
void display()
{
        int i;
        if(isEmpty())
        {
                printf("\nQueue is empty\n");
                return;
        }
        printf("\nQueue elements :\n");
        i=front;
        if( front<=rear )
        {
                while(i<=rear)
                        printf("%d ",qarray[i++]);
        }
        else
        {
                while(i<=MAX-1)
                        printf("%d ",qarray[i++]);
                i=0;
                while(i<=rear)
                        printf("%d ",qarray[i++]);
        }
        printf("\n");
}

