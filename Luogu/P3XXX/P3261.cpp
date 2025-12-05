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
int idx[310000];
ll H[310000];
bool pat[310000]; ll val[310000];
ll S[310000];
int beg[310000];
ll add[310000], mul[310000];
int cnt[310000];
int dis[310000];
int dep[310000];
priority_queue < pair < ld, int >, vector < pair < ld, int > >, greater < pair < ld, int > > > sol[310000];
struct Edge{
    Edge* nxt;
    int to;
    OPNEW;
}ed[610000];
ROPNEW;
Edge* head[310000];

int main(){
    N = read(), M = read();
    for(int i = 1; i <= N; ++i)H[i] = read < ll >();
    for(int i = 1; i <= N; ++i)idx[i] = i, add[i] = 0, mul[i] = 1;
    dep[1] = 1;
    for(int i = 2; i <= N; ++i){
        int s = read(), t = i;
        pat[i] = read(), val[i] = read < ll >();
        head[s] = new Edge{head[s], t};
        head[t] = new Edge{head[t], s};
    }
    for(int i = 1; i <= M; ++i){
        S[i] = read < ll >(), beg[i] = read();
        sol[beg[i]].push({S[i], i});
    }
    auto dfs = [](auto&& self, int p = 1, int fa = 0)->void{
        dep[p] = dep[fa] + 1;
        for(auto i = head[p]; i; i = i->nxt){
            if(SON == fa)continue;
            self(self, SON, p);
            if(sol[idx[p]].size() < sol[idx[SON]].size())swap(idx[p], idx[SON]);
            while(!sol[idx[SON]].empty()){
                auto [tp, tp_idx] = sol[idx[SON]].top(); sol[idx[SON]].pop();
                (tp *= mul[idx[SON]]) += add[idx[SON]];
                (tp -= add[idx[p]]) /= (ld)mul[idx[p]];
                sol[idx[p]].push({tp, tp_idx});
            }
        }
        while(!sol[idx[p]].empty()){
            auto [tp, tp_idx] = sol[idx[p]].top();
            (tp *= mul[idx[p]]) += add[idx[p]];
            if(tp < (ld)H[p]){
                cnt[p]++;
                dis[tp_idx] = dep[beg[tp_idx]] - dep[p];
                sol[idx[p]].pop();
            }else break;
        }
        if(p == 1){
            while(!sol[idx[p]].empty()){
                auto [tp, tp_idx] = sol[idx[p]].top(); sol[idx[p]].pop();
                dis[tp_idx] = dep[beg[tp_idx]] - dep[p] + 1;
            }
        }
        pat[p] ? (mul[idx[p]] *= val[p], add[idx[p]] *= val[p]) : add[idx[p]] += val[p];
    }; dfs(dfs);
    for(int i = 1; i <= N; ++i)printf("%d\n", cnt[i]);
    for(int i = 1; i <= M; ++i)printf("%d\n", dis[i]);
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