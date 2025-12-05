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
#define LIMV (int)(1e9)
#define MID ((gl + gr) >> 1)
#define cnt(p) (p ? p->cnt : 0)

template < typename T = int >
inline T read(void);

int N, M, Q;
struct Node{
    Node *ls, *rs;
    int cnt;
    OPNEW;
}nd[LIM << 5];
ROPNEW_NODE;
Node* root[LIM];

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
basic_string < edge > edgs;

struct Edge{
    Edge* nxt;
    int to;
    OPNEW;
}ed[2100000];
ROPNEW;
Edge* head[LIM << 1];
// unordered_map < int, pair < int, int > > rng;
int ccnt;
int ind[LIM << 1];
int val[LIM << 1];
int mnp[LIM << 1], mxp[LIM << 1];
int jmp[LIM << 2][20]; //max - 18
int idx[LIM];

int main(){
    memset(val, 0x3f, sizeof val);
    auto Pushup = [](Node* p)->void{
        if(!p)return;
        p->cnt = cnt(p->ls) + cnt(p->rs);
    };
    auto Insert = [Pushup](auto&& self, int val, int cnt, Node* lst, int gl = 0, int gr = LIMV)->Node*{
        Node* p = lst ? new Node(*lst) : new Node{npt, npt, 0};
        if(gl == gr)return p->cnt += cnt, p;
        if(val <= MID)p->ls = self(self, val, cnt, p->ls, gl, MID);
        else p->rs = self(self, val, cnt, p->rs, MID + 1, gr);
        return Pushup(p), p;
    };
    auto QueryKth = [](auto&& self, int k, Node* px, Node* py, int gl = 0, int gr = LIMV)->int{
        // printf("Querying gl = %d, gr = %d, precnt = %d, curcnt = %d, k = %d\n", gl, gr, cnt(px), cnt(py), k);
        if(gl == gr)return k > (cnt(py) - cnt(px)) ? -1 : gl;
        if(!py)return -1;
        int leftCnt = (py ? cnt(py->ls) : 0) - (px ? cnt(px->ls) : 0);//printf("leftcnt = %d\n", leftCnt);
        if(k <= leftCnt)return self(self, k, px ? px->ls : npt, py->ls, gl, MID);
        else return self(self, k - leftCnt, px ? px->rs : npt, py->rs, MID + 1, gr);
    };
    ccnt = N = read(), M = read(), Q = read();
    // for(int i = 1; i <= N; ++i)root[i] = Insert(Insert, val[i] = read(), 1, root[i - 1]);
    for(int i = 1; i <= N; ++i)val[i] = read();
    for(int i = 1; i <= M; ++i){
        int s = read(), t = read(), v = read();
        edgs += edge{s, t, v};
    }sort(edgs.begin(), edgs.end(), [](const edge &a, const edge &b)->bool{return a.val < b.val;});
    auto Kruskal = [](void)->void{
        for(auto [s, t, v] : edgs){
            int fs = uf.Find(s), ft = uf.Find(t);
            if(fs != ft){
                int fap = ++ccnt;
                val[fap] = v;
                ++ind[fs], ++ind[ft];
                head[fap] = new Edge{head[fap], fs};
                head[fap] = new Edge{head[fap], ft};
                // printf("linking fa = %d, p = [%d, %d], val = %d\n", fap, fs, ft, v);
                uf.Union(fs, fap), uf.Union(ft, fap);
            }
        }
    }; Kruskal();
    auto dfs = [](auto&& self, int p, int fa = 0)->void{
        static int cur(1);
        jmp[p][0] = fa, mnp[p] = cur;
        for(auto i = head[p]; i; i = i->nxt)
            self(self, SON, p);
        if(!head[p])idx[cur++] = p;
        mxp[p] = cur - 1;
        // printf("Complete dfs [%d, %d], p = %d\n", mnp[p], mxp[p], p);
    };
    
    for(int i = 1; i <= ccnt; ++i)if(!ind[i]){dfs(dfs, i); break;}
    for(int i = 1; i <= N; ++i)root[i] = Insert(Insert, val[idx[i]], 1, root[i - 1]);//, printf("test mx i = %d, mx2 = %d, cnt = %d, lc = %d, rc = %d, val = %d\n", i, QueryKth(QueryKth, 2, npt, root[i]), root[i]->cnt, cnt(root[i]->ls), cnt(root[i]->rs), val[idx[i]]);
    for(int i = 1; i <= 18; ++i)
        for(int p = 1; p <= ccnt; ++p)
            jmp[p][i] = jmp[jmp[p][i - 1]][i - 1];
    while(Q--){
        int p = read(), lim = read(), k = read();
        for(int i = 18; i >= 0; --i)
            if(val[jmp[p][i]] <= lim)p = jmp[p][i];
        // printf("Querying l = %d, r = %d, k = %d\n", mnp[p], mxp[p], k);
        if(k > mxp[p] - mnp[p] + 1){printf("-1\n"); continue;}
        printf("%d\n", QueryKth(QueryKth, mxp[p] - mnp[p] + 1 - k + 1, root[mnp[p] - 1], root[mxp[p]]));
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