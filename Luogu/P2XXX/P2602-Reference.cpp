#include<bits/stdc++.h>
using namespace std;
long long a,b;
long long ten[20],f[20];
long long cnta[20],cntb[20];
void solve(long long x,long long *cnt)
{
    long long num[20]={0};
    int len=0;
    while(x)
    {
        num[++len]=x%10;
        x=x/10;
    } 
    for(int i=len;i>=1;i--)
    {
        for(int j=0;j<=9;j++)
        cnt[j]+=f[i-1]*num[i];
        for(int j=0;j<num[i];j++)
        cnt[j]+=ten[i-1];
        long long num2=0;
        for(int j=i-1;j>=1;j--)
        {
            num2=num2*10+num[j];
        }
        cnt[num[i]]+=num2+1;
        cnt[0]-=ten[i-1];
    } 
}
int main()
{
    freopen("./P2602-RefOUTPUT.txt", "w", stdout);
    // scanf("%lld %lld",&a,&b);
    ten[0]=1;
    for(int i=1;i<=15;i++)
    {
        f[i]=f[i-1]*10+ten[i-1];
        ten[i]=10*ten[i-1];
    }
    // solve(a-1,cnta);
    // solve(b,cntb);
    // for(int i=0;i<=9;i++)
    // printf("%lld ",cntb[i]-cnta[i]);
    for(int i = 1; i <= 1000; ++i){
        long long ans[20];
        memset(ans, 0ll, sizeof(ans));
        solve(i, ans);
        printf("No.%d  [0]=>%lld%s", i, ans[0] + 1, (i % 5 == 0 || i == 1000) ? "\n" : "    ");
        // ans.clear();
    }
    for(int i = 100000; i <= 100050; ++i){
        long long ans[20];
        memset(ans, 0ll, sizeof(ans));
        solve(i, ans);
        printf("No.%d  [0]=>%lld%s", i, ans[0] + 1, (i % 5 == 0 || i == 1000) ? "\n" : "    ");
        // ans.clear();
    }
    for(int i = 10000; i <= 10050; ++i){
        long long ans[20];
        memset(ans, 0ll, sizeof(ans));
        solve(i, ans);
        printf("No.%d  [0]=>%lld%s", i, ans[0] + 1, (i % 5 == 0 || i == 1000) ? "\n" : "    ");
        // ans.clear();
    }
}