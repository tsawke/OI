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

template<typename T = ll>
inline T read(void);

ll N, M;
ll seed, vmax;
ll a[110000];

ll qpow(ll a, ll b, ll mod){
    ll ret(1), mul(a % mod);
    while(b){
        if(b & 1)ret = ret * mul % mod;
        b >>= 1;
        mul = mul * mul % mod;
    }return ret;
}

struct Node{
    int l, r;
    int size(void)const{return r - l + 1;}
    mutable ll val;
    friend const bool operator < (const Node &x, const Node &y){return x.l < y.l;}
};
class ODT{
    private:
        set < Node > tr;
    public:
        auto Insert(Node p){return tr.insert(p);}
        auto Split(int p){
            auto it = tr.lower_bound(Node{p});
            if(it != tr.end() && p == it->l)return it;
            --it;
            if(p > it->r)return tr.end();
            auto l = it->l, r = it->r;
            auto val = it->val;
            tr.erase(it);
            Insert(Node{l, p - 1, val});
            return Insert(Node{p, r, val}).first;
        }
        void Modify(int l, int r, ll val){
            auto itR = Split(r + 1), itL = Split(l);
            for(auto it = itL; it != itR; ++it)it->val += val;
        }
        void Assign(int l, int r, ll val){
            auto itR = Split(r + 1), itL = Split(l);
            tr.erase(itL, itR);
            Insert(Node{l, r, val});
        }
        ll QueryKth(int l, int r, int k){
            vector < Node > rnk;
            auto itR = Split(r + 1), itL = Split(l);
            for(auto it = itL; it != itR; ++it)rnk.push_back(*it);
            sort(rnk.begin(), rnk.end(), [](const Node x, const Node y)->bool{return x.val < y.val;});
            int cur(0);
            for(auto i : rnk){
                cur += i.size();
                if(cur >= k)return i.val;
            }
            return -1;
        }
        ll QuerySum(int l, int r, ll k, ll mod){
            ll ret(0);
            auto itR = Split(r + 1), itL = Split(l);
            for(auto it = itL; it != itR; ++it)
                ret = (ret + qpow(it->val, k, mod) * it->size() % mod) % mod;
            return ret;
        }
}odt;

ll rndread(void){
    #define MOD (ll)(1e9 + 7)
    ll ret = seed;
    seed = (seed * 7 + 13) % MOD;
    return ret;
}

int main(){
    N = read(), M = read(), seed = read(), vmax = read();
    for(int i = 1; i <= N; ++i)odt.Insert(Node{i, i, (rndread() % vmax) + 1});
    while(M--){
        int
            opt = (rndread() % 4) + 1,
            l = (rndread() % N) + 1,
            r = (rndread() % N) + 1;
        if(l > r)swap(l, r);
        switch(opt){
            case 1:{
                ll x = (rndread() % vmax) + 1;
                odt.Modify(l, r, x);
                break;
            }
            case 2:{
                ll x = (rndread() % vmax) + 1;
                odt.Assign(l, r, x);
                break;
            }
            case 3:{
                ll x = (rndread() % (r - l + 1)) + 1;
                printf("%lld\n", odt.QueryKth(l, r, x));
                break;
            }
            case 4:{
                ll x = (rndread() % vmax) + 1;
                ll y = (rndread() % vmax) + 1;
                printf("%lld\n", odt.QuerySum(l, r, x, y));
                break;
            }
            default:break;
        }
    }
    fprintf(stderr, "Time: %.6lf\n", (double)clock() / CLOCKS_PER_SEC);
    return 0;
}

template<typename T>
inline T read(void){
    T ret(0);
    short flag(1);
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