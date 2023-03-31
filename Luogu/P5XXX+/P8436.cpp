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



template < typename T = int >
inline T read(void);

int N, M;
struct Edge{
    Edge* nxt;
    Edge* rev;
    int to;
    bool isBridge;
    OPNEW;
}ed[4100000];
ROPNEW;
Edge* head[510000];
bitset < 510000 > inS;
int dfn[510000], low[510000];
struct edge{int s, t;};
int SCC(0);
basic_string < int > pts[510000];
bitset < 510000 > vis;

int main(){
    N = read(), M = read();
    for(int i = 1; i <= M; ++i){
        int s = read(), t = read();
        if(s == t)continue;
        head[s] = new Edge{head[s], npt, t, false};
        head[t] = new Edge{head[t], npt, s, false};
        head[s]->rev = head[t], head[t]->rev = head[s];
    }
    auto Tarjan = [](auto&& self, int p, Edge* fa = npt)->void{
        static stack < int > cur;
        static int cdfn(0);
        dfn[p] = low[p] = ++cdfn;
        cur.push(p);
        // int cnt_son(0);
        for(auto i = head[p]; i; i = i->nxt){
            if(!dfn[SON]){
                // ++cnt_son;
                self(self, SON, i->rev);
                low[p] = min(low[p], low[SON]);
                if(low[SON] > dfn[p])i->isBridge = i->rev->isBridge = true;
            }else if(i != fa)low[p] = min(low[p], dfn[SON]);
        }
        // if(!fa && !cnt_son)pts[++SCC] += p;
    };
    for(int i = 1; i <= N; ++i)if(!dfn[i])Tarjan(Tarjan, i);
    auto dfs = [](auto&& self, int p)->void{
        pts[SCC] += p;
        vis[p] = true;
        for(auto i = head[p]; i; i = i->nxt)
            if(!vis[SON] && !i->isBridge)
                self(self, SON);
    };
    for(int i = 1; i <= N; ++i)if(!vis[i])++SCC, dfs(dfs, i);
    printf("%d\n", SCC);
    for(int i = 1; i <= SCC; ++i){
        printf("%d ", (int)pts[i].size());
        for(auto p : pts[i])printf("%d ", p);
        printf("\n");
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
    }ret *= flag;
    return ret;
}