
#include <bits/stdc++.h>
using namespace std;
#define ll long long
const ll p=1e9+7;
ll n,m,k,t;
inline ll poww(ll a,ll b){
    ll re=1,sum=a;
    while(b){
        if((b&1)==1) re=(re*sum)%p;
        sum=sum*sum%p;
        b>>=1;
    }
    return re;
}
int main(){
    scanf("%lld",&t);
    // for(int i=1;i<=10;++i){
    //     printf("%d\n",poww(3,i));
    // }
    for(int o=1;o<=t;++o){
        scanf("%lld%lld%lld",&n,&k,&m);
        if(m<2){
            printf("0\n");
            continue;
        }
        if(m==2){
            if(k&1) printf("0\n");
            else printf("2\n");
            continue;
        }
        ll ans=poww((m-1)*(m-1)%p-(m-2)+p,(n-1)*k)%p*(poww(m-1,k)-((k&1)?1:-1)*(m-1)+p+p)%p;
        // ll ans=poww(((m-1)*(m-1)%p-(m-2)+p)%p,(n-1)*k);
        // if(k==3) ans=ans*m%p*(m-1)%p*(m-2)%p;
        // else{
        //     if((k&1)==1) ans=ans*m%p*poww(m-1,k-4)%p*((m-1)*(m-2)%p+(m-2)*((m-1)*(m-1)%p-(m-2)+p)%p)%p;
        //     else ans=ans*m%p*poww(m-1,k-3)%p*((m-1)+(m-2)*(m-2)%p)%p;
        // }
        printf("%lld\n",ans);
    }
    return 0;
}
