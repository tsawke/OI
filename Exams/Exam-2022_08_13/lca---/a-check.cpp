#include <bits/stdc++.h>
using namespace std;
#define N 500000+5
const int Max = 10000000;
namespace A
{
	int fa[N],dep[N],counter,n;
	int get_lca(int x,int y)
	{
		while(x!=y)
		{
			counter++;
			if(dep[x]<dep[y])swap(x,y),counter+=3;
			x=fa[x];counter++;
		}
		return x;
	}
	int main(int NN,int a[],int Q,int X[],int Y[])
	{
		counter=0;
		n=NN;counter++;dep[1]=1;
		for(int i=2;i<=n;i++)fa[i]=a[i],dep[i]=dep[fa[i]]+1,counter+=2;
		for(int i=1;i<=Q;i++)
		{
			counter++;int x=X[i],y=Y[i];counter+=2;
			get_lca(x,y);counter++;if(counter>Max)return counter;
		}
		return counter;
	}
}

namespace B
{
	int fa[20][N],dep[N],n,Q,counter,mx;
	int get_lca(int x,int y)
	{
		counter++;
		if(dep[x]<dep[y])counter+=3,swap(x,y);
		int lim=0,deep=dep[x]-dep[y];counter+=4;
		while((1<<lim)<=dep[x])counter+=2,lim++;
		for(int i=0;i<lim;i++)
		{
			counter+=2;
			if(deep&(1<<i))counter++,x=fa[i][x];
		}
		counter++;
		if(x==y)return counter++,x;
		for(int i=lim-1;~i;i--)
		{
			counter+=2;
			if(fa[i][x]!=fa[i][y])
			{
				counter+=2;
				x=fa[i][x],y=fa[i][y];
			}
		}
		counter++;
		return fa[0][x];
	}
	void init()
	{
		counter=0;memset(fa,0,sizeof(fa));
	}
	int main(int NN,int a[],int Q,int X[],int Y[])
	{
		counter=0;init();
		n=NN;counter++;dep[1]=1;
		for(int i=2;i<=n;i++)fa[0][i]=a[i],dep[i]=dep[fa[0][i]]+1,counter+=2,mx=max(mx,dep[i]),counter+=2;
		for(int i=1;(1<<i)<mx;i++)
		{
			counter+=4;
			for(int j=1;j<=n;j++)
			{
				counter+=4;
				fa[i][j]=fa[i-1][fa[i-1][j]];
			}
		}
		for(int i=1;i<=Q;i++)
		{
			counter++;int x=X[i],y=Y[i];counter+=2;
			get_lca(x,y);counter++;if(counter>Max)return counter;
		}
		return counter;
	}
}

namespace C
{
	struct node{int to,next;}e[N];
	int n,siz[N],fa[N],anc[N],son[N],dep[N],head[N],cnt,Q,counter;
	void add(int x,int y){e[cnt]=(node){y,head[x]};head[x]=cnt++;counter+=3;}
	void dfs1(int x)
	{
		siz[x]=1;counter+=5;
		for(int i=head[x];i!=-1;i=e[i].next)
		{
			counter+=3;
			dfs1(e[i].to);siz[x]+=siz[e[i].to];counter+=2;
			if(siz[e[i].to]>siz[son[x]])counter++,son[x]=e[i].to;
		}
	}
	void dfs2(int x,int top)
	{
		counter+=5;anc[x]=top;if(son[x])dfs2(son[x],top),counter+=2;
		for(int i=head[x];i!=-1;i=e[i].next)
		{
			counter+=4;
			if(e[i].to!=son[x])dfs2(e[i].to,e[i].to);
		}
	}
	int get_lca(int x,int y)
	{
		counter+=2;
		while(anc[x]!=anc[y])
		{
			counter+=4;
			if(dep[anc[x]]<dep[anc[y]])counter+=3,swap(x,y);
			x=fa[anc[x]];counter++;
		}counter+=2;
		if(dep[x]>dep[y])return y;return x;
	}
	void init()
	{
		counter=0;cnt=0;memset(fa,0,sizeof(fa));memset(son,0,sizeof(son));
		memset(anc,0,sizeof(anc));memset(siz,0,sizeof(siz));
	}
	int main(int NN,int a[],int Q,int X[],int Y[])
	{
		counter=0;init();
		n=NN;memset(head,-1,sizeof(head));counter=n;dep[1]=1;
		for(int i=2;i<=n;i++)fa[i]=a[i],dep[i]=dep[fa[i]]+1,add(fa[i],i),counter+=3;
		dfs1(1);dfs2(1,1);
		for(int i=1;i<=Q;i++)
		{
			counter++;int x=X[i],y=Y[i];counter+=2;
			get_lca(x,y);counter++;//if(counter>Max)return counter;
		}
		return counter;
	}
}

