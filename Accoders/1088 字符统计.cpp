//1088 ×Ö·ûÍ³¼Æ
#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;
int main()
{
	char a[1010];
	gets(a);
	int i;
	int x=0,y=0,z=0,o=0;
	i=0;
	for( ; i<strlen(a); i++)
	{
		if((a[i]>='a' && a[i]<='z') || (a[i]>='A' && a[i]<='Z'))
		{
			x++;
		}
		else if(a[i]>='0' && a[i]<='9')
		{
			y++;
		}
		else if(a[i]==' ')
		{
			z++;
		}
		else
		{
			o++;
		}
	}
	
	cout<<x<<" "<<y<<" "<<z<<" "<<o;
	
	
	return 0;
} 
