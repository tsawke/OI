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

template<typename T = int>
inline T read(void);

struct Edge{
    Edge* nxt;
    int to;
    OPNEW;
}ed[610000];
ROPNEW(ed);
Edge* head[310000];

int N;
int cson[310000];
int dp[310000];

void dfs(int p = 1, int fa = 0){
    for(auto i = head[p]; i; i = i->nxt)if(SON != fa)++cson[p], dfs(SON, p);
}
void MakeDP(int k, int p = 1, int fa = 0){
    dp[p] = cson[p] - k;
    for(auto i = head[p]; i; i = i->nxt)
        if(SON != fa){
            MakeDP(k, SON, p);
            dp[p] += max(0, dp[SON]);
        }
}
bool check(int k){
    MakeDP(k);
    return dp[1] <= 0;
}

int main(){
    N = read();
    for(int i = 1; i <= N - 1; ++i){
        int s = read(), t = read();
        head[s] = new Edge{head[s], t};
        head[t] = new Edge{head[t], s};
    }
    dfs();
    int l = cson[1], r = N - 1, ans = -1;
    while(l <= r){
        int mid = (l + r) >> 1;
        check(mid) ? ans = mid, r = mid - 1 : l = mid + 1;
    }printf("%d\n", ans);
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