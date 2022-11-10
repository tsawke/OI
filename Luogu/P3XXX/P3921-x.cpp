#include<bits/stdc++.h>
using namespace std;typedef long long ll;
const int maxn=15,maxm=55;
int n,m1,m2,r,a1[maxm],b1[maxn],a2[maxm],b2[maxm],c2[maxm],zt[1<<maxn],len,dep[1<<maxn],Q[(1<<maxn)+10],L,R,T;ll f[1<<maxn];
bool cz(int S,int w){return S&(1<<w-1);}
void bfs()
{
    L=R=Q[0]=0,f[0]=dep[0]=1;
    while(L<=R)
    {
        int p=Q[L++];
        if(dep[T]&&dep[p]>=dep[T])continue;
        for(int i=0;i<len;i++)
        {
            int to=zt[i],gc=zt[i]^p;
            if(__builtin_popcount(gc)>r)continue;
            if(dep[to]==dep[p]+1){f[to]+=f[p];continue;}
            if(dep[to])continue;
            dep[to]=dep[p]+1,Q[++R]=to,f[to]=f[p];
        }
    }
}
int main()
{
    // freopen("math.in","r",stdin);
    // freopen("math.out","w",stdout);
    scanf("%d%d%d%d",&n,&m1,&m2,&r);T=(1<<n)-1;
    for(int i=1;i<=m1;i++)scanf("%d%d",a1+i,b1+i);
    for(int i=1;i<=m2;i++)scanf("%d%d%d",a2+i,b2+i,c2+i);
    for(int i=0;i<=T;i++)
    {
        bool js=0;
        for(int j=1;j<=m1;j++)if(cz(i,a1[j])!=cz(i,b1[j])){js=1;break;}
        if(js)continue;
        for(int j=1;j<=m2;j++)if(cz(i,a2[j])!=cz(i,b2[j])&&cz(i,a2[j])!=cz(i,c2[j])){js=1;break;}
        if(js)continue;
        zt[len++]=i;
    }
    for(int i = 0; i < len; ++i)cout << bitset < 16 > (zt[i]) << endl;
    bfs();
    if(!dep[T])printf("-1 0");
    else printf("%d %lld",dep[T]-1,f[T]);
    return 0;
}