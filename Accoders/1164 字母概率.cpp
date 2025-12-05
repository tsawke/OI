//1164 ×ÖÄ¸¸ÅÂÊ
#include<iostream> 
#include<cstdio>
#include<cstring>
using namespace std;
int main()
{
	int i,sum;
	char a[210],x;
	while(scanf("%c ",&x)!=EOF)
	{
		sum=0;
		gets(a);
		i=0;
		for( ; i<strlen(a); i++)
		{
			if(a[i]==x || a[i]-32==x || a[i]+32==x)
			{
				sum++;
			}
		}
		
		printf("%.5lf\n",sum*1.0/strlen(a));
	}
	
	
	return 0;
}
