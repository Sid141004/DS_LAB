#include<stdio.h>
#include<string.h>
char s[20];
int top=-1,n=20;
void push(char a)
{
    s[++top]=a;
}
char pop()
{
    return s[top--];
}
typedef enum{lparem , rparem , plus , minus , times , division , mod , eos , operand}precedence;
int isp[]={19,0,12,12,13,13,13,0};
int icp[]={19,20,12,12,13,13,13,0};
precedence get_token(char c)
{
    switch(c)
    {
        case '(': return lparem;
        case ')': return rparem;
        case '+': return plus;
        case '-': return minus;
        case '*': return times;
        case '/': return division;
        case '%': return mod;
        case '#': return eos;
        default : return operand;
    }
}
char * infix2prefix(char * infix,char * prefix)
{
    int i=n-1,j=0;
    precedence temp;
    push('#');
    while(i>=0)
    {
        temp=get_token(infix[i]);
        if(temp==operand)
            {
                prefix[j++]=infix[i];
            }
        else if(temp==lparem)
        {
            while(s[top]!='(')
                    prefix[j++]=pop();
            pop();
        }
        else
        {
            while(icp[temp]<isp[get_token(s[top])])
            {
                prefix[j++]=pop();
            }
            push(infix[i]);
        }
        i--;
    }
    while(s[top]!='#')
        prefix[j++]=pop();
    prefix[j]='\0';
    char rev[n];
    for(i=0;j>=0;j--,i++)
        rev[i]=prefix[j];
    rev[i]='\0';
    return rev;
}
void main()
{
    char end[10];
    char prefix[10];
    char start[] = "a*b-c";
    printf("it is executed");
    printf("\n");
    puts(infix2prefix(start,prefix));

}
