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
    int val;
    OPNEW;
}ed[11000];
ROPNEW(ed);
Edge* head[5100];

int N, M;
int dis[5100];
int cnt[5100];
bool instack[5100];
// bool vis[5100];

// void Dijkstra(void){
//     std::priority_queue < pair < int, int >, vector < pair < int, int > >, greater < pair < int, int > > > q;
//     memset(dis, 0x3f, sizeof(dis));
//     dis[0] = 0;
//     q.push({dis[0], 0});
//     while(!q.empty()){
//         int tp = q.top().second; q.pop();
//         if(vis[tp])continue;
//         vis[tp] = true;
//         for(auto i = head[tp]; i; i = i->nxt){
//             if(dis[tp] + i->val < dis[SON])
//                 dis[SON] = dis[tp] + i->val, q.push({dis[SON], SON});
//         }
//     }
// }
bool SPFA(void){
    for(int i = 0; i <= 5010; ++i)dis[i] = -1000000000;
    memset(cnt, 0, sizeof(cnt));
    memset(instack, false, sizeof(instack));
    instack[0] = true;
    dis[0] = 0;
    queue < int > q;
    q.push(0);
    while(!q.empty()){
        int tp = q.front(); q.pop();
        instack[tp] = false;
        for(auto i = head[tp]; i; i = i->nxt){
            if(dis[tp] + i->val > dis[SON]){
                dis[SON] = dis[tp] + i->val;
                cnt[SON] = cnt[tp] + 1;
                if(cnt[SON] >= N + 1)return false;
                if(!instack[SON])q.push(SON), instack[SON] = true;
            }
        }
    }return true;
}

int main(){
    N = read(), M = read();
    for(int i = 1; i <= M; ++i){
        int s = read(), t = read(), val = read();
        head[s] = new Edge{head[s], t, -val};
    }
    for(int i = 1; i <= N; ++i){
        head[0] = new Edge{head[0], i, 0};
    }
    // Dijkstra();
    if(!SPFA())printf("NO\n"), exit(0);
    for(int i = 1; i <= N; ++i)printf("%d%c", dis[i], i == N ? '\n' : ' ');

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