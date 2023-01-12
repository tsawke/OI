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

ll K, M;
unordered_map < ll, ll > mp;

ll qpow(ll a, ll b){
    ll ret(1), mul(a);
    while(b){
        if(b & 1)ret = (__int128_t)ret * mul % M;
        b >>= 1;
        mul = (__int128_t)mul * mul % M;
    }return ret;
}

int main(){
    K = read < ll >(), M = read < ll >();
    ll lim = (ll)ceil(sqrt(M));
    for(int i = 1; i <= lim; ++i)mp.insert({(__int128_t)(9 * K + 1) % M * qpow(10, i) % M, i});
    for(int i = 1; i <= lim; ++i){
        ll val = qpow(10, (ll)i * lim);
        if(mp.find(val) != mp.end())printf("%lld\n", (ll)i * lim - mp[val]), exit(0);
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