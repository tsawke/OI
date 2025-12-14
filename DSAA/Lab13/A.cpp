#define _USE_MATH_DEFINES
#include <bits/stdc++.h>

#define PI M_PI
#define E M_E

using namespace std;

mt19937 rnd(random_device{}());
int rndd(int l, int r){return rnd() % (r - l + 1) + l;}

using ll = long long;
using unll = unsigned long long;
using uint = unsigned int;
using ld = long double;

template < typename T = int >
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

struct Edge{
    Edge* nxt;
    int to;
};

int main(){
    int N = read(), M = read();
    vector < Edge* > head(N + 1, nullptr), rhead(N + 1, nullptr);
    for(int i = 1; i <= M; ++i){
        int x = read(), y = read();
        head[x] = new Edge{head[x], y};
        rhead[y] = new Edge{rhead[y], x};
    }

    int s = read(), t = read();
    
    vector < int > vis(N + 1, 0);
    queue < int > q;

    vis[t] = 1;
    q.push(t);
    while(!q.empty()){
        int u = q.front(); q.pop();
        for(auto i = rhead[u]; i; i = i->nxt){
            if(!vis[i->to])vis[i->to] = 1, q.push(i->to);
        }
    }
    
    if(!vis[s]){printf("-1\n"); return 0;}
    
    vector < int > good(N + 1, 1);
    for(int p = 1; p <= N; ++p){
        for(auto i = head[p]; i; i = i->nxt){
            if(!vis[i->to]){good[p] = 0; break;}
        }
    }
    
    vector < int > ok(N + 1, 0);
    for(int p = 1; p <= N; ++p)
        if(good[p] && vis[p])ok[p] = 1;
    
    if(!ok[s] || !ok[t]){printf("-1\n"); return 0;}
    
    vector < int > dis(N + 1, -1);
    while(!q.empty())q.pop();
    dis[s] = 0;
    q.push(s);
    while(!q.empty()){
        int p = q.front(); q.pop();
        if(p == t)break;
        for(auto i = head[p]; i; i = i->nxt){
            if(!ok[i->to])continue;
            if(dis[i->to] != -1)continue;
            dis[i->to] = dis[p] + 1;
            q.push(i->to);
        }
    }
    
    printf("%d\n", dis[t]);
    // fprintf(stderr, "Time: %.6lf\n", (double)clock() / CLOCKS_PER_SEC);
    return 0;
}
