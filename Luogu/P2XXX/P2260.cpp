#define _USE_MATH_DEFINES
#include <bits/extc++.h>

#define PI M_PI
#define E M_E
#define npt nullptr
#define SON i->to
#define OPNEW void* operator new(size_t)
#define ROPNEW(arr) void* Edge::operator new(size_t){static Edge* P = arr; return P++;}

/******************************
abbr

******************************/

using namespace std;
using namespace __gnu_pbds;

mt19937 rnd(random_device{}());
int rndd(int l, int r){return rnd() % (r - l + 1) + l;}
bool rnddd(int x){return rndd(1, 100) <= x;}

typedef unsigned int uint;
typedef unsigned long long unll;
typedef long long ll;
typedef long double ld;
#define int ll
// #define ll __int128_t
#define MOD (19940417ll)

template<typename T = int>
inline T read(void);

ll cal(int l, int r){
    return ll((__int128_t)(l + r) * (r - l + 1) / 2 % MOD);
}
ll cal2(int l, int r){
    --l;
    __int128_t ret1 = (__int128_t)r * (r + 1) / 2 * (2 * r + 1) / 3;
    __int128_t ret2 = (__int128_t)l * (l + 1) / 2 * (2 * l + 1) / 3;
    return ll((ret1 - ret2) % MOD);
}
// #undef ll
signed main(){
    int N = read(), M = read();
    int rng = min(N, M);
    ll ans = (ll)N * N % MOD * M % MOD * M % MOD;
    for(int l = 1; l <= N;){
        int r = N / (N / l);
        ans -= (ll)M * (N / l) % MOD * cal(l, r) % MOD * M % MOD;
        // ans -= (ll)M * (N / l) % MOD * ((ll)N * (N + 1) / 2 % MOD) % MOD * M % MOD;
        // printf("l = %d, r = %d, delta = %lld\n", l, r, (ll)M * (N / l) % MOD * cal(l, r) % MOD * M % MOD);
        l = r + 1;
    }ans = (ans + MOD) % MOD;
    for(int l = 1; l <= M;){
        int r = M / (M / l);
        ans -= (ll)N * (M / l) % MOD * cal(l, r) % MOD * N % MOD;
        // printf("l = %d, r = %d, delta = %lld\n", l, r, (ll)N * (M / l) % MOD * cal(l, r) % MOD * N % MOD);
        l = r + 1;
    }ans = (ans + MOD) % MOD;
    ll tmp(0);
    for(int l = 1; l <= N;){
        int r = N / (N / l);
        tmp += (ll)(N / l) * cal(l, r) % MOD;
        l = r + 1;
    }tmp %= MOD;
    ll tmpp(0);
    for(int l = 1; l <= M;){
        int r = M / (M / l);
        tmpp += (ll)(M / l) * cal(l, r) % MOD;
        l = r + 1;
    }tmpp %= MOD;
    ans = (ans + tmp * tmpp % MOD) % MOD;
    // for(int l = 1; l <= rng;){
    //     int r = min(N / (N / l), M / (M / l));
    //     ans += (ll)(N / l) % MOD * (M / l) % MOD * cal(l, r) % MOD * cal(l, r) % MOD;
    //     printf("l = %d, r = %d, delta = %lld\n", l, r, (ll)(N / l) % MOD * (M / l) % MOD * cal(l, r) % MOD * cal(l, r) % MOD);
    //     l = r + 1;
    // }
    ll anss = (ll)rng * N % MOD * M % MOD;
    for(int l = 1; l <= rng;){
        int r = min(N / (N / l), M / (M / l));
        anss -= (ll)N * (M / l) % MOD * cal(l, r)% MOD;
        l = r + 1;
    }anss = (anss + MOD) % MOD;
    for(int l = 1; l <= rng;){
        int r = min(N / (N / l), M / (M / l));
        anss -= (ll)M * (N / l) % MOD * cal(l, r) % MOD;
        l = r + 1;
    }anss = (anss + MOD) % MOD;
    for(int l = 1; l <= rng;){
        int r = min(N / (N / l), M / (M / l));
        anss += (ll)(N / l) % MOD * (M / l) % MOD * cal2(l, r);
        //((ll)(rng + 1) * rng / 2 % MOD) % MOD * ((ll)(rng + 1) * rng / 2 % MOD) % MOD;
        l = r + 1;
    }
    ans = (ans - anss + MOD) % MOD;
    while(ans < 0)ans = (ans + MOD) % MOD;
    long long rans = ans % MOD;
    printf("%lld\n", rans);
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