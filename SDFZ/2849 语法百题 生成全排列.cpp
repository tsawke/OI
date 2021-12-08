#include <cstdio>
#include <algorithm>
using namespace std;
int a[1100];int n;
bool use[1100]={false};
void dfs(int deep){int i;
	if(deep==n+1){
		for(i=1; i<=n; i++)printf("%d%c",a[i],i==n?'\n':' ');
		return ;
	}for(i=1; i<=n; i++){
		if(!use[i]){a[deep]=i; use[i]=true; dfs(deep+1); use[i]=false;}
	}
}
int main(){scanf("%d",&n); dfs(1); return 0;}

