#include<stdio.h>
typedef struct node
{
    int coeff;
    int exp;
    struct node * next;
}node;
node * create(int c , int e , node * ptr)
{
    node * temp = (node *)malloc(sizeof(node));
    temp->coeff=c;
    temp->exp=e;
    temp->next=ptr;
    return temp;
}
node * createfunc(int n)
{
    node * front = NULL;
    node * rear ;
    int i,c,e;
    for(i=0;i<n;i++)
    {
        printf("ENTER THE COEFFECIENT AND EXPONENT : ");
        scanf("%d %d",&c,&e);
        if(front == NULL)
        {
            front = create(c , e , NULL);
            rear=front;
            printf("here if c1\n");
        }
        else
        {
            rear = rear->next = create(c,e,NULL);
        }
    }
    return front;
}
void display(node * a)
{
    if(a == NULL)
    {
        printf("THE LL IS EMPTY");
        return;
    }
    else
    {
        node * temp = a;
        while(temp!=NULL)
        {
            if(temp->exp==0)
            {
                printf("%dX^%d\n",temp->coeff,temp->exp);
                return;
            }
            else
            {
                printf("%dX^%d + ",temp->coeff,temp->exp);
                temp=temp->next;
            }
        }
    }
}
node * add(node * a , node *b)
{
    node * front=NULL;
    node * rear = front;
    //rear = front = create(0,0,NULL);
    while((a!=NULL) && (b!=NULL))
    {
        if(a->exp==b->exp)
        {
            if(a->coeff + b->coeff)
            {
                printf("here 1\n");
                if(front==NULL)
                {
                    front = create(a->coeff + b->coeff,a->exp,NULL);
                    rear=front;
                }
                else
                {
                    rear=rear->next=create(a->coeff + b->coeff,a->exp,NULL);
                }
                a=a->next;
                b=b->next;
            }
            else if(a->exp > b->exp)
            {
                if(front==NULL)
                {
                    printf("here else if\n");
                    front = create(a->coeff,a->exp,NULL);
                    rear=front;
                }
                else{
                rear = rear->next = create(a->coeff,a->exp,NULL);}
                a=a->next;
            }
            else
            {
                if(front == NULL)
                {
                    front = create(b->coeff,b->exp,NULL);
                    rear=front;
                }
                else
                {
                   printf("here else \n");
                   rear = rear->next = create(b->coeff,b->exp,NULL);
                }
                b=b->next;
            }
        }
    }
    while(b!=NULL)
    {
        rear=rear->next=create(b->coeff,b->exp,NULL);
        b=b->next;
    }
    return front;

}
int main()
{
    node * LL1 = createfunc(2);
    node * LL2 = createfunc(2);
    node * res = add(LL1,LL2);
    display(LL1);
    display(LL2);
    display(res);

}


