#include <bits/stdc++.h>
using namespace std;
int n,k,m,sum=0,a[1000],t1,t2;
bool f[200][200];
void dfs(int deep){
	if(deep==n+1){sum++; return ;}
	for(int i=1; i<=m; i++){
		bool flag=true;
		for(int j=1; j<=deep-1; j++)
			if(f[j][deep] && a[j]==i) flag=false;
		if(flag){
			a[deep]=i;
			dfs(deep+1);
		}
	}
}
int main()
{
	scanf("%d %d %d",&n,&k,&m);
	for(int i=1; i<=k; i++){cin>>t1>>t2 f[t1][t2]=true; f[t2][t1]=true;}
	dfs(1);
	printf("%d\n",sum);
	return 0;
}
