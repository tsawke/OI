#define _USE_MATH_DEFINES
#include <bits/stdc++.h>
// #include <quadmath.h>

#define PI M_PI
#define E M_E
#define npt nullptr
#define MOD 998244353

/******************************
abbr

******************************/

using namespace std;

mt19937 rnd(random_device{}());
int rndd(int l, int r){return rnd() % (r - l + 1) + l;}

typedef unsigned int uint;
typedef unsigned long long unll;
typedef long long ll;

#define int ll
#define sqrt sqrtl
#define floor floorl
#define ceil ceill
#define log logl

#define sqrtN (ll)(floor((long double)(sqrt(n))))

#define logg(a, b) (ll)(floor(log((long double)b) / log((long double) a))) 

int qpow(int a, int b){
    ll ret(1), mul(a);
    while(b){
        if(b & 1)ret = ret * mul % MOD;
        b >>= 1;
        mul = mul * mul % MOD;
    }
    return int(ret);
}

const int inv_2 = qpow(2, MOD - 2);
const int inv_6 = qpow(6, MOD - 2);

ll CalFunc(ll n){
    ll left = (n + 1) % MOD * (ll)inv_2 % MOD * ((sqrtN + n + 1)%MOD) % MOD * (ll(-sqrtN + n)%MOD) % MOD;
    ll rightl = n % MOD * ((n + 1) % MOD) % MOD * ((2 * n + 1) % MOD) % MOD * inv_6 % MOD;
    ll rightr = sqrtN % MOD * ((sqrtN + 1)%MOD) % MOD * ((2 * sqrtN + 1)%MOD) % MOD * (inv_6 % MOD) % MOD;
    ll right = (rightl - rightr + MOD) % MOD;
    return (left - right + MOD) % MOD;
}

template<typename T = int>
inline T read(void);

signed main(){
    int N = read();
    int ans(0ll);
    for(int a = 2; a * a <= N; ++a){
        // int tmpp(0);
        // for(int k = 1; k < logg(a, N); ++k){
        //     int tmp = (qpow(a, k + 1) - qpow(a, k) + MOD) % MOD;
        //     tmpp = (tmpp + tmp) % MOD; 
        // }
        // tmpp = ((N - qpow(a, logg(a, N)) + 1) % MOD + tmpp) % MOD;
        // ans = (ans + tmpp * a % MOD) % MOD; 
        ll tmp(1ll);
        for(int b = a; b <= N; b *= a, ++tmp){
            ans = (ans + (min(b * a - 1, N) - (b - 1) + MOD) % MOD * tmp % MOD * a % MOD) % MOD;
        }
    }
    ans = (ans + CalFunc(N)) % MOD;

    printf("%lld\n", ans);
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