#define _USE_MATH_DEFINES
#include <bits/stdc++.h>

#define PI M_PI
#define E M_E
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

#define EPS (double)(1e-8)

template< typename T = int >
inline T read(void);

int N, K;
bool vis[310][310];
struct Coord{int x, y;}p[310];
int ans(0);
bool Check(Coord a, Coord b, Coord c){
    // return (abs((double)(b.y - a.y) / (double)(b.x - a.x) - (double)(c.y - b.y) / (double)(c.x - b.x)) <= EPS);
    return ((ll)(b.y - a.y) * (c.x - b.x) == (ll)(c.y - b.y) * (b.x - a.x));
}

int main(){
    N = read(), K = read();
    if(K == 1)printf("Infinity\n"), exit(0);
    for(int i = 1; i <= N; ++i)p[i].x = read(), p[i].y = read();
    for(int i = 1; i <= N; ++i)
        for(int j = i + 1; j <= N; ++j)
            if(!vis[i][j]){
                basic_string < int > pts; pts += {i, j};
                for(int k = 1; k <= N; ++k)
                    if(k != i && k != j && Check(p[i], p[j], p[k]))pts += k;
                for(auto u : pts)for(auto v : pts)vis[u][v] = true;
                if((int)pts.size() >= K)++ans;
            }
    printf("%d\n", ans);
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