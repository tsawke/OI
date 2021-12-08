#include <cstdio>
#include <algorithm>
using namespace std;
unsigned long long a[110000]; unsigned long long n,m; int ans=1,sum=0;
int main(){scanf("%d%d",&n,&m);
	for(int i=1; i<=n; i++){scanf("%d",a+i); 
		if(a[i]+sum<=m)sum+=a[i];
		else{sum=a[i]; ans++;}
	}printf("%d\n",ans);
	
	return 0;
}

