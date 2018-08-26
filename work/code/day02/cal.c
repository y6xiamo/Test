#include<stdio.h>

int arr[][12] = { 
   {31,28,31,30,31,30,31,31,30,31,30,31}
   {31,29,31,30,31,30,31,31,30,31,30,31}
};
int islespyear(int year)
{
   return ((year%4==0)&&(year%100!=0))||(year%400==0);
}

int main()
{
   int base_year = 2002;
   int base_date = 2;
   
   
   int i;
   int total_day;
   for(i = base_year;i<year;i++)
   {
      
          int total_day += 365 + isleapyear[i]; 
   }
    printf("%d",(total_day+base_date)%7);
return 0;
} 
