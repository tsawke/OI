#include <bits/stdc++.h>
using namespace std;
struct coord{int x; int y;}temp,temp2,s,t;
int n,m,dis[2200][2200],a[1100][1100]; bool use[1100][1100]={false}; int dx[20]={0,-1,0,1,0},dy[20]={0,0,-1,0,1}; char c_t;
int main(){
	scanf("%d %d",&n,&m); for(int i=1; i<=n; i++) {scanf("%c",&c_t); for(int j=1; j<=m; j++) {char c; scanf("%c",&c); if(c=='#'){a[i][j]=1; use[i][j]=true;} else a[i][j]=0;}}
	s.x=1;s.y=1; t.x=n; t.y=m; queue<coord>q; use[s.x][s.y]=true; q.push(s); 
	while(!q.empty()){ temp=q.front(); q.pop(); 
		if(temp.x==t.x && temp.y==t.y){printf("%d\n",dis[temp.x][temp.y]+1); exit(0);}
		for(int i=1; i<=4; i++){coord temp2; temp2.x=temp.x+dx[i]; temp2.y=temp.y+dy[i];
			if(temp2.x>=0 && temp2.x<=n && temp2.y>=0 && temp2.y<=n && !use[temp2.x][temp2.y]){
				use[temp2.x][temp2.y]=true; dis[temp2.x][temp2.y]=dis[temp.x][temp.y]+1; q.push(temp2);
			}
		}
	}return 0;
}
