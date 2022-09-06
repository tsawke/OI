#define _USE_MATH_DEFINES
#include <bits/stdc++.h>

#define PI M_PI
#define E M_E
#define npt nullptr
#define lsiz(p) (p->ls ? p->ls->siz : 0)
#define rsiz(p) (p->rs ? p->rs->siz : 0)
#define size(p) (p ? p->siz : 0)

/******************************
abbr

******************************/

using namespace std;

mt19937 _rnd(random_device{}());
int rnd(void){return _rnd() % (uint)INT_MAX;}
int rndd(int l, int r){return rnd() % (r - l + 1) + l;}

typedef unsigned int uint;
typedef unsigned long long unll;
typedef long long ll;

struct Treap{
    Treap *ls, *rs;
    int val, pri;
    int siz, cnt;
    void* operator new(size_t);
    Treap(Treap* _ls, Treap* _rs, int _val, int _pri):ls(_ls), rs(_rs), val(_val), pri(_pri), siz(1), cnt(1){;}
    Treap(void) = default;
}tData[110000];
void* Treap::operator new(size_t){static Treap* P = tData; return ++P;}

template<typename T = int>
inline T read(void);

int N;
Treap* root;
void Pushup(Treap* P){P->siz = lsiz(P) + rsiz(P);}
pair < Treap*, Treap* > Split(Treap* P, int val){
    if(!P)return {npt, npt};
    if(val <= P->val){
        auto tmp = Split(P->ls, val);
        P->ls = tmp.second;
        Pushup(P);
        return {tmp.first, P};
    }else{
        auto tmp = Split(P->rs, val);
        P->rs = tmp.first;
        Pushup(P);
        return {P, tmp.second};
    }
}
tuple < Treap*, Treap*, Treap* > Split_By_Rank(Treap* p, int rnk){
    if(!p)return {npt, npt, npt};
    if(rnk <= lsiz(p)){
        Treap *l, *mid, *r;
        tie(l, mid, r) = Split_By_Rank(p->ls, rnk);
        p->ls = r;
        Pushup(p);
        return {l, mid, p};
    }else if(rnk <= lsiz(p) + p->cnt){
        auto l = p->ls, r = p->rs;
        p->ls = p->rs = npt;
        Pushup(p);
        return {l, p, r};
    }else{
        Treap *l, *mid, *r;
        tie(l, mid, r) = Split_By_Rank(p->rs, rnk - lsiz(p) - p->cnt);
        p->rs = l;
        Pushup(p);
        return {p, mid, r};
    }
}
Treap* Merge(Treap* l, Treap* r){
    if(!l || !r)return l ? l : r;
    if(l->pri <= r->pri){
        l->rs = Merge(l->rs, r);
        Pushup(l);
        return l;
    }else{
        r->ls = Merge(l, r->ls);
        Pushup(r);
        return r;
    }
}
void Insert(Treap* &p, int val){
    auto spl = Split(p, val);
    auto spll = Split(spl.first, val - 1);
    if(!spll.second)spll.second = new Treap(npt, npt, val, rnd());
    else spll.second->cnt++;
    auto m1 = Merge(spll.first, spll.second);
    p = Merge(m1, spl.second);
}
void Delete(Treap* &p, int val){
    auto spl = Split(p, val);
    auto spll = Split(spl.first, val - 1);
    if(!spll.second){printf("-1\n"); exit(1);}
    else if(spll.second->cnt == 1)spll.second = npt;
    else spll.second->cnt--;
    auto m1 = Merge(spll.first, spll.second);
    p = Merge(m1, spl.second);
}
int QueryRank(Treap* &p, int val){
    auto spl = Split(p, val);
    auto spll = Split(spl.first, val - 1);
    int ret = size(spll.first) + 1;
    auto m1 = Merge(spll.first, spll.second);
    p = Merge(m1, spl.second);
    return ret;
}
int QueryVal(Treap* &p, int rnk){
    Treap *l, *mid, *r;
    tie(l, mid, r) = Split_By_Rank(p, rnk);
    int ret = size(l) + 1;
    p = Merge(Merge(l, mid), r);
    return ret;
}
int FindPre(Treap* &p, int val){
    auto spl = Split(p, val - 1);
    int ret = QueryVal(spl.first, size(spl.first));
    p = Merge(spl.first, spl.second);
    return ret;
}
int FindSuf(Treap* &p, int val){
    auto spl = Split(p, val);
    int ret = QueryVal(spl.second, 1);
    p = Merge(spl.first, spl.second);
    return ret;
}
int main(){
    N = read();
    (void)read();
    root = new Treap(npt, npt, read(), rnd());
    for(int i = 2; i <= N; ++i){
        int opt = read(), x = read();
        switch(opt){
            case 1:{Insert(root, x); break;}
            case 2:{Delete(root, x); break;}
            case 3:{printf("%d\n", QueryRank(root, x)); break;}
            case 4:{printf("%d\n", QueryVal(root, x)); break;}
            case 5:{printf("%d\n", FindPre(root, x)); break;}
            case 6:{printf("%d\n", FindSuf(root, x)); break;}
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