#include <cstdio>
#include <algorithm>
#include <cstring>
#include <cstdlib>
#include <cmath>
#include <vector>
using namespace std;
typedef unsigned long long unll;
inline void readLL(unll&);
inline void read(int&);
int n, m;
unll f[110];
int main(){
    read(n); read(m);
    if(m)f[0] = 1ull;
    for(int i = 1; i <= n; ++i)
    	f[i] = i < m ? f[i - 1] * 2 : (i == m ? (f[i - 1] * 2 - 1) : (f[i - 1] * 2 - f[i - m - 1]));
    printf("%llu\n", f[n]);
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
