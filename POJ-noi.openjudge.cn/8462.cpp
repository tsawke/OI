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

int T;

int main(){
	T = read();
    for(int times = 1; times <= T; ++times){
        int N = read();
        deque< int > deq;
        deq.push_back(0);
        deq.push_back(read());
        for(int i = 2; i <= N; ++i){
            int element = read();
            deq.push_back(max(deq.front() + element, deq.at(1)));
            deq.pop_front();
        }
        printf("%d\n", max(deq.front(), deq.back()));
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