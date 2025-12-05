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
int ans(0);
int main(){
    unll x = read<unll>(), y = read<unll>();
    const bool flag = x == y ? 1 : 0;
    const unll xy = x * y;
    const unll range = sqrt(xy) - flag;
    for(unll i = 2; i <= range; ++i){
        if(xy % i == 0 && __gcd(i, xy / i) == x)++ans;
    }
    ans *= 2;
    if(flag)++ans;
    printf("%d\n", ans);
    pause();
    return 0;
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