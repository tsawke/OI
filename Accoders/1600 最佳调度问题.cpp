#include <bits/stdc++.h>
using namespace std;
int a[30],t[20],n,k,sum=2147480000,t_[30];
void dfs(int deep,int fin_t){
	if(fin_t>=sum) return ;
	if(deep==n+1){sum=min(sum,fin_t); return;}
	for(int i=1; i<=k; i++){
		if(t[i]+t_[deep]>sum) continue;
		t[i]+=t_[deep];
		a[deep]=i;
		dfs(deep+1,max(fin_t,t[i]));
		t[i]-=t_[deep];
	}
}
bool cmp(int a,int b){return a>b;}
int main()
{
	scanf("%d %d",&n,&k); 
	for(int i=1; i<=n; i++){scanf("%d",&t_[i]);}
	sort(t_+1,t_+n+1,cmp);
	dfs(1,0);
	printf("%d\n",sum);
	return 0;
}
