#pragma GCC optimize(2)
#include <cstdio>
#include <algorithm>
#include <cstring>
#include <cstdlib>
#include <cmath>
#include <vector>
#define MOD 2333333
using namespace std;
typedef unsigned long long unll;
inline void readLL(unll&);
inline void read(int&);
int n;
int dp[1100][1100];
int wealth[1100][1100];
int main(){
    read(n);
    for(int i = 1; i <= n; ++i)
        for(int j = 1; j <= i; ++i){
            read(wealth[i][j]);
            dp[i][j] = wealth[i][j];
        }
    for(int i = n - 1; i >= 1; --i)
        for(int j = 1; j <= i; ++i)
            dp[i][j] = max(dp[i + 1][j], dp[i + 1][j + 1]) + wealth[i][j];
    printf("%d\n", dp[1][1]);
//    system("pause");
    return 0;
}
inline void readLL(unll& p){
    p = 0;
	int flag(1);
	char c = getchar();
	while (c < '0' || c > '9') {
		if (c == '-')flag = -1;
		c = getchar();
	}
	while (c >= '0' && c <= '9') {
		p *= 10, p += (c - '0');
		c = getchar();
		p *= flag;
	}
}
inline void read(int& p) {
	p = 0;
	int flag(1);
	char c = getchar();
	while (c < '0' || c > '9') {
		if (c == '-')flag = -1;
		c = getchar();
	}
	while (c >= '0' && c <= '9') {
		p *= 10, p += (c - '0');
		c = getchar();
		p *= flag;
	}
}
