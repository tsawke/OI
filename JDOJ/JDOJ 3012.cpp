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
int n;
int ans(0);
int main(){
//    read(n);
//    ans = n & 1 ? (n + 1) * (2 * n * n + 3 * n - 1) / 8 : n * (n + 2) * (2 * n + 1) / 8;
//    ans = (ans + MOD) % MOD;
//    if(n & 1)ans = ((n + 1) * (2 * n * n + 3 * n - 1) / 8) % MOD;
//    else ans = (n * (n + 2) * (2 * n + 1) / 8) % MOD;
scanf("%d", &n);
    if(n & 1)printf("%d\n", (((n + 1) % MOD) * ((2 * n * n + 3 * n - 1) % MOD) / 8) % 2333333);
    else printf("%d\n", ((n % MOD) * ((n + 2) % MOD) * ((2 * n + 1) % MOD) / 8) % 2333333);
 //   system("pause");
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
