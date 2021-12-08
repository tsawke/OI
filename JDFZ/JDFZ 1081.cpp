#include <cstdio>
#include <algorithm>
#include <cstring>
#include <cstdlib>
#include <cmath>
#include <vector>
#include <map>
using namespace std;
typedef unsigned long long unll;
inline void readLL(unll&);
inline void read(int&);
int n;

int main(){
    int t; read(t);
    for(int tt = 1; tt <= t; ++tt){
        read(n);
        
		printf("%llu\n", ans);
    }

//    printf("%d\n", dp[n]);
	    system("pause");
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
