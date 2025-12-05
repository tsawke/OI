//C++11 - Template
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
#include <queue>
#include <stack>
#include <functional>
#include <unistd.h>

#define MOD 20130427

using namespace std;
typedef unsigned int uint;
typedef unsigned long long unll;
typedef long long ll;
template <typename T = int>
inline T read(void);
int B;
unll kpow(unll, unll, unll);
void Init(void);
unll f[110000][]
int main(){
	B = read();
    Init();


    return 0;
}
void Init(void){
    
}
unll kpow(unll a, unll b, unll __MOD){
    unll ret(1);
    unll MUL(a % __MOD);
    while(b){
        if(b & 1) ret = (ret * MUL) % __MOD;
        b >>= 1;
        MUL = (MUL * MUL) % __MOD;
    }
    return ret;
}
template <typename T = int>
inline T read(void)
{
	T ret(0);
	short flag(1);
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