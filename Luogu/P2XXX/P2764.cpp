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

int N, M;
struct Edge{
    Edge* nxt;
    Edge* rev;
    int to;
    int val;
    OPNEW;
}ed[110000];
ROPNEW;
Edge *head[320], *cur[320];
int nxt[150];
int ind[150];
int S, T;
int dep[320];

int main(){
    N = read(), M = read();
    S = (N + 1) << 1, T = S | 1;
    auto AddEdge = [](int s, int t, int val = 1)->void{
        head[s] = new Edge{head[s], npt, t, val};
        head[t] = new Edge{head[t], npt, s, 0};
        head[s]->rev = head[t], head[t]->rev = head[s];
    };
    for(int i = 1; i <= M; ++i){
        int s = read(), t = read();
        AddEdge(s << 1, (t << 1) | 1);
    }
    for(int i = 1; i <= N; ++i)
        AddEdge(S, i << 1), AddEdge((i << 1) | 1, T);
    auto bfs = [](void)->bool{
        memset(dep, 0, sizeof dep); dep[T] = 1;
        copy(head + 1, head + (((N + 1) << 1) | 1) + 1, cur + 1);
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
    };int ret = Dinic();
    for(int p = 1; p <= N; ++p)
        for(auto i = head[p << 1]; i; i = i->nxt)
            if(i->val == 0 && (1 << 1) <= SON && SON <= ((N << 1) | 1))
                ++ind[SON >> 1], nxt[p] = SON >> 1;
    for(int p = 1; p <= N; ++p)
        if(!ind[p]){
            int curp = p;
            while(curp)printf("%d ", curp), curp = nxt[curp];
            printf("\n");
        }
    printf("%d\n", N - ret);
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