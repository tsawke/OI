#define _USE_MATH_DEFINES
#include <bits/stdc++.h>
#include <bitset>

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

int N, Q;
struct Edge{
    Edge* nxt;
    int to;
    OPNEW;
}ed[LIM << 1];
ROPNEW;
Edge* head[LIM];
int val[LIM];
int lst(0);

int dep[LIM], hson[LIM], top[LIM], fa[LIM], siz[LIM], dfn[LIM], idx[LIM];

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
    for(auto i = head[p]; i; i = i->nxt){
        if(SON == fa[p] || SON == hson[p])continue;
        dfs_make(SON, SON);
    }
}

class SegTree{
private:
    //sum is 199994
    bitset < 30010 > tr[120000];
    int base[LIM << 2];
    #define LS (p << 1)
    #define RS (LS | 1)
    #define MID ((gl + gr) >> 1)
public:
    SegTree(void){
        for(int i = 0; i <= 110000; ++i)tr[i].set();
    }
    void Pushup(int p, int gl, int gr){
        if(gl == gr)return;
        if(gr - gl + 1 == 2)return tr[p][base[LS]] = tr[p][base[RS]] = false, void();
        tr[p] = tr[LS] & tr[RS];
    }
    void Build(int p = 1, int gl = 1, int gr = N){
        if(gl == gr)return base[p] = val[idx[gl = gr]], void();
        Build(LS, gl, MID), Build(RS, MID + 1, gr);
        Pushup(p, gl, gr);
    }
    auto Query(int l, int r, int p = 1, int gl = 1, int gr = N){
        if(l <= gl && gr <= r)return tr[p];
        bitset < 30010 > ret; ret.set();
        if(l <= MID){
            if(MID - gl + 1 == 1)ret[base[LS]] = false;
            else ret &= Query(l, r, LS, gl, MID);
        }
        if(r >= MID + 1){
            if(gr - (MID + 1) + 1 == 1)ret[base[RS]] = false;
            else ret &= Query(l, r, RS, MID + 1, gr);
        }return ret;
    }
}st;
auto Query(int s, int t){
    bitset < 30010 > ret; ret.set();
    while(top[s] != top[t]){
        if(dep[top[s]] < dep[top[t]])swap(s, t);
        ret &= st.Query(dfn[top[s]], dfn[s]);
        s = fa[top[s]];
    }if(dep[s] < dep[t])swap(s, t);
    ret &= st.Query(dfn[t], dfn[s]);
    return ret;
}

int main(){
    freopen("tree.in", "r", stdin);
    freopen("tree.out", "w", stdout);
    N = read(), Q = read();
    for(int i = 1; i <= N; ++i)val[i] = read();
    for(int i = 1; i <= N - 1; ++i){
        int s = read(), t = read();
        head[s] = new Edge{head[s], t};
        head[t] = new Edge{head[t], s};
    }dfs_pre(), dfs_make();
    st.Build();
    while(Q--){
        int M = read();
        bitset < 30010 > ans; ans.set();
        for(int i = 1; i <= M; ++i){
            int s = read() ^ lst, t = read() ^ lst;
            ans &= Query(s, t);
        }
        int ans1 = (ans.size() - ans.count()), ans2 = ans._Find_first();
        lst = ans1 + ans2;
        printf("%d %d\n", ans1, ans2);
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
/*
10 1
0 0 1 0 0 2 2 0 0 0
2 3
1 2
4 5
3 4
7 8
6 7
5 6
9 10
8 9
4 1 7 3 3 1 1 9 3
*/