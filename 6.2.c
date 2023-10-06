#include<stdio.h>
#include<stdlib.h>
#include<string.h>

char stack[50];
int top=-1;

void push(char ch)
{
stack[++top]=ch;
}

char pop()
{
return stack[top--];
}

void convert(char exp[])
{
int l,i,j=0;
char tmp[20];

l=strlen(exp);
for(i=0;i<50;i++){
stack[i]='\0';
}
printf("\nThe Infix Expression is :\n ");
for(i=0;i<l;i++){
if(exp[i]=='+'||exp[i]=='-'||exp[i]=='*'||exp[i]=='/')
push(exp[i]);
else{
tmp[j++]=exp[i];
tmp[j++]=pop();
}
}
tmp[j]="\0";
//tmp[j]=exp[top--];

puts(tmp);
}
int main()
{
char exp[100];
printf("\nEnter the Prefix Expression :\n ");
gets(exp);

convert(exp);
return 0;
}
