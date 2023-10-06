#include <stdio.h>

struct stack{
    int arr[100];
    int top;
};
struct stack s;
void push(int item)
{
if (s.top==99)
printf("Overflow \n");
else
{
    s.top++;
    s.arr[s.top]=item;

}
}

int isEmpty()
{
    return(s.top==-1);

}
int pop()
{
    if(s.top==-1)
    {
   printf("Underflow \n");
    return -1;
    }
    int item=s.arr[s.top];
    s.top=s.top-1;
    return item;

}
 void display()
 {
    while(isEmpty()==0)
    {
        int dig=pop();
        if(dig>9)
        {
        char c=(char)('A'+(dig-10));
       printf("%c",c);
        }
        else
       printf("%d",dig);
    }

 }
int main()
{
    s.top=-1;
    int num,r=0,d,base;
   printf("Enter number \n");
   scanf("%d",&num);
   printf("Enter base (2/8/16)\n");
   scanf("%d",&base);
   d=num;

    while(d!=0)
    {

r=d%base;

  push(r);
        if(d!=1)
        {

        d=d/base;


        }
            else
        break;
    }
    display();


    return 0;
}
