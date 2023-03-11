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

template < typename T = int >
inline T read(void);

ll N, K;
unordered_set < ll > legal;
ll ans(0);

int main(){
    auto qpow_with_lim = [](ll a, ll b)->ll{
        ll ret(1), mul(a);
        while(b){
            if(b & 1)
                ret = (__int128_t)ret * mul > N ? N + 1 : ret * mul;
            b >>= 1;
            mul = (__int128_t)mul * mul > N ? N + 1 : mul * mul;
        }return ret;
    };

    N = read < ll >(), K = read();
    if(K == 1)printf("%lld\n", N), exit(0);
    legal.insert(1);
    for(ll i = 2; i <= (ll)1e6; ++i){
        auto cur = (__int128_t)qpow_with_lim(i, K == 2 ? 3 : K);
        while(cur <= N)
            legal.insert(cur), cur *= i;
    }ans += legal.size();
    if(K == 2){
        for(auto v : legal)
            if((ll)sqrt((ld)v) * (ll)sqrt((ld)v) == v)--ans;
        ans += (ll)floor(sqrt((ld)N));
    }printf("%lld\n", ans);
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