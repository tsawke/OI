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

int N, M, K;
struct Edge{
    Edge* nxt;
    int to;
    bool val;
    OPNEW;
}ed[410000];
ROPNEW;
Edge* head[210000];

int dis[210000][2];
bitset < 210000 > ctrl;

int main(){
    memset(dis, -1, sizeof dis);
    N = read(), M = read(), K = read();
    for(int i = 1; i <= M; ++i){
        int s = read(), t = read(); bool v = read();
        head[s] = new Edge{head[s], t, v};
        head[t] = new Edge{head[t], s, v};
    }
    for(int i = 1; i <= K; ++i)ctrl[read()] = true;
    auto bfs = [](void)->void{
        dis[1][0] = 0;
        queue < pair < int, bool > > cur; cur.push({1, 0});
        while(!cur.empty()){
            auto [p, status] = cur.front(); cur.pop();
            for(auto i = head[p]; i; i = i->nxt)
                if(status ^ i->val && !~dis[SON][status])dis[SON][status] = dis[p][status] + 1, cur.push({SON, status});
            if(ctrl[p])for(auto i = head[p]; i; i = i->nxt)
                if(status ^ i->val ^ 1 && !~dis[SON][status ^ 1])dis[SON][status ^ 1] = dis[p][status] + 1, cur.push({SON, status ^ 1});
        }
    }; bfs();
    int ans = min(~dis[N][0] ? dis[N][0] : numeric_limits < int >::max(), ~dis[N][1] ? dis[N][1] : numeric_limits < int >::max());
    printf("%d\n", ans == numeric_limits < int >::max() ? -1 : ans);
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