#include <cstdio>
#include <algorithm>
using namespace std;
int n, t;
int dp[110000] = {1};
int a[1100];
int main(){
    scanf("%d%d", &n, &t);
    for(int i = 1; i <= n; ++i)scanf("%d", a + i);
    for(int i = 1; i <= n; ++i)
        for(int j = t; j >= a[i]; --j)
            dp[j] += dp[j - a[i]];
    printf("%d\n", dp[t]);
//    char c = getchar(); c = getchar();
    return 0;
}