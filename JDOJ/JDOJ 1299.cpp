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
int getAns(int);
int n;
unll f[1100] = {0ull, 1ull};
int main(){
    read(n);
    for(int i = 2; i <= n; ++i){
    	++f[i];
    	for(int j = 1; j <= i / 2; ++j)
    		f[i] += f[j];
	}
    
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
