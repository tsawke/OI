#define _USE_MATH_DEFINES
#include <bits/stdc++.h>

#define PI M_PI
#define E M_E
#define npt nullptr
#define SON i->to
#define OPNEW void* operator new(size_t)
#define ROPNEW void* Edge::operator new(size_t){static Edge* P = ed; if(P - ed >= 2010000)P = ed; return P++;}
#define ROPNEW_NODE void* Node::operator new(size_t){static Node* P = nd; return P++;}

using namespace std;

mt19937 rnd(random_device{}());
int rndd(int l, int r){return rnd() % (r - l + 1) + l;}
bool rnddd(int x){return rndd(1, 100) <= x;}

typedef unsigned int uint;
typedef unsigned long long unll;
typedef long long ll;
typedef long double ld;

#define EPS (1e-3)
#define SP ShortestPath
#define NF NetworkFlow
// #define INFDB (numeric_limits < double >::max() / 2.0 - 114.514)
#define INFDB (114514123.0)

template < typename T = int >
inline T read(void);

int N, M;
int Nx, Mx;

namespace NetworkFlow{
    double dis[210];
    struct Edge{
        Edge* nxt;
        Edge* rev;
        int to;
        double val;
        OPNEW;
    }ed[110000];
    ROPNEW;
    Edge *head[210], *cur[210];
    int S, T;
    int dep[210];
    void AddEdge(int s, int t, double val){
        head[s] = new Edge{head[s], npt, t, val};
        head[t] = new Edge{head[t], npt, s, 0};
        head[s]->rev = head[t], head[t]->rev = head[s];
    }
    auto Make(void){
        S = Nx + 1, T = Nx + 2;
        for(int i = 1; i <= Nx; i += 2)AddEdge(S, i, dis[i]);
        for(int i = 2; i <= Nx; i += 2)AddEdge(i, T, dis[i]);
        auto bfs = [](void)->bool{
            memset(dep, 0, sizeof dep);
            copy(head + 1, head + Nx + 2 + 1, cur + 1);
            queue < int > cur;
            dep[T] = 1; cur.push(T);
            while(!cur.empty()){
                int p = cur.front(); cur.pop();
                for(auto i = head[p]; i; i = i->nxt)
                    if(!dep[SON] && i->rev->val > 0)
                        dep[SON] = dep[p] + 1, cur.push(SON);
            }
            return dep[S];
        };
        auto dfs = [](auto&& self, int p = S, double flow = INFDB)->double{
            if(p == T)return flow;
            double mxflow(0.0);
            for(auto &i = cur[p]; i; i = i->nxt){
                if(dep[SON] == dep[p] - 1 && i->val > EPS){
                    auto cflow = self(self, SON, min(i->val, flow - mxflow));
                    i->val -= cflow, i->rev->val += cflow;
                    mxflow += cflow;
                    if(mxflow == flow)break;
                }
            }return mxflow;
        };
        auto Dinic = [dfs, bfs](void){
            double ret(0.0), tmp;
            while(bfs())while(fabs(tmp = dfs(dfs)) >= EPS)ret += tmp;
            return ret;
        };
        printf("%.1lf\n", Dinic());
    }
}

namespace ShortestPath{
    struct Edge{
        Edge* nxt;
        int to;
        double val;
        OPNEW;
    }ed[2100000];
    ROPNEW;
    Edge* head[710];
    int ind[710];
    double dis[710];
    struct edge{int s, t; int S, T;};
    basic_string < edge > edgs;
    void Make(void){
        for(int i = 1; i <= Nx; ++i){
            double l = EPS, r = 20.0, ans(-1.0);
            while(fabs(l - r) > EPS){
                double mid = (l + r) / 2.0;
                memset(head, 0, sizeof head);
                memset(ind, 0, sizeof ind);
                fill(dis + 1, dis + N + 1, INFDB);
                for(auto [s, t, S, T] : edgs)
                    head[s] = new Edge{head[s], t, T - S * mid}, ++ind[t];
                static auto Topo = [](int endp)->bool{
                    dis[N] = 0.0;
                    queue < int > cur;
                    for(int i = 1; i <= N; ++i)if(!ind[i])cur.push(i);
                    while(!cur.empty()){
                        int p = cur.front(); cur.pop();
                        for(auto i = head[p]; i; i = i->nxt){
                            dis[SON] = min(dis[SON], dis[p] + i->val);
                            --ind[SON];
                            if(!ind[SON])cur.push(SON);
                        }
                    }return dis[endp] > -EPS;
                };
                if(Topo(i))ans = mid, l = mid + EPS;
                else ans = mid, r = mid - EPS;
            }NF::dis[i] = ans > 10 + EPS ? INFDB : ans;
        }
    }
}

int main(){
    // freopen("in.txt", "r", stdin);
    N = read(), M = read();
    for(int i = 1; i <= M; ++i){
        int s = read(), t = read(), T = read(), S = read();
        SP::edgs += SP::edge{s, t, S, T};
    }Mx = read(), Nx = read();
    SP::Make();
    // for(int i = 1; i <= Nx; ++i)printf("dis[%d] = %.3lf\n", i, NF::dis[i]);
    for(int i = 1; i <= Mx; ++i){
        int s = read(), t = read();
        if(NF::dis[s] >= INFDB && NF::dis[t] >= INFDB)printf("-1\n"), exit(0);
        NF::AddEdge(s, t, INFDB);
    }NF::Make();
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