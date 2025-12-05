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

template < typename T = int >
inline T read(void);

struct Edge{
    Edge* nxt;
    int to;
    OPNEW;
}ed[610000];
ROPNEW;
Edge* head[210000];
Edge* vhead[210000];

int N, Q;
int ans(0);
int dep[210000], dfn[210000], idx[210000], top[210000], fa[210000], hson[210000], siz[210000];
basic_string < int > S;
bitset < 210000 > isKey;

void dfs_pre(int p = 1, int fa = 0){
    ::fa[p] = fa;
    siz[p] = 1;
    dep[p] = dep[fa] + 1;
    for(auto i = head[p]; i; i = i->nxt){
        if(SON == fa)continue;
        dfs_pre(SON, p);
        siz[p] += siz[SON];
        if(siz[SON] > siz[hson[p]])hson[p] = SON;
    }
}
void dfs_make(int p = 1, int top = 1){
    static int cdfn(0);
    dfn[p] = ++cdfn;
    idx[cdfn] = p;
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
void LinkVT(int s, int t){
    vhead[s] = new Edge{vhead[s], t};
    vhead[t] = new Edge{vhead[t], s};
}
void BuildVT(void){
    int len = S.size();
    sort(S.begin(), S.end(), [](const int &a, const int &b){return dfn[a] < dfn[b];});
    for(int i = 1; i < len; ++i)S += LCA(S(i), S(i + 1));
    sort(S.begin(), S.end(), [](const int &a, const int &b){return dfn[a] < dfn[b];});
    S.erase(unique(S.begin(), S.end()), S.end());
    for(auto it = S.begin(); it != prev(S.end()); ++it)LinkVT(*next(it), LCA(*it, *next(it)));
}
void dfs_vt(int p, int fa = 0){
    int cnt(0);
    for(auto i = vhead[p]; i; i = i->nxt)
        if(SON != fa)dfs_vt(SON, p), cnt += isKey[SON];
    if(isKey[p] && cnt)ans += cnt;
    if(!isKey[p] && cnt >= 2)++ans;
    if(!isKey[p] && cnt == 1)isKey[p] = true;
}

int main(){
    N = read();
    for(int i = 1; i <= N - 1; ++i){
        int s = read(), t = read();
        head[s] = new Edge{head[s], t};
        head[t] = new Edge{head[t], s};
    }dfs_pre(), dfs_make();
    Q = read();
    while(Q--){
        ans = 0;
        for(auto p : S)vhead[p] = npt, isKey[p] = false;
        S.clear();
        int cnt = read();
        while(cnt--){int p = read(); S += p, isKey[p] = true;}
        bool flag(false);
        for(auto p : S)if(isKey[fa[p]]){printf("-1\n"); flag = true; break;}
        if(flag)continue;
        BuildVT();
        dfs_vt(*S.begin());
        printf("%d\n", ans);
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