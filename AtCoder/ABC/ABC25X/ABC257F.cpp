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
Edge* head[310000];

int N, M;
int dis1[310000], disn[310000];

void bfs1(void){
    memset(dis1, 0x3f, sizeof dis1);
    bitset < 310000 > vis; vis.reset();
    queue < int > cur; cur.push(1), vis[1] = true, dis1[1] = 0;
    while(!cur.empty()){
        int p = cur.front(); cur.pop();
        for(auto i = head[p]; i; i = i->nxt)
            if(!vis[SON])
                vis[SON] = true, dis1[SON] = dis1[p] + 1, cur.push(SON);
    }
}
void bfsn(void){
    memset(disn, 0x3f, sizeof disn);
    bitset < 310000 > vis; vis.reset();
    queue < int > cur; cur.push(N), vis[N] = true, disn[N] = 0;
    while(!cur.empty()){
        int p = cur.front(); cur.pop();
        for(auto i = head[p]; i; i = i->nxt)
            if(!vis[SON])
                vis[SON] = true, disn[SON] = disn[p] + 1, cur.push(SON);
    }
}

int main(){
    N = read(), M = read();
    for(int i = 1; i <= M; ++i){
        int s = read(), t = read();
        head[s] = new Edge{head[s], t};
        head[t] = new Edge{head[t], s};
    }bfs1(), bfsn();
    for(int i = 1; i <= N; ++i){
        int ans = min({dis1[N], dis1[0] + disn[i], dis1[i] + disn[0]});
        printf("%d%c", ans >= 0x3f3f3f3f ? -1 : ans, i == N ? '\n' : ' ');
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