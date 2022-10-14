#include <cstdio>
#include <algorithm>
#include <cstring>
#include <cstdlib>
#include <cmath>
#include <vector>
#define MOD 2333333
using namespace std;
typedef unsigned long long unll;
inline void readLL(unll&);
inline void read(int&);
int f[110000] = {1};
int g[110000] = {0};
int n;
int main(){
    read(n);
    for(int i = 1; i <= n; ++i){
    	f[i] = f[i - 1] * 3 + g[i - 1] * 2, f[i] %= MOD;
    	g[i] = f[i - 1] + g[i - 1], g[i] %= MOD;
	}
	printf("%d %d\n", f[n], g[n]);
//    system("pause");
    return 0;
}

inline void readLL(unll& p){
    p = 0;
	int flag(1);
	char c = getchar();
	while (c < '0' || c > '9') {
		if (c == '-')flag = -1;
		c = getchar();
	}
	while (c >= '0' && c <= '9') {
		p *= 10, p += (c - '0');
		c = getchar();
		p *= flag;
	}
}
inline void read(int& p) {
	p = 0;
	int flag(1);
	char c = getchar();
	while (c < '0' || c > '9') {
		if (c == '-')flag = -1;
		c = getchar();
	}
	while (c >= '0' && c <= '9') {
		p *= 10, p += (c - '0');
		c = getchar();
		p *= flag;
	}
}

