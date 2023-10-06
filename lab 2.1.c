#include<stdio.h>

int str_len( char a[] )
{
    int len=0 , i;
    for (i=0;a[i]!='\0';i++)
    {
        len++;
    }
    return len;
}

int str_con(char a[],char b[])
{
    int i , j=0 , len;
    len = str_len( a );
    for(i=len;b[j]!='\0';i++,j++)
    {
        a[i]=b[j];
    }
    a[i]='\0';
    return a;
}
int str_com(char a[], char b[])
{
    int i  ;
    do {
        if (a[i]!= b[i])
        {
            return 0;
        }
        else
            i++;
    } while(a[i]!='\0'||b[i]!='\0');

    return 1;
}
int str_insert(char a[], char b[] , int pos)
{
    int i , len1 , len2;
    len1=str_len(a);
    len2=str_len(b);
    for(i=pos;i<len1;i++)
    {
        a[i+len2]=a[i];
    }
    for(i=0;b[i]!='\0';i++)
    {
        a[pos+i]=b[i];
    }
    a[str_len(a)]='\0';
    return 0;
}
int str_delete(char a[],char b[])
{
    int i , len1,len2,flag,pos,j=0,x;
    len1=str_len(a);
    len2=str_len(b);
    for(i=0;a[i]!='\0';i++)
    {
        while ( a[i] == b [j])
        {
            if(j==len2)
            {
                flag=1;
                break;
            }
            i++,j++;
        }
        j=0;
        if(flag==1)
            pos=i-len2-1;
        else
            flag=0;
    }
    printf("%d",pos);
    for(i=pos-1,j=0;b[j]!='\0';i++,j++)
    {
        a[i]=a[i+len2];
        a[i+len2]='\0';
    }
}

int main()
{
    char str1[100] = "abcdef" ;
    printf("%d",str_len(str1));
    char str2[] = "cde";
    printf("%s\n",str1);
    str_delete(str1,str2);
    printf("%s",str1);

}
