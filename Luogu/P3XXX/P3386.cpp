#define _USE_MATH_DEFINES
#include <bits/stdc++.h>

#define PI M_PI
// #define E M_E
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

int N, M, E;
struct Edge{
    Edge* nxt;
    int to;
    OPNEW;
}ed[110000];
ROPNEW;
Edge* head[51000];
bitset < 51000 > vis;
int match[51000];
int ans(0);

int main(){
    N = read(), M = read(), E = read();
    for(int i = 1; i <= E; ++i){
        int s = read(), t = read();
        head[s] = new Edge{head[s], t};
    }
    auto dfs = [](auto&& self, int p)->bool{
        for(auto i = head[p]; i; i = i->nxt){
            if(!vis[SON]){
                vis[SON] = true;
                if(!match[SON] || self(self, match[SON])){
                    match[SON] = p;
                    return true;
                }
            }
        }return false;
    };
    for(int i = 1; i <= N; ++i){
        vis.reset();
        if(dfs(dfs, i))++ans;
    }printf("%d\n", ans);

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