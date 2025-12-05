#include <cstdio>
#include <algorithm>
#include <cstring>
#include <climits>
using namespace std;
typedef long long ll;
ll dp[20][20];
ll a[20][20];
ll s;
int n, K;
int main(){
    scanf("%d%d%lld", &n, &K, &s);
    for(int i = n; i >= 1; --i){
        a[i][i] = s % 10;
        s /= 10;
    }
    for(int i = 2; i <= n; ++i)
        for(int j = i - 1; j >= 1; --j)
            a[j][i] = a[j][i - 1] * 10 + a[i][i];
    for(int i = 1; i <= n; ++i)dp[i][0] = a[1][i];
    for(int k = 1; k <= K; ++k)
        for(int i = k + 1; i <= n; ++i)
            for(int j = k; j < i; ++j)
                dp[i][k] = max(dp[i][k], dp[j][k - 1] * a[j + 1][i]);
    printf("%lld\n", dp[n][K]);
    char c = getchar(); c = getchar();
    return 0;
}