//C++11 - Template
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

int N, M, k;
int st, en;
vector< pair<int, int>/*toVertex, price*/ >vertex[20][11000];
int main(){
	N = read(), M = read(), k = read();
    st = read(), en = read();
	for(int i = 1; i <= M; ++i){
		int from = read(), to = read(), price = read();
		vertex[0][from].push_back(make_pair(to, price));
		vertex[0][to].push_back(make_pair(from, price));
	}
	for(int i = 1; i <= k; ++k){
		copy(vertex[i - 1]->begin())	
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