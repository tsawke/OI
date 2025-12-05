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

int N, Q;
vector<int>prime;
bool notPrime[100000010];
int main(){
	N = read(), Q = read();
    for(int i = 2; i <= N; ++i){
        if(!notPrime[i])prime.push_back(i);
        for(vector<int>::iterator itea = prime.begin(); itea != prime.end(), i * (*itea) <= N; ++itea){
            notPrime[i * (*itea)] = true;
            if(i % (*itea) == 0)break;
        }
    }
    for(int i = 1; i <= Q; ++i){
        int ask = read();
        printf("%d\n", prime.at(ask - 1));
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