namespace D
{
	struct node{int to,next;}e[N];
	int n,siz[N],fa[N],anc[N],son[N],dep[N],mx[N],head[N],cnt,Q,counter;
	void add(int x,int y){e[cnt]=(node){y,head[x]};head[x]=cnt++;counter+=3;}
	void dfs1(int x)
	{
		counter+=5;
		for(int i=head[x];i!=-1;i=e[i].next)
		{
			counter+=3;
			dfs1(e[i].to);mx[x]=max(mx[e[i].to]+1,mx[x]);counter+=4;
			if(mx[e[i].to]>mx[son[x]])counter++,son[x]=e[i].to;
		}
	}
	void dfs2(int x,int top)
	{
		counter+=5;anc[x]=top;if(son[x])dfs2(son[x],top),counter+=2;
		for(int i=head[x];i!=-1;i=e[i].next)
		{
			counter+=4;
			if(e[i].to!=son[x])dfs2(e[i].to,e[i].to);
		}
	}
	int get_lca(int x,int y)
	{
		counter+=2;
		while(anc[x]!=anc[y])
		{
			counter+=4;
			if(dep[anc[x]]<dep[anc[y]])counter+=3,swap(x,y);
			x=fa[anc[x]];counter++;
		}counter+=2;
		if(dep[x]>dep[y])return y;return x;
	}
	void init()
	{
		counter=0;cnt=0;memset(fa,0,sizeof(fa));memset(son,0,sizeof(son));
		memset(anc,0,sizeof(anc));memset(siz,0,sizeof(siz));memset(mx,0,sizeof(mx));
	}
	int main(int NN,int a[],int Q,int X[],int Y[])
	{
		init();
		n=NN;memset(head,-1,sizeof(head));counter=n;dep[1]=1;
		for(int i=2;i<=n;i++)fa[i]=a[i],dep[i]=dep[fa[i]]+1,add(fa[i],i),counter+=3;
		dfs1(1);dfs2(1,1);
		for(int i=1;i<=Q;i++)
		{
			counter++;int x=X[i],y=Y[i];counter+=2;
			get_lca(x,y);counter++;if(counter>Max)return counter;
		}
		return counter;
	}
}

namespace E
{
	int n,Q,counter,fa[N],dep[N];
	struct node{int to,next;}e[N];
	int head[N],cnt,vis[N],ans[5000005];
	void add(int x,int y){e[cnt]=(node){y,head[x]};head[x]=cnt++;counter+=3;}
	struct union_find
	{
		int fa[N],rot[N],siz[N];
		void init(){for(int i=1;i<=n;i++)rot[i]=i,fa[i]=i,siz[i]=1,counter+=3;}
		int find(int x){counter++;return x==fa[x]?x:fa[x]=find(fa[x]);}
		int get_rot(int x){counter++;return rot[find(x)];}
		void uni(int x,int y)
		{
			x=find(x),y=find(y);counter++;
			if(x==y)return ;counter++;if(siz[x]<siz[y])swap(x,y),counter+=5;
			siz[x]+=siz[y];fa[y]=x;counter++;
			if(dep[rot[x]]>dep[rot[y]])rot[x]=rot[y],counter++;
		}
	}A;
	vector<pair<int ,int > >v[N];
	void tarjan(int x)
	{
		counter+=3;vis[x]=1;
		for(int i=head[x];i!=-1;i=e[i].next)
		{
			int to1=e[i].to;dep[to1]=dep[x]+1;
			counter+=2;
			tarjan(to1);
			A.uni(to1,x);
		}
		int lim=v[x].size();counter+=2;
		for(int i=0;i<lim;i++)
		{
			counter+=3;pair<int ,int >p=v[x][i];
			if(vis[p.first])
			{
				counter+=3;
				ans[p.second]=A.get_rot(p.first);
			}
		}
	}
	void init()
	{
		counter=0;cnt=0;
		for(int i=0;i<N;i++)v[i].clear(),v[i].shrink_to_fit();memset(vis,0,sizeof(vis));
	}
	int main(int NN,int a[],int Q,int X[],int Y[])
	{
		cnt=counter=0;init();
		n=NN;memset(head,-1,sizeof(head));counter=n+1;A.init();
		for(int i=2;i<=n;i++)fa[i]=a[i],dep[i]=dep[fa[i]]+1,add(fa[i],i),counter+=3;
		for(int i=1;i<=Q;i++)
		{
			int x=X[i],y=Y[i];counter+=5;
			v[x].push_back(make_pair(y,i));v[y].push_back(make_pair(x,i));
		}
		tarjan(1);
		for(int i=1;i<=Q;i++)counter+=2;
		return counter;
	}
}

