#define _USE_MATH_DEFINES
#include <bits/stdc++.h>

#define npt nullptr

/******************************
abbr

******************************/

using namespace std;

mt19937 rnd(random_device{}());
int rndd(int l, int r){return rnd() % (r - l + 1) + l;}

typedef unsigned int uint;
typedef unsigned long long unll;
typedef long long ll;

template<typename T = int>
inline T read(void);

struct Node{
    int v, p;
    Node(int v, int p):v(v), p(p){;}
    Node(void) = default;
    bool operator < (const Node d)const{/////////////////////
        if(!this->p || !this->v)return true;
        if(!d.p || !d.v)return false;
        double x = (double)this->v / (double)this->p;
        double y = (double)d.v / (double)d.p;
        return x < y;
    }
    bool operator > (const Node d)const{/////////////////////
        if(!this->p || !this->v)return false;
        if(!d.p || !d.v)return true;
        double x = (double)this->v / (double)this->p;
        double y = (double)d.v / (double)d.p;
        return x > y;
    }
    Node operator + (Node d){
        return Node(this->v + d.v, this->p + d.p);
    }
    void operator = (Node d){
        this->p = d.p;
        this->v =d.v;
    }
};

struct Edge{
    Edge* nxt;
    int to;
    Node val;
    void* operator new(size_t);
    Edge(Edge* nxt, int to, Node val):nxt(nxt), to(to), val(val){;}
    Edge(void) = default;
}eData[21000];
void* Edge::operator new(size_t){static Edge* P = eData; return ++P;}
Edge* head[7500];

int N, M;

bool vis[110];
Node dis[110];
void Dijk(int);



priority_queue < 
    pair < Node, int >/*value, vertex*/,
    vector < pair < Node, int > >,
    less < pair < Node, int > >
> vert;

int main(){
    // freopen("road.in", "r", stdin);
    // freopen("road.out", "w", stdout);
    N = read(), M = read();
    for(int i = 1; i <= M; ++i){
        int f = read(), t = read(), v = read(), p = read();
        if(f == t)continue;
        head[f] = new Edge(head[f], t, Node(v, p));
    }
    Node ans(0, 0);
    for(int i = 1; i <= N; ++i){
        Dijk(i);
        if(dis[i] > ans)ans = dis[i];
        // printf("No.%d  %.3lf\n", i, (double)dis[i].v / (double)dis[i].p);
    }
    if(!ans.v || !ans.p)printf("-1\n");
    else printf("%.1lf\n", (double)ans.v / (double)ans.p);

    // fprintf(stderr, "Time: %.6lf\n", (double)clock() / CLOCKS_PER_SEC);
    return 0;
}


void Dijk(int S){
    memset(vis, false, sizeof(vis));
    // memset(dis, 0x3f, sizeof(dis));
    for(int i = 1; i <= N; ++i)dis[i].v = 0, dis[i].p = 0x3f3f3f3f;
    dis[S] = Node(0, 0);
    vert.push(make_pair(dis[S], S));
    while(!vert.empty()){
        int p;
        tie(ignore, p) = vert.top();
        vert.pop();
        if(vis[p])continue;
        vis[p] = true;
        if(p == S)vis[p] = false;
        for(auto i = head[p]; i; i = i->nxt){
            if(dis[p] + i->val > dis[i->to]){
                dis[i->to] = dis[p] + i->val;
                if(!vis[i->to])vert.push(make_pair(dis[i->to], i->to));
            }
        }
    }
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

/*

5 6
1 2 1 1
4 1 6 2
5 4 8 1
2 3 2 2
5 2 4 1
3 5 6 4

*/