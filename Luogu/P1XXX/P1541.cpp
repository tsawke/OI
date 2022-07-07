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
int score[510], card[210];
int dp[510][210];
int main(){
	N = read(), M = read();
    for(int i = 1; i <= N; ++i)score[i] = read();
    for(int i = 1; i <= M; ++i)card[i] = read();
    for(int i = 1; i <= N; ++i){
        for(int j = 1; j <= min(i, M); ++j){
            dp[i][j] = max(dp[i - card[j]][j - 1] + score[i])
        }
    }


    return 0;
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