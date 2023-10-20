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

void main()
{
    int i , t=0,m;
    insertatend();
    insertatend();
    insertatend();
    insertatend();
    disp();
    delete_ele();
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

void insertatend()
{
    int k,n,count;
    printf("here");
    node * curr = head;
    node * temp = (node *)malloc(sizeof(node));
    printf("\nENTER THE VALUE :");
    scanf("%d",&k);
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
            printf("%d\t",curr->data);
            break;
        }
        printf("%d ->",curr->data);
        curr=curr->next;
    }while(curr!=head);
    /*while(curr->next!=head)
    {
        printf("%d -> ",curr->data);
        curr=curr->next;
    }
    printf("%d",curr->data);*/
}

void delete_ele()
{
    int flag=1;
    node * curr = head;
    node * temp;
    printf("\nENTER THE ELEMENT TO BE DELETED");
    int k;
    scanf("%d",&k);
    do
    {
        if(curr->data==k)
        {
            temp = curr;
            curr->prev=curr->next;
            curr->next->prev=temp->prev;
            free(curr);
            free(temp);
            flag = 0;
            return;
        }
        else
        {
            flag=1;
        }
        curr=curr->next;
    }while(curr->next!=head);
}
