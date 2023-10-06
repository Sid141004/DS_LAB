#include<stdio.h>
typedef struct node[]
{
    int data;
    struct node * next;
    struct node * prev;
}node[3];
node[1] * first = NULL;
node[2] * first = NULL;
void insertrear(int i,int k)
{
    node[i] * newn = (node[i] *)malloc(sizeof(node[i]));
    newn->data=k;
    node[i] * temp = first;
    if(first==NULL)
    {
        first=newn;
        return;
    }
    while(temp->next!=NULL)
        temp=temp->next;
    temp->next=newn;
    newn->prev=temp;
    newn->next=NULL;
}
void disp(int i)
{
    node[i] * curr;
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
int main()
{
    printf("ENTER THE ELEMENTS OF THE FIRST dll :")
    int l=1;
    for(int i=0;i<5 ; i++)
    {
        int k;
        scanf("%d",&k);
        insertrear(l,k);
    }
    l=2
    printf("ENTER THE ELEMENTS OF THE SECOND dll :")
    for(int i=0;i<5 ; i++)
    {
        int k;
        scanf("%d",&k);
        insertrear(l,k);
    }
}
