#include <cstdio>
#include <algorithm>
#include <cstring>
#include <cstdlib>
#include <cmath>
#include <vector>
#include <iterator>
#define MOD 2333333
using namespace std;
typedef unsigned long long unll;
inline void readLL(unll&);
inline void read(int&);
int solution[1100];
int n, _time;
int beg, _end;
int main(){
    read(n), read(beg), read(_end), read(_time);
    solution[_end] = 1;
    for(int i = 1; i <= _time - 1; ++i){
    	int temp[1100];
    	memset(temp, 0, sizeof(temp));
//    	copy(begin(solution), end(solution), begin(temp));
		memcpy(temp, solution, sizeof(solution));
    	for(int j = 1; j <= n; ++j){
    		solution[j] = temp[j - 1] + temp[j + 1];
    		solution[j] %= MOD;
		}
		
//		for(int k = 1; k <= 5; ++k){printf("%d  ", temp[k]);}printf("\n");
//		for(int k = 1; k <= 5; ++k){printf("%d  ", solution[k]);}printf("\n");
//		printf("\n\n");
	}
	int ans = (solution[beg + 1] + solution[beg - 1]) % MOD;
	printf("%d\n", ans);
    
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

