#include <bits/stdc++.h>
#define int long long 
using namespace std;
const int N=1600016;
const int inf=1e9+7;
int tot,T,qwqq,n,r[6],tag[N],dis[N],vis[N],head[N];
string s,t;
struct qwq{
	int hext,to,w;
}e[20*20*20*20*20+6];
int encode(int x,int y,int z,int w) {
	if (x>9||y>9||z>9||w>9) return -1;
	if (x<-9||y<-9||z<-9||w<-9) return -1;
	return (x+10)*20*20*20+(y+10)*20*20+(z+10)*20+w+10;
}
void add(int x,int y,int z) {
	if (x==-1||y==-1) return ;
	e[++tot].hext=head[x];
	e[tot].to=y;
	e[tot].w=z;
	head[x]=tot;
}
priority_queue <pair<int,int>,vector<pair<int,int> >,greater<pair<int,int> > > q;
void dijk(int ss) {
	for (int i=1;i<=n;i++) dis[i]=inf,vis[i]=0; 
	dis[ss]=0;
	q.push({(int)0,ss});
	while (!q.empty()) {
		int u=q.top().second; q.pop();
		if (vis[u]) continue;
		vis[u]=1;
		for (int i=head[u];i;i=e[i].hext) {
			int v=e[i].to;
			if (dis[v]>dis[u]+e[i].w) {
				dis[v]=dis[u]+e[i].w;
				q.push({dis[v],v});
			}
		}
	}
	return ;
}
int tt(int x) {
	if (x==-1) return qwqq;
	return x;
}
signed main(){
	freopen("in.txt", "r", stdin);
	freopen("out2.txt", "w", stdout);
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	
	int T; cin>>T;
	n=encode(9,9,9,9);
	for (int a1=-9;a1<=9;a1++) {
		for (int a2=-9;a2<=9;a2++) {
			for (int a3=-9;a3<=9;a3++) {
				for (int a4=-9;a4<=9;a4++) {
					add(encode(a1,a2,a3,a4),encode(a1+1,a2,a3,a4),1);
					add(encode(a1,a2,a3,a4),encode(a1,a2+1,a3,a4),1);
					add(encode(a1,a2,a3,a4),encode(a1,a2,a3+1,a4),1);
					add(encode(a1,a2,a3,a4),encode(a1,a2,a3,a4+1),1);
					add(encode(a1,a2,a3,a4),encode(a1+1,a2+1,a3,a4),1);
					add(encode(a1,a2,a3,a4),encode(a1,a2+1,a3+1,a4),1);
					add(encode(a1,a2,a3,a4),encode(a1,a2,a3+1,a4+1),1);
					add(encode(a1,a2,a3,a4),encode(a1+1,a2+1,a3+1,a4),1);
					add(encode(a1,a2,a3,a4),encode(a1,a2+1,a3+1,a4+1),1);
					add(encode(a1,a2,a3,a4),encode(a1+1,a2+1,a3+1,a4+1),1);

					add(encode(a1,a2,a3,a4),encode(a1-1,a2,a3,a4),1);
					add(encode(a1,a2,a3,a4),encode(a1,a2-1,a3,a4),1);
					add(encode(a1,a2,a3,a4),encode(a1,a2,a3-1,a4),1);
					add(encode(a1,a2,a3,a4),encode(a1,a2,a3,a4-1),1);
					add(encode(a1,a2,a3,a4),encode(a1-1,a2-1,a3,a4),1);
					add(encode(a1,a2,a3,a4),encode(a1,a2-1,a3-1,a4),1);
					add(encode(a1,a2,a3,a4),encode(a1,a2,a3-1,a4-1),1);
					add(encode(a1,a2,a3,a4),encode(a1-1,a2-1,a3-1,a4),1);
					add(encode(a1,a2,a3,a4),encode(a1,a2-1,a3-1,a4-1),1);
					add(encode(a1,a2,a3,a4),encode(a1-1,a2-1,a3-1,a4-1),1);

				}
			}
		}
	}
	dijk(encode(0,0,0,0));
	qwqq=N-1; dis[N-1]=inf;
	while (T--) {
		cin>>s>>t;
		tag[1]=t[0]-s[0],tag[2]=t[1]-s[1],tag[3]=t[2]-s[2],tag[4]=t[3]-s[3];
		int ans=dis[tt(encode(tag[1],tag[2],tag[3],tag[4]))];
		for (int i=-1;i<=1;i++) 
			for (int j=-1;j<=1;j++)
				for (int k=-1;k<=1;k++) 
					for (int w=-1;w<=1;w++) {
				r[1]=tag[1]+i*10,r[2]=tag[2]+j*10,r[3]=tag[3]+k*10,r[4]=tag[4]+w*10;
				ans=min(ans,dis[tt(encode(r[1],r[2],r[3],r[4]))]);
			}
//		ans=min(ans,dis[tt(encode(10+tag[1],tag[2],tag[3],tag[4]))]);
//		ans=min(ans,dis[tt(encode(tag[1],10+tag[2],tag[3],tag[4]))]);
//		ans=min(ans,dis[tt(encode(tag[1],tag[2],10+tag[3],tag[4]))]);
//		ans=min(ans,dis[tt(encode(tag[1],tag[2],tag[3],10+tag[4]))]);
//		
//		ans=min(ans,dis[tt(encode(10+tag[1],10+tag[2],tag[3],tag[4]))]);
//		ans=min(ans,dis[tt(encode(tag[1],10+tag[2],10+tag[3],tag[4]))]);
//		ans=min(ans,dis[tt(encode(tag[1],tag[2],10+tag[3],10+tag[4]))]);
//		
//		ans=min(ans,dis[tt(encode(10+tag[1],tag[2],10+tag[3],tag[4]))]);
//		ans=min(ans,dis[tt(encode(10+tag[1],tag[2],tag[3],10+tag[4]))]);
//		ans=min(ans,dis[tt(encode(tag[1],10+tag[2],tag[3],10+tag[4]))]);
//		
//		ans=min(ans,dis[tt(encode(10+tag[1],10+tag[2],10+tag[3],tag[4]))]);
//		ans=min(ans,dis[tt(encode(tag[1],10+tag[2],10+tag[3],10+tag[4]))]);
//		ans=min(ans,dis[tt(encode(10+tag[1],tag[2],10+tag[3]+10+tag[4]))]);
//		ans=min(ans,dis[tt(encode(10+tag[1],10+tag[2],tag[3],10+tag[4]))]);
//		ans=min(ans,dis[tt(encode(10+tag[1],10+tag[2],10+tag[3],10+tag[4]))]);			
//		
//		
//
//		ans=min(ans,dis[tt(encode(-10+tag[1],tag[2],tag[3],tag[4]))]);
//		ans=min(ans,dis[tt(encode(tag[1],-10+tag[2],tag[3],tag[4]))]);
//		ans=min(ans,dis[tt(encode(tag[1],tag[2],-10+tag[3],tag[4]))]);
//		ans=min(ans,dis[tt(encode(tag[1],tag[2],tag[3],-10+tag[4]))]);
//		
//		ans=min(ans,dis[tt(encode(-10+tag[1],-10+tag[2],tag[3],tag[4]))]);
//		ans=min(ans,dis[tt(encode(tag[1],-10+tag[2],-10+tag[3],tag[4]))]);
//		ans=min(ans,dis[tt(encode(tag[1],tag[2],-10+tag[3],-10+tag[4]))]);
//		
//		ans=min(ans,dis[tt(encode(-10+tag[1],tag[2],-10+tag[3],tag[4]))]);
//		ans=min(ans,dis[tt(encode(-10+tag[1],tag[2],tag[3],10+tag[4]))]);
//		ans=min(ans,dis[tt(encode(tag[1],10+tag[2],tag[3],10+tag[4]))]);
//		
//		ans=min(ans,dis[tt(encode(10+tag[1],10+tag[2],10+tag[3],tag[4]))]);
//		ans=min(ans,dis[tt(encode(tag[1],10+tag[2],10+tag[3],10+tag[4]))]);
//		ans=min(ans,dis[tt(encode(10+tag[1],tag[2],10+tag[3]+10+tag[4]))]);
//		ans=min(ans,dis[tt(encode(10+tag[1],10+tag[2],tag[3],10+tag[4]))]);
//		ans=min(ans,dis[tt(encode(10+tag[1],10+tag[2],10+tag[3],10+tag[4]))]);			
		
			
		cout<<ans<<'\n';		
	}	
	
	
	
	return 0;
}

/*


13
4328 8947
4392 9858
2314 5439
8593 4328
7823 7547
4237 5892
4786 1905
5493 7724
4794 5182
4974 3110
4837 1113
4359 7409
4328 6347


*/
