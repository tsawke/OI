//C++98
//TODO
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
#include <unistd.h>
#include <functional>
#include <queue>
#include <stack>
#define MUL (double)(1.00000000)

using namespace std;
typedef unsigned long long unll;
typedef long long ll;
template <typename T>
inline T read(void);

int R, B;
double dp[5100][5100];//i-R j-B

int main(){
    R = read<int>(), B = read<int>();
    for(int i = 0; i <= 5010; ++i)dp[0][i] = 0.00000000;
    for(int i = 1; i <= 5010; ++i)dp[i][0] = i * MUL;
    for(int i = 1; i <= R; ++i){
        for(int j = 1; j <= B; ++j){
            dp[i][j] = (i * MUL) / ( (i + j) * MUL) * (dp[i - 1][j] + 1 * MUL) + (j * MUL) / ( (i + j) * MUL) * (dp[i][j - 1] - 1 * MUL);
        }
    }
    // for(int i = 1; i <= R; ++i)for(int j = 1; j <= B; ++j)printf("%.6lf%c", dp[i][j], j == B ? '\n' : ' ');
    int ans = dp[R][B] * 1000000;
    int inte = ans /1000000;
    ans %= 1000000;
    printf("%d.%d\n", inte, ans);

    return 0;
}

template <typename T>
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