//#pragma GCC optimize(2)
#include <cstdio>
#include <algorithm>
#include <cstring>
#include <cstdlib>
#include <cmath>
#include <vector>
#include <map>
#define map_itea map<int, int>::iterator
using namespace std;
typedef unsigned long long unll;
inline void readLL(unll&);
inline void read(int&);
int r;
unll ans(1ull);
int main(){
	read(r);
    ans += r * 4;
    for(int i = 1; i <= r; ++i){
        ans += 4 * floor(sqrt(r * r- i * i));
    }
    printf("%llu\n", ans);

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
