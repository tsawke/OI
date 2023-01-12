#define _USE_MATH_DEFINES
#include <bits/stdc++.h>

#define PI M_PI
#define E M_E
#define npt nullptr
#define SON i->to
#define OPNEW void* operator new(size_t)
#define ROPNEW(arr) void* Edge::operator new(size_t){static Edge* P = arr; return P++;}

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
}ed[610000];
ROPNEW(ed);
Edge* head[160000];

int N, M;
bitset < 160000 > vis;

int bfs(int S, int D){
    if(!D)return S;
    basic_string < int > nods;
    queue < pair < int, int > > cur;
    cur.push({S, 0}), vis[S] = true, nods += S;
    while(!cur.empty()){
        auto tp = cur.front(); cur.pop();
        for(auto i = head[tp.first]; i; i = i->nxt)
            if(!vis[SON]){
                vis[SON] = true;
                nods += SON;
                if(tp.second + 1 < D)cur.push({SON, tp.second + 1});
            }
    }int ret(0);
    for(auto nod : nods)vis[nod] = false, ret += nod;
    return ret;
}

int main(){
    N = read(), M = read();
    for(int i = 1; i <= M; ++i){
        int s = read(), t = read();
        head[s] = new Edge{head[s], t};
        head[t] = new Edge{head[t], s};
    }int Q = read();
    while(Q--){
        int S = read(), D = read();
        printf("%d\n", bfs(S, D));
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