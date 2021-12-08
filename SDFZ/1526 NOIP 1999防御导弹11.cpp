#include <cstdio>
#include <algorithm>
#define MAX_INT 2147483647
using namespace std;
int h[110]; int n=1; int maxx=0; int dp[1100]; int sum=0; bool flag[1100]=false;
int main(){while(scanf("%d",h+n)!=EOF)n++; n--;
	for(int i=1; i<=n; i++)dp[i]=true;
	for(int i=2; i<=n; i++){
		for(int j=1; j<i; j++)
			if(h[i]<=h[j])dp[i]=max(dp[i],dp[j]+1);
		maxx=max(maxx,dp[i]);
	}printf("%d\n",maxx);
	for(int i=1; i<=n; i++){
		sum++;
		for(int j=i+1; i<=n; j++){
			if(h[j]>h[i])break;
			else i++;
		}
	}
	for(int i=1; i<=n; i++){
		if(flag[])
	}
//	for(int i=1; i<=n; i++)printf("%d ",h[i]);
	printf("%d\n",sum);
	return 0;
}

