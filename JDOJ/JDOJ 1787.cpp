#include <cstdio>
#include <algorithm>
#include <cstring>
#include <cstdlib>
#include <cmath>
#include <vector>
using namespace std;
typedef unsigned long long unll;
inline void readLL(unll&);
inline void read(int&);
int n, m;
int _max[110];
unll dp[110][110];
int main(){
    read(n), read(m);
    for(int i = 1; i <= n; ++i)read(_max[i]);
    for(int i = 0; i <= n; ++i)dp[i][0] = 1ull;
    for(int i = 1; i <= n; ++i)
    	for(int j = 1; j <= m; ++j)
    		for(int k = 0; k <= min(_max[i], j); ++k){
    			dp[i][j] += dp[i - 1][j - k];
    			dp[i][j] %= 1000007ull;
			}
//	for(int i = 0; i <= n; ++i)for(int j = 0; j <= m; ++j)printf("%d%c", dp[i][j], j == m ? '\n' : ' ');
    printf("%llu\n", dp[n][m]);
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
