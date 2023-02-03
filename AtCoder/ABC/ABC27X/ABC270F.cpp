#define _USE_MATH_DEFINES
#include <bits/stdc++.h>

#define PI M_PI
#define E M_E
#define npt nullptr
#define SON i->to
#define OPNEW void* operator new(size_t)
#define ROPNEW void* Edge::operator new(size_t){static Edge* P = ed; return P++;}

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

// struct Edge{
//     Edge* nxt;
//     int to;
//     ll val;
//     OPNEW;
// }ed[410000];
// ROPNEW;
// Edge* head[210000];

ll X[210000], Y[210000];
int N, M;
ll ans(LONG_LONG_MAX);

struct Edge{
    int s, t; ll val;
    friend const bool operator < (const Edge &a, const Edge &b){
        return a.val < b.val;
    }
};
basic_string < Edge > edgs, basic_edgs;

class UnionFind{
private:
    int fa[210000];
public:
    void Clear(void){for(int i = 1; i <= 201000; ++i)fa[i] = i;}
    int Find(int x){return x == fa[x] ? x : fa[x] = Find(fa[x]);}
    void Union(int s, int t){fa[Find(s)] = fa[Find(t)];}
}uf;

ll MST(void){
    uf.Clear();
    ll ret(0);
    sort(edgs.begin(), edgs.end());
    for(auto e : edgs)
        if(uf.Find(e.s) != uf.Find(e.t))
            uf.Union(e.s, e.t), ret += e.val;
    for(int i = 1; i <= N - 1; ++i)if(uf.Find(i) != uf.Find(i + 1))return LONG_LONG_MAX;
    return ret;
}

int main(){
    N = read(), M = read();
    for(int i = 1; i <= N; ++i)X[i] = read();
    for(int i = 1; i <= N; ++i)Y[i] = read();
    for(int i = 1; i <= M; ++i){
        int s = read(), t = read(), v = read();
        // head[s] = new Edge{head[s], t, v};
        // head[t] = new Edge{head[t], s, v};
        basic_edgs += Edge{s, t, v};
    }edgs += basic_edgs;
    ans = min(ans, MST());
    // printf("%lld\n", ans);
    for(int i = 1; i <= N; ++i)edgs += Edge{i, N + 1, X[i]};
    ++N;
    ans = min(ans, MST());
    // printf("%lld\n", ans);
    edgs.clear();
    edgs += basic_edgs;
    for(int i = 1; i <= N - 1; ++i)edgs += Edge{i, N, Y[i]};
    ans = min(ans, MST());
    // printf("%lld\n", ans);
    for(int i = 1; i <= N - 1; ++i)edgs += Edge{i, N + 1, X[i]};
    ++N;
    ans = min(ans, MST());
    printf("%lld\n", ans);
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
    }
    ret *= flag;
    return ret;
}