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
    OPNEW;
}ed[1100000];
ROPNEW;
Edge* head[510000];
bitset < 510000 > inS;
int dfn[510000], low[510000];
struct edge{int s, t;};
basic_string < edge > edgs;
set < int > pt;

int main(){
    N = read(), M = read();
    for(int i = 1; i <= M; ++i){
        int s = read(), t = read();
        if(s == t)continue;
        edgs += {s, t};
        head[s] = new Edge{head[s], npt, t};
        head[t] = new Edge{head[t], npt, s};
        head[s]->rev = head[t], head[t]->rev = head[s];
    }
    auto Tarjan = [](auto&& self, int p, int rt, Edge* fa = npt)->void{
        static stack < int > cur;
        static int cdfn(0);
        dfn[p] = low[p] = ++cdfn;
        cur.push(p), inS[p] = true;
        int cnt_rt(0);
        for(auto i = head[p]; i; i = i->nxt){
            // printf("in dfs p = %d, son = %d\n", p, SON);
            if(!dfn[SON]){
                self(self, SON, rt, i->rev);
                low[p] = min(low[p], low[SON]);
                if(p != rt && low[SON] >= dfn[p])pt.insert(p);
                if(p == rt)++cnt_rt;
            }else if(i != fa)low[p] = min(low[p], dfn[SON]);
        }
        // printf("p = %d, cnt = %d\n", p, cnt_rt);
        if(p == rt && cnt_rt >= 2)pt.insert(p);
    };
    for(int i = 1; i <= N; ++i)if(!dfn[i])Tarjan(Tarjan, i, i);
    printf("%d\n", (int)pt.size());
    for(auto p : pt)printf("%d\n", p);
    // for(auto edg : edgs)if((bridge.count({edg.s, edg.t}) || bridge.count({edg.t, edg.s})))printf("%d %d\n", edg.s, edg.t);
    // printf("%d\n", (int)bridge.size());
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