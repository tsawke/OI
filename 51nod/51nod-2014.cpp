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

template< typename T = int >
inline T read(void);

int N, M;

struct Node{
    int l, r;
    mutable bool val;
    friend const bool operator < (const Node &a, const Node &b){
        return a.l < b.l;
    }
};

class ODT{
private:
    #define SIZ(it) (it->r - it->l + 1)
    set < Node > tr;
public:
    pair < set < Node >::iterator, bool > Insert(Node x){return tr.insert(x);}
    set < Node >::iterator Split(int p){
        auto it = tr.lower_bound(Node{p});
        if(it != tr.end() && it->l == p)return it;
        --it;
        int l = it->l, r = it->r;
        bool val = it->val;
        tr.erase(it);
        Insert(Node{l, p - 1, val});
        return Insert(Node{p, r, val}).first;
    }
    void Assign(int l, int r, bool val){
        auto itR = Split(r + 1), itL = Split(l);
        tr.erase(itL, itR);
        Insert(Node{l, r, val});
    }
    int Query(int l, int r){
        int ret(0);
        auto itR = Split(r + 1), itL = Split(l);
        for(auto it = itL; it != itR; ++it)ret += SIZ(it) * it->val;
        return ret;
    }
}odt;

class ODT_COL{
private:
    set < Node > tr;
public:
    pair < set < Node >::iterator, bool > Insert(Node x){return tr.insert(x);}
    set < Node >::iterator Split(int p){
        auto it = tr.lower_bound(Node{p});
        if(it != tr.end() && it->l == p)return it;
        --it;
        int l = it->l, r = it->r;
        bool val = it->val;
        tr.erase(it);
        Insert(Node{l, p - 1, val});
        return Insert(Node{p, r, val}).first;
    }
    void Modify(int l, int r){
        auto itR = Split(r + 1), itL = Split(l);
        for(auto it = itL; it != itR; ++it){
            if(!it->val)it->val = true, odt.Assign(it->l, it->r, true);
            else odt.Assign(it->l, it->r, false);
        }
    }
}odt_col[110000];

int main(){
    N = read(), M = read();
    odt.Insert(Node{1, N, false});
    for(int i = 1; i <= 101000; ++i)odt_col[i].Insert(Node{1, N, false});
    while(M--){
        int opt = read();
        if(opt == 1){
            int x = read(), idx = read(), dis = read();
            odt_col[idx].Modify(max(1, x - dis), min(N, x + dis));
        }else{
            int l = read(), r = read();
            printf("%d\n", odt.Query(l, r));
        }
    }
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