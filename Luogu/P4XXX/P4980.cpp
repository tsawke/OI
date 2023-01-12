#define _USE_MATH_DEFINES
#include <bits/stdc++.h>

#define PI M_PI
#define E M_E
#define npt nullptr
#define SON i->to
#define OPNEW void* operator new(size_t)
#define ROPNEW(arr) void* Edge::operator new(size_t){static Edge* P = arr; return P++;}

using namespace std;

mt19937 rnd(random_device{}());
int rndd(int l, int r){return rnd() % (r - l + 1) + l;}
bool rnddd(int x){return rndd(1, 100) <= x;}

typedef unsigned int uint;
typedef unsigned long long unll;
typedef long long ll;
typedef long double ld;

#define MOD (ll)(1e9 + 7)

template < typename T = int >
inline T read(void);

bitset < 110000 > notPrime;
basic_string < ll > Prime;

void Init(void){
    for(ll i = 2; i <= 101000; ++i){
        if(!notPrime[i])Prime += i;
        for(auto p : Prime){
            if(p * i > 101000)break;
            notPrime[p * i] = true;
            if(i % p == 0)break;
        }
    }
}
ll qpow(ll a, ll b){
    ll ret(1), mul(a);
    while(b){
        if(b & 1)ret = ret * mul % MOD;
        b >>= 1;
        mul = mul * mul % MOD;
    }return ret;
}
ll phi(ll x){
    ll ret(x);
    basic_string < ll > fact;
    for(auto p : Prime){
        if(p * p > x)break;
        if(x % p == 0)fact += p;
        while(x % p == 0)x /= p;
    }if(x != 1)fact += x;
    for(auto p : fact)ret /= p, ret *= (p - 1);
    return ret;
}

int main(){
    Init();
    int T = read();
    while(T--){
        ll N = read < ll >();
        ll ans(0);
        for(ll i = 1; i * i <= N; ++i){
            if(N % i != 0)continue;
            (ans += qpow(N, i) * phi(N / i) % MOD) %= MOD;
            if(i * i != N)(ans += qpow(N, N / i) * phi(i) % MOD) %= MOD;
        }(ans *= qpow(N, MOD - 2)) %= MOD;
        printf("%lld\n", ans);
    }
    fprintf(stderr, "Time: %.6lf\n", (double)clock() / CLOCKS_PER_SEC);
    return 0;
}

template < typename T >
inline T read(void){
    T ret(0);
    int flag(1);
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