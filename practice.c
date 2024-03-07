#include<stdio.h>
#define x1 21
#define x2 21
int data[x1][x2] = { 0 };
long long f[x1][x2];//结果很大，用longlong不会越界
long long dp(int a, int b, int h1, int h2)//递推函数
{
	int i, j;
	for(i=0;i<=a;i++)//遍历每一个值
		for(j=0;j<=b;j++)
			if (!data[i][j])//不为一就是不被马踩的点
			{
				if (i == 0 && j == 0)//第一种情况
					f[0][0] = 1;
				else if (i == 0 && j > 0)//第二种情况上边界
					f[0][j] = f[0][j - 1];
				else if (i > 0 && j == 0)//第三种情况左边界
					f[i][0] = f[i - 1][0];
				else
				{
 
					f[i][j] = f[i - 1][j] + f[i][j - 1];//最最主要的递推公式
 
				}
			}
	return f[a][b];//返回a,b  若返回i，j结果是0
}
 
int main()
{
	int a, b;
	int h1, h2;
 
	scanf("%d %d %d %d", &a, &b, &h1, &h2);//vs加_s
	data[h1][h2]++;
	if (h1 - 2 >= 0 && h2 - 1 >= 0)//左上一
		data[h1 - 2][h2 - 1]++;
	if (h1 - 2 >= 0 && h2 + 1 >= 0)//右上一
		data[h1 - 2][h2 + 1]++;
	if (h1 - 1 >= 0 && h2 - 2 >= 0)//左上二
		data[h1 - 1][h2 - 2]++;
	if (h1 - 1 >= 0 && h2 + 2 >= 0)//右上二
		data[h1 - 1][h2 + 2]++;
 
	if (h1 + 1 >= 0 && h2 - 2 >= 0 && h1 + 1 <= a)//左下一
		data[h1 + 1][h2 - 2]++;
	if (h2 + 2 <= b && h1 + 1 <= a)//右下一
		data[h1 + 1][h2 + 2]++;
	if (h1 + 2 >= 0 && h2 - 1 >= 0 && h1 + 2 <= a)//左下二
		data[h1 + 2][h2 - 1]++;
	if (h2 + 1 <= b && h1 + 2 <= a)//右下二
		data[h1 + 2][h2 + 1]++;
//至此所有的马点都被加一
 
	printf("%lld\n", dp(a, b, h1, h2));//可以写个遍历打印，看看变成一的点
 
return 0;
 
}
 
