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

#define MOD ((ll)1e9 + 7)

template<typename T = int>
inline T read(void);

ll qpow(ll a, ll b){
    ll ret(1), mul(a);
    while(b){
        if(b & 1)ret = ret * mul % MOD;
        b >>= 1;
        mul = mul * mul % MOD;
    }return ret;
}

ll mxA(0);

int main(){
    int T = read();
    while(T--){
        mxA = 0;
        ll N = read(), R = read < ll >();
        for(int i = 1; i <= N; ++i)mxA = max(mxA, read < ll >());
        // ll aN = read < ll >();
        ll ans(1);
        ll S = R - mxA + (N);
        for(ll i = (S - (N) + 1); i <= S; ++i)ans = (ans * i) % MOD;
        for(ll i = 1; i <= (N); ++i)ans = (ans * qpow(i, MOD - 2)) % MOD;
        printf("%lld\n", ans);
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