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
int n;
unll f[1100][2];
int main(){
    read(n);
    f[1][0] = 9; f[1][1] = 1;
    for(int i = 2; i <= n; ++i){
        f[i][0] = f[i - 1][0] * (i == n ? 8 : 9) + f[i - 1][1];
        f[i][1] = f[i - 1][1] * (i == n ? 8 : 9) + f[i - 1][0];
        f[i][0] %= 12345; f[i][1] %= 12345;
    }
    printf("%llu\n", f[n][0]);
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
