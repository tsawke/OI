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

template < typename T = int >
inline T read(void);

int P, B, N;
unordered_map < int, int > mp;

ll qpow(ll a, ll b){
    ll ret(1), mul(a);
    while(b){
        if(b & 1)ret = ret * mul % P;
        b >>= 1;
        mul = mul * mul % P;
    }return ret;
}

int main(){
    P = read(), B = read(), N = read();
    int lim = (int)ceil(sqrt(P));
    for(int i = 1; i <= lim; ++i)mp.insert({(ll)N * qpow(B, i) % P, i});
    for(int i = 1; i <= lim; ++i){
        ll val = qpow(B, (ll)i * lim);
        if(mp.find(val) != mp.end())printf("%lld\n", (ll)i * lim - mp[val]), exit(0);
    }puts("no solution\n");
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