#include <bits/stdc++.h>
using namespace std;
int a[100],n; bool use[1000],flag=false;
bool p[100]={0,0,1,1,0,1,0,1,0,0,0,1,0,1,0,0,0,1,0,1,0,0,0,1,0,0,0,0,0,1,0,1,0,0,0,0,0,1,0,0,0,1,0,1,0,0,0,1,0,0,0};
void dfs(int deep){
	if(deep>n){ if(p[a[n]+a[1]]){
		for(int i=1; i<=n; i++){printf("%d ",a[i]); flag=true;}puts("");}
		return;}
	for(int i=1; i<=n; i++){if(deep>=2 && p[i+a[deep-1]] || deep==1)
		if(!use[i]){a[deep]=i;use[i]=true;dfs(deep+1);use[i]=false;}}
} int main(){
	scanf("%d",&n);if(n==1){printf("1\n"); exit(0);}
	a[1]=1; use[1]=true; dfs(2); if(!flag) printf("No Answer\n");	
	return 0;
}
