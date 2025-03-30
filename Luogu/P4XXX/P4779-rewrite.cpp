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

template<typename T = int>
inline T read(void);

struct Edge{
    Edge* nxt;
    int to;
    int val;
    void* operator new(size_t);
}ed[210000];
void* Edge::operator new(size_t){static Edge* P = ed; return P++;}
Edge* head[210000];

int N, M, S;
int dis[110000];
bool vis[110000];

int main(){
    N = read(), M = read(), S = read();
    for(int i = 1; i <= M; ++i){
        int s = read(), t = read(), v = read();
        head[s] = new Edge{head[s], t, v};
    }

    auto Dijkstra = []() -> void{
        memset(dis, 0x3f, sizeof dis);
        dis[S] = 0;
        priority_queue < pair < int, int >, vector < pair < int, int > >, greater < pair < int, int > > > cur;
        cur.push(make_pair(dis[S], S));
        while(!cur.empty()){
            int p = cur.top().second; cur.pop();
            if(vis[p])continue;
            vis[p] = true;
            for(auto i = head[p]; i; i = i->nxt)
                if(dis[p] + i->val < dis[SON])
                    dis[SON] = dis[p] + i->val, cur.push(make_pair(dis[SON], SON));
        }
    }; Dijkstra();

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