#include <cstdio>
#include <algorithm>
using namespace std;
int n,a[110000],sum=1,ans=0;
int main(){scanf("%d",&n);
	for(int i=1; i<=n; i++)scanf("%d",a+i);
	for(int i=1; i<=n; i++){
		if(a[i]==a[i+1])sum++;
		else{ans=max(ans,sum); sum=1;}
	}printf("%d\n",ans);
	return 0;
}
