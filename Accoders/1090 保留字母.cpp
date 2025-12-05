//1090 ±£Áô×ÖÄ¸
#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;
int main()
{
	char a[100];
	gets(a);
	int i;
	i=0;
	for( ; i<strlen(a); i++)
	{
		if((a[i]>='a' && a[i]<='z') || (a[i]>='A' && a[i]<='Z'))
		    cout<<a[i];
	}
	
	
	return 0;
} 
