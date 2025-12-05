//C++11
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
typedef unsigned long long unll;
typedef long long ll;
template <typename T = int>
inline T read(void);
int Volume, n;
int volume[50];
int dp[21000];
int main(){
	Volume = read(), n = read();
	for(int i = 1; i <= n; ++i)volume[i] = read();
	for(int i = 1; i <= n; ++i)
		for(int j = Volume; j >= 1; --j)
			if(j >= volume[i])dp[j] = max(dp[j], dp[j - volume[i]] + volume[i]);
	printf("%d\n", Volume - dp[Volume]);

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