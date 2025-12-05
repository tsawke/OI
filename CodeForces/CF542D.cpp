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

#define LIM (1100000)

template < typename T = int >
inline T read(void);

ll N;
unordered_map < ll, ll > dp[2];
basic_string < ll > Prime;
unordered_map < ll, ll > pows;
bitset < LIM + 100 > notPrime;
unordered_map < ll, basic_string < ll > > tpow;
basic_string < ll > tot;

namespace MillerRabin{
    int radix[10] = {0,  2, 3, 5, 7, 11, 13, 19, 17};
    ll qpow(ll a, ll b, ll MOD){
        ll ret(1), mul(a);
        while(b){
            if(b & 1)ret = (__int128_t)ret * mul % MOD;
            b >>= 1;
            mul = (__int128_t)mul * mul % MOD;
        }return ret;
    }
    bool Check(ll N){
        if(N <= 2 || !(N & 1))return N == 2;
        ll base(N - 1); int cpow(0);
        while(base % 2 == 0)base >>= 1, ++cpow;
        for(int t = 1; t <= 8; ++t){
            if(radix[t] % N == 0)continue;
            ll cur = qpow(radix[t] % N, base, N);
            if(cur == 1)continue;
            for(int i = 1; i <= cpow; ++i){
                if(cur == N - 1)break;
                cur = (__int128_t)cur * cur % N;
                if(i == cpow)return false;
            }
        }return true;
    }
};

void Sieve(void){
    for(ll i = 2; i <= LIM; ++i){
        if(!notPrime[i])Prime += i;
        for(auto p : Prime){
            if(p * i > LIM)break;
            notPrime[p * i] = true;
            if(i % p == 0)break;
        }
    }
}
void Init(void){
    Sieve();
    for(auto p : Prime){
        ll base(p);
        while(base <= N)pows[base] = p, base *= p;
    }
    for(ll i = 1; i * i <= N; ++i){
        if(N % i)continue;
        if(pows.find(i - 1) != pows.end())
            tpow[pows[i - 1]] += i, tot += pows[i - 1];
        if(i * i != N){
            if(pows.find(N / i - 1) != pows.end())
                tpow[pows[N / i - 1]] += N / i, tot += pows[(N / i) - 1];
            else if(MillerRabin::Check(N / i - 1))
                tpow[N / i - 1] += N / i, tot += N / i - 1;
        }
    }
    sort(tot.begin(), tot.end());
    tot.erase(unique(tot.begin(), tot.end()), tot.end());
}

int main(){
    N = read < ll >();
    Init();
    dp[0][1] = 1;
    int base(0);
    for(auto p : tot){
        base ^= 1, dp[base] = dp[base ^ 1];
        for(auto lst : dp[base ^ 1])
            for(auto pri : tpow[p])
                if((__int128_t)pri * lst.first <= N && N % (pri * lst.first) == 0)
                    dp[base][pri * lst.first] += lst.second;
    }printf("%lld\n", dp[base][N]);
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