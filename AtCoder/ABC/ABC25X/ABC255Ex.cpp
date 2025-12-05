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

#define MOD (998244353ll)

template < typename T = int >
inline T read(void);

struct Node{
    ll l, r;
    mutable ll lst;
    friend const bool operator < (const Node &a, const Node &b){
        return a.l < b.l;
    }
};

class ODT{
private:
    set < Node > tr;
public:
    auto Insert(Node p){return tr.insert(p);}
    auto Split(ll p){
        auto it = tr.lower_bound(Node{p});
        if(it != tr.end() && it->l == p)return it;
        advance(it, -1);
        ll l = it->l, r = it->r, lst = it->lst;
        tr.erase(it);
        Insert(Node{l, p - 1, lst});
        return Insert(Node{p, r, lst}).first;
    }
    ll Assign(ll l, ll r, ll days){
        ll ret(0);
        auto itR = Split(r + 1), itL = Split(l);
        for(auto it = itL; it != itR; ++it)
            (ret += ((__int128_t)(it->l + it->r) * (it->r - it->l + 1) / 2ll) % MOD * (days - it->lst) % MOD) %= MOD;
        tr.erase(itL, itR);
        Insert(Node{l, r, days});
        return ret;
    }
}odt;

ll N; int Q;

int main(){
    N = read < ll >(), Q = read();
    odt.Insert(Node{1, N, 0});
    while(Q--){
        ll D = read < ll >(), L = read < ll >(), R = read < ll >();
        printf("%lld\n", odt.Assign(L, R, D));
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