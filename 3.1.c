#include <stdio.h>
#include<string.h>
#include<stdbool.h>
#define max_size 10
typedef struct
{
    int top ;
    int items[max_size];
}stack;
stack s1;
void initialise()
{
    s1.top=-1;
    printf("STACK HAS BEEN CREATED\n");
}
bool isfull()
{
    if(s1.top>=max_size-1)
    {
        s1.top=max_size-1;
        return true;
    }
    return false;
}
bool isempty()
{
    if(s1.top<0)
    {
        s1.top=-1;
        return true ;
    }
    return false;
}
void push(int num)
{
    if (isfull())
    {
        printf("STACK OVERFLOW");
        return;
    }
    else
    {
        s1.items[++s1.top]=num ;
    }
}
int pop ()
{
    if (isempty())
    {
        printf("STACK UNDERFLOW");
        return;
    }
    else
    {
        int num = s1.items[s1.top--];
        return num;
    }
}
int main()
{
    char inp[100];
    int i , length;
    printf("ENTER THE STRING : ");
    gets(inp);
    initialise();
    length = strlen(inp);
    for(i=0 ; i<length ; i++)
    {
        push(inp[i]);

    }
    for(i=0;i<length;i++)
    {
        if(pop()!=inp[i])
        {
            printf("it is not a palindrome");
            return 0;
        }
    }
    printf("it is a palindrome");
    return 0;
}
