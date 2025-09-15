#define _USE_MATH_DEFINES
#include <bits/stdc++.h>

#define PI M_PI
#define E M_E
#define npt nullptr
#define lsiz(p) (p->ls ? p->ls->siz : 0)
#define rsiz(p) (p->rs ? p->rs->siz : 0)
#define size(p) (p ? p->siz : 0)

using namespace std;

mt19937 _rnd(random_device{}());
int rnd(void){return (int)(_rnd() & 0x7fffffff);}

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
}td[400000 + 5];
void* Treap::operator new(size_t){static Treap* P = td; return ++P;}

template<typename T = int>
inline T read(void){
    T ret(0); short flag(1); int c = getchar();
    while(c != '-' && !isdigit(c)) c = getchar();
    if(c == '-')flag = -1, c = getchar();
    while(isdigit(c)){ret = ret * 10 + (c - '0'); c = getchar(); }
    ret = (T)(ret * flag); return ret;
}

Treap* root = npt;

inline void Pushup(Treap* P){if(P) P->siz = P->cnt + lsiz(P) + rsiz(P);}

pair < Treap*, Treap* > Split(Treap* P, int val){
    if(!P)return {npt, npt};
    if(val >= P->val){
        auto tmp = Split(P->rs, val);
        P->rs = tmp.first; Pushup(P);
        return {P, tmp.second};
    }else{
        auto tmp = Split(P->ls, val);
        P->ls = tmp.second; Pushup(P);
        return {tmp.first, P};
    }
}

Treap* Merge(Treap* l, Treap* r){
    if(!l && !r)return npt;
    if(!l || !r)return l ? l : r;
    if(l->pri < r->pri){
        l->rs = Merge(l->rs, r);
        Pushup(l); return l;
    }else{
        r->ls = Merge(l, r->ls);
        Pushup(r); return r;
    }
}

void Insert(Treap* &p, int val){
    auto spl = Split(p, val);
    auto spll = Split(spl.first, val - 1);
    if(!spll.second) spll.second = new Treap(npt, npt, val, rnd());
    else { spll.second->cnt++; Pushup(spll.second); }
    p = Merge(Merge(spll.first, spll.second), spl.second);
}

void Delete(Treap* &p, int val){
    auto spl = Split(p, val);
    auto spll = Split(spl.first, val - 1);
    if(spll.second){
        if(spll.second->cnt > 1){ spll.second->cnt--; Pushup(spll.second);}
        else spll.second = npt;
    }
    p = Merge(Merge(spll.first, spll.second), spl.second);
}

long long APSum(Treap* p, int z, int r, int M){
    if(!p || z<=0) return 0;
    int L = lsiz(p);
    if(z <= L) return APSum(p->ls, z, r, M);
    long long res = 0;
    res += APSum(p->ls, L, r, M);
    int t = z - L;
    int take = min(t, p->cnt);
    int s0 = L % M;
    int rself = (( (r - 1) - s0 ) % M + M) % M + 1;
    if(take >= rself){
        int k = 1 + (take - rself) / M;
        res += 1LL * k * p->val;
    }
    if(z > L + p->cnt){
        int shift = (L + p->cnt) % M;
        int rR = (( (r - 1) - shift ) % M + M) % M + 1;
        res += APSum(p->rs, z - L - p->cnt, rR, M);
    }
    return res;
}

int main(){
    int N = read(), M = read(), Q = read();
    vector < int > A(N + 100);
    for(int i = 1; i <= N; ++i)A[i] = read(), Insert(root, A[i]);

    unll _x, _y, _z; ll lst = 0;
    while(Q--){
        _x = read < unll >(); _y = read < unll >(); _z = read < unll> ();
        int x = 1 + (int)((_x + (unll)lst) % (unll)N);
        int y = 1 + (int)((_y + (unll)lst) % (unll)1000000000ULL);
        int z = 1 + (int)((_z + (unll)lst) % (unll)N);

        Delete(root, A[x]);
        A[x] = y;
        Insert(root, A[x]);

        int r = ((z - 1) % M) + 1;
        long long ans = APSum(root, z, r, M);
        printf("%lld\n", ans);
        lst = ans;
    }
    return 0;
}
