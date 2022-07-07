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
int stone[310];
int Sstone[310];
int dp[310][310];
int main(){
	N = read();
    for(int i = 1; i <= N; ++i){
        stone[i] = read();
        Sstone[i] = Sstone[i - 1] + stone[i];
        dp[i][i] = 0;
    }
    for(int i = 1; i <= N; ++i){
        int cost = Sstone[i]; 
        for(int )
    }


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