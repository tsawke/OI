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
#define MID ((gl + gr) >> 1)
#define cnt(p) (p ? p->cnt : 0)

template < typename T = int >
inline T read(void);

int N, M, Q;
int ccnt;
struct Edge{
    Edge* nxt;
    int to;
    OPNEW;
}ed[LIM << 2];
ROPNEW;
Edge *headMx[LIM << 1], *headMn[LIM << 1];
int indMx[LIM << 1], indMn[LIM << 1];
int valMx[LIM << 1], valMn[LIM << 1];
int jmpMx[LIM << 2][20], jmpMn[LIM << 2][20]; //max - 19
int mnpMx[LIM << 1], mxpMx[LIM << 1], mnpMn[LIM << 1], mxpMn[LIM << 1];
int idxMn[LIM], idxMx[LIM], dfnMn[LIM], dfnMx[LIM];

class UnionFind{
private:
    int fa[LIM << 1];
public:
    void Clear(void){for(int i = 1; i <= (LIM << 1) - 10; ++i)fa[i] = i;}
    UnionFind(void){Clear();}
    int Find(int x){return x == fa[x] ? x : fa[x] = Find(fa[x]);}
    void Union(int s, int t){if(Find(s) != Find(t))fa[Find(s)] = Find(t);}
}uf;

struct edge{int s, t; int val;};
basic_string < edge > MNST, MXST;

struct Node{
    Node *ls, *rs;
    int cnt;
    OPNEW;
}nd[LIM << 6];
ROPNEW_NODE;
Node* root[LIM];//rootMn[LIM], rootMx[LIM];

int main(){
    memset(valMn, 0x3f, sizeof valMn);
    N = read(), M = read(), Q = read();
    for(int i = 1; i <= N; ++i)mnpMx[i] = mxpMx[i] = mnpMn[i] = mxpMn[i] = i;
    for(int i = 1; i <= M; ++i){
        int s = read() + 1, t = read() + 1;
        MNST += edge{s, t, max(s, t)}, MXST += edge{s, t, min(s, t)};
    }sort(MNST.begin(), MNST.end(), [](const edge &a, const edge &b)->bool{return a.val < b.val;});
    sort(MXST.begin(), MXST.end(), [](const edge &a, const edge &b)->bool{return a.val > b.val;});
    ccnt = N;
    for(auto [s, t, v] : MNST){
        int fs = uf.Find(s), ft = uf.Find(t);
        if(fs != ft){
            int fap = ++ccnt;
            valMn[fap] = v;
            ++indMn[fs], ++indMn[ft];
            headMn[fap] = new Edge{headMn[fap], fs};
            headMn[fap] = new Edge{headMn[fap], ft};
            uf.Union(fs, fap), uf.Union(ft, fap);
            // printf("Link fa = %d, son = %d, %d\n", fap, fs, ft);
        }
    }ccnt = N, uf.Clear();
    for(auto [s, t, v] : MXST){
        int fs = uf.Find(s), ft = uf.Find(t);
        if(fs != ft){
            int fap = ++ccnt;
            valMx[fap] = v;
            ++indMx[fs], ++indMx[ft];
            headMx[fap] = new Edge{headMx[fap], fs};
            headMx[fap] = new Edge{headMx[fap], ft};
            uf.Union(fs, fap), uf.Union(ft, fap);
        }
    }
    auto dfs_mn = [](auto&& self, int p, int fa = 0)->void{
        // printf("p = %d fa = %d\n", p, fa);
        static int cur(1);
        mnpMn[p] = cur, jmpMn[p][0] = fa;
        for(auto i = headMn[p]; i; i = i->nxt)
            self(self, SON, p);
        if(!headMn[p])dfnMn[p] = cur, idxMn[cur++] = p;
        // printf("cur = %d\n", cur);
        mxpMn[p] = cur - 1;
    };
    auto dfs_mx = [](auto&& self, int p, int fa = 0)->void{
        static int cur(1);
        mnpMx[p] = cur, jmpMx[p][0] = fa;
        for(auto i = headMx[p]; i; i = i->nxt)
            self(self, SON, p);
        if(!headMx[p])dfnMx[p] = cur, idxMx[cur++] = p;
        mxpMx[p] = cur - 1;
    };
    for(int i = 1; i <= ccnt; ++i)if(!indMn[i]){dfs_mn(dfs_mn, i); break;}
    for(int i = 1; i <= ccnt; ++i)if(!indMx[i]){dfs_mx(dfs_mx, i); break;}
    for(int i = 1; i <= 19; ++i)
        for(int j = 1; j <= ccnt; ++j)
            jmpMn[j][i] = jmpMn[jmpMn[j][i - 1]][i - 1],
            jmpMx[j][i] = jmpMx[jmpMx[j][i - 1]][i - 1];
    auto Pushup = [](Node* p)->void{
        if(!p)return;
        p->cnt = cnt(p->ls) + cnt(p->rs);
    };
    auto Insert = [Pushup](auto&& self, int idx, int cnt, Node* lst, int gl = 1, int gr = N)->Node*{
        Node* p = lst ? new Node(*lst) : new Node{npt, npt, 0};
        if(gl == gr)return p->cnt += cnt, p;
        if(idx <= MID)p->ls = self(self, idx, cnt, p->ls, gl, MID);
        else p->rs = self(self, idx, cnt, p->rs, MID + 1, gr);
        return Pushup(p), p;
    };
    for(int i = 1; i <= N; ++i)root[i] = Insert(Insert, dfnMx[idxMn[i]], 1, root[i - 1]);
    auto QueryCnt = [](auto&& self, Node* px, Node* py, int l, int r, int gl = 1, int gr = N)->int{
        if(l <= gl && gr <= r)return cnt(py) - cnt(px);
        if(l > gr || r < gl)return 0;
        return self(self, px ? px->ls : npt, py ? py->ls : npt, l, r, gl, MID) + self(self, px ? px->rs : npt, py ? py->rs : npt, l, r, MID + 1, gr);
    };
    auto QueryExist = [QueryCnt](int l1, int r1, int l2, int r2)->bool{
        return QueryCnt(QueryCnt, root[l1 - 1], root[r1], l2, r2);
    };
    // for(int i = 1; i <= N; ++i)printf("%d ", idxMn[i]);
    // printf("\n");
    // for(int i = 1; i <= N; ++i)printf("%d ", idxMx[i]);
    // printf("\n");
    while(Q--){
        int S = read() + 1, T = read() + 1, L = read() + 1, R = read() + 1;
        for(int i = 19; i >= 0; --i){
            if(valMx[jmpMx[S][i]] >= L)S = jmpMx[S][i];
            if(valMn[jmpMn[T][i]] <= R)T = jmpMn[T][i];
        }
        // printf("After jumping S p = %d, val = %d\n", S, valMx[S]);
        // printf("After jumping T p = %d, val = %d\n", T, valMn[T]);
        // printf("faT p = %d, val = %d\n", jmpMn[T][0], valMn[jmpMn[T][0]]);
        // printf("Querying l1 = %d, r1 = %d, l2 = %d, r2 = %d\n", mnpMn[T], mxpMn[T], mnpMx[S], mxpMx[S]);
        printf("%d\n", QueryExist(mnpMn[T], mxpMn[T], mnpMx[S], mxpMx[S]) ? 1 : 0);
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