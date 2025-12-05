#include <bits/stdc++.h> 
using namespace std;
struct cow{int x; int mov;}a,s,t; bool use[110000]={false};
int main()
{
	queue<cow>q; scanf("%d %d",&s.x,&t.x); q.push(s); use[s.x]=true;
	while(!q.empty()){ cow temp; temp=q.front(); q.pop();
		if(temp.x==t.x){printf("%d\n",temp.mov); exit(0);} temp.mov++;
		if(temp.x+1<=100000 && !use[temp.x+1]){use[temp.x]=true; temp.x++; q.push(temp); temp.x--;} 
		if(temp.x-1>=0 && !use[temp.x-1]){use[temp.x]=true; temp.x--; q.push(temp); temp.x++;}
		if(temp.x*2<=100000 && !use[temp.x*2]){ use[temp.x]=true; temp.x*=2; q.push(temp);}
	}
	return 0;
}
