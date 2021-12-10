#include <cstdio>
#include <algorithm>
#include <cstring>
#include <cstdlib>
#include <cmath>
#include <vector>
#include <climits>
#include <deque>
using namespace std;
typedef unsigned long long unll;
inline unll readULL(void);
inline int read(void);
void hanoi(int, int, int, int);
deque<int>tow[5];
char towN2C(int);
void mov(int, int);
int main(){
	int n(read());
	for(int i = 1; i <= n; ++i)tow[1].push_back(i);
	hanoi(n, 1, 3, 2);

//    system("pause");
    return 0;
}
char towN2C(int n){
	return n == 1 ? 'A' : (n == 2 ? 'B' : 'C');
}
void mov(int f, int t){
	tow[t].push_front(tow[f].front());
	tow[f].pop_front();
}
void hanoi(int N, int from, int to, int temp){
	if(N == 1){
		printf("%d:%c->%c\n", tow[from].front(), towN2C(from), towN2C(to));
		mov(from, to);
		return;
	}
	hanoi(N - 1, from, temp, to);
	printf("%d:%c->%c\n", tow[from].front(), towN2C(from), towN2C(to));
	mov(from, to);
	hanoi(N - 1, temp, to, from);
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
		ret *= flag;
	}
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
		ret *= flag;
	}
	return ret;
}

