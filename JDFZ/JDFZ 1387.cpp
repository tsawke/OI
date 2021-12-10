#include <cstdio>
#include <algorithm>
#include <cstring>
#include <cstdlib>
#include <cmath>
#include <vector>
#include <climits>
#include <iostream>
#include <string>
#include <map>
#include <unistd.h>
using namespace std;
typedef unsigned long long unll;
typedef long long ll;
template <typename T>
inline T read(void);
int FindMax(int*, int);
int a[1100][1100];
int ans(INT_MIN);
int main(){
    int n = read<int>(), m = read<int>();
    for(int i = 1; i <= n; ++i)for(int j = 1; j <= m; ++j)a[i][j] = read<int>();
    for(int i = 1; i <= n; ++i){
        int temp[1100];
        memset(temp, 0, sizeof(temp));
        for(int j = i; j <= m; ++j){
            for(int k = 1; k <= n; ++k)temp[k] += a[k][j];
            ans = max(ans, FindMax(temp, n));
//            printf("i = %d, j = %d, Find = %d\n", i, j, FindMax(temp, n));
        }
    }
    printf("%d\n", ans);
    pause();
    return 0;
}
int FindMax(int *a, const int len){
    int ret(INT_MIN);
    int dp[len + 10];
    dp[0] = INT_MIN;
    memset(dp, 0, sizeof(dp));
    for(int i = 1; i <= len; ++i){
        if(a[i]){
            dp[i] = max(dp[i - 1] + a[i], a[i]);
            ret = max(ret, dp[i]);
        }else{
            dp[i] = INT_MIN;
        }
    }
    if(ret == INT_MIN)ret = 0;
    return ret;
}
template <typename T>
inline T read(void){
	T ret(0);
	short flag(1);
	char c = getchar();
	while (c < '0' || c > '9') {
		if (c == '-')flag = -1;
		c = getchar();
	}
	while (c >= '0' && c <= '9') {
		ret *= 10, ret += (c - '0');
		c = getchar();
    }
    ret *= flag;
	return ret;
}