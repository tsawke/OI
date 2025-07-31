#include<bits/stdc++.h>
using namespace std;

#define int long long
#define rep(x,l,r) for(int x=(l);x<=(r);++x)
#define per(x,r,l) for(int x=(r);x>=(l);--x)
#define repe(u) for(int _=head[u],v;v=e[_].to;_=e[_].next)
const int maxn=2e5+5;
const int maxm=(1<<22)-1;
const int mod=998244353;
int n,m,k,U[maxn],V[maxn],msk[maxn],cnt[maxm],fac[maxn],inv[maxn],pop[maxm];
int p[maxn][19],pmsk[maxn][19],dep[maxn];
vector<int>g[maxn];

int read(){
	int res=0,f=1;char ch;
	do{ch=getchar();if(ch=='-')f=-1;}while(!isdigit(ch));
	do{res=res*10+ch-'0';ch=getchar();}while(isdigit(ch));
	return res*f;
}

void dfs(int u,int fa){
	p[u][0]=fa;dep[u]=dep[fa]+1;
	rep(i,1,18)p[u][i]=p[p[u][i-1]][i-1],pmsk[u][i]=pmsk[u][i-1]|pmsk[p[u][i-1]][i-1];
	for(int v:g[u])if(v!=fa)dfs(v,u);
}

int qpow(int x,int k){
	int res=1;
	while(k){
		if(k&1)res=res*x%mod;
		x=x*x%mod;
		k>>=1;
	}
	return res;
}

int C(int x,int y){if(x<y)return 0;return fac[x]*inv[y]%mod*inv[x-y]%mod;}
int popcnt(int x){int res=0;while(x)res+=(x&1),x>>=1;return res;}

void solve(){
	n=read();m=read();k=read();
	rep(i,1,n-1)U[i]=read(),V[i]=read(),g[U[i]].push_back(V[i]),g[V[i]].push_back(U[i]);
	dfs(1,0);
	rep(i,0,m-1){
		int id=read(),u=U[id],v=V[id];
		if(p[u][0]==v)pmsk[u][0]|=(1<<i);
		else pmsk[v][0]|=(1<<i);
	}
	dfs(1,0);
	int tot=0,all=(1<<m)-1;
	rep(i,1,k){
		int s=read(),t=read();
		if(dep[s]>dep[t])swap(s,t);
		per(j,18,0)if(dep[p[t][j]]>=dep[s])msk[i]|=pmsk[t][j],t=p[t][j];
		if(s!=t){
			per(j,18,0)if(p[s][j]!=p[t][j])msk[i]|=pmsk[s][j],msk[i]|=pmsk[t][j],s=p[s][j],t=p[t][j];
			msk[i]|=pmsk[s][0];
			msk[i]|=pmsk[t][0];
		}
		tot|=msk[i];
		++cnt[msk[i]];
//		cout<<msk[i]<<endl;
	}
	if(tot!=all){puts("-1");return;}
	fac[0]=inv[0]=1;
	rep(i,1,k)fac[i]=fac[i-1]*i%mod;
	inv[k]=qpow(fac[k],mod-2);
	per(i,k-1,1)inv[i]=inv[i+1]*(i+1)%mod;
	
if(cnt[(1 << m) - 1]){
        printf("1 %lld\n", cnt[(1 << m) - 1]);
        exit(0);
    }

	rep(i,0,m-1)rep(S,0,all)if(S>>i&1)(cnt[S]+=cnt[S^(1<<i)])%=mod;
	rep(S,0,all)pop[S]=popcnt(S);

    

    for(int d = 2; d <= m; ++d){
        int ans(0);
        for(int S = 0; S <= (1 << m) - 1; ++S){
            ans +=
                (((m - popcnt(S)) & 1) ? -1 : 1) *
                C(cnt[S], d) %
                mod;
            ans = (ans % mod + mod) % mod;
        }
        if(ans){
            printf("%lld %lld\n", d, ans);
            // return 0;
            exit(0);
        }
    }
    printf("-1 -1\n");
	// rep(i,1,m){
	// 	int num=0;
	// 	rep(S,0,all){
	// 		if((m-pop[S])&1)num=(num-C(cnt[S],i)+mod)%mod;
	// 		else num=(num+C(cnt[S],i))%mod;
	// 	}
	// 	if(num>0){
	// 		printf("%lld %lld\n",i,num);
	// 		return;
	// 	}
	// }
}

signed main(){
//	int T=read();while(T--)
		solve();
}