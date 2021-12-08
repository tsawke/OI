//1063 计算两点之间的距离
#include<cstdio>
#include<cmath>
using namespace std;

int main()
{
	double x1,y1,x2,y2,d;
	while(scanf("%lf%lf%lf%lf",&x1,&y1,&x2,&y2)!=EOF)
	{
		d=sqrt((x2-x1)*(x2-x1)+(y2-y1)*(y2-y1));
		printf("%0.2lf\n",d);	
	}

	return 0;
}
 
