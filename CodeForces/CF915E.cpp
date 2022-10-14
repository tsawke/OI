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

struct Node{
    Node *ls, *rs;
    int val;
    int lz;
    OPNEW;
}nd[15000000];
void* Node::operator new(size_t){static Node* P = nd; return P++;}
int N, Q;

class SegTree{
    private:
        #define MID ((gl + gr) >> 1)
        #define SIZ (gr - gl + 1)
        #define LSV (p->ls ? p->ls->val : 0)
        #define RSV (p->rs ? p->rs->val : 0)
        static Node* rt;
    public:
        void Pushup(Node* p){if(!p)return; p->val = LSV + RSV;}
        void Pushdown(Node* p, int gl, int gr){
            if(!p || !~p->lz)return;
            if(!p->ls)p->ls = new Node{npt, npt, 0, -1};
            if(!p->rs)p->rs = new Node{npt, npt, 0, -1};
            p->ls->val = p->lz * (MID - gl + 1),
            p->rs->val = p->lz * (gr - MID - 1 + 1);
            p->ls->lz = p->lz, p->rs->lz = p->lz;
            p->lz = -1;
        }
        void Modify(int val, int l, int r, Node* &p = rt, int gl = 1, int gr = N){
            if(!p)p = new Node{npt, npt, 0, -1};
            if(l <= gl && gr <= r)return p->val = SIZ * val, p->lz = val, void();
            Pushdown(p, gl, gr);
            if(MID >= l)Modify(val, l, r, p->ls, gl, MID);
            if(MID + 1 <= r)Modify(val, l, r, p->rs, MID + 1, gr);
            Pushup(p);
        }
        int Query(int l, int r, Node* p = rt, int gl = 1, int gr = N){
            if(!p)return 0;
            if(l <= gl && gr <= r)return p->val;
            Pushdown(p, gl, gr);
            return
                (MID >= l ? Query(l, r, p->ls, gl, MID) : 0) +
                (MID + 1 <= r ? Query(l, r, p->rs, MID + 1, gr) : 0);
        }
}st;
Node* SegTree::rt = new Node{npt, npt, 0, -1};

int main(){
    N = read(), Q = read();
    st.Modify(1, 1, N);
    while(Q--){
        int l = read(), r = read(), opt = read();
        if(opt == 1)st.Modify(0, l, r);
        else st.Modify(1, l, r);
        printf("%d\n", st.Query(1, N));
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