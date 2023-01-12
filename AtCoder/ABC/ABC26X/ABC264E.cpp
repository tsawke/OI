#define _USE_MATH_DEFINES
#include <bits/stdc++.h>

#define PI M_PI
#define npt nullptr
#define SON i->to
#define OPNEW void* operator new(size_t)
#define ROPNEW(arr) void* Edge::operator new(size_t){static Edge* P = arr; return P++;}

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

struct Edge{int s, t;}edg[510000];
int N, M, E;
int Q;
ll rans[510000];
bool del[510000];
int qs[510000];
ll ans(0);

class UnionFind{
private:
    int fa[510000];
    int siz[510000];
    bool light[510000];
public:
    UnionFind(void){for(int i = 1; i <= 501000; ++i)fa[i] = i;}
    void Init(void){
        for(int i = 1; i <= N; ++i)siz[i] = 1;
        for(int i = N + 1; i <= N + M; ++i)light[i] = true;
    }
    int Find(int x){return x == fa[x] ? x : fa[x] = Find(fa[x]);}
    void Merge(int s, int t){
        int rs = Find(s), rt = Find(t);
        if(rs == rt)return;
        // printf("Mergeing rs = %d, rt = %d, light is %d %d\n", rs, rt, light[rs] ? 1 : 0, light[rt] ? 1 : 0);
        if(light[rs] ^ light[rt]){
            if(!light[rs] && light[rt])swap(rs, rt);
            ans += siz[rt];
            siz[rs] += siz[rt];
            fa[rt] = rs;
        }else{
            siz[rs] += siz[rt];
            fa[rt] = rs;
        }
    }
}uf;

int main(){
    // freopen("test_18.txt", "r", stdin);
    // freopen("out.txt", "w", stdout);
    N = read(), M = read(), E = read();
    uf.Init();
    for(int i = 1; i <= E; ++i){
        int s = read(), t = read();
        edg[i] = Edge{s, t};
    }Q = read();
    for(int i = 1; i <= Q; ++i)del[qs[i] = read()] = true;
    for(int i = 1; i <= E; ++i)if(!del[i])uf.Merge(edg[i].s, edg[i].t);//, printf("merge : %d %d\n", edg[i].s, edg[i].t);
    for(int i = Q; i >= 1; --i){
        rans[i] = ans;
        uf.Merge(edg[qs[i]].s, edg[qs[i]].t);
    }for(int i = 1; i <= Q; ++i)printf("%lld\n", rans[i]);
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