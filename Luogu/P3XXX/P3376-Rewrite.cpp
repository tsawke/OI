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

template < typename T = int >
inline T read(void);

int N, M, S, T;
struct Edge{
    Edge* nxt;
    Edge* rev;
    int to;
    int val;
    OPNEW;
}ed[11000];
ROPNEW;
Edge* head[11000];
Edge* cur[11000];
int dep[11000];

int main(){
    N = read(), M = read(), S = read(), T = read();
    for(int i = 1; i <= M; ++i){
        int s = read(), t = read(), v = read();
        if(s == t)continue;
        head[s] = new Edge{head[s], npt, t, v};
        head[t] = new Edge{head[t], npt, s, 0};
        head[s]->rev = head[t], head[t]->rev = head[s];
    }
    auto bfs = [](void)->bool{
        memset(dep, 0, sizeof dep); dep[T] = 1;
        copy(head + 1, head + N + 1, cur + 1);
        queue < int > q; q.push(T);
        while(!q.empty()){
            int p = q.front(); q.pop();
            for(auto i = head[p]; i; i = i->nxt)
                if(i->rev->val > 0 && !dep[SON])
                    dep[SON] = dep[p] + 1, q.push(SON);
        }return dep[S];
    };
    auto dfs = [](auto&& self, int p = S, int flow = numeric_limits < int >::max())->int{
        if(p == T)return flow;
        int cost(0);
        for(auto &i = cur[p]; i; i = i->nxt){
            if(dep[SON] == dep[p] - 1 && i->val > 0){
                int ccost = self(self, SON, min(i->val, flow - cost));
                cost += ccost;
                i->val -= ccost, i->rev->val += ccost;
                if(flow == cost)break;
            }
        }
        return cost;
    };
    auto Dinic = [dfs, bfs](void)->ll{
        ll ret(0), tmp;
        while(bfs())while((tmp = dfs(dfs)))ret += tmp;
        return ret;
    };printf("%lld\n", Dinic());
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