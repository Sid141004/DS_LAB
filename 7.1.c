/*insert in beginning , insert in end , insert at the given position , delete from the begininng , delete from the end*/
#include <stdio.h>
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
    int key;
    if(first==NULL)
    {
        printf("LIST IS EMPTY");
        first=temp;
        temp->next=NULL;
    }
    for(curr=first,prev=first;(curr->data!=k&&curr->next!=NULL);prev=curr,curr=curr->next)
    {
        if(curr->data==k)
        {
            prev->next=temp;
            temp->next=curr;
        }
    }
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

}
