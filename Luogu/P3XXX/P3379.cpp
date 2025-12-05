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

class UnionFind{
    private:
        int fa[510000];
    public:
        UnionFind(void){for(int i = 0; i <= 501000; ++i)fa[i] = i;}
        int find(int x){return fa[x] == x ? x : (fa[x] = find(fa[x]));}
        void merge(int base, int x){fa[x] = find(base);}
}uf;
int N, Q;

struct Edge{
    Edge* nxt;
    int to;
    OPNEW;
}eData[1100000];
ROPNEW(eData);

Edge* head[510000];

int jp[510000][20];
int depth[510000];
int lg[510000] = {0, 0};

void dfs(int p, int fa = 0){
	depth[p] = depth[fa] + 1;
	jp[p][0] = fa;
	for(int i = 1; i <= lg[depth[p]]; ++i)jp[p][i] = jp[jp[p][i - 1]][i - 1];
	for(auto i = head[p]; i; i = i->nxt)if(i->to != fa)dfs(i->to, p);
}
int lca(int u, int v){
	if(depth[u] < depth[v])swap(u, v);
	// for(int i = lg[depth[u] - depth[v]]; i >= 0; --i)if(depth[jp[u][i]] <= depth[v])u = jp[u][i];
	while(depth[u] > depth[v])u = jp[u][lg[depth[u] - depth[v]]];
	if(u == v)return u;
	for(int i = lg[depth[u]]; i >= 0; --i)if(jp[u][i] != jp[v][i])u = jp[u][i], v = jp[v][i];
	return jp[u][0];
}

int main(){
    N = read(), Q = read(); int rt = read();
    for(int i = 2; i <= 501000; ++i)lg[i] = lg[i >> 1] + 1;
	for(int i = 1; i <= N - 1; ++i){
        int f = read(), t = read();
        head[f] = new Edge{head[f], t};
        head[t] = new Edge{head[t], f};
    }
	dfs(rt);
	// for(int i = 1; i <= 5; ++i)for(int j = 0; j <= 5; ++j)printf("%d%c", jp[i][j], j == 5 ? '\n' : ' ');
    for(int q = 1; q <= Q; ++q){
        int u = read(), v = read();
		printf("%d\n", lca(u, v));
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