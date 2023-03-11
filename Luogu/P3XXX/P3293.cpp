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

#define LIM (110000)

template < typename T = int >
inline T read(void);

int N, M;

class SegTree{
private:
    struct Node{Node *ls, *rs; int cnt;};
    #define MID ((gl + gr) >> 1)
public:
    Node* root[210000];
    Node* Build(int gl = 0, int gr = LIM){
        if(gl == gr)return new Node{npt, npt, 0};
        return new Node{Build(gl, MID), Build(MID + 1, gr), 0};
    }
    SegTree(void){root[0] = Build();}
    Node* Create(int val, Node* lstp, int gl = 0, int gr = LIM){
        Node* p = lstp ? new Node{lstp->ls, lstp->rs, lstp->cnt + 1} : new Node{npt, npt, 1};
        if(gl != gr){
            if(val <= MID)p->ls = Create(val, p->ls, gl, MID);
            else p->rs = Create(val, p->rs, MID + 1, gr);
        }return p;
    }
    int Query(int l, int r, Node* &p, int gl = 0, int gr = LIM){
        if(!p)p = new Node{npt, npt, 0};
        if(l <= gl && gr <= r)return p->cnt;
        if(gr < l || gl > r)return 0;
        return Query(l, r, p->ls, gl, MID) + Query(l, r, p->rs, MID + 1, gr);
    }
}st;

int main(){
    N = read(), M = read();
    for(int i = 1; i <= N; ++i)st.root[i] = st.Create(read(), st.root[i - 1]);
    while(M--){
        int base = read(), exc = read(), l = read(), r = read();
        int cur(0);
        for(int i = 20; i >= 0; --i){
            auto [rngl, rngr] = base & (1 << i) ? pair{cur - exc, cur + (1 << i) - 1 - exc} : pair{cur + (1 << i) - exc, cur + (1 << (i + 1)) - 1 - exc};
            int cnt = rngl < 0 && rngr < 0 ? 0 : st.Query(rngl, rngr, st.root[r]) - st.Query(rngl, rngr, st.root[l - 1]);
            cur += (bool(base & (1 << i)) ^ (bool)cnt) << i;
        }printf("%d\n", cur ^ base);
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