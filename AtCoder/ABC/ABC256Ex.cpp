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

int N, Q;
int A[510000];

struct Node{
    int l;
    mutable int r;
    mutable ll val;
    friend const bool operator < (const Node &a, const Node &b){
        return a.l < b.l;
    }
};

class SegTree{
private:
public:
    ll tr[510000 << 2];
    ll lz[510000 << 2];
    #define LS (p << 1)
    #define RS (LS | 1)
    #define MID ((gl + gr) >> 1)
    #define SIZ(l, r) ((r) - (l) + 1)
public:
    SegTree(void){memset(lz, -1, sizeof lz);}
    void Pushup(int p){tr[p] = tr[LS] + tr[RS];}
    void Pushdown(int p, int gl, int gr){
        if(!~lz[p])return;
        lz[LS] = lz[RS] = lz[p];
        tr[LS] = SIZ(gl, MID) * lz[p];
        tr[RS] = SIZ(MID + 1, gr) * lz[p];
        lz[p] = -1;
    }
    void Build(int p = 1, int gl = 1, int gr = N){
        if(gl == gr)return tr[p] = A[gl = gr], void();
        Build(LS, gl, MID), Build(RS, MID + 1, gr);
        Pushup(p);
    }
    void Assign(int l, int r, ll v, int p = 1, int gl = 1, int gr = N){
        // printf("Assign ST : l = %d, r = %d, v = %lld, gl = %d, gr = %d, p = %d\n", l, r, v, gl, gr, p);
        if(l <= gl && gr <= r)return tr[p] = SIZ(gl, gr) * v, lz[p] = v, void();
        Pushdown(p, gl, gr);
        if(l <= MID)Assign(l, r, v, LS, gl, MID);
        if(MID + 1 <= r)Assign(l, r, v, RS, MID + 1, gr);
        Pushup(p);
    }
    ll Query(int l, int r, int p = 1, int gl = 1, int gr = N){
        if(l <= gl && gr <= r)return tr[p];
        if(r < gl || l > gr)return 0;
        Pushdown(p, gl, gr);
        return Query(l, r, LS, gl, MID) + Query(l, r, RS, MID + 1, gr);
    }
    void Desc(int siz = 3){
        int len(1);
        int cur(0);
        while(siz--){
            for(int i = 1; i <= len; ++i)printf("%lld%c", tr[++cur], i == len ? '\n' : ' ');
            len <<= 1;
        }
    }
}st;

class ODT{
private:
    set < Node > tr;
public:
    auto Insert(Node p){return tr.insert(p);}
    auto Split(int p){
        auto it = tr.lower_bound(Node{p});
        if(it != tr.end() && it->l == p)return it;
        advance(it, -1);
        if(p > it->r)return tr.end();
        int l = it->l, r = it->r;
        ll val = it->val;
        tr.erase(it);
        Insert(Node{l, p - 1, val});
        return Insert(Node{p, r, val}).first;
    }
    void Assign(int l, int r, ll val){
        auto itR = Split(r + 1), itL = Split(l);
        tr.erase(itL, itR);
        Insert(Node{l, r, val});
        st.Assign(l, r, val);
    }
    void Divide(int l, int r, ll x){
        auto itR = Split(r + 1), itL = Split(l);
        for(auto it = itL; it != itR;){
            it->val /= x;
            if(!it->val){
                decltype(it) nxt;
                for(nxt = next(it); nxt != itR; nxt = tr.erase(nxt)){
                    nxt->val /= x;
                    if(!nxt->val)it->r = nxt->r;
                    else{
                        st.Assign(it->l, it->r, it->val);
                        st.Assign(nxt->l, nxt->r, nxt->val);
                        it = next(nxt);
                        break;
                    }
                }
                if(nxt == itR)st.Assign(it->l, it->r, it->val), it = nxt;
            }else
                st.Assign(it->l, it->r, it->val), advance(it, 1);
        }
    }
    ll Query(int l, int r){
        ll ret(0);
        auto itR = Split(r + 1), itL = Split(l);
        for(auto it = itL; it != itR; ++it)
            ret += (it->r - it->l + 1) * it->val;
        return ret;
    }
    void Desc(void){
        printf("Describe ODT:\n");
        for(auto nod : tr)printf("%d ~ %d : %lld\n", nod.l, nod.r, nod.val);
    }
}odt;

int main(){
    // freopen("01_n_small_00.txt", "r", stdin);
    // freopen("out.txt", "w", stdout);
    N = read(), Q = read();
    for(int i = 1; i <= N; ++i)odt.Insert(Node{i, i, A[i] = read()});
    st.Build();
    while(Q--){
        int opt = read();
        switch(opt){
            case 1:{
                int l = read(), r = read(), x = read();
                odt.Divide(l, r, x);
                break;
            }
            case 2:{
                int l = read(), r = read(), x = read();
                odt.Assign(l, r, x);
                break;
            }
            case 3:{
                int l = read(), r = read();
                printf("%lld\n", st.Query(l, r));
                break;
            }
            default: break;
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