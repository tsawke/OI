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

int N, M, K;
ll mx(LONG_LONG_MIN);
ll val[3000];
struct Node{int bst, sec, thd;}pt[3000];
int dis[3000][3000];

struct Edge{
    Edge* nxt;
    int to;
    OPNEW;
}ed[21000];
ROPNEW(ed);
Edge* head[3000];

signed main(){
    memset(dis, 0x3f, sizeof dis);
    N = read(), M = read(), K = read() + 1;
    for(int i = 2; i <= N; ++i)val[i] = read < ll >();
    for(int i = 1; i <= M; ++i){
        int s = read(), t = read();
        head[s] = new Edge{head[s], t};
        head[t] = new Edge{head[t], s};
    }
    for(int s = 1; s <= N; ++s){
        queue < int > cur;
        dis[s][s] = 0;
        cur.push(s);
        while(!cur.empty()){
            auto p = cur.front(); cur.pop();
            for(auto i = head[p]; i; i = i->nxt)
                if(dis[s][SON] > dis[s][p] + 1)
                    dis[s][SON] = dis[s][p] + 1, cur.push(SON);
        }
    }int S = 1;
    vector < int > reach;
    for(int i = 1; i <= N; ++i)
        if(i != S && dis[S][i] <= K)reach.emplace_back(i);
    for(auto p : reach)
        for(int i = 1; i <= N; ++i)
            if(p != i && S != i && dis[p][i] <= K){
                if(val[p] >= val[pt[i].bst])
                    pt[i].thd = pt[i].sec, pt[i].sec = pt[i].bst, pt[i].bst = p;
                else if(val[p] >= val[pt[i].sec])
                    pt[i].thd = pt[i].sec, pt[i].sec = p;
                else if(val[p] >= val[pt[i].thd])
                    pt[i].thd = p;
            }
    #define JUDGE(a, b) (a && b && a != i && a != j && b != i && b != j && a != b)
    #define MAXV(a, b) (JUDGE(a, b) ? val[a] + val[b] : LONG_LONG_MIN)
    // #define MAXV(a, b) if(JUDGE(a, b))mx = max(mx, val[i] + val[j] + val[a] + val[b])

    for(int i = 2; i <= N; ++i)
        for(int j = i + 1; j <= N; ++j){
            if(dis[i][j] > K)continue;
            int bsti = pt[i].bst, seci = pt[i].sec, thdi = pt[i].thd;
            int bstj = pt[j].bst, secj = pt[j].sec, thdj = pt[j].thd;
            mx = max(
                mx,
                val[i] + val[j] + max({
                    MAXV(bsti, bstj),
                    MAXV(bsti, secj),
                    MAXV(bsti, thdj),
                    MAXV(seci, bsti),
                    MAXV(seci, secj),
                    MAXV(seci, thdj),
                    MAXV(thdi, bstj),
                    MAXV(thdi, secj),
                    MAXV(thdi, thdj)
                })
            );
        }
    printf("%lld\n", mx);
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