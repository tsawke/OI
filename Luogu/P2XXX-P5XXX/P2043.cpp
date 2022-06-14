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

using namespace std;
typedef unsigned int uint;
typedef unsigned long long unll;
typedef long long ll;
template <typename T = int>
inline T read(void);

int N;
int factor[10100];
int main(){
	N = read();
    for(int i = 1; i <= N; ++i){
        int t(i), fact(2);
        while(t > 1){
            while(t % fact == 0){
                t /= fact;
                ++factor[fact];
            }++fact;
        }
    }
    for(int i = 1; i <= N; ++i){
        if(factor[i])printf("%d %d\n", i, factor[i]);
    }

    return 0;
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