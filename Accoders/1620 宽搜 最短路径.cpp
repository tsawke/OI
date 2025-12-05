#include <bits/stdc++.h>
using namespace std;
struct coord{int x; int y;}s,t,temp;
int n; int dx[12]={0,1,1,2,2,-1,-1,-2,-2},dy[12]={0,2,-2,1,-1,2,-2,1,-1};
bool use[2200][2200];/*表示是否走过use[i][j]*/int dis[2200][2200]; //起点到dis[i][j]的最短距离
int main(){
	scanf("%d %d %d %d %d",&n,&s.x,&s.y,&t.x,&t.y); queue<coord>q; use[s.x][s.y]=true; q.push(s);
	while(!q.empty()){ temp=q.front(); q.pop(); 
		if(temp.x==t.x && temp.y==t.y){printf("%d\n",dis[temp.x][temp.y]); exit(0);}
		for(int i=1; i<=8; i++){coord temp2; temp2.x=temp.x+dx[i]; temp2.y=temp.y+dy[i];
			if(temp2.x>=0 && temp2.x<=n && temp2.y>=0 && temp2.y<=n && !use[temp2.x][temp2.y]){
				use[temp2.x][temp2.y]=true; dis[temp2.x][temp2.y]=dis[temp.x][temp.y]+1; q.push(temp2);
			}
		}
	}return 0;
}
