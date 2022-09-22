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
int n, a, b;
int f[11000];
int main(){
    read(n), read(a), read(b);
//    if(!n){printf("No Solution\n"); return 0;}
/*    n *= 2;
    f[1] = 0; f[2] = 2;
    for(int i = 2; i <= n; ++i){
    	for(int j = 1; j <= i - 1; ++j){
    		f[i] += f[i - j] * 2;
    		f[i] %= 123456;
    		f[i] *= 2;
    		f[i] %= 123456;
		}
	}
    for(int i = 1; i <= n; ++i)printf("%d\n", f[i]);*/
	f[0] = 1;
	for(int i = 1; i <= n; ++i)
		for(int j = 0; j <= i - 1; ++j){
			f[i] += f[j] * f[i - 1 - j] % 123456;
			f[i] %= 123456;
		}
			
	printf("%d\n", f[n]);
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
