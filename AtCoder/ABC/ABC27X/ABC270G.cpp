#define _USE_MATH_DEFINES
#include <bits/stdc++.h>

#define PI M_PI
#define E M_E
#define npt nullptr
#define SON i->to
#define OPNEW void* operator new(size_t)
#define ROPNEW void* Edge::operator new(size_t){static Edge* P = ed; return P++;}

using namespace std;

mt19937 rnd(random_device{}());
int rndd(int l, int r){return rnd() % (r - l + 1) + l;}
bool rnddd(int x){return rndd(1, 100) <= x;}

typedef unsigned int uint;
typedef unsigned long long unll;
typedef long long ll;
typedef long double ld;

template < typename T = int >
inline T read(void);

ll MOD, A, B, S, G;
unordered_map < ll, int > mp;

ll qpow(ll a, ll b){
    ll ret(1), mul(a);
    while(b){
        if(b & 1)ret = ret * mul % MOD;
        b >>= 1;
        mul = mul * mul % MOD;
    }return ret;
}
ll inv(ll v){return qpow(v, MOD - 2);}
ll BSGS(ll A, ll B){
    mp.clear();
    int lim = ceil(sqrt(MOD));
    ll base(1), mul(1);
    for(ll i = 1; i <= lim; ++i)(base *= A) %= MOD, mp[B * base % MOD] = i;
    for(ll i = 1; i <= lim; ++i){
        (mul *= base) %= MOD;
        if(mp.find(mul) != mp.end())return i * lim - mp[mul];
    }return -1;
}

int main(){
    // freopen("in.txt", "r", stdin);
    int T = read();
    while(T--){
        MOD = read(), A = read(), B = read(), S = read(), G = read();
        ll V = (G + B * inv(A - 1) % MOD) % MOD * inv((S + B * inv(A - 1) % MOD) % MOD) % MOD;
        if(S == G)printf("0\n");
        else if(!A)printf("%d\n", B == G ? 1 : -1);
        else if(A == 1){
            if(!B)printf("-1\n");
            else printf("%lld\n", ((G - S) * inv(B) % MOD + MOD) % MOD);
        }else printf("%lld\n", BSGS(A, V));
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