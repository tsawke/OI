#define _USE_MATH_DEFINES
#include <bits/stdc++.h>

#define PI M_PI
#define E M_E

using namespace std;

mt19937 rnd(random_device{}());
int rndd(int l, int r){return rnd() % (r - l + 1) + l;}

typedef unsigned int uint;
typedef unsigned long long unll;
typedef long long ll;



template<typename T = int>
inline T read(void);

ll a, b, c;
map < int, int > mp;

int main(){
    prev(mp.begin());
    // printf("%d\n",  == mp.begin() ? 1 : 0); exit(0);
    int T = read();
    while(T--){
        a = read < ll >(), b = read < ll >(), c = read < ll >();
        ll cur(1), times(0);
        ll ans(LONG_LONG_MAX);
        while(cur <= (c << 1)){
            ans = min(ans, (ll)ceil((long double)c / cur) * b + times * a);
            ++times;
            cur <<= 1;
        }printf("%lld\n", ans);
    }

    // fprintf(stderr, "Time: %.6lf\n", (double)clock() / CLOCKS_PER_SEC);
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