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
typedef unsigned int uint;
typedef unsigned long long unll;
typedef long long ll;
template <typename T = int>
inline T read(void);
int dp[410][410];
int main(){
	int maxVolume = read(), maxWeight = read();
    int N = read();
    for(int i = 1; i <= N; ++i){
        int volume = read(), weight = read(), calorie = read();
        for(int j = maxVolume; j >= volume; --j)
            for(int k = maxWeight; k >= weight; --k)
                dp[j][k] = max(dp[j][k], dp[j - volume][k - weight] + calorie);
    }
    printf("%d\n", dp[maxVolume][maxWeight]);

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