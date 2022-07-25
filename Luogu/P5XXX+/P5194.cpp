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
#include <functional>
using namespace std;
typedef unsigned long long unll;
typedef long long ll;
template <typename T = int>
inline T read(void);
int n, C;
int a[1100];
unll sum[1100];
unll ans(0ull);
void dfs(unll, int);
int main(){
	n = read(); C = read();
    for(int i = 1; i <= n; ++i){a[i] = read(); sum[i] = sum[i - 1] + a[i];}
//    sum[n + 1] = sum[n];
//    for(int i = 1; i <= n; ++i)printf("values:%d  %d\n", a[i], sum[i]);
    dfs(0, n + 1);
    printf("%lld\n", ans);
    return 0;
}
void dfs(unll value, int deep){
    if(value == C){
        printf("%d\n", C);
        exit(0);
    }
    if(value > C)return;
    if(sum[deep - 1] + value <= C){ans = max(sum[deep - 1] + value, ans); return;}
    ans = max(ans, value);
    dfs(value + a[deep - 1], deep - 1);
    dfs(value, deep - 1);
}
template <typename T = int>
inline T read(void)
{
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
