//1086 µç±¨ÎÄ×Ö
#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;
int main()
{
	char a[1010];
	gets(a);
	int i;
	i=0;
	for( ; i<=strlen(a)-1; i++)
	{
		if(a[i]>='a' && a[i]<'z')
		{
			a[i]++;
		}
		else if(a[i]=='z')
		{
			a[i]='a';
		}
	}
	
	puts(a);
	
	return 0;
	
} 
