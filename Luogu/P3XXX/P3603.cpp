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

int N, Q, F;
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
    //sum is 262143
    bitset < 30010 > tr[120000];
    pair < int, int > base[LIM << 2];
    #define LS (p << 1)
    #define RS (LS | 1)
    #define MID ((gl + gr) >> 1)
public:
    void Pushup(int p, int gl, int gr){
        if(gr - gl + 1 <= 2)return;
        if(MID - gl + 1 == 1)tr[p][base[LS].first] = true;
        else if(MID - gl + 1 == 2)tr[p][base[LS].first] = tr[p][base[LS].second] = true;
        else tr[p] |= tr[LS];
        if(gr - (MID + 1) + 1 == 1)tr[p][base[RS].first] = true;
        else if(gr - (MID + 1) + 1 == 2)tr[p][base[RS].first] = tr[p][base[RS].second] = true;
        else tr[p] |= tr[RS];
    }
    void Build(int p = 1, int gl = 1, int gr = N){
        if(gl == gr)return base[p] = {val[idx[gl = gr]], -1}, void();
        if(gr - gl + 1 == 2)base[p] = {val[idx[gl]], val[idx[gr]]};
        Build(LS, gl, MID), Build(RS, MID + 1, gr);
        Pushup(p, gl, gr);
    }
    auto Query(int l, int r, int p = 1, int gl = 1, int gr = N){
        bitset < 30010 > ret; ret.reset();
        if(l <= gl && gr <= r){
            if(gl == gr){ret[base[p].first] = true; return ret;}
            if(gr - gl + 1 == 2){ret[base[p].first] = ret[base[p].second] = true; return ret;}
            return tr[p];
        }
        if(l <= MID)ret |= Query(l, r, LS, gl, MID);
        if(r >= MID + 1)ret |= Query(l, r, RS, MID + 1, gr);
        return ret;
    }
}st;

auto Query(int s, int t){
    bitset < 30010 > ret; ret.reset();
    while(top[s] != top[t]){
        if(dep[top[s]] < dep[top[t]])swap(s, t);
        ret |= st.Query(dfn[top[s]], dfn[s]);
        s = fa[top[s]];
    }if(dep[s] < dep[t])swap(s, t);
    ret |= st.Query(dfn[t], dfn[s]);
    return ret;
}

int main(){
    N = read(), Q = read(), F = read();
    for(int i = 1; i <= N; ++i)val[i] = read();
    for(int i = 1; i <= N - 1; ++i){
        int s = read(), t = read();
        head[s] = new Edge{head[s], t};
        head[t] = new Edge{head[t], s};
    }dfs_pre(), dfs_make();
    st.Build();
    while(Q--){
        int M = read();
        bitset < 30010 > ans; ans.reset();
        for(int i = 1; i <= M; ++i){
            int s = read() ^ (lst * F), t = read() ^ (lst * F);
            ans |= Query(s, t);
        }
        int ans1 = ans.count(), ans2 = (~ans)._Find_first();
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