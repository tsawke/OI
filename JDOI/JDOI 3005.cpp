#include <cstdio>
#include <algorithm>
#include <cstring>
#include <cstdlib>
#include <cmath>
#include <vector>
#define MOD 2333333
using namespace std;
typedef unsigned long long unll;
unll qPow(int, int, int);
inline void readLL(unll&);
inline void read(int&);
int x, y;
int f[110000] = {0, 1, 2};
int main(){
	read(x), read(y);
//	int temp((y - x) / 2);
//    int n(temp + ((y - x) * 1.00 / 2.00 > temp * 1.00 ? 1 : 0));
//    printf("%d\n", n);  
//    printf("%llu\n", qPow(2, n - 1, MOD) + 1);
	int n(y - x);
    for(int i = 3; i <= n; ++i)f[i] = f[i - 1] + f[i - 2], f[i] %= MOD;
    printf("%d\n", f[n]);
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

