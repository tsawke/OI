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
int sx, sy;
bool block[30][30] = {false};
unll dp[30][30];
void init(void);
int main(){
	read(n), read(m), read(sx), read(sy);
	init();
	for(int i = 1; i <= n; ++i)
		for(int j = 1; j <= m; ++j)
			dp[i][j] = block[i][j] ? 0 : (dp[i - 1][j] + dp[i][j - 1]);
/*	for(int i = 0; i <= n; ++i)
		for(int j = 0; j <= m; ++j)
			printf("%d%c", dp[i][j], j == m ? '\n' : ' ');
	printf("chech block.....\n");
	for(int i = 0; i <= n; ++i)
		for(int j = 0; j <= m; ++j)
			printf("%d%c", block[i][j], j == m ? '\n' : ' ');*/
	printf("%llu\n", dp[n][m]);
//    system("pause");
    return 0;
}

void init(void){
	::block[::sx][::sy] = true;
	short dx[10] = {0,  -1, -2, -2, -1, 1, 2, 2, 1};
	short dy[10] = {0,  -2, -1, 1, 2, -2, -1, 1, 2};
	for(int i = 1; i <= 8; ++i)
		if(0 <= ::sx + dx[i] && ::sx + dx[i] <= n && 0 <= ::sy + dy[i] && ::sy + dy[i] <= m)
			::block[::sx + dx[i]][::sy + dy[i]] = true;
	if(::block[0][0]){printf("0\n"); exit(0);}
	::dp[0][0] = 1;
	for(int i = 1; i <= ::m; ++i){
		if(::block[0][i])break;
		::dp[0][i] = 1;
	}
	for(int i = 1; i <= ::n; ++i){
		if(::block[i][0])break;
		::dp[i][0] = 1;
	}
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

