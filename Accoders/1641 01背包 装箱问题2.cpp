#include <bits/stdc++.h>
using namespace std;
int n,m; int wei[110],pri[110],max_pri[110][1100];
int main(){
	scanf("%d%d",&n,&m); for(int i=1; i<=n; i++) scanf("%d",wei+i); for(int i=1; i<=n; i++) scanf("%d",pri+i);
	for(int i=1; i<=m; i++) max_pri[0][i]=0; for(int i=1; i<=n; i++) max_pri[i][0]=0;
	for(int i=1; i<=n; i++){
		for(int j=1; j<=m; j++){
			if(wei[i]>j) max_pri[i][j]=max_pri[i-1][j];
			else if((max_pri[i-1][j-wei[i]]==0) && (j!=wei[i])) max_pri[i][j]=max_pri[i-1][j];
			else max_pri[i][j]=max(max_pri[i-1][j],max_pri[i-1][j-wei[i]]+pri[i]);
		}
	}printf("%d\n",max_pri[n][m]);
	return 0;
}
