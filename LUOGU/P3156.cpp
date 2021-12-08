#include <cstdio>
#include <algorithm>
#include <cstring>
#include <cstdlib>
#include <cmath>
#include <vector>
#include <climits>
#include <iostream>
#include <string>
#include <map>
using namespace std;
typedef unsigned long long unll;
typedef long long ll;
inline unll readULL(void);
inline int read(void);
int a[2100000];
int main(){
    int n(read()), m(read());
    for(int i = 1; i <= n; ++i)a[i] = read();
    for(int i = 1; i <= m; ++i)printf("%d\n", a[read()]);
	
    system("pause");
    return 0;
}

inline unll readULL(void){
	unll ret(0);
	int flag(1);
	char c = getchar();
	while (c < '0' || c > '9') {
		if (c == '-')flag = -1;
		c = getchar();
	}
	while (c >= '0' && c <= '9') {
		ret *= 10, ret += (c - '0');
		c = getchar();
	}
   ret *= flag;
	return ret;
}
inline int read(void) {
	int ret(0);
	int flag(1);
	char c = getchar();
	while (c < '0' || c > '9') {
		if (c == '-')flag = -1;
		c = getchar();
	}
	while (c >= '0' && c <= '9') {
		ret *= 10, ret += (c - '0');
		c = getchar();
   }
   ret *= flag;
	return ret;
}
