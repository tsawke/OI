#include <cstdio>
#include <algorithm>
#include <cmath>
#include <iostream>
using namespace std;
int n,m,a[110000],b[110000],ans[110000]; int all,ansall;
int main(){scanf("%d%d",&n,&m); all=n+m; ansall=all;
	for(int i=1; i<=n; i++)scanf("%d",a+i);
	for(int i=1; i<=m; i++)scanf("%d",b+i);
	for(int i=1; i<=n; i++)ans[i]=a[i];
	for(int i=n+1; i<=all; i++)ans[i]=b[i-n];
	sort(ans+1,ans+all+1);
	for(int i=1; i<all; i++){
		if(ans[i]==ans[i+1]){ans[i]=-1e9; ansall--;}
	}
	printf("%d\n",ansall);
	for(int i=1; i<=all; i++){
		if(ans[i]!=-1e9)printf("%d ",ans[i]);
	}puts("");
	return 0;
}
