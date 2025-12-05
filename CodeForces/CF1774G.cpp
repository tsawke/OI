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

#define rng(x) (rng.at((x) - 1))
#define INF (0x3f3f3f3f)

template < typename T = int >
inline T read(void);

int N, Q;
int dp[210000][25];
struct Range{
    int l, r;
    friend const bool operator < (const Range &a, const Range &b){
        return a.l == b.l ? a.r > b.r : a.l < b.l;
    }
}rngt[210000];
basic_string < Range > rng;

int main(){
    N = read(), Q = read();
    for(int i = 1; i <= N; ++i)rngt[i].l = read(), rngt[i].r = read();
    sort(rngt + 1, rngt + N + 1);
    int curR(INF);
    for(int i = N; i >= 1; --i){
        if(rngt[i].r >= curR)continue;
        curR = rngt[i].r;
        rng += rngt[i];
    }sort(rng.begin(), rng.end());
    int tot = rng.size();
    int nxt(1);
    for(int cur = 1; cur <= tot; ++cur){
        while(nxt <= tot && rng(nxt).l <= rng(cur).r)++nxt;
        dp[cur][0] = nxt;
    }for(int i = 0; i <= 20; ++i)dp[tot + 1][i] = tot + 1;
    for(int j = 1; j <= 20; ++j)
        for(int i = 1; i <= tot; ++i)
            dp[i][j] = dp[dp[i][j - 1]][j - 1];
    while(Q--){
        int l = read(), r = read();
        auto it = lower_bound(rng.begin(), rng.end(), Range{l, INF});
        if(it == rng.end() || it->l != l){printf("0\n"); continue;}
        if(it->r == r){printf("998244352\n"); continue;}
        auto nxt = lower_bound(rng.begin(), rng.end(), Range{l + 1, INF});
        if(nxt == rng.end() || nxt->l > it->r || nxt->r > r){printf("0\n"); continue;}
        int cur = distance(rng.begin(), it) + 1;
        int cnxt = distance(rng.begin(), nxt) + 1;
        bool ret(0);
        for(int j = 20; j >= 0; --j)
            if(dp[cur][j] <= tot && rng(dp[cur][j]).r <= r)
                cur = dp[cur][j], ret ^= j ? 0 : 1;
        for(int j = 20; j >= 0; --j)
            if(dp[cnxt][j] <= tot && rng(dp[cnxt][j]).r <= r)
                cnxt = dp[cnxt][j], ret ^= j ? 0 : 1;
        if(cur == cnxt || (rng(cur).r != r && rng(cnxt).r != r)){printf("0\n"); continue;}
        printf("%d\n", ret ? 998244352 : 1);
    }
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