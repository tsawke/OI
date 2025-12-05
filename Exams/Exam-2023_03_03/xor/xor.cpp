#define _USE_MATH_DEFINES
#include <bits/stdc++.h>

#define PI M_PI
#define E M_E
#define npt nullptr
#define SON i->to
#define OPNEW void* operator new(size_t)
#define ROPNEW void* Edge::operator new(size_t){static Edge* P = ed; return P++;}
#define ROPNEW_NODE void* Node::operator new(size_t){static Node* P = nd; return P++;}

using namespace std;

mt19937 rnd(random_device{}());
int rndd(int l, int r){return rnd() % (r - l + 1) + l;}
bool rnddd(int x){return rndd(1, 100) <= x;}

typedef unsigned int uint;
typedef unsigned long long unll;
typedef long long ll;
typedef long double ld;

#define rval(i) (vdata.at((i) - 1))

template < typename T = int >
inline T read(void);

int N, M, Q;
ll A[310000];
ll ans[310000];
// ll idx[310000];
basic_string < ll > vdata;

struct Node{
    Node *ls, *rs;
    int cnt; ll val, val2;
    OPNEW;
}nd[310000 << 5];
ROPNEW_NODE;

class SegTree{
private:
    #define MID ((gl + gr) >> 1)
    #define val(p) (p ? p->val : 0)
    #define val2(p) (p ? p->val2 : 0)
public:
    Node* root[310000];
    SegTree(void){root[0] = new Node{npt, npt, 0, 0, 0};}
    void Pushup(Node* p){
        p->val = val(p->ls) ^ val(p->rs);
        p->val2 = val2(p->ls) ^ val2(p->rs);
    }
    Node* Insert(Node* lst, int val, int gl = 1, int gr = M){
        Node* p = lst ? new Node(*lst) : new Node{npt, npt, 0, 0, 0};
        if(gl == gr){
            if(++p->cnt > 1)p->val ^= rval(gl);
            p->val2 ^= rval(gl);
            // printf("l = %d, r = %d, val = %lld\n", gl, gr, p->val);
            return p;
        }
        if(val <= MID)p->ls = Insert(p->ls, val, gl, MID);
        else p->rs = Insert(p->rs, val, MID + 1, gr);
        Pushup(p);
        return p;
    }
    ll Query(Node* p){return p->val;}
    ll Query2(Node* p){return p->val2;}
}st;

class BIT{
private:
    ll tr[310000];
public:
    int lowbit(int x){return x & -x;}
    void Modify(int x, ll v){while(x <= N)tr[x] ^= v, x += lowbit(x);}
    ll Query(int x){ll ret(0); while(x)ret ^= tr[x], x -= lowbit(x); return ret;}
    ll QueryRange(int l, int r){return Query(r) ^ Query(l - 1);}
}bit;

struct Query{
    int l; int idx;
};
basic_string < Query > qs[310000];
int lst[310000];
bitset < 310000 > exists;

int main(){
    // freopen("in.txt", "r", stdin);
    // freopen("out.txt", "w", stdout);
    freopen("xor.in", "r", stdin);
    freopen("xor.out", "w", stdout);
    N = read();
    for(int i = 1; i <= N; ++i)vdata += (A[i] = read < ll >());
    sort(vdata.begin(), vdata.end());
    vdata.erase(unique(vdata.begin(), vdata.end()), vdata.end());
    M = vdata.size();
    for(int i = 1; i <= N; ++i)
        A[i] = distance(vdata.begin(), next(lower_bound(vdata.begin(), vdata.end(), A[i])));
    // for(int i = 1; i <= N; ++i)printf("%lld\n", A[i]);
    for(int i = 1; i <= N; ++i)
        st.root[i] = st.Insert(st.root[i - 1], A[i]);//, printf("[%d] : %lld\n", i, st.Query(st.root[i]));
    Q = read();
    for(int i = 1; i <= Q; ++i){
        int l = read(), r = read();
        qs[r] += Query{l, i};
        // printf("%lld\n", st.Query(st.root[r]) ^ st.Query(st.root[l - 1]));
    }ll cur(0);
    for(int r = 1; r <= N; ++r){
        // printf("Making r = %d\n", r);
        if(r != 1)bit.Modify(r - 1, cur);
        if(!exists[A[r]])exists[A[r]] = true, cur ^= rval(A[r]);
        bit.Modify(r, cur);
        if(lst[A[r]])bit.Modify(lst[A[r]], rval(A[r]));
        lst[A[r]] = r;
        bit.Modify(r, rval(A[r]));
        for(auto q : qs[r]){
            ans[q.idx] = st.Query(st.root[r]) ^ st.Query2(st.root[q.l - 1]) ^ bit.QueryRange(q.l, r);
        }
    }
    for(int i = 1; i <= Q; ++i)printf("%lld\n", ans[i]);
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