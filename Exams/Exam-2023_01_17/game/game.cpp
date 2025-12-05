#define _USE_MATH_DEFINES
#include <bits/stdc++.h>

#define PI M_PI
#define E M_E
#define npt nullptr
#define SON i->to
#define OPNEW void* operator new(size_t)
#define ROPNEW void* Edge::operator new(size_t){static Edge* P = ed; return P++;}

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

struct Edge{
    Edge* nxt;
    int to;
    OPNEW;
}ed[210000];
ROPNEW;
Edge* head[110000];

int N, Q;
ll w[110000];
int dep[110000], dfn[110000], hson[110000], siz[110000], ffa[110000], tp[110000], idx[110000];

void dfs_pre(int p = 1, int fa = 0){
    dep[p] = dep[fa] + 1;
    siz[p] = 1;
    ffa[p] = fa;
    for(auto i = head[p]; i; i = i->nxt){
        if(SON == fa)continue;
        dfs_pre(SON, p);
        siz[p] += siz[SON];
        if(siz[hson[p]] < siz[SON])hson[p] = SON;
    }
}
void dfs_make(int p = 1, int top = 1){
    tp[p] = top;
    static int cdfn(0);
    dfn[p] = ++cdfn;
    idx[cdfn] = p;
    if(hson[p])dfs_make(hson[p], top);
    for(auto i = head[p]; i; i = i->nxt)
        if(SON != ffa[p] && SON != hson[p])
            dfs_make(SON, SON);
}

struct Node{
    ll v[5], vu[5]; //v_max_with_2, v_unique
    Node(void){memset(v, 0, sizeof v), memset(vu, 0, sizeof vu);}
    friend Node operator + (const Node &a, const Node &b){
        Node ret;
        basic_string < ll > values;
        for(int i = 1; i <= 4; ++i){
            if(a.v[i])values += a.v[i];
            if(b.v[i])values += b.v[i];
        }sort(values.begin(), values.end(), greater < ll >());
        for(auto it = values.begin(); it != values.end() && next(it) != values.end() && next(it, 2) != values.end();)
            if(*it == *next(it) && *next(it) == *next(it, 2))it = values.erase(it);
            else advance(it, 1);
        for(int i = 1; i <= 4; ++i)
            ret.v[i] = (int)values.size() >= i ? values.at(i - 1) : 0;
        values.clear();
        for(int i = 1; i <= 4; ++i){
            if(a.vu[i])values += a.vu[i];
            if(b.vu[i])values += b.vu[i];
        }sort(values.begin(), values.end(), greater < ll >());
        values.erase(unique(values.begin(), values.end()), values.end());
        for(int i = 1; i <= 4; ++i)
            ret.vu[i] = (int)values.size() >= i ? values.at(i - 1) : 0;
        return ret;
    }
};

class SegTree{
private:
    Node mx[110000 << 2];
    #define LS (p << 1)
    #define RS (LS | 1)
    #define MID ((gl + gr) >> 1)
public:
    void Pushup(int p){
        mx[p] = mx[LS] + mx[RS];
    }
    void Build(int p = 1, int gl = 1, int gr = N){
        if(gl == gr)return mx[p].v[1] = mx[p].vu[1] = w[idx[gl = gr]], void();
        Build(LS, gl, MID), Build(RS, MID + 1, gr);
        Pushup(p);
    }
    void Modify(int id, int v, int p = 1, int gl = 1, int gr = N){//modify dfn////////////////////////////////
        if(gl == gr)return mx[p].v[1] += v, mx[p].vu[1] += v, void();
        if(id <= MID)Modify(id, v, LS, gl, MID);
        else Modify(id, v, RS, MID + 1, gr);
        Pushup(p);
    }
    Node Query(int l, int r, int p = 1, int gl = 1, int gr = N){
        // printf("Querying l = %d, r = %d\n", l, r);
        if(l <= gl && gr <= r)return mx[p];
        if(gr < l || r < gl)return Node();
        return Query(l, r, LS, gl, MID) + Query(l, r, RS, MID + 1, gr);
    }
}st;

void Make(int s, int t){
    Node cur;
    while(tp[s] != tp[t]){
        if(dep[tp[s]] < dep[tp[t]])swap(s, t);
        cur = cur + st.Query(dfn[tp[s]], dfn[s]);
        s = ffa[tp[s]];
    }if(dep[s] < dep[t])swap(s, t);
    cur = cur + st.Query(dfn[t], dfn[s]);
    if(!cur.vu[1] || !cur.vu[2]){printf("-1\n"); return;}
    Node ret = st.Query(1, N);
    basic_string < ll > tmp;
    for(int i = 1; i <= 4; ++i)if(ret.v[i])tmp += ret.v[i];
    for(int i = 1; i <= 2; ++i)
        if(find(tmp.begin(), tmp.end(), cur.vu[i]) != tmp.end())
            tmp.erase(find(tmp.begin(), tmp.end(), cur.vu[i]));
    if((int)tmp.size() < 2 || ((int)tmp.size() == 2 && tmp.at(0) == tmp.at(1))){printf("-1\n"); return;}
    printf("%lld %lld\n", cur.vu[2], tmp.at(0) == tmp.at(1) ? tmp.at(2) : tmp.at(1));
    // for(int i = 1; i <= 4; ++i)printf("mxchain mxvu[%d] = %lld\n", i, cur.vu[i]);
    // for(int i = 1; i <= 4; ++i)printf("mxtree mxv[%d] = %lld\n", i, ret.v[i]);
}

int main(){
    freopen("game.in", "r", stdin);
    freopen("game.out", "w", stdout);
    N = read();
    for(int i = 1; i <= N - 1; ++i){
        int s = read(), t = read();
        head[s] = new Edge{head[s], t};
        head[t] = new Edge{head[t], s};
    }dfs_pre(), dfs_make();
    for(int i = 1; i <= N; ++i)w[i] = read();
    st.Build();
    Q = read();
    while(Q--){
        int opt = read(), x = read(), y = read();
        if(opt == 0)st.Modify(dfn[x], y);
        else Make(x, y);
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

7
1 2
2 3
2 4
1 5
5 6
5 7
5 4 3 2 1 4 3
6
1 3 4
1 2 5
1 2 1
0 2 1
1 2 5
1 2 1

*/