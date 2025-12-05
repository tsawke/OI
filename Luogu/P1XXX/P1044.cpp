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

int C[110][110];
int N;

int main(){
	N = read();
    for(int i = 0; i <= 2 * N; ++i)C[i][0] = 1;
    for(int i = 1; i <= 2 * N; ++i)
        for(int j = 1; j <= N; ++j)
            C[i][j] = C[i - 1][j - 1] + C[i - 1][j];
    printf("%d\n", C[2 * N][N] - C[2 * N][N - 1]);
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