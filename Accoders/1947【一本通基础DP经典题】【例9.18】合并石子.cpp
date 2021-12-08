#include <cstdio>
#include <algorithm>
#include <cstring>
#include <climits>
using namespace std;
int dp[1100][1100];
int a[1100];
int n;
int main(){
    scanf("%d", &n);
    for(int i = 1; i <= n; ++i){
        int t;
        scanf("%d", &t);
        a[i] = a[i - 1] + t;
    }
    memset(dp, 127 / 3, sizeof(dp));
    for(int i = 1; i <= n; ++i)dp[i][i] = 0;
    for(int i = n - 1; i >= 1; --i)
        for(int j = i + 1; j <= n; ++j)
            for(int k = i; k <= j - 1; ++k)
                dp[i][j] = min(dp[i][j], dp[i][k] + dp[k + 1][j] + a[j] - a[i - 1]);
    printf("%d\n", dp[1][n]);
//    char c = getchar(); c = getchar();
    return 0;
}