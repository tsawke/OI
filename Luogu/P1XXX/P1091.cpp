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

int N;
int height[110];
int dpL[110], dpR[110];
int main(){
	N = read();
	for(int i = 1; i <= N; ++i)height[i] = read();
	for(int i = 0; i <= 101; ++i)dpL[i] = dpR[i] = 1;
	for(int i = 1; i <= N; ++i){
		for(int k = 1; k < i; ++k){
			if(height[k] < height[i])dpL[i] = max(dpL[i], dpL[k] + 1);
		}
	}
	reverse(height + 1, height + N + 1);
	for(int i = 1; i <= N; ++i){
		for(int k = 1; k < i; ++k){
			if(height[k] < height[i])dpR[i] = max(dpR[i], dpR[k] + 1);
		}
	}
	int ans(INT_MIN);
	// for(int i = 1; i <= N; ++i)printf("%d ", dpL[i]); printf("\n");
	// for(int i = 1; i <= N; ++i)printf("%d ", dpR[i]); printf("\n");
	for(int i = 1; i <= N; ++i)ans = max(ans, dpL[i] + dpR[N - i] - 1);
	printf("%d\n", N - ans);


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