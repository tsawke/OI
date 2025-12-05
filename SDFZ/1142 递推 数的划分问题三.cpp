#include <cstdio>
#include <algorithm>
using namespace std;
unsigned long long a[110][110]; int n,r;
int main(){scanf("%d%d",&n,&r);
	for(int i=1; i<=n; i++)for(int j=1; j<=r; j++){
		if(j==1 || j==i)a[i][j]=true;
		else if(i<j)a[i][j]=false;
		else a[i][j]=a[i-j][j]+a[i-1][j-1];
	}printf("%lld\n",a[n][r]);
	return 0;
}

