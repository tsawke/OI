//是啊……你就是那只鬼了……所以被你碰到以后，就轮到我变成鬼了
#include<bits/stdc++.h>
using namespace std;typedef long long ll;
template<typename T>inline void read(T &x)
{
	x=0;char c=getchar(),f=0;
	for(;c<'0'||c>'9';c=getchar()) if(c=='-') f=1;
	for(;c>='0'&&c<='9';c=getchar()) x=(x<<1)+(x<<3)+(c^48);
	if(f) x=-x;
}
const int P=1e9+7;int st[7666666],tp,nn,a[500005];
struct node{int sm,vl,sz,ls,rs,pl,as;char rv;}T[7666666];int tt,rt,n,q;
inline void New(int &x,int w) {T[x=tp?st[tp--]:++tt]=(node){w,w,1,0,0,0,-1,0};}
inline void Del(int &x) {st[++tp]=x,T[x]=(node){0,0,0,0,0,0,0,0},x=0;}
inline void Cpy(int &x) {if(x) {int nx=tp?st[tp--]:++tt;T[nx]=T[x],x=nx;}}
inline int& mod(int &x) {return x>=P?x-=P:x,x;}
inline void pushup(int x) {T[x].sm=(0ll+T[T[x].ls].sm+T[T[x].rs].sm+T[x].vl)%P,T[x].sz=T[T[x].ls].sz+T[T[x].rs].sz+1;}
inline void allr(int x) {if(x) swap(T[x].ls,T[x].rs),T[x].rv^=1;}
inline void allp(int x,int c) {if(x) mod(T[x].vl+=c),mod(T[x].pl+=c),T[x].sm=(T[x].sm+1ll*T[x].sz*c)%P;}
inline void allf(int x,int c) {if(x) T[x].pl=T[x].rv=0,T[x].as=T[x].vl=c,T[x].sm=1ll*T[x].sz*c%P;}
inline void pushr(int x) {if(x&&T[x].rv) allr(T[x].ls),allr(T[x].rs),T[x].rv=0;}
inline void pushp(int x) {if(x&&T[x].pl) allp(T[x].ls,T[x].pl),allp(T[x].rs,T[x].pl),T[x].pl=0;}
inline void pushf(int x) {if(x&&~T[x].as) allf(T[x].ls,T[x].as),allf(T[x].rs,T[x].as),T[x].as=-1;}
inline void pushdw(int x)
{
	if(x&&(T[x].pl||T[x].rv||~T[x].as)) Cpy(T[x].ls),Cpy(T[x].rs);
	if(x&&(T[x].pl||T[x].rv||~T[x].as)) pushf(x),pushp(x),pushr(x);
}
inline char rnd(int a,int b) {return rand()%(a+b)<a;}
inline void split(int x,int k,int &a,int &b)
{
	if(!x) return a=b=0,void();else pushdw(x);
	if(k<=T[T[x].ls].sz) Cpy(b=x),split(T[b].ls,k,a,T[b].ls),pushup(b);
	else Cpy(a=x),split(T[a].rs,k-T[T[x].ls].sz-1,T[a].rs,b),pushup(a);
}
inline int merge(int a,int b)
{
	if(!a||!b) return a|b;
	if(rnd(T[a].sz,T[b].sz)) return pushdw(a),Cpy(a),T[a].rs=merge(T[a].rs,b),pushup(a),a;
	else return pushdw(b),Cpy(b),T[b].ls=merge(a,T[b].ls),pushup(b),b;
}
inline void Clear(int &x) {if(!x);else Clear(T[x].ls),Clear(T[x].rs),Del(x);}
inline void paint(int x) {if(!x);else pushdw(x),paint(T[x].ls),printf("%d ",T[x].vl),paint(T[x].rs);}
inline void pull(int x) {if(!x);else pushdw(x),pull(T[x].ls),a[++nn]=T[x].vl,pull(T[x].rs);}
inline int qry(int l,int r)
{
	int a,b,c,v;split(rt,r,b,c),split(b,l-1,a,b);
	return v=T[b].sm,rt=merge(a,merge(b,c)),v;
}
inline void ass(int l,int r,int v)
{
	int a,b,c;split(rt,r,b,c),split(b,l-1,a,b);
	Cpy(b),allf(b,v),rt=merge(a,merge(b,c));
}
inline void pls(int l,int r,int v)
{
	int a,b,c;split(rt,r,b,c),split(b,l-1,a,b);
	Cpy(b),allp(b,v),rt=merge(a,merge(b,c));
}
inline void swp(int l,int r,int x,int y)
{
	int a,b,c,d,e;if(l>x) swap(l,x),swap(r,y);
	split(rt,y,d,e),split(d,x-1,c,d),split(c,r,b,c),split(b,l-1,a,b);
	swap(b,d),rt=merge(a,merge(b,merge(c,merge(d,e))));
}
inline void psh(int l,int r,int x,int y)
{
	int a,b,c,d,e,f;if(l>x) swap(l,x),swap(r,y),f=1;else f=0;
	split(rt,y,d,e),split(d,x-1,c,d),split(c,r,b,c),split(b,l-1,a,b);
	if(f) Cpy(b=d);else Cpy(d=b);
	rt=merge(a,merge(b,merge(c,merge(d,e))));
}
inline void rev(int l,int r)
{
	int a,b,c;split(rt,r,b,c),split(b,l-1,a,b);
	Cpy(b),allr(b),rt=merge(a,merge(b,c));
}
inline void build(int &x,int l,int r)
{
	int md;if(l>r) return;else md=(l+r)>>1,New(x,a[md]);
	build(T[x].ls,l,md-1),build(T[x].rs,md+1,r),pushup(x);
}
int main()
{
    freopen("P5586_5.in", "r", stdin);
    freopen("std.out", "w", stdout);
	srand(114514),read(n),read(q);for(int i=1;i<=n;i++) read(a[i]);
	build(rt,1,n);for(int op,l,r,a,b,ls=0;q--;)
	{
		read(op),read(l),read(r),l^=ls,r^=ls;
		if(op==1) printf("%d\n",ls=qry(l,r));
		if(op==2) read(a),a^=ls,ass(l,r,a);
		if(op==3) read(a),a^=ls,pls(l,r,a);
		if(op==4) read(a),read(b),a^=ls,b^=ls,psh(l,r,a,b);
		if(op==5) read(a),read(b),a^=ls,b^=ls,swp(l,r,a,b);
		if(op==6) rev(l,r);
		if(tt>=6000000) nn=0,pull(rt),tt=tp=rt=0,build(rt,1,n);
	}
	return paint(rt),putchar('\n'),0;
}