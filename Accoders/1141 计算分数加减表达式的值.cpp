//1141 ��������Ӽ����ʽ��ֵ
#include<cstdio>
using namespace std;
int main()
{
	int n,i;
	double s=0,t=1;
	scanf("%d",&n);
	for(i=1;i<=n;i++)
	{
		s=s+t/i;
		t=-t; 
	}
	printf("%0.4lf\n",s);
	return 0;
}
 
