//C++11 - Template
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
#include <queue>
#include <stack>
#include <functional>
#include <unistd.h>

using namespace std;
typedef unsigned int uint;
typedef unsigned long long unll;
typedef long long ll;
template <typename T = int>
inline T read(void);

int N, M;
bool _map[110][110];
int dp[110][2100][2100]; //i-line  from j to k
int main(){
	N = read(), M = read();
	for(int i = 1; i <= N; ++i)
		for(int j = 1; j <= M; ++j)
			_map[i][j] = readChar();
	

    return 0;
}
inline bool readChar(void){
	char c = getchar();
	while(c != 'P' && c != 'H')c = getchar();
	return c == 'P' ? false : true;
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