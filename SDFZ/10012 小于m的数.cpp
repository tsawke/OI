#include <cstdio>
#include <algorithm>
using namespace std;
int sum[11000]={0}; int n,m; int ans=0;
int main(){scanf("%d",&n);
	for(int i=1; i<=n; i++){int temp; scanf("%d",&temp); sum[temp]++;}
	scanf("%d",&m);
	for(int i=1; i<m; i++)ans+=sum[i]; printf("%d\n",ans);
	return 0;
}
