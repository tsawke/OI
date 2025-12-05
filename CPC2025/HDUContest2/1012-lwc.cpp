#include <bits/stdc++.h>
#define int long long 
using namespace std;
int T,n,ans,cnt,p[233],a[233];
bool vis[233];
void ins(int x) {   
    for (int i=62;i>=0;i--) {
        if (x&(1ll<<i)) {
            if (!p[i]) {p[i]=x;break;}
                else    x^=p[i];
        }
    }
}
int askmax() {
    int res=0;
    for (int i=62;i>=0;i--) {
        if ((res^p[i])>res) res^=p[i];
    }
    return res;
}
int js() {
    tot=0;
    if (vis[n]==0&&vis[n-1]==0) return 0;
    for (int i=1;i<=n;i++) cout<<vis[i]<<" ";cout<<endl;
    for (int i=1;i<=62;i++) p[i]=0;
    for (int i=1;i<=n;i++) {
        if (vis[i]) ins(a[i]);
     }
    int tmp=askmax();
    return tmp;
}
void dfs(int x) {
    if (x==n) {
        int tmp=js(); cnt++;

        if (ans<tmp) {
            ans=tmp;
        }
        return ;
    }
    if (vis[x]==1) {
        vis[x+1]=0;
        dfs(x+1);
        vis[x+1]=0;
        return ;
    }
    bool tf=0;
    if (vis[x]) tf=1;
    if (vis[x-1]) tf=1;
    if (tf==0) {
        vis[x+1]=1;
        dfs(x+1);
        vis[x+1]=0;
        return ;
    }
    vis[x+1]=1;
    dfs(x+1);
    vis[x+1]=0;
    dfs(x+1);
    vis[x+1]=0;
    
}
signed main(){
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    cin>>T;
    while (T--) {
        ans=0;
        cin>>n;
        for (int i=1;i<=n;i++) {
            cin>>a[i];
        }
        vis[1]=1;
        dfs(1);
        vis[1]=0;
        dfs(1);
        vis[1]=0;
        cout<<"cnt="<<cnt<<endl;
        cout<<ans<<endl;
    }
    return 0;
}