#include<bits/stdc++.h>
#define ll long long
#define lowbit(x) ((x)&(-x))
#define minn(x,y) (x>y?y:x)
using namespace std;
int n,m,k,q;
int ver[4000006];
bool l[4000006];
int tim[4000006];
int read() {
    int x = 0, w = 1;
    char ch = 0;
    while (ch < '0' || ch > '9') {
      if (ch == '-') w = -1;
      ch = getchar(); 
    }
    while (ch >= '0' && ch <= '9') {
      x = x * 10 + (ch - '0');
      ch = getchar();
    }
    return x * w;
  }
inline void addv(int x,int kk){
    if(x==0) return;
    for(int i=x;i<=n+m+1;i+=lowbit(i)){
        ver[i]+=kk;
    }
    return;
}
inline int getv(int l,int r){
    int re=0;
    for(int i=r;i>0;i-=lowbit(i)){
        re+=ver[i];
    }
    for(int i=l-1;i>0;i-=lowbit(i)){
        re-=ver[i];
    }
    return re;
}
inline void addt(int x,int kk){
    if(x==0) return;
    for(int i=x;i<=n+m+1;i+=lowbit(i)){
        tim[i]+=kk;
    }
    return;
}
inline int gett(int l,int r){
    int re=0;
    for(int i=r;i>0;i-=lowbit(i)){
        re+=tim[i];
    }
    for(int i=l-1;i>0;i-=lowbit(i)){
        re-=tim[i];
    }
    return re;
}
inline int get(int l,int r){
    if(l>r) return 0;
    if(getv(l,r)==r-l+1) return gett(l,r);
    else return 5e8;
}
int main(){
    freopen("in.txt", "r", stdin);
    freopen("out2.txt", "w", stdout);
    scanf("%d%d%d%d",&n,&k,&m,&q);
    for(int i=1;i<=n;++i){
        int x;
        scanf("%d",&x);
        addv(i,1);
        addt(i,x);
        l[i]=1;
    }
    for(int i=n+1;i<=n+m+1;++i){
        int x;
        scanf("%d",&x);
        addv(i,1);
        addt(i,x);
        l[i]=1;
    }
    for(int o=1;o<=q;++o){
        char c;
        int x,y;
        scanf(" %c",&c);
        if(c=='q'){
            int ans=5e8;
            scanf("%d%d",&x,&y);
            if(x>y) swap(x,y);
            if(y<=k){
                ans=minn(ans,get(x,y-1));
                ans=minn(ans,get(1,x-1)+get(y,n));
                ans=minn(ans,get(1,x-1)+get(y,k-1)+get(n+1,n+m+1));
            }
            else if(y<=n&&y>k&&x<=k){
                ans=minn(ans,get(x,y-1));
                ans=minn(ans,get(1,x-1)+get(y,n));
                ans=minn(ans,get(1,x-1)+get(k,y-1)+get(n+1,n+m+1));
                ans=minn(ans,get(x,k-1)+get(y,n)+get(n+1,n+m+1));
            }
            else if(y<=n&&x>k){
                ans=minn(ans,get(x,y-1));
                ans=minn(ans,get(1,x-1)+get(y,n));
                ans=minn(ans,get(k,x-1)+get(y,n)+get(n+1,n+m+1));
            }
            else if(y>n&&x<=k){
                ans=minn(ans,get(n+1,y)+get(1,x-1));
                ans=minn(ans,get(n+1,y)+get(x,n));
                ans=minn(ans,get(y+1,n+m+1)+get(x,k-1));
                ans=minn(ans,get(y+1,n+m+1)+get(1,x-1)+get(k,n));
                
            }
            else if(y>n&&x<=n){
                ans=minn(ans,get(n+1,y)+get(x,n));
                ans=minn(ans,get(n+1,y)+get(1,x-1));
                ans=minn(ans,get(y+1,n+m+1)+get(k,x-1));
                ans=minn(ans,get(y+1,n+m+1)+get(x,n)+get(1,k-1));
            }
            else{
                int sum=get(n+1,x)+get(y+1,n+m+1);
                ans=minn(ans,get(x+1,y));
                ans=minn(ans,sum+get(1,k-1));
                ans=minn(ans,sum+get(k,n));
            }
            // if(x>100) printf("%d %d ",x,y);
            if(ans>=4e8) printf("impossible\n");
            else printf("%d\n",ans);
        }
        else{
            scanf("%d",&x);
            if(c=='x') x+=n+1;
            // if(x>100) printf("%c %d\n",c,x);
            // if(x==0) printf("$%c %d\n",c,x);
            if(l[x]==0){
                l[x]=1;
                addv(x,1);
            }
            else{
                l[x]=0;
                addv(x,-1);
            }

        }
    }
}