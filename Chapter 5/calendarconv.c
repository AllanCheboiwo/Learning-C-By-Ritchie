#include <stdio.h>

static char *daytab[2] = {
   (char[13]){0,31,28,31,30,31,30,31,31,30,31,30,31},
    (char[13]){0,31,29,31,30,31,30,31,31,30,31,30,31}
};

char *month_name(int n);

int day_of_year(int year,int month, int day);
void month_day(int year,int yearday,int *pmonth,int *pday);


int main()
{
    int pmonth;
    int pday;
    month_day(1988,60,&pmonth,&pday);
    printf("The day/month represented by 60th day of 1988 is %d/%s\n",pday,month_name(pmonth));
    printf("The day/year represented by 29th day of Februar is  is %d\n",day_of_year(1988,02,29));

    return 0;

}

int day_of_year(int year,int month, int day)
{
    int i, leap;

    leap = year%4==0 && year%100!=0 || year%400==0;
    for(i=1;i<month;i++)
        day +=daytab[leap][i];
    
    return day;
}

void month_day(int year,int yearday,int *pmonth,int *pday){

    int i, leap;
    leap = year%4 == 0 && year%100 != 0 || year%400 == 0;
    
    for (i = 1; yearday > daytab[leap][i]; i++)
        yearday -= daytab[leap][i];
    *pmonth = i;
    *pday = yearday;
}

char *month_name(int n)
{
    static char *name[] = {
        "Illegal month",
        "January", "February", "March",
        "April", "May", "June",
        "July", "August", "September",
        "October", "November", "December"
    };
    return (n<1||n>12)? name[0]:name[n];
}
