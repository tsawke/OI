#include<bits/stdc++.h>
#define getc()(xS==xTT&&(xTT=(xS=xB)+fread(xB,1,1<<20,stdin),xS==xTT)?0:*xS++)
using namespace std;typedef long long ll;typedef double db;typedef long double ld;typedef unsigned long long ull;typedef unsigned int ui;char xch,xB[1<<20],*xS=xB,*xTT=xB;inline ll read(){char ch=getc();ll x=0,f=1;while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getc();}while('0'<=ch&&ch<='9'){x=(x<<1)+(x<<3)+(ch^48);ch=getc();}return x*f;}inline void write(ll x) {if(x<0) putchar('-'),x=-x;if(x>9) write(x/10);putchar(x%10+'0');}
const int maxn=5e5+10;
int n,q,nxt[maxn<<1],head[maxn<<1],cur[maxn],root[maxn<<1],size[maxn*50],lson[maxn*50],rson[maxn*50],cnt,ps[maxn],len,tail[maxn<<1];
vector<int>xl[maxn];
void push_up(int p){size[p]=size[lson[p]]+size[rson[p]];}
void update(int l,int r,int &p,int x,int y)
{
	if(!p)p=++cnt;
	if(l==r)return (void)(size[p]+=y);
	int mid=(l+r)>>1;
	if(x<=mid)update(l,mid,lson[p],x,y);
	else update(mid+1,r,rson[p],x,y);
	push_up(p);
}
int find(int l,int r,int x)
{
	if(l==r)
	{
		int sz=0;
		for(int i=0;i<len;i++)sz+=size[ps[i]];
		return sz>x?l:-1;
	}
	int mid=(l+r)>>1;
	int szl=0,szr=0;
	for(int i=0;i<len;i++)szl+=size[lson[ps[i]]],szr+=size[rson[ps[i]]];
	if(szl>x)
	{
		for(int i=0;i<len;i++)ps[i]=lson[ps[i]];
		return find(l,mid,x);
	}
	else if(szr>x)
	{
		for(int i=0;i<len;i++)ps[i]=rson[ps[i]];
		return find(mid+1,r,x);
	}
	else return -1;
}
int merge(int x,int y)
{
	if(!x||!y)return x|y;
	size[x]+=size[y];
	lson[x]=merge(lson[x],lson[y]);
	rson[x]=merge(rson[x],rson[y]);
	return x;
}
signed main()
{
	freopen("major16.in","r",stdin);
	freopen("1.out","w",stdout);
	n=read(),q=read();
	for(int i=1;i<=n;i++)
	{
		int l=read();xl[i].resize(l);cur[i]=l-1;
		for(int j=0;j<l;j++)xl[i][j]=read(),update(1,n+q,root[i],xl[i][j],1);
		head[i]=tail[i]=i;
	}
	for(int _=1;_<=q;_++)
	{
		int op=read();
		if(op==1)
		{
			int x=read(),y=read(),p=head[x];
			if(xl[p].size()==cur[p]+1)xl[p].push_back(y);
			else xl[p][cur[p]+1]=y;cur[p]++;
			update(1,n+q,root[x],y,1);
		}
		else if(op==2)
		{
			int x=read();
			while(cur[head[x]]<0)head[x]=nxt[head[x]];int p=head[x];
			update(1,n+q,root[x],xl[p][cur[p]],-1);
			if(!cur[p]&&nxt[head[x]])head[x]=nxt[head[x]];
			else cur[p]--;
		}
		else if(op==3)
		{
			int m=read();len=m;
			for(int i=0;i<m;i++)ps[i]=root[read()];
			int sz=0;for(int i=0;i<m;i++)sz+=size[ps[i]];sz>>=1;
			write(find(1,n+q,sz));putchar('\n');
		}
		else
		{
			int x1=read(),x2=read(),x3=read();
			if(tail[x2])nxt[tail[x2]]=head[x1],head[x3]=head[x2];
			else head[x3]=head[x1];tail[x3]=tail[x1];
			root[x3]=merge(root[x1],root[x2]);
		}
	}
    return 0;
}