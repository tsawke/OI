#include <bits/stdc++.h>
using namespace std;
int n,m,ans=0;
int dx[8]={0,1,0,-1,0},dy[8]={0,0,1,0,-1};
bool a[110][110];
char str[110];
void dfs(int x,int y){
	for(int i=1; i<=4; i++){
		if(a[x+dx[i]][y+dy[i]]){
			a[x+dx[i]][y+dy[i]]=0;
			dfs(x+dx[i],y+dy[i]);
		}
	}
}

int main()
{
	scanf("%d %d",&n,&m);
	cin.getline(str,105);
	for(int i=1; i<=n; i++){
		cin.getline(str+1,105);
		for(int j=1; j<=m; j++){
			if(str[j]=='0')a[i][j]=0;
			else a[i][j]=1;
		}
	}
	for(int i=1; i<=n; i++){
		for(int j=1; j<=m; j++){
			if(a[i][j]){
				ans++;
				a[i][j]=0;
				dfs(i,j);
			}
		}
	}
	printf("%d\n",ans);
	return 0;
} 
