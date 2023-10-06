//Define a structure time with data members hour, min, sec. Write the user defined
//functions to (i) Add (ii) To find difference between two objects of class time.
//Functions take two-time objects as argument and return time object. Also write the
//display and read function.
#include<stdio.h>
typedef struct
{
    int hour;
    int min;
    int sec;
} time ;
time t1,t2,diff;
void read(int number)
{
    for(int i=1;i<3;i++)
    {
        printf("ENTER TIME IN HOURS , MINUTES , SECONDS RESPECTIVELY : ");
        scanf("%s%d%s",&ti.hour,&ti.min,ti.sec);
        printf("DETAILS READ SUCCESSFULLY\n");
    }
}
void display(int number)
{
  for (int i=1;i < 3 ; i++)
  {
      printf("TIME %d IS  : ",i+1);
      printf("%d : %d : %d \n",t[i].hour,t[i].min,t[i].sec);
  }
}
time add(time t11,time t22)
{
    time add;
    if (t11.sec+t22.sec > 60)
    {
        if(t11.min + t22.min + 1 > 60)
        {
            if (t11.hour + t22.hour + 1 > 24)
                {add.hour = t11.hour + t22.hour +1 ;
                add.min  = 120 - ( t11.min + t22.min + 1);
                add.sec = 120 - (t11.sec+ t22.sec);}
            else
            {
                add.hour = t11.hour + t22.hour + 1;
                add.min  = 120 - ( t11.min + t22.min + 1);
                add.sec = 120 - (t11.sec+ t22.sec);

            }
        }

    }

}
int main()
{
    read(2);
    display(2);
    add(time t[0],time t[1];
}
