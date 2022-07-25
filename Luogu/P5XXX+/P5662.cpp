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
int days, N, coins;
int dp_by_element_exist[110];
int dp_by_element_unexist[110];
int main(){
    memset(dp_by_element_exist, 0x80, sizeof dp_by_element_exist);
    memset(dp_by_element_unexist, 0, sizeof dp_by_element_unexist);
	days = read(), N = read(), coins = read();
    for(int i = 1; i <= days; ++i){
        for(int j = 1; j <= N; ++j){
            int element = read();
            dp_by_element_exist[j] = max(dp_by_element_exist[j], dp_by_element_unexist[j] - element);
            dp_by_element_unexist[j] = max(dp_by_element_unexist[j], dp_by_element_exist[j] + element);
        }
        printf("day=%d - ", i);for(int k = 1; k <= N; ++k)printf("exist=%d  unexist=%d%c", dp_by_element_exist[k], dp_by_element_unexist[k], k == N ? '\n' : ' ');
    }
    int ans(0);
    for(int i = 1; i <= N; ++i)ans += dp_by_element_unexist[i];
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