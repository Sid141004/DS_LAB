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
int isp[]={0,19,12,12,13,13,13,0,0};
int icp[]={20,19,12,12,13,13,13,0,0};
precedence get_token(char c)
{
    switch(c)
    {
        case 'c': return lparem;
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
void postfix_eval(char * postfix)
{
    int i=0;
    precedence temp;
    while(postfix[i]!='\0')
    {

        temp = get_token(*(postfix + i));
        if (temp==operand)
            push(postfix[i] - '0');
        else
        {
            int op2=pop();
            int op1=pop();
            switch(*(postfix+i))
            {
            case '+':
                {
                    push(op1+op2);
                    break;
                }
            case '-':
                {
                    push(op1-op2);
                    break;
                }
            case '*':
                {
                    push(op1*op2);
                    break;
                }
            case '/':
                {
                    push(op1/op2);
                    break;
                }
            case '%':
                {
                    push(op1%op2);
                    break;
                }

            }
        }
        i++;
    }
    printf("result : %d",pop());
}
int main()
{
    postfix_eval("342+-");
}

