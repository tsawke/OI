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
#include <unistd.h>
#include <functional>
using namespace std;
typedef unsigned long long unll;
typedef long long ll;
template <typename T = int>
inline T read(void);
int n, m, root;
vector<int>vertex[510000];
int main(){
	n = read(), m = read(), root = read();
	for(int i = 2; i <= n; ++i){
		int x, y;
		vertex[x].push_back(y);
		vertex[y].push_back(x);
	}
	for(int i = 1; i <= m; ++i){

	}


    return 0;
}
// int calLCA
//TODO

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