/*两个阶乘和之商*/
#include <stdio.h>

int f (int n);
int main()
{
	int x , y;
	scanf("%d %d",&x, &y);
	int sum1 = f(x);
	int sum2 = f(y);
	double j = sum1*1.0/sum2;
	printf("%lf",j);
	return 0;
}
int f(int n)
{
	int s = 0,sum = 1;
	for(int i = 1;i <= n;i++){
		sum *= i;
		s += sum; 
	}
	return (s);
}
#include<stdio.h>
#include<stdlib.h>
int main()
{
    double s, r,l;
    scanf("%lf",&r);
    circle(&s,&l,r);
    printf("s = %8.21f\n",s,l);
}
void circle(double *p,double*q,double r){

}
#include<stdio.h>
#include<stdlib.h>
int main()
{
    int i;
    int *p
     = (int *)malloc(3*sizeof(int));
    int *q;
    for(q=p,i=0;i<3;i++,q++)
    scanf("%d",q);
    q = p;
    while(q<q+3)
    printf("%d\n",*q++);
    free(p);
    return 0;
}
#include<stdio.h>
int main()
{
int a,b,c;
a = 152%10;
b = 152/10%10;
c = 152/100;
printf("152 = %d + %d*10 + %d*100",a,b,c);
return 0;
}