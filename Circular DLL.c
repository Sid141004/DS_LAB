//Write a menu driven program to:
//ii) Insert an element into a doubly linked circular list
//iii) Delete an element from a doubly linked circular list.

#include<stdio.h>
#include<stdlib.h>
typedef struct node
{
    int data;
    struct node * next;
    struct node * prev;
}node;
node * head = NULL;

void insertatend();
void delete_ele();
void insertfront();

void main()
{
    int i , t=0,m;
    insertatend(5);
    insertatend(10);
    insertatend(15);
    insertatend(20);
    disp();
    delete_ele();
    disp();
    printf("\nhead prev value 1 %d\n",head->prev->data);
    insertfront(25);
    disp();
    /*while(t)
    {
        printf("\nENTER YOUR CHOICE : \n 1:INSERT AN ELEMENT \n 2:DELETE AN ELEMENT\n 3:EXIT");
        scanf("%d",&m);
        switch(m)
        {
            case 1 :
                insert();
                break;
            case 2 :
                delete_ele();
                break;
        }
    }*/
}

void insertatend(int k)
{
    node * curr = head;
    node * temp = (node *)malloc(sizeof(node));
    temp->data=k;
    if(head == NULL)
    {
        temp->next = temp;
        temp->prev = temp;
        head = temp;
        return;
    }
    node * last = head->prev;
    temp->prev=last;
    last->next=temp;
    temp->next=head;
    head->prev=temp;
}

void disp()
{
    node * curr = head;
    do
    {
        if(curr->next==head)
        {
            printf("%d\t\n",curr->data);
            break;
        }
        printf("%d <-> ",curr->data);
        curr=curr->next;
    }while(curr!=head);
}

void delete_ele()
{
    int flag=1;
    node * curr = head;
    node * temp1;
    node * temp2;
    printf("\nENTER THE ELEMENT TO BE DELETED");
    int k;
    scanf("%d",&k);
    do
    {
        if(curr->data==k)
        {
            temp1 = curr->next;
            temp2 = curr->prev;
            temp2->next=temp1;
            temp1->prev=temp2;
            free(curr);
            flag = 0;
            return;
        }
        else
        {
            flag=1;
        }
        curr=curr->next;
    }while(curr->next!=head);
    if(flag==1)
    {
        printf("\nELEMENT NOT FOUND");
    }
}
void insertfront(int k)
{
    node * temp = (node *)malloc(sizeof(node));
    temp->data=k;
    node * temp2;
    if(head==NULL)
    {
        printf("\nhere");
        temp->next=temp;
        temp->prev=temp;
        head=temp;
        return;
    }
    temp->next=head;
    printf("\nhead prev value 2 %d\n",head->prev->data);
    temp2 = head->prev;
    temp->prev=temp2;
    temp2->next=temp;
    head=temp;
}
