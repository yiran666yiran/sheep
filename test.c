#include <stdio.h>
int main()
{
    int year;
    scanf("%d",&year);
    if(year>=100000)
    {
        printf("%d-%02d",year/100,year%100);
    }else {if((year/100)<22)
    {
        printf("%d-%02d",20*100+year/100,year%100);
    }else
    {
        printf("%d-%02d",19*100+year/100,year%100);
    }
          }
    return 0;
}
