#include <cstdio>
#include <algorithm>
#include <cstring>
#include <cstdlib>
#include <cmath>
#include <vector>
#include <climits>
#define MOD 2333333
using namespace std;
typedef unsigned long long unll;
inline void readLL(unll&);
inline void read(int&);
int n;
unll qPow(int, int, int);
unll f[110000] = {0, 3, 6};
int main(){
    read(::n);
    
    for(int i = 3; i <= n; ++i){
    	f[i] = 3ull * qPow(2, i - 1, MOD) - f[i - 1];
    	f[i] %= MOD;
	}
	printf("%llu\n", f[n]);
    
//    system("pause");
    return 0;
}
unll qPow(int x, int n, int mod){
	if(!n)return 1ull;
	if(n & 1)return unll(x * qPow(x, n - 1, mod) % mod);
	else {unll temp = qPow(x, n / 2, mod); return temp * temp % mod;};
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

