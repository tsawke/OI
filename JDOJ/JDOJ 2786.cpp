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

// mt19937 rnd(random_device{}());
// int rndd(int l, int r){return rnd() % (r - l + 1) + l;}
// bool rnddd(int x){return rndd(1, 100) <= x;}

typedef unsigned int uint;
typedef unsigned long long unll;
typedef long long ll;
typedef long double ld;



// template<typename T = int>
// inline T read(void);

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

   ll qmul(ll x, ll y, ll MOD){
        // return (__int128_t)x * y % MOD;
        ll quot = (ld)x / MOD * y;
        ll ret = (unll)x * y - (unll)quot * MOD;
        return (ret + MOD) % MOD;
    }
ll qpow(ll a, ll b, ll MOD){
        ll ret(1), mul(a);
        while(b){
            if(b & 1)ret = qmul(ret, mul, MOD);
            b >>= 1;
            mul = qmul(mul, mul, MOD);
        }
        return ret;
    }
int main(){

    #define read read < ll >
    #define __int128_t ll


    #define MOD (23333333333333333ll)
    ll inv = qpow(2, MOD - 2ll, MOD);
    #define SUM(l, r) (qmul(qmul((l + r), (r - l + 1), MOD), inv, MOD))
    ll N = read();
    ll ans(0);
    ans += qmul(N, N, MOD);
    for(ll l = 1; l <= N;){
        ll r = N / (N / l);
        ans = (ans - qmul((N / l), SUM(l, r), MOD) + MOD) % MOD;
        l = r + 1;
    }
    printf("%lld\n", ans);

    // fprintf(stderr, "Time: %.6lf\n", (double)clock() / CLOCKS_PER_SEC);
    return 0;
}



