#include<cstring>
#include<cstdio>
#include<algorithm>
#include<iostream>
#include<cmath>

using namespace std;
const int N=500010,INF=1<<30;
int n,c[1<<22],son[N],siz[N],dep[N];
int head[N],nxt[N],D[N],ans[N];

inline int read(){
    int x=0,f=1;
    char ch=getchar();
    while(!isdigit(ch)){if(ch=='-') f=-1;ch=getchar();}
    while(isdigit(ch)){x=x*10+(ch^48);ch=getchar();}
    return x*f;
}

void dfs(int u){
    siz[u]=1;
    for(int i=head[u];i;i=nxt[i]){
        D[i]^=D[u];
        dep[i]=dep[u]+1;
        dfs(i);siz[u]+=siz[i];
        if(siz[i]>siz[son[u]]) son[u]=i;
    }
}

void init(int u){
    c[D[u]]=-INF;
    for(int i=head[u];i;i=nxt[i]) init(i);
}

int o;
void up(int u){
    ans[o]=max(ans[o],dep[u]+c[D[u]]);
    for(int i=0;i<=21;i++) ans[o]=max(ans[o],dep[u]+c[1<<i^D[u]]);
    for(int i=head[u];i;i=nxt[i]) up(i);
}

void ins(int u){
    c[D[u]]=max(c[D[u]],dep[u]);
    for(int i=head[u];i;i=nxt[i]) ins(i);
}

//dsu on tree
void work(int u){
    for(int i=head[u];i;i=nxt[i])
        if(i!=son[u]) work(i),init(i);
    if(son[u]) work(son[u]); o=u;
    for(int i=head[u];i;i=nxt[i])
        if(i!=son[u]) up(i),ins(i);
    c[D[u]]=max(c[D[u]],dep[u]);
    ans[u]=max(ans[u],dep[u]+c[D[u]]);
    for(int i=0;i<=21;i++) ans[u]=max(ans[u],dep[u]+c[1<<i^D[u]]);//枚举满足条件的y
    ans[u]-=dep[u]<<1;//x-y的距离=dep[y]+dep[x]-2*dep[x]
    for(int i=head[u];i;i=nxt[i]) ans[u]=max(ans[u],ans[i]);//在子树内比较
}

int main(){
    n=read();
    for(int i=0;i<(1<<22);i++) c[i]=-INF;
    for(int i=2,x;i<=n;i++){
        x=read();
        nxt[i]=head[x];head[x]=i;
        char c=getchar();
        while(c>'v'||c<'a') c=getchar();
        D[i]=1<<(c-'a');
    }
    dfs(1);work(1);
    for(int i=1;i<=n;i++) printf("%d ",ans[i]);
    return 0;
}