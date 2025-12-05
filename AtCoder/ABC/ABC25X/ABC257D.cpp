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

template < typename T = int >
inline T read(void);

int N;
struct Node{ll x, y, p;}nod[300];
ll dis[300][300];
ll ans(LONG_LONG_MAX);

int main(){
    N = read();
    for(int i = 1; i <= N; ++i)nod[i].x = read(), nod[i].y = read(), nod[i].p = read();
    for(int i = 1; i <= N; ++i)
        for(int j = 1; j <= N; ++j)
            if(i == j)dis[i][j] = 0;
            else
                dis[i][j] = (ll)ceil((ld)(abs(nod[i].x - nod[j].x) + abs(nod[i].y - nod[j].y)) / (ld)nod[i].p),
                dis[j][i] = (ll)ceil((ld)(abs(nod[i].x - nod[j].x) + abs(nod[i].y - nod[j].y)) / (ld)nod[j].p);
    for(int k = 1; k <= N; ++k)
        for(int i = 1; i <= N; ++i)
            for(int j = 1; j <= N; ++j)
                dis[i][j] = min(dis[i][j], max(dis[i][k], dis[k][j]));
    for(int s = 1; s <= N; ++s){
        ll mx(-1);
        for(int t = 1; t <= N; ++t)mx = max(mx, dis[s][t]);
        ans = min(ans, mx);
    }printf("%lld\n", ans);
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