namespace F
{
	int n,Q,counter,a[N*2];
	struct node{int to,next;}e[N];
	int head[N],place[N*2][22],dep[N*2],minn[N*2][22],cnt,tims;
	void add(int x,int y){e[cnt]=(node){y,head[x]};head[x]=cnt++;counter+=3;}
	void dfs(int from,int x)
	{
		a[x]=++tims;
		place[tims][0]=x;
		dep[tims]=dep[a[from]]+1;
		minn[tims][0]=dep[tims];counter+=4;
		for(int i=head[x];i!=-1;i=e[i].next)
		{
			int to1=e[i].to;
			if(to1!=from)
			{
				dfs(x,to1);
				a[x]=++tims;
				dep[tims]=dep[a[from]]+1;
				minn[tims][0]=dep[tims];
				place[tims][0]=x;
			}
		}
		return ;
	}
	void init()
	{
		counter=0;cnt=0;memset(a,0,sizeof(a));tims=0;
		memset(place,0,sizeof(place));memset(minn,0,sizeof(minn));
	}
	int main(int NN,int a[],int Q,int X[],int Y[])
	{
		cnt=counter=0;init();
		n=NN;memset(head,-1,sizeof(head));counter+=n;
		for(int i=2;i<=n;i++)
		{
			int x=a[i];
			add(x,i);
			counter+=3;
		}
		dfs(0,1);
		for(int j=1;j<=21;j++)
		{
			counter+=3;
			for(int i=1;i<=2*n-1;i++)
			{
				counter+=3;
				if(i+(1<<j-1)>n*2-1)break;counter+=5;
				if(minn[i][j-1]<minn[i+(1<<(j-1))][j-1])
				{
					minn[i][j]=minn[i][j-1];
					place[i][j]=place[i][j-1];counter+=2;
				}else
				{
					minn[i][j]=minn[i+(1<<(j-1))][j-1];
					place[i][j]=place[i+(1<<(j-1))][j-1];counter+=2;
				}
			}
		}
		for(int i=1;i<=Q;i++)
		{
			int x=X[i],y=Y[i];counter+=3;
			if(a[x]>a[y])swap(x,y),counter+=3;
			int len=a[y]-a[x]+1;
			int t=(int)log2(len);counter+=3;counter++;
			// if(minn[a[x]][t]<minn[a[y]-(1<<t)+1][t])
			// {
				// printf("%d\n",place[a[x]][t]);
			// }else
			// {
				// printf("%d\n",place[a[y]-(1<<t)+1][t]);counter++;
			// }
		}
		return counter;
	}
}

namespace G
{
	int fa[N],counter;
	bool check(int x,int y)
	{
		while(fa[x])
		{
			counter+=2;
			if(x==y)return 1;
			x=fa[x];
		}return 0;
	}
	vector<int>v[N];
	int get_lca(int now,int x,int y)
	{
		int lim=v[now].size();
		for(int i=0;i<lim;i++)
		{
			counter+=2;
			if(counter>Max)return 0;
			if(check(x,v[now][i])&&check(y,v[now][i]))return get_lca(v[now][i],x,y);
		}
		return now;
	}
	void init()
	{
		for(int i=0;i<N;i++)v[i].clear(),v[i].shrink_to_fit();
	}
	int main(int n,int a[],int Q,int X[],int Y[])
	{
		counter=0;init();
		counter++;
		for(int i=2;i<=n;i++)fa[i]=a[i],counter++,v[fa[i]].push_back(i),counter++;
		counter++;
		for(int i=1;i<=Q;i++)
		{
			int x=X[i],y=Y[i];counter+=2;get_lca(1,x,y);
			counter++;if(counter>Max)return counter;
		}
		return counter;
	}
}
mt19937 rnd(random_device{}());
int rndd(int l, int r){return rnd() % (r - l + 1) + l;}
int NNN, QQQ;
int a[510000];
int x[510000], y[510000];
int main(){
    freopen("test.out", "r", stdin);
	scanf("%d", &NNN);
    for(int i = 2; i <= NNN; ++i)scanf("%d", &a[i]);
    scanf("%d", &QQQ);
    for(int i = 1; i <= QQQ; ++i){
        scanf("%d%d", &x[i], &y[i]);
    }
    int Time[10];
    Time[1] = A::main(NNN, a, QQQ, x, y);
    Time[2] = B::main(NNN, a, QQQ, x, y);
    Time[3] = C::main(NNN, a, QQQ, x, y);
    Time[4] = D::main(NNN, a, QQQ, x, y);
    Time[5] = E::main(NNN, a, QQQ, x, y);
    Time[6] = F::main(NNN, a, QQQ, x, y);
    Time[7] = G::main(NNN, a, QQQ, x, y);
    for(int i = 1; i <= 7; ++i)printf("%c: %d\n", (char)('A' + i - 1) , Time[i] > 10000000 ? -1 : Time[i]);
	return 0;
}