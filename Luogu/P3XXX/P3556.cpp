#define _USE_MATH_DEFINES
#include <bits/extc++.h>

#define PI M_PI
#define E M_E
#define npt nullptr
#define SON i->to
#define OPNEW void* operator new(size_t)
#define ROPNEW(arr) void* Edge::operator new(size_t){static Edge* P = arr; return P++;}

/******************************
abbr

******************************/

using namespace std;
using namespace __gnu_pbds;

mt19937 rnd(random_device{}());
int rndd(int l, int r){return rnd() % (r - l + 1) + l;}
bool rnddd(int x){return rndd(1, 100) <= x;}

typedef unsigned int uint;
typedef unsigned long long unll;
typedef long long ll;
typedef long double ld;

template<typename T = int>
inline T read(void);

struct Edge{
    Edge* nxt;
    int to;
    OPNEW;
}eData[21000];
ROPNEW(eData);
Edge* head[11000];

int N, M, K;
short dis[10100][10100];
bool vis[10100];
queue < int > q;
void bfs(int S){
    memset(vis, false, sizeof(vis));
    q.push(S);
    // vis[S] = true;
    while(!q.empty()){
        int tp = q.front(); q.pop();
        for(auto i = head[tp]; i; i = i->nxt){
            if(vis[SON])continue;
            vis[SON] = true;
            dis[S][SON] = dis[S][tp] + 1;
            q.push(SON);
        }
    }
}

int main(){
    N = read(), M = read(), K = read();
    for(int i = 1; i <= M; ++i){
        int f = read(), t = read();
        head[f] = new Edge{head[f], t + N};
        head[t + N] = new Edge{head[t + N], f};
        head[t] = new Edge{head[t], f + N};
        head[f + N] = new Edge{head[f + N], t};
    }
    for(int i = 1; i <= N; ++i)bfs(i);
    for(int i = 1; i <= K; ++i){
        int f = read(), t = read(), d = read();
        int diss = dis[f][(d & 1) ? t + N : t];
        printf("%s\n", diss && d >= diss ? "TAK" : "NIE");
    }
    fprintf(stderr, "Time: %.6lf\n", (double)clock() / CLOCKS_PER_SEC);
    return 0;
}

template<typename T>
inline T read(void){
    T ret(0);
    short flag(1);
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