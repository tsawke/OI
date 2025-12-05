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

int N, Q;
struct Edge{
    Edge* nxt;
    int to;
    int val;
    OPNEW;
}ed[21000];
ROPNEW(ed);
Edge* head[11000];

int q[110];
bool ans[110];
bool vis[11000];

int mx[11000];
int siz[11000];
int rt(0);
void ResetRoot(void){rt = 0, mx[rt] = N;}
void dfs_rt(int p = 1, int fa = 0, int Siz = N){
    siz[p] = 1; mx[p] = 0;
    for(auto i = head[p]; i; i = i->nxt){
        if(SON == fa || vis[SON])continue;
        dfs_rt(SON, p, Siz);
        siz[p] += siz[SON];
        mx[p] = max(mx[p], siz[SON]);
    }mx[p] = max(mx[p], Siz - siz[p]);
    if(mx[p] < mx[rt])rt = p;
}

struct Status{
    int dis, col;
    friend const bool operator < (const Status &a, const Status &b){return a.dis < b.dis;}
}st[11000]; int cnt(0);
void dfs_dis(int p, int fa, int cur, int col){
    st[++cnt] = Status{cur, col};
    for(auto i = head[p]; i; i = i->nxt){
        if(SON == fa || vis[SON])continue;
        dfs_dis(SON, p, cur + i->val, col);
    }
}

void Cal(int p){
    st[cnt = 1] = Status{0, 0};
    int col(0);
    for(auto i = head[p]; i; i = i->nxt)if(!vis[SON])dfs_dis(SON, p, i->val, ++col);
    sort(st + 1, st + cnt + 1);
    for(int i = 1; i <= Q; ++i){
        if(ans[i])continue;
        int l = 1, r = cnt;
        while(l < r){
            while(r && st[l].dis + st[r].dis > q[i])--r;
            if(st[l].col != st[r].col && st[l].dis + st[r].dis == q[i]){ans[i] = true; break;}
            if(++l > cnt)break;
        }
    }
}
void Make(int p){
    vis[p] = true;
    Cal(p);
    for(auto i = head[p]; i; i = i->nxt){
        if(vis[SON])continue;
        ResetRoot();
        dfs_rt(SON, p, siz[SON]);
        Make(rt);
    }
}

int main(){
    // freopen("P3806_7.in", "r", stdin);
    N = read(), Q = read();
    for(int i = 1; i <= N - 1; ++i){
        int s = read(), t = read(), v = read();
        head[s] = new Edge{head[s], t, v};
        head[t] = new Edge{head[t], s, v};
    }
    for(int i = 1; i <= Q; ++i)q[i] = read();
    ResetRoot(); dfs_rt(); dfs_rt(rt); Make(rt);
    for(int i = 1; i <= Q; ++i)printf("%s\n", ans[i] ? "AYE" : "NAY");
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