#include <bits/stdc++.h>
using namespace std;
bool f[20][20]; int t1,t2,n,a[20],sum=0;
void dfs(int deep){
	if(deep==6){sum++; return;}
	for(int i=1; i<=4; i++){bool flag=false;
		for(int j=1; j<=5; j++)
			if(f[j][deep] && a[j]==i) flag=true;
		if(!flag){a[deep]=i; dfs(deep+1); a[deep]=0;}
	}
}
int main()
{
	scanf("%d",&n);
	for(int i=1; i<=n; i++){scanf("%d %d",&t1,&t2); f[t1][t2]=true; f[t2][t1]=true;}
	dfs(1); printf("%d\n",sum);
	return 0;
} 
