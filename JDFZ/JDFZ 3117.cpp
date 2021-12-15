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
#include <unistd.h>
#include <bitset>

using namespace std;
typedef unsigned long long unll;
typedef long long ll;
template <typename T>
inline T read(void);
bool prime_f[11000];
int prime_n[11000];
vector<int>prime;
void Init(void);
int main(){
    Init();
    for(int i = 1; i <= 10; ++i){
        int temp = read<int>();
        for(vector<int>::iterator itea = prime.begin(); itea != prime.end() && !prime_f[temp] && temp > 1; ++itea){
            while(temp % (*itea) == 0){++prime_n[*itea]; temp /= *itea;}
        }
        if(temp > 1)++prime_n[temp];
    }
    unll ans(1ull);
    for(int i = 1; i <= 10100; ++i){
        if(prime_n[i])ans *= (prime_n[i] + 1);
        ans %= 10ull;
    }
    printf("%lld\n", ans);
    pause();
    return 0;
}
void Init(void){
    for(int i = 2; i <= 10100; ++i){
        bool flag(true);
        for(int j = 2; j <= sqrt(i); ++j)if(i % j == 0){flag = false; break;}
        prime_f[i] = flag;
        if(flag)prime.push_back(i);
    }
}
template <typename T>
inline T read(void){
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