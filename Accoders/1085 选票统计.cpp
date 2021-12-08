//1085 Ñ¡Æ±Í³¼Æ
#include<iostream>
#include<cstring>
#include<cstdio>
using namespace std;

char a[110];
int num[100]={0};
int len,p,n;

int main()
{
	cin>>a;
	len=strlen(a);
	for(int i=0; i<len; i++)
	{
		if(a[i]>='a' && a[i]<='z')
		{
			a[i]=a[i]-32;
		}
	}
	for(int i=0; i<len; i++)
	{
		if(a[i]>=65 && a[i]<=90)
		{
			if(a[i]>='A' && a[i]<='Z')
			{
				p=int(a[i]);
				num[p]++;
			}
		}
	}
	
	for(int i=65; i<=90; i++)
	{
		if(num[i]>0)
		{
			cout<<num[i]<<endl;
			
		}
	}
	
	
	return 0;
}
