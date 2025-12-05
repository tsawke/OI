#define _USE_MATH_DEFINES
#include <bits/stdc++.h>

#define PI M_PI
#define E M_E
#define npt nullptr
#define SON i->to
#define OPNEW void* operator new(size_t)
#define ROPNEW void* Edge::operator new(size_t){static Edge* P = ed; return P++;}
#define ROPNEW_NODE void* Node::operator new(size_t){static Node* P = nd; return P++;}

using namespace std;

mt19937 rnd(random_device{}());
int rndd(int l, int r){return rnd() % (r - l + 1) + l;}
bool rnddd(int x){return rndd(1, 100) <= x;}

typedef unsigned int uint;
typedef unsigned long long unll;
typedef long long ll;
typedef long double ld;

#define MOD (998244353ll)
#define LIM (210000)

template < typename T = int >
inline T read(void);

int N, M, K;
ll phi[LIM + 100];
bitset < LIM + 100 > notPrime;
basic_string < int > Prime;
ll fact[LIM + 100], inv[LIM + 100];

int main(){
    auto qpow = [](ll a, ll b)->ll{
        ll ret(1), mul(a);
        while(b){
            if(b & 1)ret = ret * mul % MOD;
            b >>= 1;
            mul = mul * mul % MOD;
        }return ret;
    };
    auto Init = [qpow](void)->void{
        phi[1] = fact[0] = 1;
        for(int i = 2; i <= LIM; ++i){
            if(!notPrime[i])phi[i] = i - 1, Prime += i;
            for(auto p : Prime){
                if((ll)i * p > LIM)break;
                notPrime[i * p] = true;
                if(i % p == 0)phi[i * p] = p * phi[i] % MOD;
                else phi[i * p] = phi[p] * phi[i] % MOD;
                if(i % p == 0)break;
            }
        }
        for(int i = 1; i <= LIM; ++i)fact[i] = fact[i - 1] * i % MOD;
        inv[LIM] = qpow(fact[LIM], MOD - 2);
        for(int i = LIM - 1; i >= 0; --i)inv[i] = inv[i + 1] * (i + 1) % MOD;
    };Init();
    auto GetC = [](ll n, ll m)->ll{
        if(n < m || n < 0 || m < 0)return 0;
        return fact[n] * inv[m] % MOD * inv[n - m] % MOD;
    };
    auto Cal = [qpow, GetC](ll N, ll M, ll K)->ll{
        ll ret(0);
        for(int i = 0, flag = 1; i * (K + 1) <= M; ++i, flag *= -1)
            (ret += ((flag * GetC(N, i) * GetC(M - i * (K + 1) + N - 1, N - 1) % MOD) + MOD) % MOD) %= MOD;
        (ret *= (N + M) * qpow(N, MOD - 2) % MOD) %= MOD;
        return ret;
    };
    ll ans(0);
    N = read(), M = read(), K = read();
    if(N == M)printf("%d\n", K >= N ? 1 : 0), exit(0);
    for(int i = 1; i <= N; ++i)
        if(N % i == 0 && M % i == 0)
            (ans += Cal((N - M) / i, M / i, K) * phi[i] % MOD) %= MOD;
    (ans *= qpow(N, MOD - 2)) %= MOD;
    printf("%lld\n", ans);
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