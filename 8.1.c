#include<stdio.h>
typedef struct node
{
    int data;
    struct node * next;
    struct node * prev;
}node;
node * first = NULL;
void createnode(int d)
{
    node * curr = (node *)malloc(sizeof(node));
    curr->data=d;
    curr->next=NULL;
    curr->prev=NULL;
    first = curr;
}
void disp()
{
    node * curr;
    if(first==NULL)
    {
        printf("LIST IS EMPTY");
        return;
    }
    for(curr=first;curr!=NULL;curr=curr->next)
    {
        if(curr->next==NULL)
        {
            printf(" %d\n",curr->data);
            return;
        }
        else
        {
            printf("%d ->",curr->data);
        }
    }
}
void insertrear(int k)
{
    node * newn = (node *)malloc(sizeof(node));
    newn->data=k;
    node * temp = first;
    while(temp->next!=NULL)
        temp=temp->next;
    temp->next=newn;
    newn->prev=temp;
    newn->next=NULL;
}
void delrear()
{
    node * temp = first;
    node * curr;
    while(temp->next!=NULL)
    {
        temp=temp->next;
    }
    curr = temp->prev;
    free(temp);
    curr->next=NULL;
}
void insertat(int k,int p)
{
    node * curr = (node *)malloc(sizeof(node));
    node * temp;
    node * prev1;
    int count = 0;
    curr->data=k;
    temp = first;
    while(p)
    {
        if(p!=count++)
        {
            temp=temp->next;
        }
        else
        {
            break;
        }
    }
    prev1= temp->prev;
    prev1->next=curr;
    curr->next=temp;
    temp->prev=curr;
    curr->prev=prev1;
}
void deleteat(int p)
{
    node * curr = (node *)malloc(sizeof(node));
    node * temp;
    node * prev1;
    node * after;
    int count = 0;
    temp = first;
    while(p)
    {
        if(p!=count++)
        {
            temp=temp->next;
        }
        else
        {
            break;
        }
    }
    prev1=temp->prev;
    after=temp->next;
    prev1->next=temp->next;
    after->prev=prev1;
    free(temp);
}
void insertafter(int k,int p)
{
    node * temp = (node *)malloc(sizeof(node));
    node * curr;
    node * after;
    temp->data=k;
    curr = first;
    for(curr=first;curr->next!=NULL;curr=curr->next)
    {
        if(curr->data==p)
        {
            after=curr->next;
            temp->next=after;
            after->prev=temp;
            curr->next=temp;
            temp->prev=curr;
            return;
        }
    }
    printf("NODE  NOT FOUND\n");
}
void insertbefore(int k, int p)
{
    node * temp = (node *)malloc(sizeof(node));
    node * curr;
    node * prev1;
    temp->data=k;
    curr = first;
    while(curr->next->data!=p && curr->next !=NULL)
    {
        curr=curr->next;
    }
    temp->next=curr->next;
    curr->next=temp;
    temp->prev=curr;
}
void reverse()
{
    node * curr = first -> next;
    node * temp;
    first->next = NULL;
    while(curr!=NULL)
    {
        temp=curr;
        curr=curr->next;
        temp->next=first;
        temp->prev=curr;
        first=temp;
    }
}
int main()
{
    createnode(5);
    insertrear(10);
    disp();
    insertrear(15);
    insertrear(20);
    insertrear(25);
    delrear();
    disp();
    insertat(30,2);
    disp();
    deleteat(2);
    disp();
    insertafter(30,10);
    disp();
    insertbefore(35,15);
    disp();
    reverse();
    disp();
}

