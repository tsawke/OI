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

#define MOD (1000003ll)
#define LIMIT (510000)

template < typename T = int >
inline T read(void);

int A, B;
int N;
basic_string < int > Prime;
bitset < LIMIT + 100 > notPrime;

ll qpow(ll a, ll b){
    ll ret(1), mul(a);
    while(b){
        if(b & 1)ret = ret * mul % MOD;
        b >>= 1;
        mul = mul * mul % MOD;
    }return ret;
}
int Phi(int x){
    int ret(x);
    basic_string < int > fact;
    for(auto p : Prime){
        if(p * p > x)break;
        if(x % p == 0)fact += p;
        while(x % p == 0)x /= p;
    }if(x != 1)fact += x;
    for(auto f : fact)ret /= f, ret *= (f - 1);
    return ret;
}

int main(){
    for(int i = 2; i <= LIMIT; ++i){
        if(!notPrime[i])Prime += i;
        for(auto p : Prime){
            if(p * i > LIMIT)break;
            notPrime[p * i] = true;
            if(i % p == 0)break;
        }
    }
    int T = read();
    while(T--){
        A = read(), B = read();
        N = (A + B) / __gcd(A, B);
        ll ans(0);
        for(int i = 1; i * i <= N; ++i){
            if(N % i)continue;
            if(i * i != N)
                (ans += qpow(2, (ll)__gcd(A, B) * i) * Phi(N / i) % MOD) %= MOD,
                (ans += qpow(2, (ll)__gcd(A, B) * (N / i)) * Phi(i) % MOD);
            else (ans += qpow(2, (ll)__gcd(A, B) * i) * Phi(N / i) % MOD) %= MOD;
        }(ans *= qpow(N, MOD - 2)) %= MOD;
        printf("%lld\n", (qpow(2, A + B) - ans + MOD) % MOD);
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