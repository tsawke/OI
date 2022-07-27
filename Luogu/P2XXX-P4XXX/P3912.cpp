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
// vector<int>prime;
int prime[10000010];
bool notPrime[100000010];
int main(){
	N = read();int ans(0);
    for(int i = 2; i <= N; ++i){
        if(!notPrime[i])prime[++ans] = i;
        // for(vector<int>::iterator itea = prime.begin(); itea != prime.end(), i * (*itea) <= N; ++itea){
        for(int j = 1; j <= ans && prime[j] * i <= N; ++j){
            notPrime[i * prime[j]] = true;
            if(i % prime[j] == 0)break;
        }
    }
    // printf("%d\n", (int)prime.size());
    printf("%d\n", ans);
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