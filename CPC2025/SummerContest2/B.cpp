#include <bits/stdc++.h>
#define int long long 
using namespace std;
const int N=1000006;
const int m=500002;
int dp[N],a[N],b[N],val[N],tree[N],vall[N];
int n,c,p,q;
int lowbit(int x) {
	return x&(-x);
}
void add(int x,int k) {
	for (;x<=m;x+=lowbit(x)) {
		tree[x]=max(tree[x],k);
	}
}
int query(int x){
	int t=0;
	for (;x;x-=lowbit(x)) {
		t=max(t,tree[x]);
	}
	return t;
}
signed main(){
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	cin>>n>>c>>p>>q;
	string st; cin>>st;
	for (int i=1;i<=n;i++) {
		if (st[i-1]=='Y') a[i]=1;
	}
	for (int i=1;i<=n;i++) b[i]=b[i-1]+a[i];
	for (int i=1;i<=n;i++) val[i]=q*b[i]-p*i;
	val[0]=0;                              // 把 C[0]=0 也参与压缩
	for (int i=0;i<=n;i++) vall[i]=val[i];
	sort(vall,vall+n+1);
	int cur=unique(vall,vall+n+1)-vall-1;
	for (int i=0;i<=n;i++) {
		val[i]=lower_bound(vall+1,vall+cur+1,val[i])-vall;
	}

	add(val[0],0);                         // 先把 j=0 插入 BIT
	for (int i=1;i<=n;i++) {
		if (i-c >= 0) add(val[i-c],dp[i-c]);      // 新起点入窗

		dp[i]=dp[i-1];                            // 至少保持原段位
		int tmp=query(val[i]);                   // 窗口内最大 dp
		if (tmp==dp[i-1]) dp[i]++;               // ***关键改动①②***
	}
	cout<<dp[n]<<endl;
	return 0;
}
