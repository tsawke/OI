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

map < ll, ll > mp;
ll A, P, B;

ll BSGS(ll a, ll b, ll MOD, ll k = 1){
    mp.clear();
    ll lim = (ll)ceil(sqrt(MOD));
    ll cur(1);
    for(int i = 1; i <= lim; ++i)(cur *= a) %= MOD, mp[b * cur % MOD] = i;
    ll powA = cur * k % MOD;
    for(int i = 1; i <= lim; ++i){
        if(mp.find(powA) != mp.end())return i * lim - mp[powA];
        (powA *= cur) %= MOD;
    }return -0x3f3f3f3f;
}
ll exBSGS(ll a, ll b, ll MOD){
    ll originA = a % MOD, originB = b % MOD, originMOD = MOD;
    a %= MOD, b %= MOD;
    if(b == 1 || MOD == 1)return 0;
    ll cnt(0), k(1);
    ll cur(1);
    while(true){
        if(cur == originB)return cnt;
        (cur *= originA) %= originMOD;
        ll d = __gcd(a, MOD);
        if(b % d)return -0x3f3f3f3f;
        if(d == 1)return BSGS(a, b, MOD, k) + cnt;
        k = k * a / d % MOD, b /= d, MOD /= d;
        ++cnt;
    }
}

int main(){
    while(true){
        A = read(), P = read(), B = read();
        if(!A && !P && !B)exit(0);
        ll ret = exBSGS(A, B, P);
        if(ret < 0)printf("No Solution\n");
        else printf("%lld\n", ret);
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