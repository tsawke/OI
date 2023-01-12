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

ll P, A, B, X1, T;
unordered_map < ll, ll > mp;

ll qpow(ll a, ll b){
    ll ret(1), mul(a);
    while(b){
        if(b & 1)ret = ret * mul % P;
        b >>= 1;
        mul = mul * mul % P;
    }return ret;
}

int main(){
    int t = read();
    while(t--){
        mp.clear();
        P = read(), A = read(), B = read(), X1 = read(), T = read();
        if(X1 == T){printf("1\n"); continue;}
        if(A == 0){printf("%d\n", B == T ? 2 : -1); continue;}
        if(A == 1){
            if(B == 0){printf("-1\n"); continue;}
            printf("%lld\n", ((T - X1) % P + P) % P * qpow(B, P - 2) % P + 1);
            continue;
        }
        ll b = ((T - B * qpow((1 - A + P) % P, P - 2) % P) % P + P) % P * qpow(((X1 - B * qpow((1 - A + P) % P, P - 2) % P) % P + P) % P, P - 2) % P;
        ll lim = (ll)ceil(sqrt(P));
        for(int i = 1; i <= lim; ++i)mp.insert({b * qpow(A, i) % P, i});
        for(int i = 1; i <= lim; ++i){
            ll val = qpow(A, (ll)i * lim);
            if(mp.find(val) != mp.end()){printf("%lld\n", (ll)i * lim - mp[val] + 1); break;}
            if(i == lim)puts("-1");
        }
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