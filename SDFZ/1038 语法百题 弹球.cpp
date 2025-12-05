#include <cstdio>
#include <algorithm>
using namespace std;
int n; double m,hei,all=0;
int main(){scanf("%lf %d",&m,&n); hei=m*1.00; all+=m*1.00;
	if(n==1){printf("%.2lf %.2lf\n",hei/2.00,all); return 0;}
	else{
		for(int i=1; i<=n; i++){
			hei/=2; if(i!=n)all+=hei*2.00;
		}
	}printf("%.2lf %.2lf\n",hei,all);
	return 0;
}
