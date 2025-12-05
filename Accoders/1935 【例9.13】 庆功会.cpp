#include <cstdio>
#include <algorithm>
using namespace std;
int n, m;
int dp[110000];
int wei[1100], pri[1100], s[1100];
int main(){
    scanf("%d%d", &n, &m);
    for(int i = 1; i <= n; ++i)scanf("%d%d%d", wei + i, pri + i, s + i);
    for(int i = 1; i <= n; ++i)
        for(int j = m; j >= 1; --j)
            for(int k = 1; k <= s[i]; ++k){
                if(j < k * wei[i])break;
                dp[j] = max(dp[j], dp[j - k * wei[i]] + k * pri[i]);
            }
    printf("%d\n", dp[m]);
    char c = getchar(); c = getchar();
    return 0;
}