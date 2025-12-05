//1087 字符串正反连接
#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;
int main()
{
	char a[60];
	int i;
	scanf("%s",a);
	printf("%s",a);
	
	i=strlen(a)-1;
	for( ; i>=0; i--)
	{
		printf("%c",a[i]);
	}
	
	return 0;
	
} 
