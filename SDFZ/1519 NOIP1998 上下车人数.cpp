#include <cstdio>
#include <algorithm>
#include <cmath>
#include <cstring>
using namespace std;
int a0,n,m,a[110]={0},x[110]={0},suma[110]={0},sumx[110]={0},ans,num;
int main(){scanf("%d%d%d%d",&a0,&n,&m,&num); 
	a[1]=1; a[2]=0; x[1]=0; x[2]=1;
	for(int i=3; i<=n; i++){
		a[i]=a[i-1]+a[i-2]; x[i]=x[i-1]+x[i-2];
	}suma[1]=a0; sumx[1]=0;
	for(int i=2; i<=n; i++){
		suma[i]=suma[i-1]+a[i]*a0;
		sumx[i]=sumx[i-1]+x[i];
	}
	int temp=(m-suma[n-3]-a0)/sumx[n-3];
	ans=suma[num-2]+sumx[num-2]*temp+a0;
	printf("%d\n",ans);
	return 0;
}
