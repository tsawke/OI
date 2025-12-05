//#include <bits/stdc++.h>
#include <iostream>
using namespace std;
int n,m;
int a[100];
bool use[100];
void dfs(int deep){
	if(deep>m){
		for(int i=1; i<=m; i++) cout<<a[i]<<" ";
		cout<<endl;
		return;
	}
	for(int i=a[deep-1]+1; i<=n; i++){
		a[deep]=i;
		if(!use[i]){
		use[i]=true;
		dfs(deep+1);
		use[i]=false;
		}
	}
}
int main()
{
	ios::sync_with_stdio(false);
	cin>>n>>m;
	dfs(1);
	return 0;
}
