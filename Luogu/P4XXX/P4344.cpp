#define _USE_MATH_DEFINES
#include <bits/extc++.h>

#define PI M_PI
#define E M_E
#define npt nullptr
#define SON i->to
#define OPNEW void* operator new(size_t)
#define ROPNEW(arr) void* Edge::operator new(size_t){static Edge* P = arr; return P++;}

/******************************
abbr

******************************/

using namespace std;
using namespace __gnu_pbds;

mt19937 rnd(random_device{}());
int rndd(int l, int r){return rnd() % (r - l + 1) + l;}
bool rnddd(int x){return rndd(1, 100) <= x;}

typedef unsigned int uint;
typedef unsigned long long unll;
typedef long long ll;
typedef long double ld;



template<typename T = int>
inline T read(void);

// int bool2int(pair < bool, bool > v){return (int)v.first * 10 + (int)v.second;}
// pair < bool, bool > int2bool(int v){return {v / 10, v % 10};}

struct Node{
    int l, r;
    mutable bool val;
    const int size(void)const{return r - l + 1;}
    friend const bool operator < (const Node &x, const Node &y){return x.l < y.l;}
};
class ODT{
    private:
        set < Node > tr;
    public:
        auto Insert(Node p){return tr.insert(p);}
        auto Split(int p){
            auto it = tr.lower_bound(Node{p});
            if(it != tr.end() && it->l == p)return it;
            --it;
            if(p > it->r)return tr.end();
            auto l = it->l, r = it->r;
            auto val = it->val;
            tr.erase(it);
            Insert(Node{l, p - 1, val});
            return Insert(Node{p, r, val}).first;
        }
        void Assign(int l, int r, bool val){
            auto itR = Split(r + 1), itL = Split(l);
            tr.erase(itL, itR);
            Insert(Node{l, r, val});
        }
        int CountAndAssign(int l, int r){
            auto itR = Split(r + 1), itL = Split(l);
            int ret(0);
            for(auto it = itL; it != itR; it = tr.erase(it))
                if(it->val)ret += it->size();
            Insert(Node{l, r, false});
            return ret;
        }
        void Fill(int l, int r, int siz){
            if(!siz)return;
            auto itR = Split(r + 1), itL = Split(l);
            for(auto it = itL; it != itR; ++it){
                if(it->val)continue;
                if(it->size() <= siz)it->val = true, siz -= it->size();
                else{
                    Assign(it->l, it->l + siz - 1, true);
                    // int rng = it->l + siz - 1;
                    // int cl = it->l, cr = it->r;
                    // tr.erase(it);
                    // Insert(Node{cl, rng, true});
                    // Insert(Node{rng + 1, cr, true});
                    break;
                }
            }
        }
        int QueryMax(int l, int r){
            int ret(0);
            auto itR = Split(r + 1), itL = Split(l);
            int cur(0);
            for(auto it = itL; it != itR; ++it){
                !it->val
                    ? cur += it->size(), ret = max(ret, cur)
                    : cur = 0;
            }
            return ret;
        }
}odt;
int N, M;
struct Input{
    int opt;
    int l, r;
    int L, R;
};
vector < Input > in;
int main(){
    // freopen("P4344_21.in", "r", stdin);
    N = read(), M = read();
    odt.Insert({1, N, true});
    int cnt(0);
    int mx(0);
    while(M--){
        int opt = read();
        int l, r, L, R;
        L = R = -1;
        l = read(), r = read();
        if(opt == 1)L = read(), R = read();
        in.push_back(Input{opt, l, r, L, R});
    }
    int lst(-1);
    for(auto i : in){
        if(i.l == i.r && !((lst ^ i.l) & 1))++cnt, mx = i.l;
        lst = i.l & 1;
    }
    // printf("%d\n", cnt);
    if(mx >= N / 2 && cnt >= 1000){
        for(auto i : in){
            if(i.opt == 2){
                // if(i.l & 1)--i.l;
                // if(i.r & 1)++i.r;
                printf("%d\n", 1);
            }
        }
        return 0;
    }
    for(auto i : in){
        int opt = i.opt;
        int l = i.l, r = i.r, L = i.L, R = i.R;
        switch(opt){
            case 0:{
                // int l = read(), r = read();
                odt.Assign(l, r, false);
                break;
            }
            case 1:{
                // int l0 = read(), r0 = read(), l1 = read(), r1 = read();
                odt.Fill(L, R, odt.CountAndAssign(l, r));
                break;
            }
            case 2:{
                // int l = read(), r = read();
                printf("%d\n", odt.QueryMax(l, r));
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