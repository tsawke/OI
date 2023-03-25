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
#define INFLL (0x3f3f3f3f3f3f3f3fll)
#define CLEAR(arr) (memset(arr, 0, sizeof arr))

template < typename T = int >
inline T read(void);

int N, M;
int Q, K, S;
int ccnt;
int curp(1);
int ind[LIM << 1];
int val[LIM << 1];
int idx[LIM];
ll dis[LIM];
ll lst;
int mnp[LIM << 1], mxp[LIM << 1];
int jmp[LIM << 2][20]; //max - 19
bitset < LIM > vis;
struct edge{int s, t; int val;};
basic_string < edge > edgs;

struct Edge{
    Edge* nxt;
    int to;
    int val;
    OPNEW;
}ed[41000000];
ROPNEW;
Edge* head[LIM << 1];
Edge* ghead[LIM];

class UnionFind{
private:
    int fa[LIM << 1];
public:
    void Clear(void){for(int i = 1; i <= (LIM << 1) - 10; ++i)fa[i] = i;}
    UnionFind(void){Clear();}
    int Find(int x){return x == fa[x] ? x : fa[x] = Find(fa[x]);}
    void Union(int s, int t){if(Find(s) != Find(t))fa[Find(s)] = Find(t);}
}uf;

class SegTree{
private:
    ll mn[LIM << 2];
    #define LS (p << 1)
    #define RS (LS | 1)
    #define MID ((gl + gr) >> 1)
public:
    void Clear(void){memset(mn, 0x3f, sizeof mn);}
    SegTree(void){memset(mn, 0x3f, sizeof mn);}
    void Pushup(int p){
        mn[p] = min(mn[LS], mn[RS]);
    }
    void Build(int p = 1, int gl = 1, int gr = N){
        if(gl == gr)return mn[p] = dis[idx[gl = gr]], void();
        Build(LS, gl, MID), Build(RS, MID + 1, gr);
        Pushup(p);
    }
    ll Query(int l, int r, int p = 1, int gl = 1, int gr = N){
        if(l <= gl && gr <= r)return mn[p];
        if(l > gr || r < gl)return INFLL;
        return min(Query(l, r, LS, gl, MID), Query(l, r, RS, MID + 1, gr));
    }
}st;

int main(){
    // freopen("return.in", "r", stdin);
    // freopen("return.out", "w", stdout);
    // freopen("in.txt", "r", stdin);
    // freopen("out.txt", "w", stdout);
    auto Dijkstra = [](void)->void{
        memset(dis, 0x3f, sizeof dis); vis.reset();
        priority_queue < pair < ll, int >, vector < pair < ll, int > >, greater < pair < ll, int > > > cur;
        dis[1] = 0; cur.push({dis[1], 1});
        while(!cur.empty()){
            int p = cur.top().second; cur.pop();
            if(vis[p])continue;
            vis[p] = true;
            for(auto i = ghead[p]; i; i = i->nxt)
                if(dis[p] + i->val < dis[SON])
                    dis[SON] = dis[p] + i->val, cur.push({dis[SON], SON});
        }
    };
    auto dfs = [](auto&& self, int p, int fa = 0)->void{
        mnp[p] = curp, jmp[p][0] = fa;
        for(auto i = head[p]; i; i = i->nxt)
            self(self, SON, p);
        if(!head[p])idx[curp++] = p;
        mxp[p] = curp - 1;
    };
    int T = read();
    while(T--){
        curp = 1;
        st.Clear(), uf.Clear(); edgs.clear();
        CLEAR(ind), CLEAR(val), CLEAR(idx), lst = 0, CLEAR(mnp), CLEAR(mxp), CLEAR(jmp), CLEAR(head), CLEAR(ghead);
        ccnt = N = read(), M = read();
        for(int i = 1; i <= M; ++i){
            int s = read(), t = read(), dis = read(), val = read();
            edgs += edge{s, t, val};
            ghead[s] = new Edge{ghead[s], t, dis};
            ghead[t] = new Edge{ghead[t], s, dis};
        }Dijkstra();
        sort(edgs.begin(), edgs.end(), [](const edge &a, const edge &b)->bool{return a.val > b.val;});
        for(auto [s, t, v] : edgs){
            int fs = uf.Find(s), ft = uf.Find(t);
            if(fs != ft){
                int fap = ++ccnt;
                val[fap] = v;
                ++ind[fs], ++ind[ft];
                head[fap] = new Edge{head[fap], fs};
                head[fap] = new Edge{head[fap], ft};
                uf.Union(fs, fap), uf.Union(ft, fap);
            }
        }
        for(int i = 1; i <= ccnt; ++i)if(!ind[i]){dfs(dfs, i); break;}
        for(int i = 1; i <= 19; ++i)
            for(int j = 1; j <= ccnt; ++j)
                jmp[j][i] = jmp[jmp[j][i - 1]][i - 1];
        st.Build();
        Q = read(), K = read(), S = read();
        while(Q--){
            int p = (read() + K * lst - 1) % N + 1, h = (read() + K * lst) % (S + 1);
            for(int i = 19; i >= 0; --i)
                if(val[jmp[p][i]] > h)p = jmp[p][i];
            ll ans = st.Query(mnp[p], mxp[p]);
            lst = ans;
            printf("%lld\n", ans);
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