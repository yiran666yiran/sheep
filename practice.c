#include<stdio.h>
#define x1 21
#define x2 21
int data[x1][x2] = { 0 };
long long f[x1][x2];//����ܴ���longlong����Խ��
long long dp(int a, int b, int h1, int h2)//���ƺ���
{
	int i, j;
	for(i=0;i<=a;i++)//����ÿһ��ֵ
		for(j=0;j<=b;j++)
			if (!data[i][j])//��Ϊһ���ǲ�����ȵĵ�
			{
				if (i == 0 && j == 0)//��һ�����
					f[0][0] = 1;
				else if (i == 0 && j > 0)//�ڶ�������ϱ߽�
					f[0][j] = f[0][j - 1];
				else if (i > 0 && j == 0)//�����������߽�
					f[i][0] = f[i - 1][0];
				else
				{
 
					f[i][j] = f[i - 1][j] + f[i][j - 1];//������Ҫ�ĵ��ƹ�ʽ
 
				}
			}
	return f[a][b];//����a,b  ������i��j�����0
}
 
int main()
{
	int a, b;
	int h1, h2;
 
	scanf("%d %d %d %d", &a, &b, &h1, &h2);//vs��_s
	data[h1][h2]++;
	if (h1 - 2 >= 0 && h2 - 1 >= 0)//����һ
		data[h1 - 2][h2 - 1]++;
	if (h1 - 2 >= 0 && h2 + 1 >= 0)//����һ
		data[h1 - 2][h2 + 1]++;
	if (h1 - 1 >= 0 && h2 - 2 >= 0)//���϶�
		data[h1 - 1][h2 - 2]++;
	if (h1 - 1 >= 0 && h2 + 2 >= 0)//���϶�
		data[h1 - 1][h2 + 2]++;
 
	if (h1 + 1 >= 0 && h2 - 2 >= 0 && h1 + 1 <= a)//����һ
		data[h1 + 1][h2 - 2]++;
	if (h2 + 2 <= b && h1 + 1 <= a)//����һ
		data[h1 + 1][h2 + 2]++;
	if (h1 + 2 >= 0 && h2 - 1 >= 0 && h1 + 2 <= a)//���¶�
		data[h1 + 2][h2 - 1]++;
	if (h2 + 1 <= b && h1 + 2 <= a)//���¶�
		data[h1 + 2][h2 + 1]++;
//�������е���㶼����һ
 
	printf("%lld\n", dp(a, b, h1, h2));//����д��������ӡ���������һ�ĵ�
 
return 0;
 
}
 
