//1176 ¶ÌÐÅ¼Æ·Ñ
#include<iostream>
#include<cstdio>
#include<cmath>
using namespace std;

int count(int n)
{
	if(n%70==0)
	{
		return n/70;
	}
	else
	{
		return (n/70+1);
	}
} 

int main()
{
	int n,m,sum=0;
	scanf("%d",&n);
    while(n--)
    {
    	scanf("%d",&m);
		sum=sum+count(m);
    }
		
	printf("%.1lf\n",sum*0.1);
	return 0;
}
