#include<bits/stdc++.h> 
using namespace std; 
int n,sum=0,a[100][100],f[100][100],dx[10]={0,0,0,1,1,1,-1,-1,-1},dy[10]={0,1,-1,0,1,-1,0,1,-1}; 
void dfs(int x,int y){
	int t1,t2;
	if(x==1 && y==n){sum++; return;}
	for(int i=1;i<=8;i++){
	 	t1=x+dx[i]; t2=y+dy[i]; 
		if(t1>0 && t2>0 && t1<=n && t2<=n && a[t1][t2]==0 && f[t1][t2]==0){
		f[t1][t2]=1;
		dfs(t1,t2);
		f[t1][t2]=0;}
	}return; 
} 
int main()
{
	scanf("%d",&n); 
	for(int i=1;i<=n;i++) for(int j=1;j<=n;j++) scanf("%d",&a[i][j]);
	f[1][1]=1; dfs(1,1);
	printf("%d\n",sum);
	return 0;
}
