 #include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define max 100

char stack[max];
int top=-1;
void push(char ch)
{
stack[++top]=ch;
}
char pop()
{
return stack[top--];
}
void eval(char exp[])
{
int l,i,j=0;
l=strlen(exp);
 int result;
for(i=l-1;i>=0;i--)
{
if(isalnum(exp[i]))
push(exp[i]-'0');
else if (exp[i]== '+' || exp[i] == '-' || exp[i] == '*' || exp[i] == '/'
            || exp[i] == '^')
{
char operator=exp[i];
if(top<1)
    printf("invalid");
int op2=pop();
int op1=pop();
switch(operator)
{
case'+':
result=op2+op1;
break;
case'-':
result=op1-op2;
break;
case'*':
result=op2*op1;
break;
case'/':
    if(op2==0)
    {
        printf("division by zero \n");
        return;
    }
result=op1/op2;
break;
case '^':
result=op1^op2;
break;
}
push(result);
}
}
int finalresult=pop();
printf("Evaluated prefix expression is :\n");
printf("%d",finalresult);
}
int main()
{
char prefix[max];
printf("Enter prefix expression\n");
gets(prefix);
eval(prefix);
return 0;
}
