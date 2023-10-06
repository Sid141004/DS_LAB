#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef enum {
    operand,
    operator
} precedence;

#define MAX_SIZE 100

char s[MAX_SIZE][20]; // Changed from char*[20] to char s[MAX_SIZE][20]
int top = -1;

// Function to push an element onto the stack
void push(char a[])
{
    if (top >= MAX_SIZE - 1)
    {
        printf("Stack is full\n");
    }
    else
    {
        strcpy(s[++top], a);
    }
}

// Function to pop an element from the stack
char* pop()
{
    if (top == -1) {
        printf("Stack is empty\n");
        exit(1);
    }
    else
    {
        return s[top--];
    }
}

// Function to check if a character is an operand or an operator
precedence get_token(char c)
{
    if (c >= '0' && c <= '9')
        return operand;
    else
        return operator;
}

// Function to convert postfix expression to infix expression
void postfix2infix(char postfix[])
{
    char temp1[3], temp2[20], op1[20], op2[20]; // Fixed variable declarations
    int i = 0;
    precedence temp;
    while (postfix[i] != '\0')
    {
        temp = get_token(postfix[i]);
        temp1[0] = postfix[i];
        temp1[1] = '\0';

        if (temp == operand)
        {
            push(temp1);
        }
        else
        {
            strcpy(op2, pop());
            strcpy(op1, pop());

            strcpy(temp2, "(");
            strcat(temp2, op1);
            strcat(temp2, temp1);
            strcat(temp2, op2);
            strcat(temp2, ")"); // Added closing parenthesis

            push(temp2);
        }
        i++;
    }
    printf("Infix Expression: %s\n", s[top]); // Print the final infix expression
}

int main() {
    char postfix[100];
    printf("Enter a postfix expression: ");
    scanf("%s", postfix);

    postfix2infix(postfix);

    return 0;
}


/*
Enter a postfix expression: 67+4+
Infix Expression: ((6+7)+4)
*/
