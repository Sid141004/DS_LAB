#include<stdio.h>
#define max 5
int queue[max];
int front=-1;
int rear=-1;
void enqueue(int element)
{
if(front==-1 && rear==-1)
{
front=rear=0;
queue[rear]=element;
}
else if((rear+1)%max==front)
printf("\n Queue is overflow ");
else
{
rear=(rear+1)%max;
queue[rear]=element;
}
}
int dequeue()
{
if((front==-1)&&(rear==-1))
printf("\n Queue is underflow ");
else if(front==rear)
{
printf("\n The dequeued element is %d",queue[front]);
front=rear=-1;
}
else
{
printf("\n the dequeued element is %d",queue[front]);
front=(front+1)%max;
}}
void display()
{
int i=front;
if(front==-1 && rear==-1)
printf("\n queue is empty");
else
{
printf("\n Elements in a queue are");
while(i<=rear)
{
printf("%d",queue[i]);
i=(i+1)%max;
}}}
int main()
{
int choice,item;
do
{
printf("\n 1.insert");
printf("\n 2.delete");
printf("\n 3.display");
printf("\n Enter your choice");
scanf("%d",&choice);
switch(choice)
{
    case 1:
printf("\n enter element for insertion in queue");
scanf("%d",&item);
enqueue(item);
break;
case 2:

dequeue();

break;
case 3:
display();
break;
default:
printf("wrong choice \n");
}
}while(choice<=3);
return 0;
}
