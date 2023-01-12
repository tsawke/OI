#include<bits/stdc++.h>
using namespace std;
#define MAXN 100005
typedef long long ll;
mt19937 myrand(1);
int lson[MAXN*40],rson[MAXN*40],val[MAXN*40],lazy1[MAXN*40],lazy3[MAXN*40],siz[MAXN*40],pri[MAXN*40],dep[MAXN*40],tot,root;
ll sum[MAXN*40],lazy2[MAXN*40];
basic_string<int> q;
int NewNode(int x){
	int p;
	if(q.size())
		p=q[q.size()-1],q.pop_back(),cout<<p<<endl;
	else p=++tot;
	lson[p]=rson[p]=lazy2[p]=lazy3[p]=0;
	val[p]=sum[p]=x;
	lazy1[p]=-1;
	siz[p]=1;
	pri[p]=myrand();
	dep[p]=1;
	return p;
}
int CopyNode(int x){
	int p;
	if(q.size())
		p=q[q.size()-1],q.pop_back();
	else p=++tot;
	lson[p]=lson[x],rson[p]=rson[x];
	lazy1[p]=lazy1[x],lazy2[p]=lazy2[x],lazy3[p]=lazy3[x];
	val[p]=val[x],siz[p]=siz[x],pri[p]=pri[x],dep[p]=dep[x],sum[p]=sum[x];
	return p;
}
void push1(int p,int x){if(p)lazy1[p]=x,lazy2[p]=0,val[p]=x,sum[p]=(ll)val[p]*siz[p];}
void push2(int p,int x){if(p)lazy2[p]+=x,val[p]+=x,sum[p]+=(ll)x*siz[p];}
void push3(int p){if(p)swap(lson[p],rson[p]),lazy3[lson[p]]^=1,lazy3[rson[p]]^=1;}
void pushdown(int p){
	if(lazy1[p]==-1&&!lazy2[p]&&!lazy3[p])return;
	if(lson[p])lson[p]=CopyNode(lson[p]);
	if(rson[p])rson[p]=CopyNode(rson[p]);
	if(lazy1[p]!=-1)push1(lson[p],lazy1[p]),push1(rson[p],lazy1[p]),lazy1[p]=-1;
	if(lazy2[p])push2(lson[p],lazy2[p]),push2(rson[p],lazy2[p]),lazy2[p]=0;
	if(lazy3[p])push3(lson[p]),push3(rson[p]),lazy3[p]=0;
}
void update(int p){
	sum[p]=sum[lson[p]]+sum[rson[p]]+val[p];
	dep[p]=max(dep[lson[p]],dep[rson[p]])+1;
	siz[p]=siz[lson[p]]+siz[rson[p]]+1;
}
basic_string<int> v;
void dfs(int p,int op){
	if(p)pushdown(p);
	if(lson[p])dfs(lson[p],op);
	if(p)v.push_back(op?val[p]:p);
	if(rson[p])dfs(rson[p],op);
}
void print(int p){
	dfs(p,1);
	for(auto p:v)
		printf("%d ",p);
	v.clear();
	printf("\n");
}
void del(int p){
	dfs(p,0);
	q+=v;
	v.clear();
}
int Rand(int x,int y){
	return myrand()%(y-x+1)+x;
}
int rebuild(int x,int y,int z){
	if(x>y)return 0;
	int mid=(x+y)>>1;
	z=pri[mid]=Rand(z,2e9);
	val[mid]=v[mid];
	if(x==y){
		int p=x;
		lson[p]=rson[p]=0;
		sum[p]=val[p]=v[x];siz[p]=1;
		dep[p]=1;
		return p;
	}
	lson[mid]=rebuild(x,mid-1,z);
	rson[mid]=rebuild(mid+1,y,z);
	update(mid);return mid;
}
void split(int p,int k,int &x,int &y){
	if(!p)return x=y=0,void();
	p=CopyNode(p);pushdown(p);
	if(siz[lson[p]]+1<=k)
		x=p,split(rson[p],k-siz[lson[p]]-1,rson[x],y);
	else y=p,split(lson[p],k,x,lson[y]);
	update(p);
}
int merge(int x,int y){
	if(!x||!y)return x|y;
	pushdown(x),pushdown(y);
	if(pri[x]<=pri[y])return rson[x]=merge(rson[x],y),update(x),x;
	else return lson[y]=merge(x,lson[y]),update(y),y;
}
void ins(int x){x=NewNode(x),root=merge(root,x);}
ll op1(int l,int r){
	int x,y,z,w;
	split(root,r,w,z);
	split(w,l-1,x,y);
	ll ans=sum[y];
	root=merge(merge(x,y),z);
	return ans;
}
void op2(int l,int r,int v){
	int x,y,z,w;
	split(root,r,w,z);
	split(w,l-1,x,y);
	push1(y,v);
	root=merge(merge(x,y),z);
}
void op3(int l,int r,int v){
	int x,y,z,w;
	split(root,r,w,z);
	split(w,l-1,x,y);
	push2(y,v);
	root=merge(merge(x,y),z);
}
void op4(int l1,int r1,int l2,int r2){
	int op=0;
	if(l1>l2)op=1,swap(l1,l2),swap(r1,r2);
	int x,y,z,w,u,v;
	split(root,r2,w,v);
	split(w,l2-1,w,u);
	split(w,r1,w,z);
	split(w,l1-1,x,y);
	if(!op){del(u),u=CopyNode(y);}
	else {del(y),y=CopyNode(u);}
	root=merge(merge(merge(x,y),merge(z,u)),v);
}
void op5(int l1,int r1,int l2,int r2){
	if(l1>l2)swap(l1,l2),swap(r1,r2);
	int x,y,z,w,u,v;
	split(root,r2,w,v);
	split(w,l2-1,w,u);
	split(w,r1,w,z);
	split(w,l1-1,x,y);
	swap(y,u);
	root=merge(merge(merge(x,y),merge(z,u)),v);
}
void op6(int l,int r){
	int x,y,z,w;
	split(root,r,w,z);
	split(w,l-1,x,y);
	push3(y);
	root=merge(merge(x,y),z);
}
int n,m;
const int mx=200;
int main(){
	// freopen("dote___strvct.in","r",stdin);
	// freopen("dote___strvct.out","w",stdout);
	cin>>n>>m;int op,x,y,l,r;
	for(int i=1;i<=n;++i)
		scanf("%d",&x),ins(x);
	while(m--){
		scanf("%d%d%d",&op,&l,&r);
		if(op==1)printf("%lld\n",op1(l,r));
		if(op==2)scanf("%d",&x),op2(l,r,x);
		if(op==3)scanf("%d",&x),op3(l,r,x);
		if(op==4)scanf("%d%d",&x,&y),op4(l,r,x,y);
		if(op==5)scanf("%d%d",&x,&y),op5(l,r,x,y);
		if(op==6)op6(l,r);
		// if(dep[root]>=mx||tot-q.size()>5e6){
		// 	v.push_back(0);
		// 	dfs(root,1);
		// 	root=rebuild(1,v.size()-1,0);
		// 	tot=v.size()-1;
		// 	v.clear();
		// }
	}
	dfs(root,1);
	for(auto p:v)
		printf("%d ",p);
}
