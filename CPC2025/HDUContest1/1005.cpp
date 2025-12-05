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

#define SON (i->to)

template<typename T = int>
inline T read(void);

namespace std {
    template <>
    struct hash< pair< int, int > >{
        size_t operator()(const pair< int, int > &p) const{
            auto h1 = hash< int >{}(p.first);
            auto h2 = hash< int >{}(p.second);
            return h1 ^ (h2 << 1);
        }
    };
}

struct Edge{
    Edge* nxt;
    int to;
    int belong;
};
Edge* head[110000];

int N, M;

unordered_map < int, unordered_map < int, int > > dis;
unordered_set < pair < int, int > > vis;


void Dijkstra(void){
    // for(int i = 0; i <= N; ++i)dis[i] = 0x3f3f3f3f3f3f3f3f;
    // vis.reset();
    dis.clear(), vis.clear();
    priority_queue < pair < ll, pair <int, int > >, vector < pair < ll, pair <int, int > > >, greater < pair < ll, pair <int, int > > > > cur;
    for(auto i = head[1]; i; i = i->nxt)
        dis[1][i->belong] = 0, cur.push({0, {1, i->belong}});
    // dis[1] = 0, cur.push({0, 1});
    while(!cur.empty()){
        auto [p, bel] = cur.top().second; cur.pop();
        // int p = cur.top().second; cur.pop();
        // if(vis[p])continue;
        if(vis.find({p, bel}) != vis.end())continue;
        // printf("Caling p = %d, bel = %d\n", p, bel);
        vis.insert({p, bel});
        // vis[p] = true;
        for(auto i = head[p]; i; i = i->nxt)
            // for(auto bel : dis[p]){
                if(dis[SON].find(i->belong) == dis[SON].end() || dis[SON][i->belong] > dis[p][bel] + (bel == i->belong ? 0 : 1))
                    dis[SON][i->belong] = dis[p][bel] + (bel == i->belong ? 0 : 1), cur.push({dis[SON][i->belong], {SON, i->belong}});
            // }
            
    }
}


int main(){
    int T = read();
    while(T--){
        N = read(), M = read();
        for(int i = 0; i <= N; ++i)head[i] = nullptr;
        for(int i = 1; i <= M; ++i){
            int s = read(), t = read(), belong = read();
            head[s] = new Edge{head[s], t, belong};
            head[t] = new Edge{head[t], s, belong};
        }
        Dijkstra();
        int mn = (INT_MAX);
        for(auto val : dis[N])mn = min(mn, val.second);//, printf("In ans: bel = %d, ans = %d\n", val.first, val.second);
        // for(auto i : dis){
        //     for(auto j : i.second){
        //         printf("At %d, belong %d, dis = %d\n", i.first, j.first, j.second);
        //     }
        // }
        printf("%d\n", mn + 1);
    }
    

    // fprintf(stderr, "Time: %.6lf\n", (double)clock() / CLOCKS_PER_SEC);
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