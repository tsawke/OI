#define _USE_MATH_DEFINES
#include <bits/stdc++.h>
#include <numeric>

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

#define INF (numeric_limits < int >::max())

template < typename T = int >
inline T read(void);

struct Edge{
    Edge* nxt;
    Edge* rev;
    int to;
    int val;
    int pri;
    OPNEW;
}ed[110000];
ROPNEW;
Edge *head[5100], *cur[5100];

int N, M, S, T;
int pri(0);
int dis[5100];
bitset < 5100 > inq;
bitset < 5100 > vis;

int main(){
    N = read(), M = read(), S = read(), T = read();
    auto AddEdge = [](int s, int t, int val, int pri)->void{
        head[s] = new Edge{head[s], npt, t, val, pri};
        head[t] = new Edge{head[t], npt, s, 0, -pri};
        head[s]->rev = head[t], head[t]->rev = head[s];
    };
    for(int i = 1; i <= M; ++i){
        int s = read(), t = read(), val = read(), pri = read();
        AddEdge(s, t, val, pri);
    }
    auto SPFA = [](void)->bool{
        copy(head, head + N + 1, cur);
        queue < int > cur; inq.reset(), fill(dis, dis + N + 1, INF);
        inq[T] = true; dis[T] = 0, cur.push(T);
        while(!cur.empty()){
            int p = cur.front(); cur.pop(); inq[p] = false;
            for(auto i = head[p]; i; i = i->nxt){
                if(i->rev->val > 0 && dis[p] + i->rev->pri < dis[SON]){
                    dis[SON] = dis[p] + i->rev->pri;
                    if(!inq[SON])cur.push(SON), inq[SON] = true;
                }
            }
        }return dis[S] != INF;
    };
    auto dfs = [](auto&& self, int p = S, int flow = INF)->int{
        if(p == T)return flow;
        int mxflow(0);
        vis[p] = true;
        for(auto &i = cur[p]; i; i = i->nxt){
            if(vis[SON] || dis[p] != dis[SON] + i->pri || i->val <= 0)continue;
            int cflow = self(self, SON, min(i->val, flow - mxflow));
            mxflow += cflow;
            i->val -= cflow, i->rev->val += cflow;
            pri += i->pri * cflow;
            if(mxflow == flow)break;
        }return vis[p] = false, mxflow;
    };
    auto MCMF = [SPFA, dfs](void)->int{
        int ret(0), tmp;
        while(SPFA())while((tmp = dfs(dfs)))ret += tmp;
        return ret;
    };auto flow = MCMF();
    printf("%d %d\n", flow, pri);
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