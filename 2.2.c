// write a C program to define a structure student with the data members to store name,
//roll no and grade of the student. Also write the member functions to read, display, and
//sort student information according to the roll number of the student. All the member
//functions will have array of objects as arguments.
#include <stdio.h>
typedef struct
    {
        char name[15 ];
        int roll_no;
        char grade[2];

    } student;
    student s[100];
void read(int number)
{
    for(int i=0;i<number;i++)
    {
        printf("ENTER NAME , ROLL NUMBER , GRADE : ");
        scanf("%s%d%s",&s[i].name,&s[i].roll_no,&s[i].grade);
        printf("DETAILS READ SUCCESSFULLY\n");
    }
}
void display(int number)
{
  for (int i=0;i < number ; i++)
  {
      printf("DETAILS OF THE STUDENT %d ARE : ",i+1);
      printf("%s\t%d\t%s\n",s[i].name,s[i].roll_no,s[i].grade);
  }
}
void sort(int n)
{
    for(int i=0;i<n-1;i++)
    {
        for(int j=i;j<n-i-1;j++)
        {
            if(s[j].roll_no>s[j+1].roll_no)
            {
                student temp = s[j];
                s[j]=s[j+1];
                s[j+1]=temp;
            }
        }
    }
}

int main()
{

}


