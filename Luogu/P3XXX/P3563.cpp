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
}ed[510000];
ROPNEW(ed);
Edge* head[260000];

int N;
int siz[260000], msiz[260000], rt(0);
void dfs(int p, int fa = -1){
    msiz[p] = 0;
    siz[p] = 1;
    for(auto i = head[p]; i; i = i->nxt){
        if(SON == fa)continue;
        dfs(SON, p);
        siz[p] += siz[SON];
        msiz[p] = max(msiz[p], siz[SON]);
    }
    msiz[p] = max(msiz[p], N - siz[p]);
    if(!rt || msiz[p] < msiz[rt])rt = p;
}
int cnt[260000];
int tot(0);
ll ans(0);
bitset < 260000 > dp;
int main(){
    N = read();
    for(int i = 1; i <= N - 1; ++i){
        int s = read(), t = read();
        head[s] = new Edge{head[s], t};
        head[t] = new Edge{head[t], s};
    }
    dfs(1);
    dfs(rt);
    for(int i = 1; i <= N; ++i)if(i != rt)ans += siz[i];
    for(auto i = head[rt]; i; i = i->nxt)cnt[siz[SON]]++;
    for(int i = 1; i <= N / 2; ++i)while(cnt[i] > 2)cnt[i] -= 2, cnt[i * 2]++;
    dp[0] = true;
    for(int i = 1; i <= N; ++i)while(cnt[i]--)dp |= dp << i;
    for(int i = N / 2; i >= 0 ; --i)if(dp[i]){ans += (ll)i * (N - i - 1); break;}
    printf("%d %lld\n", N - 1, ans);

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