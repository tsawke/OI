#include<bits/stdc++.h>
using namespace std;
const int mx=110;
int dp[mx*5][mx],n,w[mx],v[mx],sumv,minv=INT_MAX,sv;
int main()
{
	cin>>n>>sumv;
	for (int i=1;i<=n;i++) cin>>v[i]>>w[i],minv=min(minv,v[i]),sv+=v[i];
	minv--;
        for (int i=1;i<=n;i++) v[i]-=minv;
        sv-=n*minv;
	for (int i=1;i<=n;i++)
	for (int j=sv;j>=v[i];j--)
	for (int k=n;k>=1;k--)
	if (j+k*minv<=sumv) dp[j][k]=max(dp[j][k],dp[j-v[i]][k-1]+w[i]);//cout<<dp[j][k]<<" "<<j<<" "<<k<<endl;
    
	int ans=0;
	for (int j=1;j<=sv;j++)
	for (int i=1;i<=n;i++) ans=max(ans,dp[j][i]);
    int basePrice = minv, totalPrice = sv;
    printf("Base Price = %d\nTotal Price = %d\n", basePrice, totalPrice);
	printf("All Price:");for(int i = 1; i <= n; ++i)printf("%d ", v[i]);puts("");
	for(int i = 1; i <= totalPrice; ++i)for(int j = 1; j <= n; ++j)printf("%d%c", dp[i][j], j == n ? '\n' : ' ');
	cout<<ans;
	return 0;
}