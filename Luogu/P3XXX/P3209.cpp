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
    int to;
    OPNEW;
}ed[1100000];
ROPNEW;
Edge* head[1410];

// int tot(0);
// bitset < 210 > G[210];
int N, M;
bitset < 1410 > vis;
// int cyc[210];
int pos[210];
struct{int s, t;}edgs[11000];

void dfs(int p){
    vis[p] = true;
    for(auto i = head[p]; i; i = i->nxt)if(!vis[SON])dfs(SON);
}
bool Check(int p){
    vis.reset(), dfs(p);
    for(int i = 1; i <= M; ++i)if(vis[i << 1] && vis[(i << 1) | 1])return false;
    return true;
}

int main(){
    int T = read();
    while(T--){
        memset(head, 0, sizeof head);
        // tot = 0;
        // for(int i = 0; i <= 205; ++i)G[i].reset();
        N = read(), M = read();
        for(int i = 1; i <= M; ++i){
            // int s = read(), t = read();
            // G[s][t] = G[t][s] = true;
            edgs[i] = {read(), read()};
        }
        for(int i = 1; i <= N; ++i)pos[read()] = i;
        if(M > N * 3 - 6){printf("NO\n"); continue;}
        // for(int i = 2; i <= N; ++i)
        //     G[cyc[i]][cyc[i - 1]] = G[cyc[i - 1]][cyc[i]] = false;
        // G[cyc[1]][cyc[N]] = G[cyc[N]][cyc[1]] = false;
        // for(int i = 1; i <= N; ++i)
        //     for(int j = i + 1; j <= N; ++j)
        //         if(G[i][j])edgs[++tot] = {min(pos[i], pos[j]), max(pos[i], pos[j])};
        // if(M > 600)printf("$\n"), exit(1);
        for(int i = 1; i <= M; ++i)edgs[i] = {min(pos[edgs[i].s], pos[edgs[i].t]), max(pos[edgs[i].s], pos[edgs[i].t])};
        for(int i = 1; i <= M; ++i)
            for(int j = i + 1; j <= M; ++j)
                if(
                    (edgs[i].s < edgs[j].s && edgs[j].s < edgs[i].t && edgs[i].t < edgs[j].t) ||
                    (edgs[j].s < edgs[i].s && edgs[i].s < edgs[j].t && edgs[j].t < edgs[i].t)
                ){
                    head[i << 1] = new Edge{head[i << 1], (j << 1) | 1};
                    head[(i << 1) | 1] = new Edge{head[(i << 1) | 1], j << 1};
                    head[j << 1] = new Edge{head[j << 1], (i << 1) | 1};
                    head[(j << 1) | 1] = new Edge{head[(j << 1) | 1], i << 1};
                }
        for(int i = 1; i <= M; ++i){
            bool a = Check(i << 1), b = Check((i << 1) | 1);
            if(!a && !b){printf("NO\n"); break;}
            if(i == M)printf("YES\n");
        }
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