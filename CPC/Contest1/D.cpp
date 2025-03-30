
#include <bits/stdc++.h>
using namespace std;
#define ll long long
int n,m,ans;
struct qwq{
    int val;
    int vera,verb;
    bitset<10004> s;
}d[10004];
int main(){
    scanf("%d%d",&n,&m);
    for(int i=2;i<=n+1;++i){
        int x;
        scanf("%d%d%d%d",&x,&d[i].vera,&d[i].verb,&d[i].val);
        d[i].s.set(i);
    }
    for(int i=n+1;i>=2;--i){
        d[d[i].vera].s|=d[i].s;
        d[d[i].verb].s|=d[i].s;
    }
    for(int i=2;i<=n+1;++i){
        int sum=0;
        for(int j=i;j<=n+1;++j){
            if(d[i].s[j]) sum+=d[j].val;
        }
        if(sum>=m){
            ans++;
            printf("%d %d\n",i,sum);
        }
    }
    printf("%d",ans);
    return 0;
}
