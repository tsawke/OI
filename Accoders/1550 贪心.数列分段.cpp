//1550 贪心.数列分段 
#include <bits/stdc++.h>
using namespace std;

int a[100010];

int main()
{
	ios::sync_with_stdio(false);
	int n,m,sum=0;
	cin>>n>>m; 
	for(int i=1; i<=n; i++) cin>>a[i];
	for(int i=1; i<n; i++){
		if(a[i]+a[i+1]<=m) a[i+1]+=a[i];
		else sum++;
	}
	sum++;
	cout<<sum<<endl;
	return 0;
}
