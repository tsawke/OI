#define _USE_MATH_DEFINES
#include <bits/extc++.h>

#define PI M_PI
#define E M_E
#define npt nullptr
#define SON i->to
#define OPNEW void* operator new(size_t)
#define ROPNEW(arr) void* Edge::operator new(size_t){static Edge* P = arr; return P++;}

using namespace std;
using namespace __gnu_pbds;

mt19937 rnd(random_device{}());
int rndd(int l, int r){return rnd() % (r - l + 1) + l;}
bool rnddd(int x){return rndd(1, 100) <= x;}

typedef unsigned int uint;
typedef unsigned long long unll;
typedef long long ll;
typedef long double ld;

template< typename T = int >
inline T read(void);

class UnionFind{
private:
    int siz[110000];
    int fa[110000];
public:
    UnionFind(void){for(int i = 1; i <= 101000; ++i)fa[i] = i, siz[i] = 1;}
    int Find(int x){return x == fa[x] ? x : fa[x] = Find(fa[x]);}
    void Union(int origin, int son){
        if(Find(origin) == Find(son))return;
        siz[Find(origin)] += siz[Find(son)];
        fa[Find(son)] = Find(origin);
    }
    int GetSiz(int x){return siz[Find(x)] - 1;}
}uf;
struct Edge{
    int s, t;
    int val;
    friend const bool operator < (const Edge &a, const Edge &b){return a.val < b.val;}
};std::priority_queue < Edge > ed;
int ans[110000];
struct Query{
    int v, k;
    int idx;
    friend const bool operator < (const Query &a, const Query &b){return a.k > b.k;}
}qs[110000];
int N, Q;

int main(){
    N = read(), Q = read();
    for(int i = 1; i <= N - 1; ++i){
        int s = read(), t = read(), val = read();
        ed.push(Edge{s, t, val});
    }
    for(int i = 1; i <= Q; ++i){
        int k = read(), v = read();
        qs[i] = Query{v, k, i};
    }sort(qs + 1, qs + Q + 1);
    for(int i = 1; i <= Q; ++i){
        while(!ed.empty() && ed.top().val >= qs[i].k)
            uf.Union(ed.top().s, ed.top().t), ed.pop();
        ans[qs[i].idx] = uf.GetSiz(qs[i].v);
    }
    for(int i = 1; i <= Q; ++i)printf("%d\n", ans[i]);
    fprintf(stderr, "Time: %.6lf\n", (double)clock() / CLOCKS_PER_SEC);
    return 0;
}

template < typename T >
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