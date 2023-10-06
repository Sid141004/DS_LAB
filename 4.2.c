#include <stdio.h>
#define n 4
#define m 3
typedef struct{
    int row;
    int column;
    int val;
}sparse ;
sparse s[10];
void main()
{
    int a[10][10],i,j;
    for(i=0;i<m;i++)
    {
        for(j=0;j<n;j++)
            scanf("%d",&a[i][j]);
    }
    s[0].row=m;
    s[0].column=n;
    int k=0,count=0;
    for(i=0;i<m;i++)
    {
        for(j=0;j<n;j++)
        {
            if(a[i][j]!=0)
            {
                k++;
                s[k].row=i;
                s[k].column=j;
                s[k].val=a[i][j];
                printf("%d\t%d\t%d\n",s[k].row,s[k].column,s[k].val);
            }
        }
    }
    s[0].val=k;
}
