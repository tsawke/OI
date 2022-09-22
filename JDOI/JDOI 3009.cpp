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
unll f[110000][5];
int n;
int main(){
    read(n);
    f[1][1] = f[1][2] = f[1][3] = 1;
    for(int i = 2; i <= n; ++i){
    	f[i][1] = f[i - 1][1] + f[i - 1][2] + f[i - 1][3];
    	f[i][2] = f[i - 1][1] + f[i - 1][2] + f[i - 1][3];
    	f[i][3] = f[i - 1][1] + f[i - 1][2];
    	f[i][1] %= MOD;
    	f[i][2] %= MOD;
    	f[i][3] %= MOD;
	}
	int ans(f[n][1] + f[n][2] + f[n][3]);
	ans %= MOD;
    printf("%d\n", ans);
    
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

