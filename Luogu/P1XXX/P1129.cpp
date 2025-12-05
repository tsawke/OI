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

struct Edge{
    Edge* nxt;
    Edge* rev;
    int to;
    int val;
    OPNEW;
}ed[2100000];
ROPNEW;
Edge* head[81000];
Edge* curh[81000];
int N;
int S, T;
int dep[81000];

int main(){
    auto bfs = [](void)->bool{
        memset(dep, 0, sizeof dep);
        copy(head + 1, head + (N << 1) + 2 + 1, curh + 1);
        queue < int > cur;
        cur.push(T); dep[T] = 1;
        while(!cur.empty()){
            int p = cur.front(); cur.pop();
            for(auto i = head[p]; i; i = i->nxt)
                if(i->rev->val > 0 && !dep[SON])
                    dep[SON] = dep[p] + 1, cur.push(SON);
        }return dep[S];
    };
    auto dfs = [](auto&& self, int p = S, int flow = INT_MAX)->int{
        if(p == T)return flow;
        int mxflow(0);
        for(auto &i = curh[p]; i; i = i->nxt){
            if(i->val <= 0 || dep[SON] != dep[p] - 1)continue;
            int cflow = self(self, SON, min(i->val, flow - mxflow));
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
    int Ts = read();
    while(Ts--){
        memset(head, 0, sizeof head);
        N = read();
        S = (N << 1) | 1, T = S + 1;
        auto add = [](int s, int t, int v)->void{
            head[s] = new Edge{head[s], npt, t, v};
            head[t] = new Edge{head[t], npt, s, 0};
            head[s]->rev = head[t], head[t]->rev = head[s];
        };
        for(int i = 1; i <= N; ++i)add(S, i, 1), add(i + N, T, 1);
        for(int i = 1; i <= N; ++i)
            for(int j = 1; j <= N; ++j)
                if(read())add(i, j + N, 1);
        auto ret = Dinic();
        printf("%s\n", ret == N ? "Yes" : "No");
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