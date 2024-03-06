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