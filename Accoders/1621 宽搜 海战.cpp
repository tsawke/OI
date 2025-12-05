#include <bits/stdc++.h>
using namespace std;
struct coord{int x; int y;}temp,temp2;
int n,m,sum=0,a[1100][1100]; bool use[1100][1100]={false}; int dx[20]={0,-1,-1,-1,0,0,1,1,1},dy[20]={0,-1,0,1,-1,1,-1,0,1}; char c_t;
void bfs(int i,int j){coord start; start.x=i; start.y=j; queue<coord>q; use[start.x][start.y]=false; q.push(start);
	while(!q.empty()){ temp=q.front();
		for(int i=1; i<=8; i++){ temp2.x=temp.x+dx[i]; temp2.y=temp.y+dy[i];
		if(temp2.x>=0 && temp2.x<=n && temp2.y>=0 && temp2.y<=m && use[temp2.x][temp2.y]) {use[temp2.x][temp2.y]=false; q.push(temp2);}}
	}return ;
}
int main(){
	scanf("%d %d",&n,&m); for(int i=1; i<=n; i++) {scanf("%c",&c_t); for(int j=1; j<=m; j++) {char c; scanf("%c",&c); if(c=='#'){a[i][j]=1; use[i][j]=true;} else a[i][j]=0;}}
	for(int i=1; i<=n; i++) for(int j=1; j<=m; j++) if(a[i][j]+a[i-1][j]+a[i][j-1]+a[i-1][j-1]==3) {printf("Bad placement.\n"); exit(0);}
	for(int i=1; i<=n; i++) for(int j=1; j<=m; j++) if(use[i][j]) {bfs(i,j); sum++;}
	printf("There are %d ships\n",sum); return 0;
}
