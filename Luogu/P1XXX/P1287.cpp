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
int Cal(int, int);
int main(){
	N = read(), M = read();
    int ans(Cal(N, M));
    for(int i = 1; i <= M; ++i)ans *= i;
    printf("%d\n", ans);
    return 0;
}
int Cal(int n, int m){
    if(n < 0 || m < 0 || m > n)return 0;
    if(n == m)return 1;
    return m * Cal(n - 1, m) + Cal(n - 1, m - 1);
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