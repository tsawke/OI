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

struct Node{
    #define val(p) (p ? p->val : 0)
    #define cnt(p) (p ? p->cnt : 0)
    Node* ls, *rs;
    int val, cnt;
    OPNEW;
}nd[LIM << 6];
ROPNEW_NODE;

void Pushup(Node* p){
    if(!p)return;
    if(cnt(p->ls) >= cnt(p->rs))p->val = val(p->ls), p->cnt = cnt(p->ls);
    else p->val = val(p->rs), p->cnt = cnt(p->rs);
}

class SegTree{
private:
    #define LS (p << 1)
    #define RS (LS | 1)
    #define MID ((gl + gr) >> 1)
public:
    Node* root;
    void Modify(int idx, int v, Node* &p, int gl = 1, int gr = LIM){
        if(!p)p = new Node{npt, npt, 0, 0};
        if(gl == gr)return p->cnt += v, p->val = p->cnt ? gl = gr : 0, void();
        if(idx <= MID)Modify(idx, v, p->ls, gl, MID);
        else Modify(idx, v, p->rs, MID + 1, gr);
        Pushup(p);
    }
    int Query(void){
        return val(root);
    }
}st[LIM];

Node* Merge(Node* A, Node* B, int gl = 1, int gr = LIM){
    if(!A || !B)return A ? A : B;
    if(gl == gr)return A->cnt += B->cnt, A->val = A->cnt ? gl = gr : 0, A;
    if(!A->ls && B->ls)A->ls = B->ls;
    else A->ls = Merge(A->ls, B->ls, gl, MID);
    if(!A->rs && B->rs)A->rs = B->rs;
    else A->rs = Merge(A->rs, B->rs, MID + 1, gr);
    return Pushup(A), A;
}

int N, M;

struct Edge{
    Edge* nxt;
    int to;
    OPNEW;
}ed[LIM << 1];
ROPNEW;
Edge* head[LIM];

int dep[LIM], dfn[LIM], idx[LIM], top[LIM], hson[LIM], siz[LIM], fa[LIM];

void dfs_pre(int p = 1, int fa = 0){
    ::fa[p] = fa, dep[p] = dep[fa] + 1, siz[p] = 1;
    for(auto i = head[p]; i; i = i->nxt){
        if(SON == fa)continue;
        dfs_pre(SON, p);
        siz[p] += siz[SON];
        if(siz[SON] > siz[hson[p]])hson[p] = SON;
    }
}
void dfs_make(int p = 1, int top = 1){
    static int cdfn(0);
    dfn[p] = ++cdfn, idx[cdfn] = p;
    ::top[p] = top;
    if(hson[p])dfs_make(hson[p], top);
    for(auto i = head[p]; i; i = i->nxt)
        if(SON != fa[p] && SON != hson[p])dfs_make(SON, SON);
}
int LCA(int s, int t){
    while(top[s] != top[t]){
        if(dep[top[s]] < dep[top[t]])swap(s, t);
        s = fa[top[s]];
    }if(dep[s] < dep[t])swap(s, t);
    return t;
}

int ans[LIM];

void dfs_merge(int p = 1, int fa = 0){
    for(auto i = head[p]; i; i = i->nxt)
        if(SON != fa)dfs_merge(SON, p), st[p].root = Merge(st[p].root, st[SON].root);
    ans[p] = st[p].Query();
}

int main(){
    N = read(), M = read();
    for(int i = 1; i <= N - 1; ++i){
        int s = read(), t = read();
        head[s] = new Edge{head[s], t};
        head[t] = new Edge{head[t], s};
    }dfs_pre(), dfs_make();
    for(int i = 1; i <= M; ++i){
        int s = read(), t = read(), v = read(), lca = LCA(s, t);
        // printf("s = %d, t = %d, lca = %d\n", s, t, lca);
        st[s].Modify(v, 1, st[s].root), st[t].Modify(v, 1, st[t].root);
        st[lca].Modify(v, -1, st[lca].root), st[fa[lca]].Modify(v, -1, st[fa[lca]].root);
    }dfs_merge();
    for(int i = 1; i <= N; ++i)printf("%d\n", ans[i]);
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