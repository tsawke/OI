#include <cstdio>
#include <algorithm>
using namespace std;
int n, m;
int dp[110000];
int wei[1100], pri[1100];
int main(){
    scanf("%d%d", &n, &m);
    for(int i = 1; i <= n; ++i)scanf("%d%d", wei + i, pri + i);
    for(int i = 1; i <= n; ++i)
        for(int j = 1; j <= m; ++j)
            if(j >= wei[i])dp[j] = max(dp[j], dp[j - wei[i]] + pri[i]);
    printf("max=%d\n", dp[m]);
//    char c = getchar(); c = getchar();
    return 0;
}