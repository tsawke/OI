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
#define log2(n) (floor(log(n) / log(2.00)))
using namespace std;
typedef unsigned int uint;
typedef unsigned long long unll;
typedef long long ll;
template <typename T = int>
inline T read(void);
int sHour, sMinute, eHour, eMinute;
int Time;
int N;
int dp[1100];
void makeDP(int, int, bool);
int main(){
	sHour = read(), sMinute = read(), eHour = read(), eMinute = read();
    N = read();
    Time = (eHour - sHour) * 60 + (eMinute - sMinute) * 1;
    for(int i = 1; i <= N; ++i){
        int time = read(), value = read(), times = read();
        if(!times) makeDP(time, value, true);
        else{
            int base = 1;
            while(times > 0){
                // int POW = int(pow(2, base));
                // if(POW > times){--base; continue;}
                // times -= POW;
                // --base;
                if(times < base){
                    makeDP(time * times, value * times, false);
                    break;
                }
                else{
                    times -= base;
                    makeDP(time * base, value * base, false);
                    base *= 2;
                }
            }
        }
    }
    printf("%d\n", dp[Time]);
    return 0;
}
void makeDP(int time, int value, bool mode/*false--01 true--complete*/){
    // printf("Making DP time = %d  value = %d  mode = %d\n", time, value, (int)mode);
    if(mode)
        for(int j = time; j <= ::Time; ++j)
            dp[j] = max(dp[j], dp[j - time] + value);
    else
        for(int j = ::Time; j >= time; --j)
            dp[j] = max(dp[j], dp[j - time] + value);
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