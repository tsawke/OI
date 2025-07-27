#include <bits/stdc++.h>
#define int long long 
using namespace std;
const int N=200005;
const int MOD=1e9+7;
struct qwq{
	int x,y,val,xy,yx;
}a[N];
int T,n,b[N],ans;
int tree1[N],tree2[N],tree3[N],tree4[N];
int tree5[N],tree6[N],tree7[N],tree8[N];
bool cmp1(qwq A,qwq B) {
	return A.x<B.x;	
}
int lowbit(int x) {
	return x&(-x);	
}

void add1(int x,int k) {
	if (x<0) return ;
	for (x;x<=n;x+=lowbit(x)) {
		tree1[x]=(tree1[x]+k)%MOD;
	}
}
void add2(int x,int k) {
	if (x<0) return ;
	for (x;x<=n;x+=lowbit(x)) {
		tree2[x]=(tree2[x]+k)%MOD;
	}
}
void add3(int x,int k) {
	if (x<0) return ;
	for (x;x<=n;x+=lowbit(x)) {
		tree3[x]=(tree3[x]+k)%MOD;
	}
}
void add4(int x,int k) {
	if (x<0) return ;
	for (x;x<=n;x+=lowbit(x)) {
		tree4[x]=(tree4[x]+k)%MOD;
	}
}
void add5(int x,int k) {
	if (x<0) return ;
	for (x;x<=n;x+=lowbit(x)) {
		tree5[x]=(tree5[x]+k)%MOD;
	}
}
void add6(int x,int k) {
	if (x<0) return ;
	for (x;x<=n;x+=lowbit(x)) {
		tree6[x]=(tree6[x]+k)%MOD;
	}
}
void add7(int x,int k) {
	if (x<0) return ;
	for (x;x<=n;x+=lowbit(x)) {
		tree7[x]=(tree7[x]+k)%MOD;
	}
}
void add8(int x,int k) {
	if (x<0) return ;
	for (x;x<=n;x+=lowbit(x)) {
		tree8[x]=(tree8[x]+k)%MOD;
	}
}



int query1(int x) {
	int t=0;
	for (;x;x-=lowbit(x)) {
		t=(t+tree1[x])%MOD;
	}
	return t;
}
int query2(int x) {
	int t=0;
	for (;x;x-=lowbit(x)) {
		t=(t+tree2[x])%MOD;
	}
	return t;	
}
int query3(int x) {
	int t=0;
	for (;x;x-=lowbit(x)) {
		t=(t+tree3[x])%MOD;
	}
	return t;	
}
int query4(int x) {
	int t=0;
	for (;x;x-=lowbit(x)) {
		t=(t+tree4[x])%MOD;
	}
	return t;
}
int query5(int x) {
	int t=0;
	for (;x;x-=lowbit(x)) {
		t=(t+tree5[x])%MOD;
	}
	return t;	
}
int query6(int x) {
	int t=0;
	for (;x;x-=lowbit(x)) {
		t=(t+tree6[x])%MOD;
	}
	return t;	
}
int query7(int x) {
	int t=0;
	for (;x;x-=lowbit(x)) {
		t=(t+tree7[x])%MOD;
	}
	return t;	
}
int query8(int x) {
	int t=0;
	for (;x;x-=lowbit(x)) {
		t=(t+tree8[x])%MOD;
	}
	return t;	
}


signed main() {
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	cin>>T;
	while (T--) {
		cin>>n;
		for (int i=1;i<=n;i++) {
			cin>>a[i].x>>a[i].y>>a[i].val;
			tree1[i]=tree2[i]=tree3[i]=tree4[i]=0;
			tree5[i]=tree6[i]=tree7[i]=tree8[i]=0;
		}
		ans=0;
		sort(a+1,a+n+1,cmp1);
		int suma=0,sumx=0,sumax=0;
		for (int i=1;i<=n;i++) {
			int t=((i-1)*a[i].val%MOD*(a[i].x+MOD)%MOD+suma*(a[i].x+MOD)%MOD+3*MOD)%MOD;
	//		cout<<" mid: "<<i<<" t="<<t<<endl;
			t=(t-(a[i].val*(sumx+MOD)%MOD+MOD)%MOD-sumax+3*MOD)%MOD;
	//		cout<<" mid: "<<i<<" t="<<t<<endl;
			ans=(ans+t)%MOD;
			suma=(suma+a[i].val)%MOD;
			sumx=(sumx+a[i].x+MOD)%MOD;
			sumax=(sumax+(a[i].x+MOD)*a[i].val%MOD+MOD)%MOD;
	//		cout<<"i="<<i<<" suma="<<suma<<" sumx="<<sumx<<" sumax="<<sumax<<" t="<<t<<endl;
		}
	//	cout<<"ans="<<ans<<endl;
		
		int cnt=0;
		for (int i=1;i<=n;i++) {
			b[i]=a[i].y-a[i].x;		
		}
		sort(b+1,b+n+1);
		int cur=unique(b+1,b+n+1)-b-1;
		for (int i=1;i<=n;i++) {
			a[i].yx=lower_bound(b+1,b+cur+1,a[i].y-a[i].x)-b;
			a[i].yx++;
		}
		
		for (int i=1;i<=n;i++) { //y[i]-y[j]>x[i]-x[j]
			int t=query7(a[i].yx-1)*a[i].val%MOD*(a[i].y-a[i].x)%MOD;
			t=(t-query1(a[i].yx-1)-a[i].val*query2(a[i].yx-1)%MOD+(a[i].y-a[i].x)*query3(a[i].yx-1)+2*MOD)%MOD;
			ans=(ans+t)%MOD;
			add1(a[i].yx,a[i].val*(a[i].y-a[i].x)%MOD);
			add2(a[i].yx,(a[i].y-a[i].x+MOD)%MOD);
			add3(a[i].yx,a[i].val);
			add7(a[i].yx,1);
		}

	//	cout<<"qwq ans="<<ans<<endl;
		cnt=0;
		for (int i=1;i<=n;i++) {
			b[i]=a[i].x+a[i].y;		
		}
		sort(b+1,b+n+1);
		cur=unique(b+1,b+n+1)-b-1;
		for (int i=1;i<=n;i++) {
			a[i].xy=lower_bound(b+1,b+cur+1,a[i].x+a[i].y)-b;
			a[i].xy++;
		}
		reverse(a+1,a+n+1);
		for (int i=1;i<=n;i++) { //x[i]+y[i]<x[j]+y[j]
			int t=(-query8(a[i].xy-1)*a[i].val%MOD*(a[i].x+a[i].y+2*MOD)%MOD+MOD)%MOD;
			t=(t+query4(a[i].xy-1)%MOD-query5(a[i].xy-1)*(a[i].x+a[i].y+2*MOD)%MOD+a[i].val*query6(a[i].xy-1)%MOD+MOD)%MOD;
			t=(-t+MOD)%MOD;
			ans=(ans+t)%MOD;
			
			add4(a[i].xy,a[i].val*(a[i].x+a[i].y+2*MOD)%MOD);
			add5(a[i].xy,a[i].val);
			add6(a[i].xy,(a[i].x+a[i].y+2*MOD)%MOD);
			add8(a[i].xy,1);
		}
		
		cout<<ans<<'\n';		
	}
    return 0;
}

/*

1
6
1 1 1
1 2 2
1 3 3
2 1 4
2 2 5
2 3 6






1
5
-3 1 1 
-2 -1 2 
-3 4 4 
2 7 5
4 6 9

1
2 
1 1 500
1 2 2000



*/