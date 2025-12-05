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
#define LIMIT (1100000)

template < typename T = int >
inline T read(void);

int A, B;
int N, gcdv;
ll ans(0);
ll pow2[LIMIT + 100];
basic_string < int > Prime;
bitset < LIMIT + 100 > notPrime;
struct Num{int v; int cnt;};
basic_string < Num > fact;

ll qpow(ll a, ll b){
    ll ret(1), mul(a);
    while(b){
        if(b & 1)ret = ret * mul % MOD;
        b >>= 1;
        mul = mul * mul % MOD;
    }return ret;
}
void Init(int x){
    fact.clear();
    for(auto p : Prime){
        if(p * p > x)break;
        if(x % p == 0)fact += {p, 0};
        while(x % p == 0)fact.back().cnt++, x /= p;
    }if(x != 1)fact += {x, 1};
}
void dfs(int dep = 0, ll d = 1, ll base = 1, ll div = 1){
    if(dep == (int)fact.size())
        return (ans += pow2[gcdv * (N / d)] * (d / div * base) % MOD) %= MOD, void();
    dfs(dep + 1, d, base, div);
    base *= (fact.at(dep).v - 1), div *= fact.at(dep).v;
    for(int i = 1; i <= fact.at(dep).cnt; ++i)
        d *= fact.at(dep).v, dfs(dep + 1, d, base, div);
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
    pow2[0] = 1;
    for(int i = 1; i <= LIMIT; ++i)pow2[i] = pow2[i - 1] * 2 % MOD;
    int T = read();
    while(T--){
        A = read(), B = read();
        N = (A + B) / __gcd(A, B), gcdv = __gcd(A, B);
        Init(N);
        ans = 0;
        dfs();
        (ans *= qpow(N, MOD - 2)) %= MOD;
        printf("%lld\n", (pow2[A + B] - ans + MOD) % MOD);
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