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
int T;
ll lucas(ll, ll, ll);
ll getC(ll, ll, ll);
int main(){
	


    return 0;
}
ll lucas(ll n, ll m, ll MOD){
    if(!m)return 1ll;
    return (getC(n % MOD, m % MOD, MOD) * lucas(n / MOD, m / MOD, MOD) % MOD);
}
ll getC(ll n, ll m, ll MOD){
    return ()
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