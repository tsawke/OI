#define _USE_MATH_DEFINES
#include <bits/stdc++.h>

#define PI M_PI
#define E M_E
#define npt nullptr
#define SON i->to
#define OPNEW void* operator new(size_t)
#define ROPNEW void* Edge::operator new(size_t){static Edge* P = ed; return P++;}
#define ROPNEW_NODE void* Node::operator new(size_t){static Node* P = nd; return P++;}

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

int N, M, Q;
struct Edge{
    Edge* nxt;
    int to;
    int val;
    OPNEW;
}ed[210000];
ROPNEW;
Edge* head[110000];

class UnionFind{
private:
public:
    int fa[110000];
    void Clear(void){for(int i = 1; i <= 101000; ++i)fa[i] = i;}
    UnionFind(void){Clear();}
    int Find(int x){return x == fa[x] ? x : fa[x] = Find(fa[x]);}
    void Union(int s, int t){if(Find(s) != Find(t))fa[Find(s)] = Find(t);}
}uf;

bitset < 110000 > illegal;
ll dis[110000];

int main(){
    // freopen("in.txt", "r", stdin);
    memset(dis, -1, sizeof dis);
    N = read(), M = read(), Q = read();
    for(int i = 1; i <= M; ++i){
        int s = read(), t = read(), v = read();
        head[s] = new Edge{head[s], t, v};
        head[t] = new Edge{head[t], s, -v};
        uf.Union(s, t);
    }
    for(int i = 1; i <= N; ++i){
        if(uf.fa[i] == i){
            static auto dfs = [](auto&& self, int p, int origin, ll cdis = 0)->void{
                if(!~dis[p])dis[p] = cdis;
                else if(dis[p] != cdis)return illegal[origin] = true, void();
                else return;
                for(auto i = head[p]; i; i = i->nxt)
                    self(self, SON, origin, cdis + i->val);
            }; dfs(dfs, i, i);
        }
    }
    while(Q--){
        int s = read(), t = read();
        if(uf.Find(s) != uf.Find(t)){printf("nan\n"); continue;}
        int fx = uf.Find(s);
        if(illegal[fx]){printf("inf\n"); continue;}
        printf("%lld\n", dis[t] - dis[s]);
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
    }ret *= flag;
    return ret;
}