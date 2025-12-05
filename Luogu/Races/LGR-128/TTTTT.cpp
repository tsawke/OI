#include<bits/stdc++.h>
using namespace std;
#define MAXN 4000005
typedef long long ll;
int n,k;ll b[MAXN];
namespace gcd_seg
{
    #define lson(p) ((p)<<1)
    #define rson(p) ((p)<<1|1)
    #define mid ((x+y)>>1)
    ll a[8397000];
    void build(int x,int y,int p){
        if(x==y)return a[p]=::b[x],void();
        build(x,mid,lson(p));
        build(mid+1,y,rson(p));
        a[p]=__gcd(a[lson(p)],a[rson(p)]);
    }
    ll query(int x,int y,int l,int r,int p){
        if(l<=x&&r>=y)return a[p];
        if(l<=mid&&r>mid)return __gcd(query(mid+1,y,l,r,rson(p)),query(x,mid,l,r,lson(p)));
        if(r>mid) return query(mid+1,y,l,r,rson(p));
        else return query(x,mid,l,r,lson(p));
    }
}
#define lowbit(x) ((x)&(-(x)))
void add(int x,ll v){
	for(;x<=n+1;x+=lowbit(x))
		b[x]=min(b[x],v);
}
ll query(int x){
	ll ans=1e15;
	for(;x;x-=lowbit(x))
		ans=min(ans,b[x]);
	return ans;
}
int L[MAXN];
namespace IO
{
	#define gc()(xS==xTT&&(xTT=(xS=xB)+fread(xB,1,1<<20,stdin),xS==xTT)?0:*xS++)
	#define pc(x)(p3-obuf<1000000)?(*p3++=x):(fwrite(obuf,p3-obuf,1,stdout),p3=obuf,*p3++=x)
	char xch,xB[1<<20],*xS=xB,*xTT=xB,obuf[1000000],*p3=obuf;
	inline ll read(){char ch=gc();ll x=0,f=1;while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=gc();}while('0'<=ch&&ch<='9'){x=(x<<1)+(x<<3)+(ch^48);ch=gc();}return x*f;}
	static char cc[20];template<typename item>
	inline void pt( item x){ int len=0;if(!x)pc('0');if(x<0)x=-x,pc('-');while(x)cc[len++]=x%10+'0',x/=10;while(len--)pc(cc[len]);}
	inline void pS(string s){for(int i=0;i<s.length();i++)pc(s[i]);}
	inline ll read2(){char ch=gc();ll x=0,f=1;while(ch<'0'||ch>'1'){if(ch=='-')f=-1;ch=gc();}while('0'<=ch&&ch<='9'){x=(x<<1)+(ch^48);ch=gc();}return x*f;}
}
int main(){
	freopen("D.in","r",stdin);
	cin>>n>>k;
	for(int i=1;i<=n;++i)
		b[i]=IO::read();
	ll g=b[1];
	for(int i=1;i<=n;++i)
		g=__gcd(g,b[i]);
	for(int i=1;i<=n;++i)
		b[i]/=g;
	gcd_seg::build(1,n,1);
	memset(b,0x3f,sizeof(b));
	for(int i=1;i<=n;++i){
		L[i]=L[i-1];
  		for(int j=L[i]+1;j<=i;++j){
			if(gcd_seg::query(1,n,j,i,1)!=1)break;
			L[i]=j;
		}
	}
	add(1,0);ll F;
	for(int i=1;i<=n;++i){
        if(L[i]==i);
		else if(L[i]==0)F=1e15;
		else F=query(L[i])+i+k;
		add(i+1,F-i);
	}
	cout<<F;
}