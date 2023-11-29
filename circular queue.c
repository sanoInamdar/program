#include<stdio.h>
#define MAX 5
void enqueue(int x);
void dequeue();
void display();
void exit();
int queue[MAX],front=-1,rear=-1;
int main()
{
 int ch,x;
 while(1)
 {
 printf("\n1.enqueue\n2.dequeue\n3.display\n4.exit\n");
 scanf("%d",&ch);
 switch(ch)
 {
 case 1: printf("enter value to insert ");
 scanf("%d",&x);
enqueue(x);
 break;
 case 2:dequeue();
 break;
 case 3:display();
 break;
 case 4: exit();
 break;
 default:printf("\nwrong choice");
 }
 }
}
void enqueue(int x)
{
if(front==-1&&rear==-1)
{
 front=rear=0;
 queue[rear]=x;
}
else if((rear+1)%MAX==front)
{
 printf("queue is full");
}
else
{
 rear=(rear+1)%MAX;
 queue[rear]=x;
}
}
void dequeue()
{
 if(front==-1&&rear==-1)
 {
 printf("queue is empty");
 }
 else if(front==rear)
 {
 printf("%d is deleted",queue[front]);
 front=rear=-1;
 }
 else
 {
 printf("%d is deleted",queue[front]);
 front=(front+1)%MAX;
 }
}
void display()
{
 int i=front;
 if(front==-1&&rear==-1)
 {
 printf("queue is empty");
 }
 else
 {
 while(i<=rear)
 {
 printf("\n%d",queue[i]);
 i=(i+1)%MAX;
 }
 }
}

