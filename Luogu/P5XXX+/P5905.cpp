#define _USE_MATH_DEFINES
#include <bits/stdc++.h>

#define PI M_PI
#define E M_E

using namespace std;

mt19937 rnd(random_device{}());
int rndd(int l, int r){return rnd() % (r - l + 1) + l;}

typedef unsigned int uint;
typedef unsigned long long unll;
typedef long long ll;

#define SON i->to
#define INF (ll)(1e9)

template<typename T = int>
inline T read(void);

struct Edge{
    Edge* nxt;
    int to;
    int val;
    void* operator new(size_t);
}ed[11000];
void* Edge::operator new(size_t){static Edge* P = ed; return P++;}
Edge* head[3100];

int N, M;
int H[3100];

int dis[3100];
ll ans[3100];
bool vis[3100];

bool inq[3100];
int cnt[3100];


int main(){
    N = read(), M = read();
    for(int i = 1; i <= M; ++i){
        int s = read(), t = read(), v = read();
        head[s] = new Edge{head[s], t, v};
    }

    for(int i = 1; i <= N; ++i)
        head[0] = new Edge{head[0], i, 0};
    
    auto SPFA = []() -> void{
        memset(H, 0x3f, sizeof H); H[0] = 0;
        queue < int > cur;
        cur.push(0); inq[0] = true; ++cnt[0];
        while(!cur.empty()){
            int p = cur.front(); cur.pop(); inq[p] = false;
            for(auto i = head[p]; i; i = i->nxt)
                if(H[p] + i->val < H[SON]){
                    H[SON] = H[p] + i->val;
                    if(!inq[SON]){
                        inq[SON] = true;
                        cur.push(SON);
                        if(++cnt[SON] >= N + 1){
                            printf("-1\n");
                            exit(0);
                        }
                    }
                }
        }
    }; SPFA();

    // auto Ford = []() -> void{
    //     memset(H, 0, sizeof H);
    //     H[0] = 0;
    //     for(int c = 1; c <= N - 1; ++c)
    //         for(int p = 0; p <= N; ++p)
    //             for(auto i = head[p]; i; i = i->nxt)
    //                 H[SON] = min(H[SON], H[p] + i->val);
    // }; Ford();

    for(int p = 1; p <= N; ++p)
        for(auto i = head[p]; i; i = i->nxt)
            i->val += H[p] - H[SON]; //non-negative - based on the inequation
    
    auto Dijkstra = [](int S) -> void{
        memset(dis, 0x3f, sizeof dis); dis[S] = 0;
        memset(vis, 0, sizeof vis);
        static priority_queue < pair < int, int >, vector < pair < int, int > >, greater < pair < int, int > > > cur;
        while(!cur.empty())cur.pop();
        cur.push({dis[S], S});
        while(!cur.empty()){
            int p = cur.top().second; cur.pop();
            if(vis[p])continue;
            vis[p] = true;
            for(auto i = head[p]; i; i = i->nxt)
                if(dis[p] + i->val < dis[SON])
                    dis[SON] = dis[p] + i->val, cur.push({dis[SON], SON});
        }
        for(int i = 1; i <= N; ++i)ans[S] += (ll)i * (dis[i] == 0x3f3f3f3f ? INF : (dis[i] - (H[S] - H[i])));
    };
    for(int i = 1; i <= N; ++i)Dijkstra(i);
    for(int i = 1; i <= N; ++i)printf("%lld\n", ans[i]);

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