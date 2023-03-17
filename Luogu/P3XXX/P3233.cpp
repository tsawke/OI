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

#define S(i) (S.at(i - 1))
#define LIM (310000)
#define INF (0x3f3f3f3f)

template < typename T = int >
inline T read(void);

struct Edge{
    Edge* nxt;
    int to;
    OPNEW;
}ed[2100000];
ROPNEW;
Edge* head[LIM];
Edge* vhead[LIM];

int N, Q, M;
int dep[LIM], siz[LIM], dfn[LIM], fa[LIM], top[LIM], idx[LIM], hson[LIM];
int lg2[LIM], mndis[LIM], mnp[LIM], ans[LIM], qs[LIM];
int jmp[LIM][20]; //max 2^19
basic_string < int > S;
bitset < LIM > isKey;

int main(){
    memset(mndis, 0x3f, sizeof mndis);
    N = read();
    for(int i = 1; i <= N - 1; ++i){
        int s = read(), t = read();
        head[s] = new Edge{head[s], t};
        head[t] = new Edge{head[t], s};
    }
    auto Init = [](void)->void{
        lg2[1] = 0;
        for(int i = 2; i <= N; ++i)lg2[i] = lg2[i >> 1] + 1;
    }; Init();
    auto dfs_pre = [](auto&& self, int p = 1, int fa = 0)->void{
        dep[p] = dep[fa] + 1, ::fa[p] = fa, siz[p] = 1, jmp[p][0] = fa;
        for(auto i = head[p]; i; i = i->nxt){
            if(SON == fa)continue;
            self(self, SON, p);
            siz[p] += siz[SON];
            if(siz[SON] > siz[hson[p]])hson[p] = SON;
        }
    }; dfs_pre(dfs_pre);
    auto dfs_make = [](auto&& self, int p = 1, int top = 1)->void{
        static int cdfn(0);
        dfn[p] = ++cdfn, idx[cdfn] = p, ::top[p] = top;
        if(hson[p])self(self, hson[p], top);
        for(auto i = head[p]; i; i = i->nxt)
            if(SON != fa[p] && SON != hson[p])self(self, SON, SON);
    }; dfs_make(dfs_make);
    auto LCA = [](int s, int t)->int{
        while(top[s] != top[t]){
            if(dep[top[s]] < dep[top[t]])swap(s, t);
            s = fa[top[s]];
        }if(dep[s] < dep[t])swap(s, t);
        return t;
    };
    auto Handle = [](void)->void{
        for(int i = 1; i <= N; ++i)
            for(int j = 1; j <= 19; ++j)
                jmp[i][j] = jmp[jmp[i][j - 1]][j - 1];
    }; Handle();
    auto BuildVT = [LCA](void)->void{
        sort(S.begin(), S.end(), [](const int &a, const int &b)->bool{return dfn[a] < dfn[b];});
        int len = S.size();
        for(int i = 1; i <= len - 1; ++i)S += LCA(S(i), S(i + 1));
        sort(S.begin(), S.end(), [](const int &a, const int &b)->bool{return dfn[a] < dfn[b];});
        S.erase(unique(S.begin(), S.end()), S.end());
        for(auto it = S.begin(); it != S.end() && next(it) != S.end(); advance(it, 1)){
            int lca = LCA(*it, *next(it));
            vhead[lca] = new Edge{vhead[lca], *next(it)};
            vhead[*next(it)] = new Edge{vhead[*next(it)], lca};
        }
    };
    auto QueryChain = [](int s, int t)->void{
        int p = s;
        for(int i = lg2[dep[s]]; i >= 0; --i)
            if(dep[jmp[p][i]] > dep[t])p = jmp[p][i];
        ans[mnp[t]] -= siz[p];
        int spl = s;
        for(int i = lg2[dep[s]]; i >= 0; --i){
            int lens = dep[s] - dep[jmp[spl][i]] + mndis[s], lent = dep[jmp[spl][i]] - dep[t] + mndis[t];
            if(dep[jmp[spl][i]] > dep[t] && (lens < lent || (lens == lent && mnp[s] < mnp[t])))spl = jmp[spl][i];
        }ans[mnp[s]] += siz[spl] - siz[s], ans[mnp[t]] += siz[p] - siz[spl];
    };
    auto dfs_upward = [](auto&& self, int p = 1, int fa = 0)->void{
        for(auto i = vhead[p]; i; i = i->nxt){
            if(SON == fa)continue;
            self(self, SON, p);
            int cdis = dep[SON] - dep[p];
            if(mndis[SON] + cdis < mndis[p])mndis[p] = mndis[SON] + cdis, mnp[p] = mnp[SON];
            else if(mndis[SON] + cdis == mndis[p])mnp[p] = min(mnp[p], mnp[SON]);
        }if(isKey[p])mndis[p] = 0, mnp[p] = p;
    };
    auto dfs_downward = [QueryChain](auto&& self, int p = 1, int fa = 0)->void{
        for(auto i = vhead[p]; i; i = i->nxt){
            if(SON == fa)continue;
            int cdis = dep[SON] - dep[p];
            if(mndis[p] + cdis < mndis[SON])mndis[SON] = mndis[p] + cdis, mnp[SON] = mnp[p];
            else if(mndis[p] + cdis == mndis[SON])mnp[SON] = min(mnp[SON], mnp[p]);
            QueryChain(SON, p);
            self(self, SON, p);
        }ans[mnp[p]] += siz[p];
    };
    Q = read();
    while(Q--){
        for(auto p : S)vhead[p] = npt, mndis[p] = INF, mnp[p] = 0, ans[p] = 0, isKey[p] = false;
        S.clear();
        M = read();
        for(int i = 1; i <= M; ++i)S += (qs[i] = read()), isKey[S.back()] = true;
        if(!isKey[1])S += 1;
        BuildVT();
        dfs_upward(dfs_upward), dfs_downward(dfs_downward);
        for(int i = 1; i <= M; ++i)printf("%d%c", ans[qs[i]], i == M ? '\n' : ' ');
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