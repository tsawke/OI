#include <cstdio>
#include <algorithm>
using namespace std;
int m;
int dp[110000] = {1};
int a[10] = {0, 10, 20, 50, 100};
int main(){
    scanf("%d", &m);
    for(int i = 1; i <= 4; ++i)
        for(int j = a[i]; j <= m; ++j)
            dp[j] += dp[j - a[i]];
    printf("%d\n", dp[m]);
    char c = getchar(); c = getchar();
    return 0;
}