#include<stdio.h>
#include<string.h>
char s[20];
int top=-1;
void push(char a)
{
    s[++top]=a;
}
char pop()
{
    return s[top--];
}
typedef enum{lparem , rparem , plus , minus , times , division , mod , eos , operand}precedence;
int isp[]={0,19,12,12,13,13,13,0};
int icp[]={20,19,12,12,13,13,13,0};
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
char * infix2postfix(char * infix,char * postfix)
{
    int i=0,j=0;
    precedence temp;
    push('#');
    while(infix[i]!='\0')
    {
        temp=get_token(infix[i]);
        if(temp==operand)
            {
                postfix[j++]=infix[i];
            }
        else if(temp==rparem)
        {
            while(s[top]!='(')
                    postfix[j++]=pop();
            pop();
        }
        else
        {
            while(icp[temp]<=isp[get_token(s[top])])
            {
                postfix[j++]=pop();
            }
            push(infix[i]);
        }
        i++;
    }
    while(s[top]!='#')
        postfix[j++]=pop();
    postfix[j]='\0';
    return postfix;
}
void main()
{
    char end[10];
    char postfix[10];
    char start[] = "((a+b)-c)/d";
    printf("it is executed");
    printf("\n");
    puts(infix2postfix(start,postfix));

}
