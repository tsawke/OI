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

#define MOD (ll)(1e9 + 7)

template < typename T = int >
inline T read(void);

int N, K;
ll ans(0);
int a[11000];
ll dp[11000][110];
basic_string < int > nxt[11000];

int main(){
    freopen("B.in", "r", stdin);
    freopen("B.out", "w", stdout);
    N = read(), K = read();
    for(int i = 1; i <= N; ++i)a[i] = read();
    for(int i = 1; i <= N; ++i)
        for(int j = i + 1; j <= N; ++j)
            if(a[j] > a[i])nxt[i] += j;
    for(int i = 1; i <= N; ++i)dp[i][1] = 1;
    for(int i = 1; i <= N - 1; ++i)
        for(int j = 1; j <= K; ++j)
            for(auto nx : nxt[i])
                (dp[nx][j + 1] += dp[i][j]) %= MOD;
    for(int i = 1; i <= N; ++i)(ans += dp[i][K]) %= MOD;
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