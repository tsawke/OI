#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
int n,m,sum=0; bool ho[11000]={true},flag=false;
int main(){scanf("%d%d",&n,&m);
	if(n==1){printf("0\n"); return 0;}
	for(int i=1; i<=n; i++)ho[i]=true;
	for(int i=1; i<=m; i++){
		sum=(sum+i)%n;
		if(sum==0)sum=n;
		ho[sum]=false;
	}
	for(int i=1; i<=n; i++){
		if(ho[i])printf("%d ",i);
		flag=true;
	}if(flag)puts("");
	if(!flag)printf("0\n");
	return 0;
}


