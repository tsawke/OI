#include <cstdio>
#include <algorithm>
#include <cstring>
#include <cstdlib>
#include <cmath>
#include <vector>
#define MOD 12345
using namespace std;
typedef unsigned long long unll;
inline void readLL(unll&);
inline void read(int&);
int n;
int f[1100] = {0, 3};
int g[1100] = {0, 1};
int main(){
    read(n);
    for(int i = 2; i <= n; ++i){
    	f[i] = 3 * f[i - 1] + 2 * g[i - 1];
    	g[i] = f[i - 1] + g[i - 1];
    	f[i] %= MOD;
    	g[i] %= MOD;
	}
//    for(int i = 1; i <= n; ++i)printf("*****%d\n", f[i]);
    printf("%d\n", (f[n] + g[n]) % MOD);
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

