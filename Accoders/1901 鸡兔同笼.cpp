//1901 ����ͬ��
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
				/*����ʹ����max��min����
				ͷ�ļ�����algorithe
				�÷���max(һ������һ����)*/
			}
			printf("%d %d\n",minn,maxx);
			
	}
	return 0;
} 
