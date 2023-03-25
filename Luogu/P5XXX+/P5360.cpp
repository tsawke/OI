#define _USE_MATH_DEFINES
#include <bits/stdc++.h>

#define PI M_PI
#define E M_E
#define npt nullptr
#define SON i->to
#define OPNEW void* operator new(size_t)
#define ROPNEW void* Edge::operator new(size_t){static Edge* P = ed; if(P - ed > 20100000)P = ed; return P++;}
#define ROPNEW_NODE void* Node::operator new(size_t){static Node* P = nd; return P++;}

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

int N, M, Q;
unsigned int SA, SB, SC;
int lim;
struct edge{int s, t; int val;};
int nxtR[110][11000], nxtL[110][11000];

struct Edge{
    Edge* nxt;
    int to;
    int val;
    OPNEW;
}ed[21000000];
ROPNEW;

class VirtualTree{
private:
    Edge* head[1100];
public:
    bitset < 1100 > isKey;
    bitset < 1100 > invt;
    basic_string < edge > edgs;
    void Clear(void){memset(head, 0, sizeof head);  isKey.reset(); invt.reset(); edgs.clear();}
    VirtualTree(void){Clear();}
    void AddEdge(int s, int t, int val){
        head[s] = new Edge{head[s], t, val};
        head[t] = new Edge{head[t], s, val};
    }
    bool dfs_pre(int p = 1, int fa = 0){
        int cnt(0);
        for(auto i = head[p]; i; i = i->nxt)
            if(SON != fa)cnt += dfs_pre(SON, p);
        invt[p] = isKey[p] | (cnt >= 2);
        return invt[p] | bool(cnt);
    }
    void dfs_link(int p = 1, int lst = 0, int mxv = 0, int fa = 0){
        if(invt[p]){
            if(lst)edgs += edge{lst, p, mxv};
            lst = p, mxv = 0;
        }
        for(auto i = head[p]; i; i = i->nxt)
            if(SON != fa)dfs_link(SON, lst, max(mxv, i->val), p);
    }
}vt;

class MST{
private:
public:
    int tot;
    ll sum;
    basic_string < edge > edgs;
    void Clear(void){edgs.clear(); sum = 0; tot = 0;}
    MST(void){Clear();}
    ll Query(void){ll ret(sum); for(auto edg : edgs)ret += edg.val; return ret;}
}pre[11000], suf[11000];

class UnionFind{
private:
    int fa[1100];
public:
    void Clear(void){for(int i = 0; i <= 1010; ++i)fa[i] = i;}
    UnionFind(void){Clear();}
    int Find(int x){return x == fa[x] ? x : fa[x] = Find(fa[x]);}
    void Union(int s, int t){if(Find(s) != Find(t))fa[Find(s)] = Find(t);}
}uf;

int main(){
    N = read(), M = read();
    auto GetWeight = [](void)->int{SA ^= SA << 16; SA ^= SA >> 5; SA ^= SA << 1; unsigned int t = SA;SA = SB;SB = SC;SC ^= t ^ SA;return SC % lim + 1;};
    auto Gen = [GetWeight](void)->void{
        scanf("%u%u%u%d", &SA, &SB, &SC, &lim);
        for(int i = 1; i <= N; ++i)for(int j = 1; j <= M; ++j)nxtR[i][j] = GetWeight();
        for(int i = 1; i < N; ++i)for(int j = 1; j <= M; ++j)nxtL[i][j] = GetWeight();
    }; Gen();
    auto MergeMST = [](const MST &A, const MST &B, int idx)->auto{
        unordered_map < int, int > mp;
        ll cur(0);
        MST ret;
        ret.edgs += A.edgs;
        for(auto edg : B.edgs)ret.edgs += edge{edg.s + A.tot, edg.t + A.tot, edg.val};
        for(int i = 1; i <= N; ++i)ret.edgs += edge{A.tot - N + i, A.tot + i, nxtR[i][idx]};
        sort(ret.edgs.begin(), ret.edgs.end(), [](const edge &a, const edge &b)->bool{return a.val < b.val;});
        uf.Clear(), vt.Clear();
        for(int i = 1; i <= N; ++i)vt.isKey[i] = vt.isKey[A.tot + B.tot - i + 1] = true;
        for(auto edg : ret.edgs)
            if(uf.Find(edg.s) != uf.Find(edg.t))vt.AddEdge(edg.s, edg.t, edg.val), uf.Union(edg.s, edg.t), cur += edg.val;
        vt.dfs_pre(), vt.dfs_link();
        ret.edgs = vt.edgs; ret.tot = 0;
        for(int i = 1; i <= A.tot + B.tot; ++i)if(vt.invt[i])mp[i] = ++ret.tot;
        for(auto &edg : ret.edgs)edg.s = mp[edg.s], edg.t = mp[edg.t], cur -= edg.val;
        ret.sum = A.sum + B.sum + cur;
        return ret;
    };
    for(int j = 1; j <= M; ++j)for(int i = 1; i < N; ++i)
        pre[j].edgs += edge{i, i + 1, nxtL[i][j]}, suf[j].edgs += edge{i, i + 1, nxtL[i][j]}, suf[j].tot = pre[j].tot = N;
    for(int j = 2; j < M; ++j)pre[j] = MergeMST(pre[j - 1], pre[j], j - 1);
    for(int j = M - 1; j > 1; --j)suf[j] = MergeMST(suf[j], suf[j + 1], j);
    Q = read();
    while(Q--){
        int l = read(), r = read();
        printf("%lld\n", MergeMST(suf[r + 1], pre[l - 1], M).Query());
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