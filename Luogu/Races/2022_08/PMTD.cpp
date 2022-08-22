#define _USE_MATH_DEFINES
#include <bits/stdc++.h>

#define PI M_PI
#define E M_E

#define abbr

using namespace std;

mt19937 rnd(random_device{}());
int rndd(int l, int r){return rnd() % (r - l + 1) + l;}

typedef unsigned int uint;
typedef unsigned long long unll;
typedef long long ll;

#define int ll

template<typename T = int>
inline T read(void);

int N, M;
int maxx(INT_MIN), minn(INT_MAX);
signed main(){
    N = read(), M = read();
    for(int i = 1; i <= N; ++i){
        int tmp = read();
        maxx = max(maxx, tmp), minn = min(minn, tmp);
    }
    while(M--){
        if(maxx >= 2)maxx *= 2;
        else maxx += 2;
    }
    printf("%lld\n", maxx - minn);
    fprintf(stderr, "Time: %.6lf\n", (double)clock() / CLOCKS_PER_SEC);
    return 0;
}



template<typename T>
inline T read(void){
    T ret(0);
    short flag(1);
    char c = getchar();
    while(c != '-' && !isdigit(c))c = getchar();
    if(c == '-')flag = -1, c = getchar();
    while(isdigit(c)){
        ret *= 10;
        ret += int(c - '0');
        c = getchar();
    }
    ret *= flag;
    return ret;
}