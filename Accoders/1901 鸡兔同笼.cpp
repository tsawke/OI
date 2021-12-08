//1901 鸡兔同笼
#include<iostream>
#include<algorithm>
#include<cstdio> 
using namespace std;
int main()
{
	int n;
	scanf("%d",&n);
	int i=1;
	for( ; i<=n; i++)
	{
		int a;
		scanf("%d",&a);
		int maxx=-1, minn=a;
		if(a%2!=0)
		{
			printf("%s\n","0 0");
			continue;
		}
			int i=0;
			for( ; 4*i<=a; i++)
			{
				int j=(a-4*i)/2;
				maxx=max(maxx,i+j);
				minn=min(minn,i+j);
				/*上面使用了max和min函数
				头文件加上algorithe
				用法：max(一个数，一个数)*/
			}
			printf("%d %d\n",minn,maxx);
			
	}
	return 0;
} 
