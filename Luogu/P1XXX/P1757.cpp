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
int Weight, N;
int maxGroupN(-1);
int dp[1100][1100];
vector< pair<int, int>/*weight, value*/ > group[1100];
int main(){
	Weight = read(), N = read();
    for(int i = 1; i <= N; ++i){
        int weight = read(), value = read(), groupN = read();
        group[groupN].push_back(make_pair(weight, value));
        maxGroupN = max(maxGroupN, groupN);
    }
    for(int g = 1; g <= maxGroupN; ++g){
        if(group[g].empty())continue;
        for(int i = Weight; i >= 1; --i)/*weight*/{
            for(int j = 1; j <= (int)group[g].size(); ++j)/*group[g] N*/{
                if(group[g].at(j - 1).first <= i)dp[i][j] = max(dp[i][j], dp[i - group[g].at(j - 1).first][j] + group[g].at(j - 1).second);
            }
        }
    }
    printf("%d\n", dp[Weight][group[maxGroupN].size()]);

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