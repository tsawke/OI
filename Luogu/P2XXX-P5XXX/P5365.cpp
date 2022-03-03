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
int N, minScheme;
int num[110000], price[110000];
int dp[110000];
int main(){
	N = read(), minScheme = read();
    for(int i = 1; i <= N; ++i)num[i] = read();
    for(int i = 1; i <= N; ++i)price[i] = read();
    for(int i = 1; i <= N; ++i){
        int base(1);
        int times = num[i];
        while(times > 0){
            if(base > times){
                makeDP(price[i], times);
                break;
            }
            else{
                times -= base;
                makeDP(price[i], base);
                base <<= 1;
            }
        }
    }
    int 
    printf("%d\n", ans);
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