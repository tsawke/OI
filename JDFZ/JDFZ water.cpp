//#pragma GCC optimize(2)
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
int qPow(int, int, int);
int getAns(unll);
unll n;

int main(){
	readLL(::n);
	printf("%d\n", getAns(n));
	

    system("pause");
    return 0;
}
int getAns(unll n){
	if(n < 5ull)return 0;
	return n / 5ull + getAns(n / 5ull);
}
int qPow(int x, int n, int mod){
	if(!n)return 1;
	if(n & 1){
		return (qPow(x, n - 1, mod) * x) % mod;
	}
	else{
		int temp = qPow(x, n / 2, mod);
		return (temp * temp) % mod;
	}
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
