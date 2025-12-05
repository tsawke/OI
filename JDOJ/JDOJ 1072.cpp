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
int dp[1100000];
int main(){
    read(n), read(m);
	if(n < m){printf("0\n"); return 0;}
	dp[1] = m;
/*	dp[1][1] = 1;
	int a(1), b(2);
    for(int i = 1; i <= n; ++i, swap(a, b)){
    	for(int j = 1; j <= m; ++j){
    		for(int k = 1; k <= j; ++k)
    		dp[b][j] = (dp[b][j] + dp[a][k]) % 20102010;
		}
	}*/
/*	for(int i = 2; i <= n; ++i){
		if(i <= m)dp[i] = (dp[i - 1] * (m - i + 2 - 1)) % 20102010;
		else dp[i] = (((dp[i - 1] * (m - 1)) % 20102010) + (dp[i - 2] * (m - 1))) % 20102010;
	}*/
	for(int i = 2; i <= n; ++i)
		dp[i] = (dp[i - 1] * (i != n ? (m - 1) : (m - 2)) + i != n ? 0 : ((m - 1) * dp[i - 2 - 1])) % 20102010;
    
    printf("%d\n", dp[n]);
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
