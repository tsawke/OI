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

#define LIM (210000)

template < typename T = int >
inline T read(void);

struct Node{
    Node *ls, *rs;
    ll cnt;
    OPNEW;
}nd[LIM << 5];
ROPNEW_NODE;
Node* root[LIM];

#define LS (p << 1)
#define RS (LS | 1)
#define MID ((gl + gr) >> 1)
#define cnt(p) (p ? p->cnt : 0)

void Pushup(Node* p){
    if(!p)return;
    p->cnt = cnt(p->ls) + cnt(p->rs);
}
void Modify(int idx, int val, Node* &p, int gl = 1, int gr = LIM){
    if(!p)p = new Node{npt, npt, 0};
    if(gl == gr)return p->cnt += val, void();
    if(idx <= MID)Modify(idx, val, p->ls, gl, MID);
    else Modify(idx, val, p->rs, MID + 1, gr);
    Pushup(p);
}
ll QueryCnt(int l, int r, Node* p, int gl = 1, int gr = LIM){
    if(!p || gr < l || gl > r)return 0;
    if(l <= gl && gr <= r)return p->cnt;
    return QueryCnt(l, r, p->ls, gl, MID) + QueryCnt(l, r, p->rs, MID + 1, gr);
}
ll QueryByRnk(ll rnk, Node* p, int gl = 1, int gr = LIM){
    // printf("Querying rnk = %lld, gl = %d, gr = %d, cnt = %lld\n", rnk, gl, gr, cnt(p));
    if(!p)return -1;
    if(gl == gr)return rnk <= cnt(p) ? gl = gr : -1;
    if(rnk <= cnt(p->ls))return QueryByRnk(rnk, p->ls, gl, MID);
    else return QueryByRnk(rnk - cnt(p->ls), p->rs, MID + 1, gr);
}
Node* Merge(Node* A, Node* B, int gl = 1, int gr = LIM){
    if(!A || !B)return A ? A : B;
    if(gl == gr)return A->cnt += B->cnt, A;
    if(!A->ls && B->ls)A->ls = B->ls;
    else A->ls = Merge(A->ls, B->ls, gl, MID);
    if(!A->rs && B->rs)A->rs = B->rs;
    else A->rs = Merge(A->rs, B->rs, MID + 1, gr);
    return Pushup(A), A;
}
Node* Split(Node* &S, int val, int gl = 1, int gr = LIM){
    if(!S)return npt;
    Node* np = new Node{npt, npt, 0};
    if(val <= MID)return np->rs = S->rs, S->rs = npt, np->ls = Split(S->ls, val, gl, MID), Pushup(S), Pushup(np), np;
    else if(val == MID + 1)return np->rs = S->rs, S->rs = npt, Pushup(S), Pushup(np), np;
    else return np->rs = Split(S->rs, val, MID + 1, gr), Pushup(S), Pushup(np), np;
}

int N, M;
int cur(1);

int main(){
    N = read(), M = read();
    for(int i = 1; i <= N; ++i)Modify(i, read(), root[cur]);
    while(M--){
        int opt = read();
        switch(opt){
            case 0:{
                int idx = read(), l = read(), r = read();
                Node *L = Split(root[idx], l), *R = Split(L, r + 1);
                root[++cur] = L, root[idx] = Merge(root[idx], R);
                // printf("origin : %lld, split : %lld\n", QueryCnt(1, LIM, root[idx]), QueryCnt(1, LIM, root[cur]));
                break;
            }
            case 1:{
                int t = read(), s = read();
                root[t] = Merge(root[t], root[s]);
                break;
            }
            case 2:{
                int idx = read(), cnt = read(), val = read();
                Modify(val, cnt, root[idx]);
                break;
            }
            case 3:{
                int idx = read(), l = read(), r = read();
                printf("%lld\n", QueryCnt(l, r, root[idx]));
                break;
            }
            case 4:{
                int idx = read(); ll rnk = read < ll >();
                printf("%lld\n", QueryByRnk(rnk, root[idx]));
                break;
            }
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