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

int N;
int cnt(0);
int to[110000];
bool vis[110000];
class UnionFind{
private:
    int fa[110000];
    int dis[110000];
public:
    UnionFind(void){for(int i = 1; i <= 101000; ++i)fa[i] = i, dis[i] = 0;}
    int Find(int x){return x == fa[x] ? x : fa[x] = Find(fa[x]);}
    int GetDis(int x){return dis[x];};
    void Union(int origin, int son){fa[son] = Find(origin);}
}uf;
int main(){
    N = read();
    for(int i = 1; i <= N; ++i){
        to[i] = read();
        if(uf.Find(to[i]) == i){
            int cur(to[i]);
            while(cur != i)++cnt, cur = to[cur];
            ++cnt;
        }else uf.Union(to[i], i);
    }
    printf("%d\n", cnt);
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