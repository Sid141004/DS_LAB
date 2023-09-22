/*insert in beginning , insert in end , insert at the given position , delete from the begininng , delete from the end*/
#include <stdio.h>
#include <stdlib.h>
#define size 8
typedef struct node
{
    int data;
    struct node * next;
}node;
node * first = NULL;
void insert(int n)
{
    node * temp = (node *)malloc(size);
    temp->next=NULL;
    temp->data=n;
    node * curr;
    if(first==NULL)
        first=temp;
    else
    {
        for(curr=first ; curr->next!=NULL;curr=curr->next);
        curr->next=temp;
    }
}
void disp()
{
    node * curr;
    if(first==NULL)
        printf("list is empty");
    else
    {
        for(curr=first;curr!=NULL;curr=curr->next)
        {
            printf("%d\t",curr->data);
        }
        printf("\n");
    }
}
void insertfront(int n)
{
    node * temp = (node *)malloc(size);
    temp->data=n;
    temp->next=first;
    first=temp;
}
void insertbefore(int n,int k)
{
    node * temp=(node *)malloc(size);
    temp->data=n;
    node * curr;
    node * prev;
    int key = k;
    if(first==NULL)
    {
        printf("LIST IS EMPTY");
        first=temp;
        temp->next=NULL;
    }
    for(curr=first,prev=first;(curr!=key&&curr->next!=NULL);prev=curr,curr=curr->next)
    {
        if(curr->next->data==k)
        {
            temp->next=curr->next;
            curr->next=temp;
            return;
        }
    }
    /*curr = first;
    while(curr->next->data!=key&&curr->next!=NULL)
    {
        curr=curr->next;
    }
    if(curr->next == NULL)
    {
        printf("NODE NOT FOUND");
        free(temp);
        return;
    }
    temp->next = curr->next;
    curr->next = temp;
    printf("inserted sucessfully\n");*/
}
void deletefirst()
{
    node * temp = (node *)malloc(size);
    if(first->next== NULL)
    {
        temp=first;
        first=NULL;
        free(temp);
        return;
    }
    temp=first;
    first=first->next;
    free(temp);
}
void deleteend()
{
    node * curr = first;
    node * prev = first;
    while(curr->next!=NULL)
    {
        prev=curr;
        curr=curr->next;
    }
    prev->next=NULL;
    free(curr);
}
int main()
{
    insert(3);
    disp();
    insert(4);
    insert(5);
    disp();
    insertfront(6);
    disp();
    insertbefore(7,5);
    disp();
    insertbefore(9,7);
    disp();
    deletefirst();
    disp();
    deleteend();
    disp();
}
