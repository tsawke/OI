#include <cstdio>
#include <algorithm>
using namespace std;
int n,a[110],sum[5]={0},alls; double percent[5]={0};
int main(){scanf("%d",&n); for(int i=1; i<=n; i++) scanf("%d",a+i);
	for(int i=1; i<=n; i++){
		if(a[i]>=0 && a[i]<=18)sum[1]++;
		else if(a[i]<=35)sum[2]++;
		else if(a[i]<=60)sum[3]++;
		else sum[4]++;
	}alls=sum[1]+sum[2]+sum[3]+sum[4];
	for(int i=1; i<=4; i++)percent[i]=sum[i]*1.0000/(alls*1.0000);
	for(int i=1; i<=4; i++){
		printf("%.2lf",percent[i]*100); printf("%c\n",char(37));
	}
	return 0;
}
