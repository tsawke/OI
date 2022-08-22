#define _USE_MATH_DEFINES
#include <bits/stdc++.h>
#include <unistd.h>

#define PI M_PI
#define E M_E

using namespace std;

mt19937 rnd(random_device{}());
int rndd(int l, int r){return rnd() % (r - l + 1) + l;}

#define npt nullptr
#define upd(from, to, val)do{\
    head[from] = new Edge(head[from], npt, to, val);\
    head[to] = new Edge(head[to], npt, from, 0);\
    head[from]->rev = head[to], head[to]->rev = head[from];\
}while(false)

typedef unsigned int uint;
typedef unsigned long long unll;
typedef long long ll;

struct Edge{
    Edge *nxt, *rev;
    int to, val;
    void* operator new(size_t);
    Edge(Edge *Nxt = npt, Edge *Rev = npt, int To = -1, int Val = 0):nxt(Nxt), rev(Rev), to(To), val(Val){;}
}eData[210000];
Edge *head[120], *cur[120];
void* Edge::operator new(size_t){static Edge *P = eData; return ++P;}
int dep[110];
template<typename T = int>
inline T read(void);
int N, M;
const int S(101), T(102);


bool bfs(void){
    // for(int i = 1; i <= 100; ++i)printf("%d ", eData[i].val);
    copy(head + 1, head + 110 + 1, cur + 1);
    memset(dep, 0, sizeof(dep));
    queue < int > q;
    q.push(T);
    dep[T] = 1;
    while(!q.empty()){
 //       printf("Q-Front = %d\n", q.front());sleep(1);
        int from = q.front(); q.pop();
        for(auto i = head[from]; i; i = i->nxt){
            if(i->rev->val > 0 && !dep[i->to]){
                dep[i->to] = dep[from] + 1;
                q.push(i->to);
            }
        }
        if(dep[S])break;
    }
    // for(int i = 1; i <= N; ++i)printf("%d ", dep[i]);
    // printf("\n"); //sleep(3);
    return dep[S];
}
int dfs(int p = S, int flow = INT_MAX){
    if(p == T)return flow;
    int cost(0);
    for(auto &i = cur[p]; i; i = i->nxt){
        if(i->val > 0 && dep[p] - 1 == dep[i->to]){
            int icost = dfs(i->to, min(flow - cost, i->val));
            cost += icost;
            i->val -= icost;
            i->rev->val += icost;
            if(cost == flow)break;
        }
    }
    if(!cost)dep[p] = INT_MAX;
    return cost;
}

int Dinic(void){
    int ret(0), tmp;
    while(bfs())while((tmp = dfs()))ret += tmp;
    return ret;
}



int main(){
    M = read(), N = read();
    int x, y;//x->foreign y->english
    while((x = read()) != -1 && (y = read()) != -1)upd(x, y, 1);
    for(int i = 1; i <= M; ++i)upd(S, i, 1);
    for(int i = M + 1; i <= N; ++i)upd(i, T, 1);
    // printf("Input Complete\n");
    printf("%d\n", Dinic());
    for(int i = 1; i <= M; ++i){
        for(auto j = head[i]; j; j = j->nxt){
            if(!j->val && j->to != S)printf("%d %d\n", i, j->to);
        }
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