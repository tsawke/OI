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
int n;
int fa[210000];
int Find(int, int&);


int main(){
	n = read();
	for(int i = 1; i <= n; ++i)fa[i] = i;
	for(int i = 1; i <= n; ++i){
		


	}
    return 0;
}
int Find(int x, int& cnt){
	++cnt;
	if(fa[x] == x)return x;
	return Find(fa[x], cnt);
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
