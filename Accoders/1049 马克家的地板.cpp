//1049 马克家的地板
#include<iostream>
#include<cstdio>
using namespace std;
int main()
{
	char k;
	int n,i,j;
	scanf("%d %c",&n,&k);
	i=1;
	for( ; i<=n; i++)
	{
		j=1;
		for( ; j<=n; j++)
		{
			printf("%c",k);
		}
		j=0;
		cout<<endl;
	}
    return 0;
} 
