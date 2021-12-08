//1173 单词的平均长度
#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;
int main()
{
	char a[10100];
	int i,sum=0,all=0;
	gets(a);
	
	i=0;
	for( ; a[i]!='.'; i++)
	{
		if((a[i]>='a' && a[i]<='z') || (a[i]>='A' && a[i]<='Z'))
		{
			all++;
		}
		else if(a[i]==' ')
		{
			sum++;
		}
		else
		{
			all++;
		}
	}
	
	sum++;
	printf("%.1lf",(all*1.0)/(sum*1.0));
	
	return 0;
}
