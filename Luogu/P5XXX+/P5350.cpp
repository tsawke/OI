#define _USE_MATH_DEFINES
#include <bits/extc++.h>

#define PI M_PI
#define E M_E
#define npt nullptr
#define SON i->to
#define OPNEW void* operator new(size_t)
#define ROPNEW(arr) void* Edge::operator new(size_t){static Edge* P = arr; return P++;}

using namespace std;
using namespace __gnu_pbds;

mt19937 rnd(random_device{}());
int rndd(int l, int r){return rnd() % (r - l + 1) + l;}
bool rnddd(int x){return rndd(1, 100) <= x;}

typedef unsigned int uint;
typedef unsigned long long unll;
typedef long long ll;
typedef long double ld;

#define MOD (ll)(1e9 + 7)

template< typename T = int >
inline T read(void);

int N, M;
ll ans[310000];

struct Node{
    int l, r;
    mutable ll val;
    friend const bool operator < (const Node &a, const Node &b){return a.l < b.l;}
};
class ODT{
private:
    #define SIZ(it) (it->r - it->l + 1)
    set < Node > tr;
public:
    auto Insert(Node x){return tr.insert(x);}
    auto Split(int p){
        auto it = tr.lower_bound(Node{p});
        if(it != tr.end() && it->l == p)return it;
        --it;
        int l = it->l, r = it->r;
        ll v = it->val;
        tr.erase(it);
        Insert(Node{l, p - 1, v});
        return Insert(Node{p, r, v}).first;
    }
    void Assign(int l, int r, ll val){
        auto itR = Split(r + 1), itL = Split(l);
        tr.erase(itL, itR);
        Insert(Node{l, r, val});
    }
    void Modify(int l, int r, ll val){
        auto itR = Split(r + 1), itL = Split(l);
        for(auto it = itL; it != itR; ++it)it->val = (it->val + val) % MOD;
    }
    ll Query(int l, int r){
        ll ret(0);
        auto itR = Split(r + 1), itL = Split(l);
        for(auto it = itL; it != itR; ++it)ret = (ret + SIZ(it) * it->val % MOD) % MOD;
        return ret;
    }
    void Copy(int l1, int r1, int l2, int r2){
        auto itR = Split(r1 + 1), itL = Split(l1);
        basic_string < Node > tmp;
        for(auto it = itL; it != itR; ++it)tmp += Node{it->l + (l2 - l1), it->r + (l2 - l1), it->val};
        itR = Split(r2 + 1), itL = Split(l2);
        tr.erase(itL, itR);
        for(auto nod : tmp)Insert(nod);
    }
    void Swap(int l1, int r1, int l2, int r2){
        basic_string < Node > S, T;
        auto itR = Split(r1 + 1), itL = Split(l1);
        for(auto it = itL; it != itR; ++it)S += Node{it->l + (l2 - l1), it->r + (l2 - l1), it->val};
        tr.erase(itL, itR);
        itR = Split(r2 + 1), itL = Split(l2);
        for(auto it = itL; it != itR; ++it)T += Node{it->l - (l2 - l1), it->r - (l2 - l1), it->val};
        tr.erase(itL, itR);
        for(auto nod : S + T)Insert(nod);
    }
    void Reverse(int l, int r){
        basic_string < Node > vals;
        auto itR = Split(r + 1), itL = Split(l);
        for(auto it = itL; it != itR; ++it)vals += *it;
        tr.erase(itL, itR);
        for(auto nod : vals)Insert(Node{r - nod.r + l, r - nod.l + l, nod.val});
    }
    void SetAns(void){
        for(auto nod : tr)
            for(int i = nod.l; i <= nod.r; ++i)ans[i] = nod.val;
    }
}odt;

int main(){
    N = read(), M = read();
    for(int i = 1; i <= N; ++i)odt.Insert(Node{i, i, read()});
    while(M--){
        int opt = read();
        switch(opt){
            case 1:{int l = read(), r = read(); printf("%lld\n", odt.Query(l, r)); break;}
            case 2:{int l = read(), r = read(), val = read(); odt.Assign(l, r, val); break;}
            case 3:{int l = read(), r = read(), val = read(); odt.Modify(l, r, val); break;}
            case 4:{int l1 = read(), r1 = read(), l2 = read(), r2 = read(); odt.Copy(l1, r1, l2, r2); break;}
            case 5:{int l1 = read(), r1 = read(), l2 = read(), r2 = read(); odt.Swap(min(l1, l2), min(r1, r2), max(l1, l2), max(r1, r2)); break;}
            case 6:{int l = read(), r = read(); odt.Reverse(l, r); break;}
        }
    }
    odt.SetAns();
    for(int i = 1; i <= N; ++i)printf("%lld%c", ans[i], i == N ? '\n' : ' ');
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