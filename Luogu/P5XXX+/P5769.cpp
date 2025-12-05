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

#define INF (0x3f3f3f3f)
#define LIM (510)

template < typename T = int >
inline T read(void);

int N, M;
int S, T;
int P[LIM];
int Tim[LIM][LIM];
int dis[LIM][LIM];
int dep[LIM << 1];

struct Edge{
    Edge* nxt;
    Edge* rev;
    int to;
    int val;
    OPNEW;
}ed[610000];
ROPNEW;
Edge *head[LIM << 1], *cur[LIM << 1];

struct Line{int s, t, tim;}line[LIM];

int main(){
    memset(dis, 0x3f, sizeof dis);
    N = read(), M = read();
    S = (M << 1) + 1, T = (M << 1) + 2;
    for(int i = 1; i <= N; ++i)P[i] = read();
    for(int i = 1; i <= N; ++i)for(int j = 1; j <= N; ++j)Tim[i][j] = read();
    for(int i = 1; i <= N; ++i)for(int j = 1; j <= N; ++j)dis[i][j] = Tim[i][j] + P[j], dis[j][i] = Tim[j][i] + P[i];
    for(int i = 1; i <= N; ++i)dis[i][i] = 0;
    for(int p = 1; p <= N; ++p)
        for(int s = 1; s <= N; ++s)
            for(int t = 1; t <= N; ++t)
                dis[s][t] = min(dis[s][t], dis[s][p] + dis[p][t]);
    for(int i = 1; i <= M; ++i){
        int s = read(), t = read(), tim = read();
        line[i] = Line{s, t, tim};
    }
    auto AddEdge = [](int s, int t, int val = 1)->void{
        head[s] = new Edge{head[s], npt, t, val};
        head[t] = new Edge{head[t], npt, s, 0};
        head[s]->rev = head[t], head[t]->rev = head[s];
    };
    for(int i = 1; i <= M; ++i)
        for(int j = 1; j <= M; ++j)
            if(i != j && line[i].tim + Tim[line[i].s][line[i].t] + P[line[i].t] + dis[line[i].t][line[j].s] <= line[j].tim)
                AddEdge(i, j + M);
    for(int i = 1; i <= M; ++i)
        AddEdge(S, i), AddEdge(i + M, T);
    auto bfs = [](void)->bool{
        memset(dep, 0, sizeof dep); dep[T] = 1;
        copy(head + 1, head + (M << 1) + 2 + 1, cur + 1);
        queue < int > cur; cur.push(T);
        while(!cur.empty()){
            int p = cur.front(); cur.pop();
            for(auto i = head[p]; i; i = i->nxt)
                if(!dep[SON] && i->rev->val > 0)
                    dep[SON] = dep[p] + 1, cur.push(SON);
        }return dep[S];
    };
    auto dfs = [](auto&& self, int p = S, int flow = INF)->int{
        if(p == T)return flow;
        int mxflow(0);
        for(auto &i = cur[p]; i; i = i->nxt){
            if(dep[SON] != dep[p] - 1 || i->val <= 0)continue;
            auto cflow = self(self, SON, min(i->val, flow - mxflow));
            mxflow += cflow;
            i->val -= cflow, i->rev->val += cflow;
            if(mxflow == flow)break;
        }return mxflow;
    };
    auto Dinic = [bfs, dfs](void)->int{
        int ret(0), tmp;
        while(bfs())while((tmp = dfs(dfs)))ret += tmp;
        return ret;
    };
    printf("%d\n", M - Dinic());
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